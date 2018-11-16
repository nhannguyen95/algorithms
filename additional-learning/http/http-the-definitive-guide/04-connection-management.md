TCP connections are reliable. Once a TCP connection is established, message exchanged between client's and server's computers will never be lost, damaged, or received out of order.

---

**The seven layered OSI model**

The OSI (Open Systems Interconnection) model partitions a communication system into 7 abstraction layers:

```
7. Application Layer    (Anyone)
6. Presentation Layer   (Password)
5. Session Layer        (Secretly)
4. Transport Layer      (Tell)
3. Network Layer        (Not)
2. Data Link Layer      (Do)
1. Physical Layer       (Please)
```

The OSI model is then divided into two segments for more ease, Upper layers (5, 6, 7), and Data Flow layers (1, 2, 3, 4). The upper layers are directly related to the  user interface while the OSI model’s 4rth, 3rd, 2nd, and 1st layer are also called Data Flow Layers because they are related to the data flow. Each data flow layer has a Protocol Data Unit (PDU).

Each data flow layer’s Protocol Data Unit is defined as follows:
- Transport Layer: **Segment** is the PDU of the Transport layer.
- Network Layer: **Packet** is the PDU of the Transport layer.
- Data Link Layer: **Frame** is the PDU of the Transport layer.
- Physical Layer: **Bit** is the PDU of the Transport layer.

---

**Networking protocols at each of Data Flow layers**

The sending and receiving of data from a source device to the destination device is possible with the help of networking protocols when data encapsulation is used.

Below is HTTP and HTTPs network protocol stacks:

```
-------------------- 
        HTTP        | Application Layer
--------------------
    (TLS or SSL)    | Security Layer (for HTTPs)
--------------------
        TCP         | Transport Layer
--------------------
        IP          | Network Layer
--------------------
 Network interfaces | Data link layer
--------------------
```

When client sends a http message, the process goes top down.

When server receives a http message, the process goes bottom up.

---

**The data encapsulation process**

The application layers user data (HTTP message) is handed down to the Transport layer:

**Transport layer: TCP header encapsulation, PDU = Segment**

TCP takes the stream of data, the data stream is broken up into chunks called segments:

```
--------------------------------------------------------------------------------------                     |
                  Source port               |              Destination port                                |
--------------------------------------------------------------------------------------                     |
                                  TCP Sequence number                                                      |
--------------------------------------------------------------------------------------                     | TCP Segment
                              Piggybacked acknowledgment                                                   |
--------------------------------------------------------------------------------------                     |
Hdr length|Reserved|URG|ACK|PSH|RST|SYN|FIN |               Window size                                    |  
--------------------------------------------------------------------------------------                     |
              TCP Checksum                  |             Urgent pointer                                   |
--------------------------------------------------------------------------------------                     |
                           GET /index.html HTTP/1.1<CR><LF>                             | Chunk of         |
                           Host: www.example.com                                        | TCP data stream  |
--------------------------------------------------------------------------------------                     |
```

Some TCP segment headers:
- TCP Checksum: to ensure the data integrity when the receiver receives the message.
- TCP Sequence number: so that the data stream can be put back together on the destination with exact order as transmitted.

---

**Network layer: IP header encapsulation, PDU = Packet**

Each segment is handed to the network layer for logical addressing and routing through a routed protocol like IP. The segments are "wrapped" inside IP packets (like envelops), each TCP segment is carried by an IP packet from one IP address to another IP address.

```
IP packet:

-------------------------------------------------------------------------------------------------
 Version | Hdr length (words) | Type of service |          Total datagram length (bytes)
-------------------------------------------------------------------------------------------------
         Packet ID (16-bit number)              | Flags |     Fragmentation offset
-------------------------------------------------------------------------------------------------
 Time to live (TTL) | Upper-level protocol      |              Header checksums
-------------------------------------------------------------------------------------------------
                                        Source IP adress
-------------------------------------------------------------------------------------------------
                                     Destination IP address
-------------------------------------------------------------------------------------------------
                   ----------------------------------------------------------
                  |                         TCP Segment                      |           
                   ----------------------------------------------------------  
------------------------------------------------------------------------------------------------
```

Each IP packet contains:
- An IP packet header (ususally 20 bytes)
- A TCP segment header (usually 20 bytes)
- A chunk of TCP data (0 or more bytes)

**Data link layer: Network interfaces, PDU = Frame**

The Data Link layer receives the packets from the Network layer and places them on the network medium such as cable or wireless medium.

The Data Link layer encapsulates each packet in a frame and the MAC header carries the source Mac address and destination Mac address. If the device is on a different network, then the frame is sent to a router to be routed through an internetwork.

**Data link layer: PDU = Bit**

To put this frame on the network, it must first be put into a digital signal. Since a frame is really a logical group of 1s and 0s, the OSI model’s Physical layer is responsible for encapsulating these digits into a digital signal, which devices on the same local network read.

---

A computer might have several TCP connections open at any one time

A TCP connection is distinguished by four values:

```
<source-IP-address, source-port, destination-IP-address, destination-port>
```

