/*
 *  packet_struct.h
 *  Packet
 *
 *  Created by Joey Sabey on 17/07/08.
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
 
#include "data_struct.h"

#define PACKET_OVERHEAD 270
/* 270 =
<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<packet type="" xmlns="http://wyspr.s4t4n.net/packet
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
xsi:schemaLocation="http://wyspr.s4t4n.net/packet http://wyspr.s4t4n.net/packet/wyspr-packet_0.2.xsd">
<data></data>
</packet>
*/
#define XML_TAG "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define XMLNS "http://wyspr.s4t4n.net/packet"
#define SCHEMA_LOC "http://wyspr.s4t4n.net/packet http://wyspr.s4t4n.net/packet/wyspr-packet_0.2.xsd"

struct packet
{
 char *name;
 struct data *entry;
 int entry_count;
};


void packet_create(struct packet *pack, char *name);
void packet_add_data(struct packet *pack, char *name, char *value);
void packet_output(struct packet *pack, char **buffer);
int packet_size(struct packet *pack);
void packet_free(struct packet *pack);


