/*
 *  data_struct.c
 *  Test Packet
 *
 *  Created by Joey Sabey on 18/07/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */
 
#include <stdlib.h>
#include <string.h>
#include "data_struct.h"

int data_size(struct data *x)
{
	int size = 0;
	size += DATA_OVERHEAD;
	size += strlen(x->name);
	size += strlen(x->value);
	return size;
}

void data_output(struct data *x, char **buffer)
{
	*buffer = malloc(data_size(x) + 1);
	strcat(*buffer, "<d type=\"");
	strcat(*buffer, x->name);
	strcat(*buffer, "\">");
	strcat(*buffer, x->value);
	strcat(*buffer, "</d>");
}