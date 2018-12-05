Transport Layer means Application-to-Application connections: it allows the communication between two applications on two different computers.

**Port** ID (or port) is an 16-bit integer (0 - 65535). When the computer receives an IP packet from any other device, it will send the payload to the right application based on the Port ID

**Socket** = IP address + port, 2 sockets uniqueqly identify a TCP connection.

The Protocol Data Unit (PDU) at this layer is **Segment** (or **Datagram**), the header of the segment is different if the protocol used is TCP or UDP, but 2 fields are always present: [source Port ID and destination port ID](https://www.ictshore.com/wp-content/uploads/2016/12/1016-05-Segment.png).

**Transport Layer Port ranges**

|Range name|Range|Description|
|-|-|-|
|Well-known|0-1023|Used for popular service (HTTP, FTP etc.)
|Reserved|1024-49151|Used for service applications (the ones running on servers)| 
|Dynamic|49152-65535|Ports in this range are used by client application as they do not need a specific Port ID,but instead just any port to be able to make requests to servers|

## TCP

**Transmission Control Protocol**:
- has been designed with a major goal: ensure a **reliable** delivery of data between remote applications.
  > This is possible because the receiver notifies the sender when it receives data and, in case it doesn’t, there is a mechanism that triggers the sender to re-transmit data that was not received.
- is a **connection-oriented** protocol, which means that the 2 application must establish a connection before they can actually start to exchange data.
- grants **ordered delivery**: data arrives in the order they were sent, if not they are reordered by the receiver.

### [TCP header](https://www.ictshore.com/wp-content/uploads/2016/12/1016-07-TCP_segment.png)

All the above features are possible thanks to the implementation of TCP with a dedicated header in the segment and with specific algorithms that run on the computer that is using TCP to talk:
- **Source Port**
- **Destination Port**
- **Sequence number**: in TCP, we send a *stream of bytes*, this field identifies to which byte in the full stream the first byte of the TCP payload corresponds to.
- **Acknowledgement number**: this field is used by the receiver to tell the sender that it has received some data. It is populated with the byte number the receiver expect to see next after what it already received.
- **Flags**:
  - **ACK** (Acknowledgement): Set to 1 from the receiver to tell the sender to check out the Acknowledgment number field.
  - **RST** (Reset): Inform the other device that the connection is being closed immediatly (hard reset of the connection).
  - **SYN** (Sync): Used to establish a connection.
  - **FIN** (Finish): Used to gracefully close a connection.
- **Check sum**: hash of the entire segment used by the receiver to verify that no errors happened during the transmission.

### [TCP Three-way handshake procedure](https://www.ictshore.com/wp-content/uploads/2016/12/1016-06-Three_way_handshake.png)

This procedure involves 3 exchanges of data, assume that device A wants to talk to device B:
- Step 1: A sends an emtpy TCP segment with the *SYN flag set to 1*, this segment contains only the source and destination ports and that flat set.
- Step 2: If the application on B is willing to respond to A, B will send back an empty segment with the ports specified, the *SYN and ACK flag set to 1*, implies that B got the request and is willing to open the connection.
- Step 3: A sends back to B with the *ACK flag set to 1*. After that, the connection is successfully established and 2 devices can start exchanging data.

### The data transfer

The data is received in the order they were sent with the aid of the `Sequence number` field. When an application is sending data to another, the sequence number is used to tell what is the position of the first data byte being send (the first byte of the payload) in the entire data stream.

The data is transfered reliable with the aid of the [`Acknowledgement number`](https://www.ictshore.com/wp-content/uploads/2016/12/1016-09-acknoledgment.png): Let say A wants to send 1000 bytes, but can only sends 100 bytes at a time. So the first sequence number is 0, the second is 100 and so on.

The *retransmission* is triggered in three cases:
- When the sender do not receive acknowledgement segments (timeout):
  > When A sends a segment, it waits for an acknowledgement from B stating that B has received the segment.
- When the receiver misses a segment:
  > If B has missed a segment but the next one was correctly received (for example B received 0-100, 200-300; it knows 100-200 is missed), B will send back to A an acknowledgement number of 100, meaning that B has received correctly the first 100 bytes, A needs to retransmiss the missed segment 100-200 *(and all segments after this)*; in the meantime, **all the received segments after that will be discarded** (this is obviously not the optimal behaviour,  but it is the one *used in the most basic implementations* that do not rely on *Selective Acknowledgment*). This way all data will be delivered reliably. 
- When the receiver verifies that the checksum do not match the segment.

### Connection termination

[The original article](https://www.ictshore.com/free-ccna-course/transport-layer-tcp-and-udp/) is well written.

[Demonstration](https://i.stack.imgur.com/vjr9Q.png)

## UDP

**User Datagram Protocol** is born at the same time of TCP, UDP:
- is a **connection-less** protocol: there is no need to establish a connection before data can be sent, instead an application can simply choose to send data immediately.
- is a **fast** protocol: allowing more data to be sent with a single segment if compared to TCP.
- works in **best effort**: mean that there is no built-in mechanism to verify that segments were received, they are just sent hoping that they won’t be lost (This also implies the lack of ordered delivery).

UDP is today mainly used for real-time application, with RTP (Real Time Protocol) sitting on top of it at the session layer. This is because real-time applications (video and/or audio streams) need speed (otherwise they wouldn’t be real-time!) and ordered delivery if possible: this mean that if they receive two segments almost at the same time, they have to know which one has to go first, but in case they do not receive something, there is no time to arrange a retransmission, the stream must continue (this is why sometimes you may hear disruption in a VoIP call). Because of its simplicity and extensibility, UDP is being considered as a great protocol to replace TCP in the future, but for now these ideas remain only theories and studies.

### [UDP header](https://www.ictshore.com/wp-content/uploads/2016/12/1016-11-UDP_segment.png)

UDP header has just the information that allow the delivery to the correct application:
- **UDP Length**: how long is the segment (header + data).
- **UDP Checksum**: to verify the integrity of data.
- ***Source port** and checksum are optional fields.*

If we use all fields, **UDP has a header of 64 bits**, much smaller than the 160-bit long TCP header; implies that we can send 96 bits more of data with UDP than with TCP => UDP is faster.

### Limitations

UDP:
- do not order packets, and therefore the receiver cannot guess in which order they were sent originally.
- is not reliable, what is lost is just lost, no UDP component will trigger a re-transmission.

## UDP vs TCP

UDP is extremely faster then TCP: not only because it can send 96 bits more in every segment, but also because there is no connection establishment and the sender does not have to wait for acknowledgements.

It is a protocol that truly works at the Transport layer, because re-transmission and ordered delivery should be tasks managed at the session layer (which TCP covers too).
> By having a light-weight protocol at the transport layer, we can then decide which other extra features to implement within the application.


