If HTTP is the courier, HTTP messages are the packages it uses to move things around.

---

To describe transactional direction: the terms **inbound** and **outbound**.

Messages travel inbound to the origin server.

When their work is done, they travel outbound back to the user agent.

---

The sender of any messages is **upstream** of the receiver (C is upstream of S for the request).

The receiver of any messages is **downstream** of any sender (C is downstream of S for the response).

---

The start line and headers are just ASCII text, broken up by lines. Each line ends with a two-character end-of-line sequence, consisting of a Carriage Return (ASCII 13) and a Line-Feed character (ASCII 10). This end-of-line sequence is written " CRLF”.

The body can contain text or binary data or can be empty.

---

**Format for a request message**

```
<method> <request-URL> <version> (start line for request message, or request line)
<headers>
"blank_line"
<entity-body>
```

- method: how the client wants the server to perform on the resource: GET, HEAD, POST, etc.
- request-URL: Resource URL
- version: HTTP version that the message is using, format: `HTTP/<major>.<minor>`, like `HTTP/1.1`.
- headers: Each line is a `<name>:<value>` pair, followed by a CRLF. The headers are terminated by a blank line (CRLF), marking the end of the list of headers and the beginning of the entity body.
- entity-body: optional body, some methods require one such that `POST` and `PUT`.

Excerpt From: David Gourley. “HTTP: The Definitive Guide.” iBooks. 

---

**Format for a response message**

```
<version> <status> <reason-phrase> (start line for response message, or response line)
<headers>
"blank_line"
<entity-body>
```

- status: 3-digit HTTP status code.
- reason-phrase: human-readable version of the numeric code.

---

Status code classes:

|Overall range|Defined range|Category|
|-|-|-|
|100-199|100-101|Informational|
|200-299|200-206|Successfull|
|300-399|300-305|Redirection|
|400-499|400-415|Client error|
|500-599|500-505|Server error|

---

Not all HTTP methods are implemented by every server. To be compliant with HTTP 1.1, a server need implement only GET and HEAD methods for its resources.

GET is a safe method (nothing will happen on the server as a result of the HTTP request):
- ask servers to send a resource.

HEAD is a safe method:
- same as GET, but the server returns only the headers in the response, no entity body. Using HEAD you can: find out a resource without getting it, check if an object exists or test the resource has been modified.

PUT:
- Is often used to deposit data into a resource on the server.
- server take the body of the request and either use it to create/replace a document named by the requested URL.

POST:
- Is often used to support HTML forms: send input data to the server.

TRACE:
- When a client makes a request, that request may have to travel through firewalls, proxies, gateways, or other applications. Each of these has the opportunity to modify the original HTTP request. The TRACE method allows clients to see how its request looks when it finally makes it to the server (in the body of the response message).
- Drawback: TRACE does not provide a mechanism to distinguish methods. Many HTTP applications do different things depending on the method, and they just make the call as to how they process a TRACE request.

OPTIONS:
- Asks the server to tell us about the various supported capabilities of the web server (in the Allow Header of the response message).

DELETE:
- Asks the server to delete the resources specified by the request URL.


























