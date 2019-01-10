HTTP uses reliable data-transmission protocols, it guarantees that your data will not be damaged during transit.

---

Web servers speak the HTTP protocol, so they are often called HTTP servers.

---

Because the Internet hosts many thousands of different data types, HTTP carefully tags each object being transported through the Web with a data format label called a MIME type:
- text/html
- text/plain
- image/jpeg
- application/vnd.ms-powerpoint
- etc.

A server sends HTTP object data to clients with an attached MIME (`Content-type`) type so clients know how to handle the object.

---

URI (Uniform Resource Identifier) - uniquely identifying and locating information resources on the Internet.

URIs come in 2 flavor: URLs and URNs

**URL - Uniform Resource Locator**: the most common form of resource identifier, it describes the specific location of a resource on a particular serve.

Most URL has 3 main parts (more in chapter 02):
- scheme: the protocol used when accessing a server to get the resource (usually `http://`).
- server Internet address.
- name (or path to) the resource on the server.

```
E.x:
scheme://server location/path
[http://][example.com][/books/http.pdf]
```

**URN - Uniform Resource Name**: serves a unique name for a particular resource, independent of where the resource currently resides.

```
E.x: urn:ietf:rfc:2141
```

URNs are still experimental and needs a supporting infrastructure to resolve resource locations.

---

A web page is often a collection of resources, not a single one (may be hosted at different server): HTML skeleton, images, etc.

---

HTTP is an application layer protocol. It doesn't worry about the details of network communication.

Instead, HTTP uses TCP/IP to transport the data. It hides the peculiarities of individual networks and hardware, allow them to talk together reliably.

TCP/IP is:
- Reliable: once a TCP connection is established, message exchanged will never be lost or damaged.
- In-order delivery (data will always arrive in the order in which it was sent.
- Unsegmented data stream (can dribble out data in any size at any time) (?)

HTTP network protocol stack:

|Layer|Protocol|
|-|-|
|Application|HTTP|
|Transport|TCP|
|Network|IP|
|Data link|Network-specific link interface|
|Physical|Physical network hardware|

---

Read more: https://bit.ly/2DjAC3p

Before an HTTP client sends a message to a server, a TCP/IP connection between C and S needs to be established with known server's address and TCP port number with specific software program running on the server:

Consider the request `https://www.example.com:80/books/http.html`:
- From the URL: the browser extracts protocol used is HTTP, server's host name (and uses DNS to convert into server's IP address), TCP port number (if any, default = 80).
- The browser uses those info to establish a TCP connection with the web server
- HTTP requests exchanged like below...
- The connection is closed, the browser displays the result

```
 ________  HTTP Request                             ________
|        | (*) [HTTP Message]                      |        |
| CLIENT | --------------------------------------> | SERVER |
|        |                                         |        |
|        |                           HTTP Response |        |
|        |                    (**) [HTTP Message]  |        |
 --------  <--------------------------------------  --------

HTTP Request (*)
(HTTP Message from C to S: Request message)
-----------------------------------------------------
Start line | GET /books/http.html HTTP/1.1
-----------------------------------------------------
Headers    | User-agent: Mozilla/4.5 [en] (win98; U)
           | Host: www.example.com
           | Accept: text/html, image/gif, image/jpeg
           | Accept-language: en
-----------------------------------------------------
Body       | No request body


HTTP Response (**)
(HTTP Message from S to C: Response message)
-----------------------------------------------------
Start line | HTTP/1.0 200 OK
-----------------------------------------------------
Headers    | Content-type: text/html
           | Content-length: 12
           | Date: Sun, 01 Oct 2000 23:25:17 GMT
           | Server: Apache1.3.11 (Unix)
           | Last-modified: Tue, 04 Jul 2000
-----------------------------------------------------
Body       | <html> ... </html>
```

3 parts of a HTTP message:
- Start line: what to do for a request / what happened for a response.
- Headers: <name: value>
- Body: optional data

An **HTTP Transaction** consists of a request command and a response result.

This communication happens with formatted blocks of data called **HTTP messages**.

An HTTP method tells the server what action to perform:
- GET
- PUT: Store data from client into a named server resource.
- DELETE
- POST: Send client data into a server gateway application.
- HEAD: Send just the HTTP headers from the response for the named resource.

Some common HTTP status codes:
- 200: OK.
- 302: Redirect. Go somewhere else to get the resource.
- 404: Not found.

---

HTTP/1.1 is the current version of HTTP. HTTP/2.0 (HTTP-NG) focuses on performance optimizations for remote execution of server logic, there are no plans to replace this with HTTP/1.1.

---

Besides 2 aforementioned **web applications** web browsers and web servers, there are many other web applications that you interact with on the Internet:

- Proxies:
  - HTTP proxy servers sit between C and S, receive client's HTTP requests and relaying them to the server.
  - Proxies can be used for security, filter requests and responses, filter out adult content , etc.
 
- Caches (Web cache, caching proxy):
  - A special type of HTTP proxy server that keeps copies of popular previous-requested documents that pass through the proxy. A client may be able to download a document quickly from a nearby cache than from a distant web server.
 
- Gateways:
  - Special web server that connects to other applications.
  - The client may not be aware it is communicating with a gateway.
 
- Tunnels:
  - Often used to transport non-HTTP data over 1 or more HTTP connections, without looking at the data.
 
- Agents:
  - Any client programs that make HTTP requests on the user's behalf.
  - For examples: web browsers, spiders..
