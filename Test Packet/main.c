#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packet_struct.h"

#define PACKET_OVERHEAD 270
/* 270 =
<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<packet type=""><data></data></packet>
*/
#define DATA_OVERHEAD 15 //15 = <d type=""></d>

#define XML_TAG "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define XMLNS "http://wyspr.s4t4n.net/packet"
#define SCHEMA_LOC "http://wyspr.s4t4n.net/packet http://wyspr.s4t4n.net/packet/wyspr-packet_0.2.xsd"

void packet_create(struct packet *pack, char *name);
void packet_add_data(struct packet *pack, char *name, char *value);
void data_print(struct data x);
void packet_output(struct packet *pack, char **buffer);
void packet_free(struct packet *pack);

int main (int argc, const char * argv[])
{
   struct packet ptest;
	
	packet_create(&ptest, "echo");
	packet_add_data(&ptest, "content", "This message goes out to everybody connected!");
	packet_add_data(&ptest, "origin", "GameFreak7744");
	
	char *cpack;
	//cpack = malloc((ptest.total_size)+1);
	packet_output(&ptest, &cpack);
	printf(cpack);
	
	
	packet_free(&ptest);
   return 0;
}


void packet_create(struct packet *pack, char *name)
{
	pack->name = malloc(strlen(name)+1);
	stpcpy(pack->name, name);
	pack->entry_count = 0;
	pack->total_size = PACKET_OVERHEAD + strlen(name);
}

void packet_add_data(struct packet *pack, char *name, char *value)
{
	int packet_size = 0;
	int x = 0;
	struct data **y = &pack->entry;
	while(x < pack->entry_count)
	{
		packet_size += (*y)->size;
		y = &(*y)->next;
		x++;
	}
	
	*y = malloc(sizeof(struct data));
	(*y)->name = malloc(strlen(name)+1);
	(*y)->name = name;
	(*y)->value = malloc(strlen(value)+1);
	(*y)->value = value;
	(*y)->size = DATA_OVERHEAD + strlen(name) + strlen(value);
	
	packet_size += (*y)->size;
	pack->total_size = PACKET_OVERHEAD + packet_size;
	
	pack->entry_count++;
}

void data_print(struct data x)
{
	printf("<d type=\"");
	printf(x.name);
	printf("\">");
	printf(x.value);
	printf("</d>");
}

void packet_output(struct packet *pack, char **buffer)
{
	*buffer = malloc((pack->total_size)+1);
	strcat(*buffer, XML_TAG);
	strcat(*buffer, "<packet type=\"");
	strcat(*buffer, pack->name);
	strcat(*buffer, "\" xmlns=\"");
	strcat(*buffer, XMLNS);
	strcat(*buffer, "\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"");
	strcat(*buffer, SCHEMA_LOC);
	strcat(*buffer, "\"><data>");
	int x = 0;
	struct data **y = &pack->entry;
	while(x < pack->entry_count)
	{
		strcat(*buffer, "<d type=\"");
		strcat(*buffer, (*y)->name);
		strcat(*buffer, "\">");
		strcat(*buffer, (*y)->value);
		strcat(*buffer, "</d>");
		y = &(*y)->next;
		x++;
	}
	strcat(*buffer, "</data></packet>");
	//printf(buffer);
}

void packet_free(struct packet *pack)
{
	free(pack->name);
	int x = 0;
	struct data **y = &pack->entry;
	while(x < pack->entry_count)
	{
		struct data **z = y;
		y = &(*y)->next;
		//free((*z)->name);
		//printf((*y)->name);
		//printf(pack->entry->name);
		//free((*z)->value);
		//free(*z);
		x++;
	}
}
