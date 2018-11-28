The collective duties of storing, brokering, and administering content resources is called **web hosting**. 

**Hosting** is one of the primary functions of a web server. You need a server to hold, serve, log access to, and administer your content.

If you don't want to manage the required hardware and software yourself, you need a **hosting service** (or **hoster**). Hosters rent you serving and web-site administration services and provide various degrees of security, reporting, and ease of use. Hosters typically pool web sites on heavy-duty web servers for cost-efficiency, reliability, and performance.

---

**Dedicated hosting**: web owners can sign up for the dedicated web hosting service to lease a dedicated web server.

**Virtual hosting**: many people want to have a web presence but don't have high traffic web sites. It will be a waste for them to lease a dedicated web server. Many web hosters offer lower-cost web hosting services by sharing one computer between several customers. This is called **shared hosting** or **vitual hosting**. Each web site appears to be hosted by a different server, but they really are hosted on the same physical server.

> 1000 web sites can be hosted on the same server, but this does not necessarily mean that 1000 web sites are served from only 1 PC. Hosters can create banks of replicated servers (called **server famrs**) and spread the load across the farm of servers.

---

HTTP/1.0 mistakenly assumed that each web server would host exactly one web site. Meaning that if a client tries to connect to the server `www.example.com/index.html`, the HTTP request only says `GET /index.html` *without a hostname*. If the server is virutally hosting multiple sites, this isn't enough information to figure out what virtual web site is being accessed.

4 workarounds before HTTP/1.1 comes out:
- Virtual hosting by URL path: adding special path components to the URL so the server can determine the site: `www.example.com/joe/index.html`.
- Virtual hosting by port number: each site is assigned a different port number on the web server (end users need to specify the port). 
- Virtual hosting by IP address: each virtual site gets one or more unique IP addresses, the IP addreses for all of the virtual web sites are attached to the same shared physical server.
  > Drawbacks: computer systems usually have a limit on how many virtual IP addresses can be bound to a machine.
- Virtual hosting by Host header: enhanced versions of HTTP/1.0 define a Host request header the carries the site name.

HTTP/1.1 solves this problem be defining the `Host` header.

---

**Making web sites reliable**:

- **Mirrored Server Farms**: a server farm is a bank of identically configured web servers that can cover for each other. The content on each server in the farm can be mirrored, so that if one has a problem another can fill in.

  Mirrored servers often follow a hierarchical relationship: the web owners push the origin web content to a **master origin server**, the mirrored servers that receive content from the master origin server are called **replica origin servers** (the origin server is responsible for sending content to the replica servers).

- **Content Distribution Networks (CDN)**: is simply a network whose purpose is the distribution of specific content. The nodes of the network can be web servers, surrogates, or proxy caches.

- **Surrogate Caches in CDNs**: surrogate (reverse proxies) caches can be used in place of replica origin servers. They receive server requests on behalf of *a specific set of origin servers*. The difference is that a surrogate doesn not store entire compies of the origin server content; they sotre whatever content their clients request in their cache, and the origin server does not have the responsibility to update their content.

- **Proxy Caches in CDNs**: Unlike surrogates, traditional proxy caches can receive requests aimd at any web servers.

---

**Making web sites fast**:
- Server farms and distributed proxy caches or surrogate servers distribute network traffic can also help web sites load faster by avoiding congestion; distributing the content brings it closer to end users, so that the travel time from server to client is lower.
- We can also encoding the content for fast transportation (assume that the receiving client can uncompress it).
