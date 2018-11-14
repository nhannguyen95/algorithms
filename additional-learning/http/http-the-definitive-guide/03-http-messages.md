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

**Status code 100: Continue**

If a client wants to send an entity (maybe a file) to a server, it can first send an initial request that contains an *Expect request header* with the value 100-continue.

If a server receives that request (with the Expect header and 100-continue value), it will respond with either the HTTP status code of 100 Continue response or an error code, indicating if the server will be able to handle or use the file that the client is about to send or not.

That is to say, the usage of 100-continue of Expect request header of the client application is an optimization.

Important notes:
- If the client doesn't intend to send an entity to the server, it shouldn't send a 100-continue Expect header, this will only confuse the server into thinking that the client might be sending an entity.
- If the server doesn't find the 100-continue Expect header in the request message, it shouldn't send back an HTTP status code of 100.
- Clients shouldn't wait for the server to send a 100 Continue response. After some timeout, it should just send the entity.
- If the server receives some (or all) of the entity before it has had a chance to send a 100 Continue response, it does not need to send this status code, because the client already has decided to continue. When the server is done reading the request, however, it still needs to send a final status code for the request (it can just skip the 100 Continue status).

**200 OK**: Request is okay, entity body contains requested resource.

**201 Created**: for requests that create server objects like PUT, the object must be created before the server sends this code.

**202 Accepted**: The request is valid, but there are no guarantees that the server will complete/perform the request.

**203 Non-Authoritative Information**: The info contained in the entity headers came not from the origin server but from an intermediary that had a copy of a resource.

**204 No Content**: The response message contains headers and a status line, but no entity body.

**206 Partial Content**: Clients can request part or a range of a document by using special headers.

**300 Multiple choices**: Returned when a client has requested a URL that actually refers to multiple resources, such as a server hosting an English and French version of an HTML document.

**301 Moved Permanently**: Used when the requested URL has been moved. The response should contain in the Location header the URL where the resource now resides.

**304 Not Modified**: If a client makes a conditional request, such as a GET if the resource has not been changed recently, this code is used to indicate that the resource has not changed. (For example there maybe a If-Modified-Since header in the Headers of request message).

**305 Use Proxy**: Used to indicate that the resource must be accessed through a proxy; the location of the proxy is given in the Location header.

**400 Bad request**: malformed request.

**401 Unauthorized**

**403 Forbidden**: the request was refused by the server.

**404 Not Found**.

**405 Method Not Allowed**: The Allow header should be included in the response to tell the client what methods are allowed on the requested resource.

**500 Internal Server Error**

**501 Not Implemented**

**502 Bad Gateway**: Used when a server acting as a proxy or gateway encounters a bogus response from the next link in the request response chain.

**503 Service Unavailable**: server currently cannot service the request but will be able to in the future.

**504 Gateway Timeout**: the response is coming from a gateway or proxy that has timed out waiting for a response to its request from another server.

**505 HTTP Version Not supported**

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

---

**General headers**: used by both clients and servers.
- `Date: Tue 3 Oct 1974 02:16:00 GMT`
- `Transfer-Encoding`: Tells the receiver what encoding was performed on the message in order for it to be transported safely.
- *General caching headers*: directives about how and when to cache local copies of objects instead of always fetching them directly from the origin server.
  - `Cache-Control`

**Request headers**: used in request messages, provide extra information to servers. 
- `Client IP`
- `Host`: hostname and port of the server to which the request is being sent.
- `Referer`: the URL of the document that contains the current request URI.
- `User-Agent`: the name of the application making the request.
- *Accept headers*: tell servers what clients want/don't want:
  - `Accept: */*`: client is willing to receive any type of data.
  - `Accept-Charset`
  - `Accept-Encoding`
  - `Accept-Language`
- *Conditional request headers* help client put restrictions on requests:
  - `Expect`: Allows a client to list server behaviors that it requires for a request
  - `If-Match`
  - `If-Modified-Since`: Restricts the request unless the resource has been modified since the specified date.
  - `Range`: Requests a specific range of a resource, if the server supports range requests.
- *Request security headers*: used to require clients to authenticate themselves before getting access to certain resources
  - `Authorization`: Contains the data the client is supplying to the server to authenticate itself.
  - `Cookie`: Used by clients to pass a token to the server—not a true security header, but it does have security implications.
- *Proxy request headers*:
  - `Max-Forwards`: The maximum number of times a request should be forwarded to another proxy or gateway on its way to the origin server—used with the TRACE method.
  - `Proxy-Authorization`: Same as `Authorization`, but used when authenticating with a proxy

**Response headers**: used in response mesage, provide extra information to clients.
- `Age`: How old the response is (since it was sent)
- `Public`: A list of request methods the server supports for its resources
- `Retry-After`: retry if a resource is unavailable
- `Server: Tiki-Hut/1.0`
- `Title`: title of html document source
- `Warning`
- *Negitiation headers*:
  - `Accept-Ranges`: The type of ranges that a server will accept for this resource
  - `Vary`: a list of headers the server looks at to pick which is the best version of a resource to send the client.
- *Response security headers*:
  - `Set-Cookie`: Not a true security header, but it has security implications; used to set a token on the client side that the server can use to identify the client

**Entity headers**: headers that deal with the entity body (payload).
- `Allow`: Lists the request methods that can be performed on this entity
- `Location`: Tells the client where the entity really is located; used in directing the receiver to a (possibly new) location (URL) for the resource.
- *Content headers*:
  - `Content-Base`: The base URL for resolving relative URLs within the body
  - `Content-Encoding`
  - `Content-Language`
  - `Content-Length`
  - `Content-Location`
  - `Content-MD5`: MD5 checksum of the body
  - `Content-Range`: The range of bytes that this entity represents from the entire resource
  - `Content-Type: text/html; charset=iso-latin-1`
- *Entity caching headers*: provides information about the entity being cached:
  - `ETag`: The entity tag (ID) associated with this entity.
  - `Expires`: The date and time at which this entity will no longer be valid and will need to be fetched from the original source.
  - `Last-Modified`: The last date and time when this entity changed

**Extension headers**: nonstandard headers that have been created by application developers.
