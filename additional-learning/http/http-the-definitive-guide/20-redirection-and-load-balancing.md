The goal of redirection is to send HTTP messages to available web servers as quickly as possible.

Many redirection techniques work for servers, proxies, caches, and gateways because of their common, server-like traits (clients send them an HTTP request, and they process it).

## General redirection methods

### HTTP Redirection

Web servers can send short redirect message back to clients, telling them to try someplace else.

Some web sites use HTTP redirection as a simple form of load balancing.

Some policies for the chosen server: round-robin load balancing, minimizing latency, choosing shortest path, etc.

Example:

```
Client sends a request to www.example.com
GET /index.html HTTP/1.1
Host: www.example.com
User-Agent: ..

The server sends back a redirect message with status code 302:
HTTP/1.1 302 Redirect
Server: Stronghold/2.4.2
Location: http://161.58.225.45/index.html

The client's browser resends the request to host 161.58.225.45.
```

Disadvantages:
  - The original server needs a significant amount of processing power to determine which server to redirect to.
  - User delays are increased, because 2 round trips are required to access pages.
  - If the redirecting server is broken, the stil will be broken.
  
Because of these weaknesses, HTTP redirection usually is used in combination with one or more of the other redirection techniques.

### DNS Redirection

The DNS resolver may be the client's own operating system, a DNS server in the client's network, or a more remote DNS server.

*DNS allows several IP addresses to be associated to a single domain, and it can be configured to return varying IP addresses.*

Some of the most redirection techinques to achieve that:
  - DNS round robin: choose the web server at the front of the list, then rotate the list.
  - Load-balacing algorithm: DNS servers keep track of the load on web servers and place the least-loaded web servers at the front of the list.
  - Proximity-routing algorithm: DNS servers can direct users to nearby web servers (when the farm of web servers is geographically dispersed)
  - Fault-masking algorithm: DNS servers can monitor the health of the networkand route requests away from service interruptions or other faults.

### Anycast Addressing

Several geographically dispersed web server have the exact same IP address, each web server advertises itself as a router to a neighboring backbone router. When the backbone router receives packets aimed at the anycast address, it looks for the nearest web server (router) that accepts that IP address.

### IP MAC Forwarding

HTTP messages are sent in the form of addressed data packets. Each packet has a layer-4 address: source, destination IP addresses and TCP port numbers. Each packet also has a layer-2 address: the Media Access Control (MAC) address, to which layer-2 devices (switches and hubs) pay attention.

The job of 2-layer devices is to receive packets with particular incoming MAC addresses and forward them to particular outgoing MAC addresses.

### IP Address Forwarding

A switch or other layer 4-aware device examines TCP/IP addressing on incoming packets and routes packets accordingly by changing the destination IP address, instead of the MAC address. This type of forwarding is also called *Network Address Translation (NAT)*.

### Network Element Control Protocol (NECP)

No notes.

## Proxy redirection methods

Clients know how to go to a proxy by 3 ways:
  - Explicit browser configuration.
  - Dynamic automatic configuration.
  - Transparent interception.
  
A proxy can in turn redirect requests to a different proxy (For example, a proxy cache that does not have the content in its cache may choose to redirect the client to another cache).

## Cache redirection methods

---

## Internet cache protocols (ICP)

This protocol allows caches to look for content hits in sibling caches. If a cache does not have the content requested in an HTTP message, it can ask nearby caches, all at the same time, if any of them have a particular URL in their caches.

The nearby caches send back a short message saying HIT if they have that URL or MISS if they don't, the cache is then free to open an HTTP connection to a neighbor cache that has the object.

ICP is simple and lightweigh, ICP messages are 32-bit packed structures in network byte order, making them easy to parse. They are carried in UDP datagrams for efficiency. UDP is an unreliable Internet protocol, which means that the data can get destroyed in transit, so programs that speak ICP need to have timeouts to detect lost datagrams.

## Cache Array Routing Protocol (CARP)

The CARP protocol allows a group of proxy servers to be viewed as single collective cache, instead of a group of cooperating but separate caches (as in ICP). 

By applying a hash function to the URL of a web object, CARP maps web objects to a specific proxy server. Because each web object has a unique home, we can determine the location of the object by a single lookup.

## Hyper Text Caching Protocol (HTCP)

The Hyper Text Caching Protocol (HTCP) reduces the probability of false hits by allowing siblings to query each other for the presence of documents using the URL and all of the request and response headers.


