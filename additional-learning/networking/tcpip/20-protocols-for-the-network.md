## DNS (Domain Name System)

A client can ask to a DNS server (that is, a server that implements DNS protocol) the IP address of a website. Each computer is configured with the IP address of a DNS server, and it will contact that server for any DNS query it has to do.

DSN uses port **53:UDP** (server side) or **53:TCP** in case the traffic goes over a low-quality link or in case the response contains a lot of information.

Domain names are divided into **DNS Zones**, each zone managed by a set of server. At the root of the Internet (*level-zero*), we have a zone named `.`, which is handled by the root DNS servers; we also have *first-level domain* (like `.com`), *second-level domain* (like `.com.vn`).

The name of a website or server, with all its parent domains (as an example, google.com.vn) is called **Fully Qualified Domain Name (FQDN)**.

In real world, when a client a DNS server, that server may not know exactly what is the IP address of the website the client is looking for, but it knows about a more specific DNS managing this zone.
> For example, assume a client contact the `.` (dot) DNS server asking for *mail.ictshore.com*:
> - `.` server knows it is part of the `.com` zone, so it redirects the client the IP address of a server managing the `.com` zone.
> - The client performs the same query to the `.com` DNS server, the server redirects the client the IP address of a server managing the `.ictshore.com` zone.
> - The client tries again, this time the `.ictshore.com` DNS server knows the IP address and responds the client.
>
> Another uncommon option is **Recursive DNS**, in which the DSN server performs other queries to other DNS servers instead of redirecting the client to the right zone. You should avoid this for 2 reasons:
> - An attacker can overwhelm the DNS server with a huge load of queries.
> - The server may take some time to perform all the queries, the client may timeout the connection.

Both DNS servers and clients store DNS information:
- the DNS client just remember the final binding between name and IP address, and keeps it for minutes or hours.
- the DNS server, instead, has a complex database that can be compared to a table with several records of different types.

## DHCP (Dynamic Host Configuration Protocol)

DHCP is the protocol used to assign IP addresses to clients automatically, it uses **UDP port 68** on client and **UDP port 67** on server.

[If a client connects to a network](https://www.ictshore.com/wp-content/uploads/2017/01/1020-05-DHCP_lease_process.png):
- It first sends a broadcast **DHCP Discovery (D)** to see if there is a server in the network willing to give an IP address.
- Any **DHCP server** in the network that wants to give an IP address to the client replies with the a **DHCP Offer (O)**, containing an offered IP address.
- At this point, client officially requests the IP address offered by the server with a **DHCP Request (R)**.
- Then, the server pings that IP address with a **DHCP Acknowledgement (A)**. From now on, the client can use its new IP address.

> DHCP-obtained addresses do not last forever, they leased for a specific amount of time (generally 24 hours). In this time span, the DHCP server keeps track of the association of clients to IP addresses. To do that, it remembers the MAC address that issued the request.

> If more servers make an offer to the client, the client will make a Request for the Offer the client received first.

> Beside IP address, DHCP servers assign to clients a subnet mask and default gateway so that it will be able to interact in the network.

Suppose you are managing a network infrastructure for a large corporate environment, you can config a router so that it listen to DHCP requests from clients in a same subnet (this configuration is called **DHCP relay**), take them and put them in UDP segments destined to the remote HDCP server ([pic](https://www.ictshore.com/wp-content/uploads/2017/01/1020-06-DHCP_centralized_deployment_and_IPAM.png)).

## TFTP (Trivial File Transfer Protocol)

A very simple/trivial protocol to transfer file.

TFTP is mainly used to download logs or to push the operating system and/or the configuration to a remote network device, such as a switch or a router.

Unlike FTP, which works with two separate TCP channels (one for control, and one for data). TFTP implements control and data over a single channel, which is UDP-based and uses port 69 (server-side).

No secure version of TFTP currently exists.

## Dynamic Routing

[Read the original article](https://www.ictshore.com/free-ccna-course/protocols-for-the-network/)




