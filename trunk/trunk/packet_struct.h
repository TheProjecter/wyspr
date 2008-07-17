/*
 *  packet_struct.h
 *  Packet
 *
 *  Created by Joey Sabey on 16/07/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */
 
#include "data_struct.h"

struct packet
{
 char *name;
 struct data *entry;
 int entry_count;
 int total_size;
};