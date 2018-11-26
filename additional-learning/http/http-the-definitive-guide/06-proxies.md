Web proxy servers are intermediaries. Proxies sit between clients and servers and act as "middlemen" (clients often use web proxy servers to access web servers on their behalf), shuffling HTTP messages back and forth between the parties.

=> HTTP proxy servers are both web servers and web clients (send response to client, send request to server).

---

**Public proxies**: Proxies shared among numerous clients (like caching proxy servers).

**Private proxies**: Proxies dedicated to a single client

---

Proxies connect two or more applications that speak the same protocol, while gateways hook up two or more parties that speak different protocols (acts like a protocol converter):

```
Client <---HTTP---> Proxy <---HTTP---> Server

Client <---HTTP---> Web/email Gateway <---POP---> Email server
```

---

Some usages of proxies:

- Child filter: since proxy servers can see and touch all passing HTTP traffic, elementary school can use filtering proxies to block access to adult content.
- Document access controller: require password for requests to credential data.
- Security firewall: used by network security engineers to enhance security; firewall proxies restrict which application-level protocols flow in and out of an organization, scrutinize that traffic to detect virus.
- Web cache: web caching proxy maintain local copies of popular documents for reducing slow and costly Internet communication.
- Content router: Proxies as content router can vector requests to particular web servers based on Internet traffix conditions and type of content. For example, client A paid for higher performance, client B didn't; when they request to the same resource of server X, the requests go through a content router, the content router forward A's request to a nearby replica caches for higher performance and forward B's request to the origin X server (slower). Similarly, client A can access to server X faster than server Y if X paid to have content distributed to replica caches but Y didn't.
- Transcoder: transcoding proxies can convert GIF images to JPEG as they fly by to reduce size, compress text data or even convert documents into foreign languages on the fly.
- Anonymizer: proxies provide heightened privacy and anonymity by actively removing identification from HTTP messages (UX may be diminished, some websites may not function properly):

```
GET /something/.. HTTP/1.1           --> Keep
Date: ...                            -->
User-agent: Mozilla/4.75 (Win98; U)  --> User-agent: Mozilla/4.75 (remove user's computer and OS type)
Referer: http://example.com          --> Remove this header to obscure other sites the user has visited
Cookie: profile=''                   --> Remove cookies to eliminate profiling and identity data
Cookie: income='30k'                 --> As above
```

---

We can place/deploy proxies at:

```
1. Egress proxy:
- is placed at the exit points of local network to control the traffic with the Internet.
- usage: filtering adult content in school, offer firewall protection from outside hackers.

client <--LAN--> Proxy <-----Internet-----> Server
client

2. Access (ingress) proxy:
- is placed at ISP access points, processing the aggregate requests from customers.
- usage: ISPs use caching proxy to store copies of popular documents, increase download speed for their customers and reduce Internet bandwidth cost.

client <--ISPs access points--> Proxy <-----Internet-----> Server
client

3. Surrogates proxy:
- is placed in front of webservers.
- usage: add security features to web servers, improve performance by using web server caches.

client <-----Internet-----> Proxy <--LAN--> Server
client

4. Network exchange proxy:
- is placed in the Internet peering exchange points between networks.
- usage: alleviate congestion at Internet junctions through caching, monitor traffic flows.
```

---

HTTP messages may be passed from proxy to proxy until they eventually reach the origin server:

```
client <-----> proxy 1 <-----> proxy 2 <-----> server
             (child of 2)    (parent of 1)  : server -> client: direction of hierachy
```

However, a proxy may forward the request to forward messages to a varied and changing set of proxy servers and origin servers (dynamic parenting routing logic):
- If the requested objects belongs to a server that has paid for content distribution, the proxy forward the request to a nearby cache server.
- Load balancing: A child may pick a parent proxy based on the current level of workload to spread the load around.
- Geographic proximity routing: A child proxy might select a parent responsible for the origin server's geographic region.
- etc

---

There are four common ways to cause client traffic to get to a proxy:
- Modify the client: If a client is configured to use a proxy server, the client sends HTTP requests directly and intentionally to the proxy, instead of to the origin server. This can be done via manually set a proxy in your browser.
- Modify the network: the network infrastructure intercepts and steers web traffix into a proxy without client's knowledge (this is called an *intercepting proxy*)
- Modify the DNS namespace: ?
- Modify the web server: some web servers can redirect client requests to a proxy by 305 HTTP redirection command.

---

When client sends request directly to a server, it sends the partial URI:

```
GET /index.html HTTP/1.1
```

When client sends request to a server through a proxy or a server that uses virtual hosting, it sends the full URI, so that the proxy can have enough information about the server to establish TCP connection with it:

```
GET http://www.example.com(:80)/index.html HTTP/1.1
```

In case the proxy receives a partial URI, it can check the Host header for origin server name and port number. 

---

`Via` header field lists information about each intermediate node (proxy or gateway) through which a message passes. `Via` header field contains a comma-separated list of *waypoints*. Each waypoint represents an individual proxy server or gateway hop and contains information about the protocol and address of that intermediate node.

```
client ---> proxy1.net ---> proxy2.com ---> server
           (HTTP 1.1)       (HTTP 1.0)  ^
                                        |
                                   Request message
                                   Via: 1.1 proxy1.net, 1.0 proxy2.com
```

Both request and response messages pass through proxies, so both request and response messages have Via headers. Via header for responses is almost always the reverse of the Via header for requests.

---

Note: The `Server` response header field describes the software used by the origin server (therefore intermidiate proxies shouldn't modify this):

```
Server: Apache/1.3.14 (Unix) PHP/4.0.4
```

---

HTTP/1.1's TRACE method lets you trace a request message through a chain of proxies, observing what proxies the message passes through and how each proxy modifies the request message. TRACE is very useful for debugging proxy flows.

---

When a request for restricted content arrives at a proxy server, the proxy server can return a 407 Proxy Authorization Required status code demanding access credentials, accompanied by a Proxy-Authenticate header field that describes how to provide those credentials.

When the client receives the 407 response, it attempts to gather the required credentials, either from a local database or by prompting the user.

---

Note:

```
Request:
OPTIONS /index.html HTTP/1.1

Response:
Allow: GET, POST.. (proxies can't modify this header)
```
