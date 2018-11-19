Web proxy servers are intermediaries. Proxies sit between clients and servers and act as "middlemen" (it communicates with the server on the client's behalf), shuffling HTTP messages back and forth between the parties.

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
- Modify the client: If a client is configured to use a proxy server, the client sends HTTP requests directly and intentionally to the proxy, instead of to the origin server.
- Modify the network: the network infrastructure intercepts and steers web traffix into a proxy without client's knowledge (this is called an *intercepting proxy*)
- Modify the DNS namespace: ?
- Modify the web server: some web servers can redirect client requests to a proxy by 305 HTTP redirection command.

---





Excerpt From: David Gourley. “HTTP: The Definitive Guide.” iBooks. 





