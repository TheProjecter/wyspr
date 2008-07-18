/*
 *  main.c
 *  Packet
 *
 *  Created by Joey Sabey on 16/07/08.
 *  Copyright (c) 2008 Joey Sabey, et al.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packet_struct.h"

#define PACKET_OVERHEAD 270
/* 270 =
<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<packet type=""><data></data></packet>
*/

#define XML_TAG "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define XMLNS "http://wyspr.s4t4n.net/packet"
#define SCHEMA_LOC "http://wyspr.s4t4n.net/packet http://wyspr.s4t4n.net/packet/wyspr-packet_0.2.xsd"

void packet_create(struct packet *pack, char *name);
void packet_add_data(struct packet *pack, char *name, char *value);
void packet_output(struct packet *pack, char **buffer);
int packet_size(struct packet *pack);
void packet_free(struct packet *pack);

int main (int argc, const char * argv[])
{
   struct packet ptest;
	
	packet_create(&ptest, "echo");
	packet_add_data(&ptest, "content", "This message goes out to everybody connected!");
	packet_add_data(&ptest, "origin", "GameFreak7744");
	
	char *cpack;
	packet_output(&ptest, &cpack);
	printf(cpack);
	
	char *cdata;
	data_output(ptest.entry, &cdata);
	printf(cdata);
	
	packet_free(&ptest);
   return 0;
}


void packet_create(struct packet *pack, char *name)
{
	pack->name = malloc(strlen(name)+1);
	strcpy(pack->name, name);
	pack->entry_count = 0;
	pack->entry = NULL;
}

void packet_add_data(struct packet *pack, char *name, char *value)
{
	struct data **y = &pack->entry;
	while(*y)
	{
		y = &(*y)->next;
	}
	
	*y = malloc(sizeof(struct data));
	(*y)->name = malloc(strlen(name)+1);
	(*y)->name = name;
	(*y)->value = malloc(strlen(value)+1);
	(*y)->value = value;
	(*y)->next = NULL;
	
	pack->entry_count++;
}

void packet_output(struct packet *pack, char **buffer)
{
	*buffer = malloc(packet_size(pack)+1);
	strcat(*buffer, XML_TAG);
	strcat(*buffer, "<packet type=\"");
	strcat(*buffer, pack->name);
	strcat(*buffer, "\" xmlns=\"");
	strcat(*buffer, XMLNS);
	strcat(*buffer, "\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"");
	strcat(*buffer, SCHEMA_LOC);
	strcat(*buffer, "\"><data>");
	struct data *y = pack->entry;
	while(y)
	{
		strcat(*buffer, "<d type=\"");
		strcat(*buffer, y->name);
		strcat(*buffer, "\">");
		strcat(*buffer, y->value);
		strcat(*buffer, "</d>");
		y = y->next;
	}
	strcat(*buffer, "</data></packet>");
	//printf(buffer);
}

int packet_size(struct packet *pack)
{
	int size = 0;
	size += strlen(pack->name);
	size += PACKET_OVERHEAD;
	struct data *y = pack->entry;
	while(y)
	{
		size += strlen(y->name);
		size += strlen(y->value);
		size += DATA_OVERHEAD;
		y = y->next;
	}
	return size;
}

void packet_free(struct packet *pack)
{
	free(pack->name);
	pack->name = NULL;
	struct data *y = pack->entry;
	while(y)
	{
		struct data *z = y;
		y = y->next;
		printf(z->name);
		free(z->name);
		z->name = NULL;
		printf(z->value);
		free(z->value);
		z->value = NULL;
		free(z);
	}
}
