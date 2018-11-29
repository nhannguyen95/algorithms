The goal of redirection is to send HTTP messages to available web servers as quickly as possible.

Many redirection techniques work for servers, proxies, caches, and gateways because of their common, server-like traits (clients send them an HTTP request, and they process it).

Redirection techniques:
- Web Cache Coordination Protocol (WCCP)
- Intercache Communicaion Protocol (ICP)
- Hyper Text Caching Protocol (HTCP)
- Network Element Control Protocol (NECP)
- Cache Array Routing Protocol (CARP)
- Web Proxy Autodiscovery Protocol (WPAP)

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







