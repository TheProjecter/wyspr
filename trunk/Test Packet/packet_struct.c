/*
 *  packet_struct.c
 *  Test Packet
 *
 *  Created by Joey Sabey on 18/07/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packet_struct.h"

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
		size += data_size(y);
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
