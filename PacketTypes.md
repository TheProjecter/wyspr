# Introduction #

This page details the different types of [packet](Packet.md) used in the Wyspr protocol, the type of node that will send and receive these packets, the usage of the packets, the type of data they contain, and what version(s) of the protocol the packets are used by.


# Packets #

## [connectrequest](connectrequest.md) ##
Requests to connect to a host node.

### Packet Route ###
  * Client to Host

### Data ###
  * Required
    * chat - Name of the chat the client wishes to connect to
  * Optional
    * password - Password for the chat


---


## [standby](standby.md) ##
Requests the receiver increase their time-out time, when they are waiting for a response from the sender. The amount of time is generally decided by the sender.

### Data ###
  * Required
    * ref - The reference number of the original request package.

### Packet Route ###
  * Client to Host
  * Host to Client
  * Host to Host


---


## [refer](refer.md) ##
Used by a host node to tell a potential client node that is trying to connect to connect to a different host node. Used if the host node is disproportionately overburdened, has reached the limit it is willing to host to, or otherwise refuses to host the client that is attempting to connect. May be used during chat if the host is disconnecting from the chat, passing the user to a less busy host node, etc.

### Data ###
  * Optional
    * ip - The IP address of another host to connect to.

### Packet Route ###
  * Host to Client


---


## [assignid](assignid.md) ##
Used by a host node to tell a new client node their unique ID, which they must use to communicate with the host node.

### Data ###
  * Required
    * id - The ID number.

### Packet Route ###
  * Host to Client


---


## [allow](allow.md) ##
Response to a _request_  packet of whatever kind, when no additional information is required, and the request was allowed.

### Data ###
  * Required
    * ref - The reference number of the original request package.

### Packet Route ###
  * Host to Client
  * Client to Host
  * Host to Host


---


## deny ##
Response to a _request_  packet of whatever kind, when no additional information is required, and the request was denied.

### Data ###
  * Required
    * ref - The reference number of the original request package.

### Packet Route ###
  * Host to Client
  * Client to Host
  * Host to Host


---


## [message](message.md) ##
Used by a client node to send a message to their host node for broadcast over the network.

### Data ###
  * Required
    * content - The message to be broadcast.

### Packet Route ###
  * Client to Host


---


## [echo](echo.md) ##
Used by a host node to pass on a message to its client nodes, and other hosts.

### Data ###
  * Required
    * content - The actual message being echoed.
    * origin - The username of the original sender.

### Packet Route ###
  * Host to Host
  * Host to Client


---


## [queryload](queryload.md) ##
Used, when a host node is concerned with the client load it is hosting, to query the other hosts to check if their load is suitably lighter to refer a client node. A referrequest should not be sent unless the sending host node would still have a higher proportional load after referral, to prevent ping-ponging the client node between host nodes. Reply should be a loaddata packet.

### Packet Route ###
  * Host to Host


---


## [loaddata](loaddata.md) ##
Used to reply to a _queryload_ packet.

### Data ###
  * Required
    * ref - The reference number of the original query.
    * currentload - The number of clients currently connected.
    * maxload - The maximum number of clients the host will allow.

### Packet Route ###
  * Host to Host


---


## [referrequest](referrequest.md) ##
Requests a host node accept a new client node. Used by a host node to request another host node accept a new client node, for example if the sender is highly overburdened, has reached their personal client node limit, etc. Response should be an _allow_ or _deny_ packet.

### Packet Route ###
  * Host to Host

### Data ###
  * Optional
    * reason - Reason the host node wishes to refer.