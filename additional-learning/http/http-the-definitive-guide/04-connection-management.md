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











