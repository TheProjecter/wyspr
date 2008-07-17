/*
 *  data.h
 *  Packet
 *
 *  Created by Joey Sabey on 16/07/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

struct data
{
 char *name;
 char *value;
 int size;
 struct data *next;
};