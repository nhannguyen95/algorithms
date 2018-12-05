## TCP States

[Pic 1](https://www.ictshore.com/wp-content/uploads/2016/12/1017-01-TCP_States_diagram.png), [Pic 2](https://www.ictshore.com/wp-content/uploads/2016/12/1017-02-TCP_States_in_a_connection.png)

Some explanation:
- **Responder** is the device waiting for request, generally it is the server. **Initiator** is the device deciding to actively start a connection (generally it is the client).
- Openning connection: We can assume that the TCP's starting point is the `CLOSED` state. When the application (on the server) starts, the server `LISTEN`s for the client to make requests. The client can actively open a connection to the server by sending the SYN (`SYN_SENT` state).
- Closing connection: Once data exchange is completed, one of the two devices will want to close the connection. The device actively initiating the closure of the connection is the Initiator. For now, you can ignore the `CLOSING` state, we will explain that in *Simultaneous Closure*.

> When a connection is initiated, the Transmission Control Block (TCB) is defined. It is a set of information and variables to be stored in the memory of the device for the entire time of the connection. This includes the source and destination ports.

[**Simultaneous Closure**](https://www.ictshore.com/wp-content/uploads/2016/12/1017-03-Simultaneous_close.png): happens when both devices are actively trying to close the connection at the same time.

[**Reset a TCP connection**](https://www.ictshore.com/wp-content/uploads/2016/12/1017-04-Reset_connection.png): the device sending the RST will move to `CLOSED` state after that, the other device no longer receive any acknowlegment thus it also moves to `CLOSED` state after a timeout.

## [TCP Windowing](https://www.ictshore.com/wp-content/uploads/2016/12/1017-05-TCP_Windowing.png)

In the TCP segment’s header we can find a 16-bit long field called **Window Size**. It identifies the **receiver window**. Window Size is the number of bytes that the device sending the segment can store waiting for the application to process them.

By *sending that value in each segment*, the device is saying “Hey you, you can send me X bytes and I guarantee I will store them in my temporary memory so that the application will process them eventually”, where X is the Window Size value.

> Window size is sent in every segment, and in every segment it defines the total space available in the buffer of the device sending it. The device that receive the segment with the Window Size will transmit as many bytes as it can, but the amount of bytes left unacknowledged cannot exceed the Window Size.

## [Selective Acknowledgement (Selective ACK or simply SACK)](https://www.ictshore.com/wp-content/uploads/2016/12/1017-06-TCP_selective_acknowledgment_SACK_vs_normale_ACK.png)

In the traditional implementation of TCP, when a segment is lost, it has to be retransmitted, *and all segments after the lost one has to be retransmitted too, even if they were received correctly*. (This is because of the nature of the acknowledgement number, which tells the other device which byte is expected next).

SACK improves this by allowing a device to individually acknowledge segments, so that only the lost ones are retransmitted.

SACK implements two different TCP header options:
- **Sack-Permitted Option**: this option is used during the three-way handshake to verify that both TCP partners support the SACK mechanism.
- **Sack Option**: used to tell the other device which segments are acknowledged with SACK.

## Header Compression

Header compression is a cool TCP features that allows bandwidth enhancement on low-speed links, such as satellite connections. This feature is implemented on the routers (network devices) in the path.

Imagine a router that has to process IP packets containing TCP segments, if you are doing some heavy use of a connection (such as downloading a file from a server), the router will see a lot of packets with the same source and destination IPs, all of them containing the same source and destination ports in the segment’s header => With header compression, we can send them just once.

A router implementing header compression takes IP and TCP addresses in the header, plus other fields that will not change during the connection, and run an algorithm on them to extrapolate an unique identifier (hash ID) which is much more smaller. All the router’s receiving a compressed header must know its expanded value to send the packet/segment to the right destination. In the end, a router will de-compress the header and send the normal one to the destination device.

## Handling network congestions

### Fast retransmit

In a normal TCP implementation, we should wait for ACKs to decide what we have to retransmit. With fast retransmit enabled, if an ACK is not received within a specific timeout, the segment not yet acknowledged is automatically re-sent, to save time.

This can unnecessarily saturate high-latency low-bandwidth networks, as information is not truly lost but it simply takes time to arrive on the other side.

### TCP congestion control

We need to find a way to use as much bandwidth as possible, without flooding the network with traffic and overwhelming it. We need some tools to control the congestion, and TCP has those tools.

**Congestion window (CWND)** defines the number of bytes that can be sent before we must stop and wait for acknowledgement.

### [UDP predominance and TCP starvation](https://www.ictshore.com/wp-content/uploads/2016/12/1017-10-TCP_starvation-1.png)

TCP implements such a sophisticated mechanisms to back-off in case of network congestion, but UDP does not. So,if a lot of traffic is generated in UDP, so much that TCP and UDP together exceed the network capacity, TCP will back-off due to the congestion control algorithm. UDP instead, will continue to use the bandwidth it was already using, and if some UDP traffic was queued due to the network congestion, it will be triggered now that the network is not congested anymore. If this saturate the network again, TCP will continue to back-off until UDP is almost the only traffic in the network.

**Quality of Service (QoS)** is a mechanism on WAN links to avoid that these links get saturated with UDP traffic. QoS rules can keep UDP separated from TCP so that UDP can saturate only its part of the network, can grant a percentage of bandwidth for some applications or can even reserve bandwidth to other applications (meaning that this part of bandwidth will be used only by some applications, and in case they are not using it nothing else will be able to use it).




