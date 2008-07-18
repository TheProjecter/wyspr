/*
 *  data_struct.c
 *  Test Packet
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