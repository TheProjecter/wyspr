# Introduction #
This packet is sent from a client to a host, to be broadcast across the network.

### Packet Route ###
  * Client to Host

### Data ###
  * Required
    * ccontent - The actual message to be broadcast.


---


# Example message Packet #

```
<?xml version="1.0"?>
<soap:Envelope
xmlns:soap="http://www.w3.org/2001/12/soap-envelope"
soap:encodingStyle="http://www.w3.org/2001/12/soap-encoding">
<soap:Header>
<wyspr:type xmlns:wyspr="http://wyspr.s4t4n.net/packets" soap:mustUnderstand="1">message</wyspr:type>
</soap:Header>
<soap:Body>
   <wyspr:content>
      This is the message that will be sent to the chat.
   </wyspr:content>
</soap:Body>
</soap:Envelope>
```