It means if a machine (`source-IP`) has many TCP connection to the same application (`des-port`) from a server (`des-IP`), these connection have different `source-port` number.

---

## HTTP Transaction delays

```
Server  ------------------------------------------------->
                ^        \      ^             \
               /          \   /                \
              /            v /                  v
Client [-----][------------][------][----][-------][----]
          DNS     Connect    Request       Response Close
      Look up                       Process
       
```

We can see that the transaction processing time can be quite small compared to the time required to set up TCP connections and transfer the request and response messages. Unless the client or server is overloaded or executing complex dynamic resources, most HTTP delays are caused by TCP network delays.

We next disscuss some of the most common TCP-related delays. These magnitude of these delays depends on:
- Hardware speed
- The load of the network and server.
- The size of the request ans response message.
- The distance between client and server.
- Tenchnical intricacies of the TCP protocol.

### DNS look up

A client first needs to determine the IP address and port number of the web server from the URI. If the hostname in the URI was not recently visited, it may take tens of seconds to convert the hostname from a URI into an IP address using the DNS resolution infrastructure.

Luckily, most HTTP clients keep a small DNS cache of IP addresses for recently accessed sites.

### TCP Connection Handshake Delays

Before you send any data, TCP softwares exchange a series of IP packets to negotiate the terms of the connection:

```
Server: 
                      ^     \           ^           \
                   [SYN]     \    [ACK + GET/HTTP]]  \ 
                    /      [SYN+ACK]  /               [HTTP/1.1 304 Not Modified]
                   /            v    /                 v
Client:    connect|-------------|------------------------|
      connection handshake delay            data transfer
```

- To request new TCP connection, client sends a small TCP packet (40 - 60 bytes) with SYN flag set, which means it's a connection request.
- If the server accepts the connection, it computes some connection params and sends a TCP packet back with SYN and ACK flags set, meaning that the connection request is accepted
- Finally, client sends an acknowledgement back to the server, lets it know that the connection was established successfully. Modern TCP stacks let the client send data in this ackknowledgement packet.

HTTP programmer never sees these packets, they are managed by TCP/IP softwares.

This handshake procedure creates a measurable delay when HTTP transactions do not exchange much data (as is commonly the case). The end result: small HTTP transactions may spend >= 50%  of time doing TCP setup.

=> Need a mechanism to allow HTTP to reuse existing connections.

### Delay Acknowledgments

Because the Internet itself does not guarantee reliable packet delivery (Internet routers are free to destroy packets at will if they are overloaded), TCP implements its own acknowledgment scheme to guarantee successful data delivery.

That means when the receiver receives the intact segment (by checking its sequence number and checksum), it will returns small acknowledgment packets back to the sender. If a sender does not receive an acknowledgment within a specified window of time, the sender concludes the packet was destroyed or corrupted and resends the data.

Because acknowledgements are small, TCP allows them to “piggyback" on outgoing data packets heading in the same direction. This combination can make more efficient use of the network. To increase the chance an ack finds a data packet heading in the same direction, many TCP stacks implement a *delayed acknowledgement* algorithm: it helds outgoing acks in the buffer for a certain window of time (100-200 ms), if no outgoing data packet arrives that time, the ack is sent in its own packet.

Downside: There just aren't many packets heading in the reverse direction when you want them => The algorithm frequentlly introduces significant delays => depending on you case, you may want to disable this algo.

### Nagle's algorithm and TCP_NODELAY

TCP permits applications to stream data of any size to the TCP stack, even a singly byte. But because each IP packet carries >= 40 bytes of flags and headers, network performance can be degraded serverly if TCP sends many packets containing small amounts of data.

Nagle's algorithm discourages the sending of packets that are not full size (maximum-size packet is around 1500 bytes on a LAN, few hundred bytes across internet). Non-full-size packets are buffered and are sent when the buffer has accumulated enough data to send a full packet (or went all previous pending packets have been acknowledged).

Downside:
- Small HTTP messages may be delayed waiting for additional data that will arrive.
- Nagle's algo interacts poorly with Delayed Acknowledgemnts: it will hold up the sending of data until an acknowledgment arrives (so that the new data is sent along), but the acknowledgment itself will be delayed 100-200 milliseconds by the delayed acknowledgment algorithm.

HTTP applications can disable this algo by setting the TECT_NODELAY param.

### TIME_WAIT Accumulation and Port Exhaustion

When a TCP endpoint closes a TCP connection, it maintains in memory the IP addresses and port numbers of recently closed connection in a short time, typically around twice the estimated maximum segment lifetime (~ 2 mins). This prevents 2 connections with exact same IP address and port from being created, closed and recreated within 2 mins (because establishing a TCP connection is costly as mentioned).

Let say on a computer client sending HTTP request to a server, the `des-IP` of the server is fixed and the `des-port` is 80 by default. So new TCP connection is corresponding to a port in the computer. Let say the number of available `source-port` is 60000 and the connection's IP address and port is maintains within 2 mins, the maximum transaction per second is 60000 / 120 = 500.

---





