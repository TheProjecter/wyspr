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

