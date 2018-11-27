**HTTP Entities**:

If HTTP messages are the crates, then HTTP entities are the actual cargo:

```
 ----------------------------------------
| HTTP Crate                             |
|                                        |
|   HTTP/1.0 200 OK                      |
|   Server: Netscape-Enterprise/3.6      |
|   Date: ...                            |
|  ------------------------------------  |
| | Content-type: text/plain    Entity | |
| | Content-length: 3           headers| |
| |                                    | |
| | abc                Entity body     | |
|  ------------------------------------  |
 ---------------------------------------- 

```

HTTP entity headers describe the contents of an HTTP message:

- `Content-Type` (of the original body)
- `Content-Length` (in byte)
  > If HTTP message doesn't have a body (like HEAD response), don't include Content-Length header.
- `Content-Language`
- `Content-Encoding`: Any transformation (compression, etc) performed on the object data.
  > To make it more secure or to compress it to save space
- `Content-Location`: An alternate location for the object at the time of the request.
- `Content-Range`
- `Content-MD5`: checksum of the entity body (for data integrity).
  > Only the server where the response originates may compute this header.
  > This is removed in HTTP/1.1
- `Last-Modified`: (at the server)
- `Expires`: the date time this entity data will become stale.
- `Allow`
- `ETag`: A uniquie validator for this particular instance of the document.
- `Cache-Control`

---

When an HTTP fill-in form is submitted, fields are sent as separate parts of a multipartbody, allowing forms to be filled out with values of differents and lengths:

```
Content-Type: multipart/form-data; boundary=AaB03x (acts like a delimiter between different parts of the body)
--AaB03x
Content-Disposition: form-data; name="submit-name"
Sally
--AaB03x
Content-Disposition: form-data; name="files"
Content-Type: multipart/mixed; boundary=BbC04y
--BbC04y
Content-Disposition: file; filename="essayfile.txt"
Content-Type: text/plain
..contents of eassayfile.txt..
```

HTTP responses to range requests also can be multipart:

```
HTTP/1.0 206 Partial content
Server: ..
Date: ..
Content-Location: http://...
Content-Type: multipart/x-byteranges; boundary=[abc]
Last-Modified: ...

--[abc]
Content-Type: text/plain
Content-Range: bytes 0-174/1441

<content> (175 bytes)
--[abc]
Content-Type: text/plain
Content-Range: bytes 552-761/1441

<content>
..
```

---

**Content Encoding**:
- A web server generates an original response message with original Content-Type and Content-Length.
- A content-encoding server (the origin server itself or a downstream proxy) creates an encoded message with the same Content-Type but a new Content-Length specifying the length of the encoded message, and a `Content-Encoding` header so that the receiving knows how to decode it.
- The receiving program gets the encoded message, decodes it and obtains the original.

**Content-Encoding Types**:
- gzip: gnu zip encoding.
- compress: unix file compression program.
- deflate: compressed into zlib format.
- identity: no encoding has been performed.

> The gzip, compress, and deflate encodings are lossless compression algorithms; gzip typically is the most effective and widely used algorithm.

Client can give the server a list of encoding algorithms that it wants the server to use using `Accept-Encoding` headers:

```
Accept-Encoding: compress, gzip
Accept-Encoding: * (anything)
Accept-Encoding: compress;q=0.5, gzip;q=1.0 (the larger q is, the more preferable the encoding is)
```

---

**Transfer Encoding**: you apply it to a message to change the way the message data is transferred accross the network.

When the connection between the client and server is not persistent, clients do not need to know the size of the body they are reading, they expect to read the body until the server closes the connection.

With persistent connections, the size of the body must be known and sent in the Content-Length header before the body can be written. When content is dynamically created at a server, it may not be possible to know the length of the body before sending it.

Chunked encoding provides a solution for this dilemma, by allowing servers to send the body in chunks, specifying only the size of each chunk. As the body is dynamically generated, a server can buffer up a portion of it, send its size and the chunk, and then repeat the process until the full body has been sent.

Steps:
- First, the client sends HTTP request to the server:
  ```
  GET /new_products.html HTTP/1.1
  Host: www.example.com
  User-Agent: ...
  TE: trailers, chunked   // trailers: means the client is willing to accept trailers on the end of chunk-encoded messages
                          // chunked: client accepts chunked encoding
  ```
- The server's response starts with a HTTP response:
  ```
  HTTP/1.1 200 OK
  Content-type: text/plain
  Transfer-encoding: chunked  // the message has been transfer-encoded with the chunked encoding
  ```
  Then a list of chunks:
  ```
  Chunk #1:
  27 (length in bytes)
  <content>..
  
  Chunk #2:
  10
  <content>
  
  Chunk #3: (last chunk)
  0
  ```
  Followed by a trailer that contains optinal metadata whose value might not have been known at the start of the message:
  ```
  Trailer:
  Content-MD5: <md5>
  ```

---

Let assume you downloaded 400 bytes of a document the network was suddenly interupted. Provided that the document did not change at the origin server between the time you first requested it and you've just reconnected with the network again. You can make a **range requests** asking for the range or part of the document you failed to get:

```
GET /bigfile.html HTTP/1.1
Host: www.example.com
Range: bytes=4000-
User-Agent ...
```

The range header can also be used so that a client can request different ranges of the same document from different servers in order to speed up overall download time.

The server can tell clients if they accept range requests or not:

```
HTTP/1.1 2002 OK
Date: ..
Server: ..
Accept-Ranges: bytes
```

Range headers are used extensively by popular peer-to-peer file-sharing client software to download different parts of multimedia files simultaneously, from different peers.

---

If the server has a newer version of a document than the document's copy at the client, instead of sending the server the whole document, the server can only send the difference between 2 document versions, this is obtained by using **delta encoding**.

Delta encoding can reduce transfer times, but it can be tricky to implement since the server needs to keep all different copies of the document and extra disk space too.
