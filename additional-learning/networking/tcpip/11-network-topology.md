A **network topology** is the representation of links between the nodes within a network:
  - A node is any device that can be plugged into a network and communicating within the network: it does not matter how it can be plugged in (with a cable, in Wi-Fi and so on)
    > a PC, a router, a smartphone, a laptop, a switch, etc.
  - A link is any type of connection that can allow two devices to talk.
    > a coaxial cable, an ethernet cable, a fiber optic cable, a wireless connection, etc.

---

3 types of transmission:
  - **Simple**: information can flow in a single direction (A to B, but not B to A).
  - **Half Duplex**: information can flow in both direction, but not simultaneoulsy (if A is talking to B, B has to listen)
  - **Full Duplex** (the best one): information can flow in both direction simultaneously. We can obtain full duplex using a switch.

---

## [Share Media Topology](https://www.ictshore.com/wp-content/uploads/2016/10/1011-04-Shared_media.png)

In this topology, nodes are connected together by the **same link**, for example wireless connections (the link is the air).

Share Media topology:
  - is extremely easy to design.
  - everything a device "says" in a cable is heard from all other nodes => easy to communicate.
  - Problem: communication cannot overlap, **only a single device can be talking** at a given tiem.

Two major algorithms have been deleloped over the year to solve this problem:
  - Carrier Sense Multiple Access (CSMA) - we use it today: each device can decides autonomously if they have to talk or not, the logic is that it listens for what is happening on the media and talk as soon as nobody is talking.
  - Token Ring (legacy): was originally developed for circular topologies. The logic is simple: nodes elect a master node to generate a token, nodes circulate this token arround and only the node currently has the token can talk.
 
## [Star Topology](https://www.ictshore.com/wp-content/uploads/2016/11/1011-08-Star_topology.png)

Best pratice to be used in data centers (connecting servers).

In this topology, all devices connect to a single device in the center (call it node A).

Major benefit is **centralized management and control**: all the traffix passes through node A, we can apply policy to restrict some users to reach some other devices on the network, we can filter and inspect traffic to allow or deny some specific applications, and we can manage the overall infrastructure from the central point.

Problem: if node A fails, all the other nodes will be disconnected and isolated

## [Hierarchical Topology](https://www.ictshore.com/wp-content/uploads/2016/11/1011-09-Hierarchical_topology.png)

The evolution of Star Topology, which is a *star of stars*. 

A hierarchical topology is a topology where traffic flows between leaf nodes by passing through one or more central nodes (like a rooted tree with layers).

Benefit: centralized management and control.

The problem in the Star Topology is solved: if an internode fails, other devices will disconnect but this won't disrupt the whole topology, it would be segmented instead.

## [Mesh Topology](https://www.ictshore.com/wp-content/uploads/2016/11/1011-11-Full_mesh.png)

A mesh is a topology where a node is connected to one or more other nodes, in such a way that at least one path exists between any two given nodes.

2 types of meshes:
- **Full mesh**: every node is connected to all the other nodes => add reliability to the network but expensive and hard to manage.
- **Partial mesh**: each node is connected to multiple nodes , but not necessarily to all the others.

Meshes are mainly used in the **Service Provider** environment, connections between cities and countries are mainly partial meshes (maybe using *submarine cable*), but this is not limited to the network within the service provider.

---

In a **Layer 2 topology**, each device working at the OSI Layer 2 (Data Link, such as switches) and above has to be represented.

In a **Layer 3 topology**, each device working at the OSI Layer 3 (Network) and above has to be represented (routers, firewalls, computers, etc.).

*At the OSI Layer 4 (Transport) and above, we don’t have topologies anymore*. This is because these layers just do not care about the underlying network and path, so we just represent tunnels: logical connections between devices and/or applications. These types of drawing are used specifically for security purposes to represent which type of traffic has to be allowed and which type of traffic should be blocked instead.

