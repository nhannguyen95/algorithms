## IP Addresses

IPv4 (or IP) is the fourth version of the Internet Protocol, it works with 2 key elements: *information* sent along data to other devices, and *addresses*.

An IPv4 address is 4 bytes long (32 bits). To represent it, we convert each byte in decimal notion and divide them with a dot (`.`), this is knows as **IP dotted notation**.

The bits on the left of IP addresses are more generic than the bits on the right, for example computers in the same broadcast domain will have majority of the IP address in common, and only differ some bits on the right:

```
10.125.8.1
10.125.8.2
```

We divide IP addresses into 2 parts:
  - Left part - **Network ID**: mean ID of subnets (which is a group of contiguous devices that share the same broadcast domain).
  - Right part - **Host ID**: mean ID of devices.
  
**Classful Addressing**: We classify IP addresses into 5 classes:

|Class|Starting bits|Network space|Host space|Range|Networks available|Hosts available|Description|
|-|-|-|-|-|-|-|-|
|A|`0`|7 bits|24 bits|`1.0.0.0` to `127.255.255.255`|128|16'777'216|Normal class, can be assigned to devices|
|B|`10`|14 bits|16 bits|`128.0.0.0` to `191.255.255.255`|16'384|65'536|As above|
|C|`110`|21 bits|8 bits|`192.0.0.0` to `233.255.255.255`|2'097'152|256|As above|
|D|`1110`|-|-|`224.0.0.0` to `239.255.255.255`|-|-|Multicast addresses, used to reach multiple devices|
|E|`1111`|-|-|`240.0.0.0` to `255.255.255.254`|-|-|Experimental addresses|

Problem: let say you plan to connect 10 devices in your network, you may purchase a class C network, and you will waste `256 - 10 = 246` hosts.

To overcome that and increase the flexibility, **classless addressing** has been released: for each IP address, we have a **subnet mask** of 32 bits, with 1 bits are on the left and 0 bits are on the right, these bits define the Network ID and Host ID of the IP address.

All modern networks work with classless addressing, it is the reason why we didn’t run out of IPv4 addresses back in the ’90s.

- Majority of IP address is unicast.
- `224.0.0.0` to `239.255.255.255`: multicast.
- Broadcast address:
  - Standard broadcast `255.255.255.255`: represents all nodes in the same subnet (no matter which subnet).
  - Directed broadcast: used to reach all nodes in a specific subnet (which is not your subnet). `Broadcast address of each subnet = (ip_address & subnet_mask) | ~subnet_mask`. Once a packet with that destination reach the target subnet, it will be converted in a standard broadcast. 

## [The IP Packet](https://www.ictshore.com/wp-content/uploads/2016/11/1013-07-IP_Packet.png)

Some fields in the header of a IP packet:
- **Version**: 4 if using IPv4.
- **Internet Header Length (IHL)**: size of the packet header.
- **Total length**: total length of the IP packet (including data) in bytes.
- **Flags**: 3-bit field:
  - Reserved for future use, must be set to 0
  - **DF (Don’t Fragment)** – this packet cannot be broken into multiple smaller packets.
  - **MF (More Fragments)** – set to 1 if this packet is the result of fragmentation.
- **Time to Live (TTL)** – Field used to prevent loops, each time that packet passes through a network device this field is decremented by one, when a device receives a packets with a TTL of 0 it will discard it, so that a packet has a maximum numbers of hops it can traverse before being dropped
- **Source address** – IP address of the originating device
- **Destination address** – IP address of the target device
- **Header checksum**: used to check the header information was not corrupted during transmission.

## The Router

First to differentiate subnet and LAN:
- A subnet is a logical IP network and a layer-3 network.
- LAN is a physical network running some kind of layer 2 networking protocol that may also be running TCP/IP.
  
Till this point, to wrap it up:

### If sender and receiver are on the same subnet:

The sender needs to send this frame:

```
<L2 frame><L3 packet><L4 segment>PAYLOAD DATA</L4 segment></L3 packet></L2 frame>
```

In which L2 frame contains MAC addresses, L3 packet contain IP addresses.

But initially, the sender only has its own IP address, MAC address, receiver's IP address. To know MAC address of the receiver it uses a data-link layer protocol called **Address Resolution Protocol (ARP)**. This protocol is used to obtain the MAC address of a device that is being assigned to an IP address, all we need to do is just ask “Who has this IP address? Could you tell me your MAC address please?”. So the procedure is that the sender sends *ARP request* to all contiguous nodes and receives back a *ARP response* that contains MAC address that associated with the receiver's IP address. Then it can send the information.

### If sender and receiver are not on the same subnet (remote receiver)

To send information to a remote receiver, the sender needs to send the frame to a **default router / default gateway** (all traffic in/out the Internet must go through this router, while routers in any given path are known as *hops*).

>  Routers must have at least two network interface cards, each of them with its own MAC and IP address: each interface should be placed in a different subnet.

This time, the frame from the sender to the default router contains the MAC address of one of the ports of the router (instead of the MAC address of the remote receiver). The router discards that data-link frame header, encapsulate the remaining data (the IP packet) with a new frame header containing the MAC address of the next hop:

```
Out of default gateway:
<New L2 frame><L3 packet>...</L3 packet></New L2 frame>
L3 packet still contains IP addresses of the original sender and the (remote) receiver
```

The default router knows the information about the next hop to forwards the frame with the help of **routing table**, this tables store the information needed for the router to reach a specific subnet from the current one.

The process is repeated until the frame reaches the router that has the same subnet with the remote receiver, the L2 frame now contains the MAC address of the receiver (like in the case the sender and receiver are in the same subnet).


