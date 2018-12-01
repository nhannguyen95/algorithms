The data link layer:
  - is the one that allow the communication between two contiguous nodes, that are nodes having access to a common media (connected together either directly or via a shared media)
  - allows the network layer to communicate seamlessly over an heterogeneous network.
  

> The physical layer has no intelligence built-in, it’s just about transforming bits into signals and vice versa, without knowing what these bits actually mean

Data link layer is implemented in NICs.

Applications are executed inside CPUs, each application will start its own data (such as web page) and will break down that data in a network-layer form inside the CPU. Then the CPU will pass this network-layer data to the NIC that will then manage the data link layer and then the transformation of that into signals (physical layer).

2 sub-layers:
  - Logical Link Control (LLC): communicates with the CPU.
  - Media Access Control (MAC): puts signals on the cables and reads them from it
---

At the sender: the information (the application data) is originated by application layer, then it is passed down until it reaches the physical layer, each layer adds some extra pieces of information. We call this **encapsulation**.

The data that is added at a layer in the sender will only be read at that layer in the receiver.

The application data plus all the extra information added by layers are called **Protocol Data Unit (PDU)**.

The network layer PDU is called **Packet**, when it is passed down to the Data link layer, [it is "envoloped" in a **Frame**](https://www.ictshore.com/wp-content/uploads/2016/11/1012-06-MAC_from_to.png).

---

In order to deliver data to the correct destination device, we have to know its address. At data link layer, we use **Layer 2 address**, that is MAC address assigned to any NIC.

---

Frame's structure: 3 parts:
  - Header: set of fields that are needed for the purpose of transmitting/receiving: MAC addresses, type/length field.
  - Payload: content from upper layers.
  - FCS (Frame Checksum): a field that allows the receiver to check if the message was disrupted over the transmission.

---

The switch is the king device at the Data Link layer. It is a network device that has generally 8, 12, 24 or 48 ports (NICs) used to connect together computers and end devices.

Each switch implements a *dynamic* **MAC address table** that stores in the switch's memory and associate MAC addresses of connected devices to the port on the switch where these devices are connected. When the switch receives a frame:
  - if it doesn't know the receiver MAC address, it just sends the frame to all of connected devices and hopes to receive the response back from the receiver; it then associates the MAC address of that receiver to the port that connects to it.
  - If it knows the receiver MAC address, it just needs to forward the frame to the corresponding port.
  
This feature of switches allows full-duplex transmission, because you can send and receive simultaniously since no collision happen anymore.

Another cool feature of modern switches is the **Virtual Local Area Networks (VLANs)**. Basically, you can configure a switch to group its ports in groups, traffic will spread only between ports inside the same group and not between different group.

---

**unicast addresses** – represent a single LAN interface. A unicast frame will be sent to a specific device, not to a group of devices on the LAN.

**multicast addresses** – represent a group of devices in a LAN. A frame sent to a multicast address will be forwarded to a group of devices on the LAN.

**broadcast addresses** – represent all device on the LAN. Frames sent to a broadcast address will be delivered to all devices on the LAN.









