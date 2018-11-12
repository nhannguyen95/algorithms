HTTP uses reliable data-transmission protocols, it guarantees that your data will not be damaged transit.

---

Web servers speak the HTTP protocol, so they are often called HTTP servers.

---

```
 ________  HTTP Request                             ________
|        | (*) [HTTP Message]                      |        |
| CLIENT | --------------------------------------> | SERVER |
|        |                                         |        |
|        |                           HTTP Response |        |
|        |                    (**) [HTTP Message]  |        |
 --------  <--------------------------------------  --------
 
HTTP Request (*)
----------------
GET /books/http.pdf HTTP/1.0
Host: www.example.com


HTTP Response (**)
------------------
HTTP/1.0 200 OK
Content-type: text/html
Content-length: 12
```

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

Most URL has 3 parts:
- scheme: the protocol used to access the resource (usually `http://`).
- server Internet address.
- name (or path to) the resource on the server.

```
E.x: [http://][example.com][/books/http.pdf]
```

**URN - Uniform Resource Name**: serves a unique name for a particular resource, independent of where the resource currently resides.

```
E.x: urn:ietf:rfc:2141
```

URNs are still experimental and needs a supporting infrastructure to resolve resource locations.

---

A web page is often a collection of resources, not a single one (may be hosted at different server): HTML skeleton, images, etc.
