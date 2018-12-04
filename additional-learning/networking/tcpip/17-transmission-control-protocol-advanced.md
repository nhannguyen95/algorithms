## TCP States

[Pic](https://www.ictshore.com/wp-content/uploads/2016/12/1017-01-TCP_States_diagram.png)

Some explanation:
- **Responder** is the device waiting for request, generally it is the server. **Initiator** is the device deciding to actively start a connection (generally it is the client).
- Openning connection: We can assume that the TCP's starting point is the `CLOSED` state. When the application (on the server) starts, the server `LISTEN`s for the client to make requests. The client can actively open a connection to the server by sending the SYN (`SYN_SENT` state).
- Closing connection: Once data exchange is completed, one of the two devices will want to close the connection. The device actively initiating the closure of the connection is the Initiator. For now, you can ignore the `CLOSING` state, we will explain that in *Simultaneous Closure*.

> When a connection is initiated, the Transmission Control Block (TCB) is defined. It is a set of information and variables to be stored in the memory of the device for the entire time of the connection. This includes the source and destination ports.
