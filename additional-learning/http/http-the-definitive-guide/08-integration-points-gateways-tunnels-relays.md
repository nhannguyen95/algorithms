A gateway is the glue between resources and applications. An application ask a gateway (through HTTP for example) to handle the request, the gate way use an another appropriate protocol to get the resource from server and provide the response back to the application:

```
Example of an HTTP/FTP server-side gate way:

HTTP Client <---------HTTP---------> Gateway <---------FTP---------> FTP Server
----------------------------        (port 80)                       (port 8080)
HTTP request:               |
GET ftp://ex.com/ somefile  |
```

Gateways are described by their client- and server-side protocols, separated by a slash:

```
<client-protocol>/<server-protocol>
```

**Server-side gateways** speak HTTP with clients and a foreign protocol with server (HTTP/*).

**Client-side gateways** speak a foreign protocol with clients and a HTTP with server (*/HTTP).

---

We can direct HTTP traffic to gateways (the same way we do with proxies). For example you can configure to send FTP URLs to an HTTP/FTP gateway. The result is depicted in the first figure:

- The gateway opens a FTP connection to the FTP server on port 8080.
- Sends the USER and PASS commands to log in to the server.
- Issues the CWD command to change to proper directory.
- Sets the download type as ASCII.
- Fetches the document's last modification time with MDTM.
- Tells the server to expect a passive data retrieval request using PASV.
- Requests the object retrieval using RETR.
- Opens a data connection to the FTP server on a port returned on the control channel; as soon as the data channel is opened, the object content flows back to the gateway.

---

**HTTP/HTTPs: Server-side security gateways**

```
Client ------HTTP------> Gateway ------HTTP+SSL------> Server
                              (encrypting all inbound request
                               to provide extra privacy and security
                               for the server)
```


**HTTPs/HTTP: Client-side security gateways**

```
Client ------HTTP+SSL------> Gateway ------HTTP------> Server
            (gateway includes more efficient        | Now the traffic is unencrypted,
            decryption algorithm than the server    | use with caution!
            => reduce load from the origin server)  |
```

---

The most common form of gateway is application server: application server = gateway + destination server.

The request comes to the application server is now passed directly to an appropriate application *running on the server* through a gateway **application programming interface (API)** in a form of a process (instead of passing to a remote server).

The first popular API for application gateways was the **Common Gateway Interface (CGI)**, CGI is a standard set of protocols for web servers to execute programs/applications that execute like console application in response to HTTP request for special URLs, collect the program output, and send it back in HTTP responses.

One of the trickier issues in wiring up applications is negotiating the protocol interface between the two applications so that they can exchange data, often this is done on an application-by-application basis. To work together, applications usually need to exchange more complex information with one another than is expressible in HTTP headers => The Internet community has developed a set of standards and protocols that allow web applications to talk to each other. These standards are loosely referred to as **web services**.

So with gateways, HTTP can be used to enable access to various kinds of resources and to enable applicaiton-to-application communication.

---

**Web tunnels** were first developed to carry encrypted SSL traffix through firewalls. Many organizations make all traffic go through packet-filtering routers or proxy servers to enhance security. But some protocols like encrypted SSL cannot be proxied by traditional proxy servers since the information is encrypted. Web tunnels let the SSL traffic be carried through the port 80 HTTP firewall by transporting it through an HTTP connection.

Let say a client wants to send SSL traffic (or a non-HTTP traffic) to a server without being rejected by port-filtering firewalls, it can first set up a tunnel with a tunnel endpoint (a gateway):
- The client sends a HTTP request with CONNECT method to ask the tunnel gateway to open TCP connection.
- Once the TCP connection is established, the gateway notifies the client by sending `HTTP 200 Connection Established Response`.

At this point, client can send SSL traffic that is ecapsulated into HTTP message and send to the tunnel's port 80. It will then be decapsulated back into normal SSL connections to be sent to port 443 on the server:

```

Client --------> [SSL]                     [SSL]------------> ()---SSL connection---) ---> [SSL]--> Server:443
                   |                         ^
              Tunnel start            Tunel endpoint (:80)
                   |                         | 
                   v                         |
[HTTP+SSL]->()----HTTP Connection-----)->[HTTP+SSL]

   (Going through port-filtering firewalls)
```

