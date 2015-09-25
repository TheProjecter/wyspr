# Introduction #
Requests to connect to a host node.

### Packet Route ###
  * Client to Host

### Data ###
  * Required
    * chat - Name of the chat the client wishes to connect to
  * Optional
    * password - Password for the chat


---


# Example connectrequest Packet #

```
<packet type="connectrequest">
  <chat>nameofchat</chat>
</packet>
```