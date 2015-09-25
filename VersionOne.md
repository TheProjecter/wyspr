# Introduction #

_**Version One**_ is the current goal of the Wyspr project.
It will be known, when finished, as Wyspr 1.0, and all specification will be updated to this version number at the same time.
This page is designed to act as a sort of _checklist_ for the development towards this goal.
Included on this page are a list of things that Version One must be able to do, and a list of things it does not have to be able to do.


# Version One must #

  * Create a network based on a 'backbone' of host nodes
  * Allow new client nodes and host nodes to connect to the network using a [file](gateway.md)
  * Allow client nodes to pass messages to every node on the network through host nodes
  * Allow host nodes to refer potential new clients to another host node
  * Correctly handle host notes disconnecting, both unexpectedly, and expectedly


# Version One need not #

  * Send personal messages accross the network
  * Dynamically update the XML gateway file with new temporary host nodes
  * Allow chat moderation
  * Allow password-protected chats
  * Support multiple-room chats