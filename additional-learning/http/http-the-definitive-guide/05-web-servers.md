In this chapter:
- What are web servers?
- Some forms of web servers
- Web servers' tasks:
  - 1/ Accepting clients' TCP connection
  - 2/ Receiving request message
  - 3/ Processing the request
  - 4/ Mapping and accessing the resource
  - 5/ Building the response
  - 6/ Sending the response
  - 7/ Logging

---

**The term "web server" can refer either to web server software or to the particular device or computer dedicated to serving the web pages.**

Web servers comes in all flavors, shapes, and sizes. There are trivial 10-line Perl script web servers, 50-MB secure commerce engines, and tiny servers-on-a-card. But whatever the functional differences, all web servers receive HTTP requests for resources and serve content back to the clients

Web servers:
- implement HTTP protocol
- manage web resources
- provide web server administrative capabilities
- share responsibilities for managing TCP connections with the OS, the underlying OS manages the hardware details of the underlying computer system and provides TCP/IP network support, file systems to hold resources, and process management to control current computing activities.

---

Many forms of web servers:

## General-Purpose Software Web Servers

You can install and run general-purpose software web servers on standard computer systems.

Common software:
- The free Apache software
- Microsoft web server
- Sun iPlanet servers
- etc.

## Web Server Appliances

If you don't want the hassle of installing soft ware, you can purchase a web server appliance. Web server appliances are prepackaged software/hardware solutions. The vendor preinstalls a software server onto a vendor-chosen computer platform and preconfigures the software.

Some examples of web server appliances:
- Sun/Cobalt RaQ web appliances
- Toshiba Magnia SG10
- IBM Whistle web server appliance

## Embedded Web Servers

Embedded servers are tiny web servers intended to be embedded into consumer products (ex. printers..). Embedded web servers allow users to administer their consumer devices using a convenient web browser interface.

Some example:
- IPic match-head sized web server
- NetMedia SitePlayer SP1 Ethernet Web Server

---

Several common tasks of a state-of-the-art commercial web servers:

## 1. Accepting Client Connections

When a client requests a TCP connection to the web server, the web server establishes the connection and determines which client is on the other side of the connection, extracting the IP address from the TCP connection. *(Different operating systems have different interfaces and data structures for manipulating TCP connections. In Unix environments, the TCP connection is represented by a socket, and the IP address of the client can be found from the socket using the getpeername call.)*

Web server can reject and immediately close any connection if the client IP address or hostname is unauthorized or is a known malicious client.

When receiving a request from a client, web servers can determine the client user through *ident* (if both web server and client support the IETF ident protocol). The client listens on TCP port 113 for ident requests, web servers can opens its own connection and sends a simple request asking for client's user name and retrieves it from the client's reponse message.

*ident* doesn't work well accross public Internet because:
- Many client PCs don't run *ident* protocol.
- ident protocol is insecure, delays HTTP transactions
- Many filewalls won't permit incoming ident trafic.
- There are privacy concerns about exposing client usernames.

## 2. Receiving Request Messages

When a web server receives a request message, it parses the request message:
- Parses the request start line (method, URI, HTTP version), ending with CRLF.
- Reads the message headers, each ends with CRLF (these headers - name/value pairs - can be stored in a fast lookup table to quickly access later)
- Detect the end-of-headers blank line, ending with CRLF.
- (if present) Reads the request body.

The web server may needs to store the partial message data in memory until it receives enough data to parse it and make sense of it (since data is sent in packets).

High-performance web servers support thousands of simultaneous connections, constantly watch for new web requests. Different web server architectures service requests in different ways:
- *Single-threaded web servers*: web servers process 1 request at a time until completion until it process the next one => performance problem.
- *Multiprocess and multithreaded web servers*: multiple processes or higher-efficiency threads process requests simultaneously. Large number of processes or threads may consume too much memory & resources => web servers put a limit on the maximum number of them.
- *Multiplexed I/O servers*: all the connections are simultaneously watched for activity. When a connection changes state (ex. when data becomes available), it is processed and returned to the open connection list.
- *Multiplexed multithreaded web servers*.

Note: Systems where threads are created in advance are called "worker pool" systems, because a set of threads waits in a pool for work to do.

## 3. Processing Requests

No notes.

## 4. Mapping and Accessing Resources

Web servers are resource servers: they deliver precreated content or resource-generating applications running on the servers.

Normally, the web server takes the URI from request message and appends it to the *document root*.

```
Request: /books/http.pdf
Web server's document root: /usr/local/files
Web server returns the file /usr/local/files/books/http.pdf
```

2 web sites hosted on the same web server can have completely distinct content by using virtually hosted docroots. A virtually hosted web server identifies the correct document root to use from IP address or hostname in the URI or the Host header:


```
Request A to server X:
GET /index.html HTTP/1.0
Host: www.joes-hardware.com
=> Return /docs/joes/index.html

Request B to server X:
GET /index.html HTTP/1.0
Host: www.marys-antiques.com
=> Return /docs/marys/index.html
```

A web server can receive requests for directory URLs, where the path resolves to a directory, not a file. Some configuration of web servers to handle this:
- Return an error
- Return index.html file in that directory
- Scan the directory, and return an HTML page containing the contents.

Web servers can also map URIs to dynamic resources (programs that generate content on demand). A class of web servers called *application servers* connect web servers to sophisticated back-end applications.

## 5. Building Response

Once the web server has identified the resource, it performs the action described in the request method and returns the response message.

If a response body is present:
- `Content-Type`: MIME type of the response body, web server can use the extension of the filename to indicate MIME type (ex. .gif -> image/gif), this strategy is most commonly used. Some other strategies: *Magic typing*: map content of file -> MIME type, *explicit typing*: force MIME type of a file, etc.
- `Content-Length`

Web servers sometimes return redirection reponses to tell browser to go elsewhere to perform the request (the redirecting URL is in `Location` header of the response message). Redirects are useful for:
- Permanently moved resources: 301
- Temporarily moved resources (come back with the old URL in the future): 303, 307 
- URL augmentation: the server generates a new URL with embedded state info, the client follows the redirect and reissuing the request with full and state-augmented URL. 303, 307.
- Load balancing: redirect the client to a less heavily loaded server. 303, 307.
- Canonicalizing directory names: if client requests a URI for a directory name without a trailing `/`, most web servers redirect the client to a URL with the `/` added, so that relative links work correctly.

## 6. Sending Responses

The server needs to be extra cautious to compute `Content-Length` header correctly, or the client will have no way of knowing when a response ends.

## 7. Logging

Finally, when a transaction is complete, the web server notes an entry into a log file, describing the transaction performed





