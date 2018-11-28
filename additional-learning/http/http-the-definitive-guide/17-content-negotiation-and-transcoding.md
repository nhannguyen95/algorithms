**Content-Negotiation**: deciding which page at a server is the right one for a client:
  - Server can serve a page (corresponding to 1 URI) of different languages, these different versions are called *variants*.
  - Server can automatically generate customized pages (ie. convert and HTML page into a WML page for handheld devices), these kind of dynamic content tranformations are called *transcodings*.
  
 3 techniques of content-negotiation:
  - Client-driven: client makes a request, server sends a list of choices, client chooses.
    > Advantages:
    >  - easiest to implement at servers
    >  - clients make best choice
    >
    > Drawbacks:
    >  - 2 requests are needed => add latency
  - Server-driven: server examines client's request headers and decides what version to serve.
    > Clients need to provide enough information (Accept headers), servers then compare Accept header with Entity header
    > to serve clients the correct version of the page:
    >    ```
    >    Accept header   |   Entity header
    >    Accept              Content-Type
    >    Accept-Language     Content-Language
    >    Accept-Charset      Content-Type
    >    Accept-Encoding     Content-Encoding
    >    ```
    > Since HTTP is stateless, these information needs to be in every request.
  - Transparent: An intermediate device (usually a cache proxy) does a request negotiation on the client's behalf.
 
 ---
 
If the server doesn't have a document that matches the client's needs, it may be able to transform one of its existing documents into something that the client can use (for example an intermediate cache can base on `User-Agent` header of the request to know what kind of browser the client is using to communicate with the server to serve appropriate document). This option is called **transcoding**.

Some hypothetical transcodings:
- HTML document -> WML document.
- High-resolution image -> Low-resolution image
- Image in 64K colors -> Black-and-white
- Complex page with frames -> Simple text page without frames or images
- Page with ads -> page with ads removed
