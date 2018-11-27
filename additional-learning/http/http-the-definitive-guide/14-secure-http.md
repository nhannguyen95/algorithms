HTTPs provides a stronger scheme to secure HTTP transactions using digital cryptography, *data can be read only from sender and receiver*.

HTTPs provides:
- Server authentication (clients know who they're talking to)
- Client authentication (servers know who they're talking to)
- Data Integrity
- Encryption (no fear of eavesdropping)
- Efficiency (a fast-enough algorithm)
- etc.

## Digital Cryptography

Cryptography is the art and science of *encoding and decoding* messages. It is based on **ciphers**: algorithms (or coding schemes) to encode a **plaintext** to **ciphertext** and an accompanying way to decode the ciphertext later.

> For example: 3-character rotation cipher (rot3) used by Julius Caesar.

In practice, since the cipher (the encoding and decoding algorithm) is public to everyone, it needs a **key** parameter so that even one knew how the scheme works (or steal it), he wouldn't be able to make the decoder work. (In reality, having the logic of the algorithm can sometimes help to crack the code, because the algorithm logic may point to patterns that can be exploited).

> For example: rot3 can be parameterized by rotN, with N is key.

With the advent of digital computation, we can make ciphers complicated and have very large keys. The longer the key, the harder it is to crack the code by randomly guessing keys.

Let denote P = plaintext, E = encoding function with key e, C = ciphertext, D = decoding function with key d, we have:

```
C = E(P, e)
P = D(C, d)
```

### Symmetric-Key Cryptography (Mã hoá khoá đối xứng)

Digital cipher algorithms are called symmetric-key ciphers if they use the same key value for encoding and decoding: *e = d*.

Some popular symmetric-key cipher algorithms are DES, Triple-DES, RC2, RC4.

One disadvantage of symmetric-key ciphers is that both the sender and receiver have to have a shared secret key before they can talk to each other. Say that we have N nodes, and each node wants to talk securely with all the other N-1 nodes, there are roughly N<sup>2</sup> total secret keys: ad administrative nightmare.

### Public-Key Cryptography (Mã hoá khoá công khai)

Public-key cryptography uses 2 asymmetric keys: one for encoding messages for a host, and another for decoding the host's messages. The encoding key is publicly known to the world (thus the name), thus everyone can send message to the host; and only the host knows the private decoding key, so only the host can decode/read messages sent to it.

The challenge of any public-key asymmetric cryptosystem is to make sure no bad guy can compute the secret/private key even if he has all of the following clues:
- The public key (which anyone can get since it's public)
- A piece of ciphertext (obtained by snooping the network)
- A message and its associated ciphertext (obtained by running the encode on any text)

One popular public-key cryptosystem that meets all these needs is the [RSA algorithm](algorithms-and-data-structures/rsa.md).

### Digital signatures

Digigal signatures are special cryptographic checksums attached to a message, they have 2 benefits:
- Prove that the author wrote the message.
- Prevent message tampering.

Digital signatures often are generated using asymmetric, public-key technology like [RSA algorithm](algorithms-and-data-structures/rsa.md)

### Digital certificates

When you establish a secure web transaction through HTTPs, modern browsers automatically fetch the digital certificate for the server being connected to (if the server does not have a certificate, the secure connection fails), this includes:
- Name and hostname of the website.
- Public key of the website.
- Name of the signing authority.
- Signature from the signing authority.

When the browser receives the certificate, it checks the signing authority.

Identifying information, verified and signed by a trusted organization. If it is a public, well-respected signing authority, the browser will already know its public key (browsers ship with certificates of many signing authorities preinstalled), so it can verify the signature. If the signing authority is unknown, the browser isn't sure if it should trust the signing authority and usually displays a dialog box for the user to read and see if he trusts the signer. The signer might be the local IT department, or a software vendor.

The idea for a website to have a certificate is that clients whant to know thay they are talking to the origanization they think they are talking to when they're for example posting their credit card information. That is to say, server certificates, signed by a well-known authority, help clients assess how much they trust the server before sending the credit card or personal information.

## HTTPS

HTTPs combines HTTP protocol with a powerful set of symmetric, asymmetric, and certificate-based cryptographic techniques, making it very secure and flexible and easy to administer.

HTTPs is just HTTP sent over a secure transport layer. Instead of sending HTTP messages unencrypted to TCP and accross the world-wide Internet, HTTPs sends the HTTP messages first to a security layer that encrypts them before sending them to TCP.

Today, the HTTP security layer is implemented by SSL and its modern replacement TLS (they are similar and we can use "SSL" to mean either SSL or TLS).

**Secure Transport Setup**:
- The client performs a HTTPs request to the server, for example `https://www.example.com/transactions`, it first open a connection to port 443 (the default port for HTTPs) on the web server.
- Once the connection is established, the client and server perform the **SSL handshake** to initialize the SSL layer, negotiating cryptography parameters and exchanging keys.
- Once the SSL initialization is done, client can send request messages to the security layer (they are of course encrypted before being sent to TCP):
  ```
  Request:
  Client -->[Encoding]-----TCP connection---->[Decoding]--> Server
  
  Response:
  Client <--[Decoding]<----TCP connection-----[Encoding]<-- Server
  ```

**SSL Handshake**: Client and server:
- Exchange protocol version numbers.
- Client sends cipher choices and requests server's certificate to server, server sends back chosen cipher and its certificate.
- Authenticate the identity of each side.
- Generate temporary session keys to encrypt the channel.

---

SSL is a *complicated binary* protocol, there are several open source libraries exist to make it easier to program SSL clients and servers such as OpenSSL

---

**Problem with proxies**: If clients encrypt the HTTP message and the message is sent to a proxy, the proxy no longer has the ability to read the HTTP header (since it is encrypted) => it won't know where to forward the request.

To make HTTPs work with proxies, we can use HTTPs SSL tunneling protocol: the client first tells the proxy the secure host and port to which it wants to connect using HTTP:

```
CONNECT ww.example.com:443 HTTP/1.0
User-agent: Mozilla/1.1N
<raw SSL-encrypted data follow here..>
```

The proxy evaludate the request and make a connection to the destination server, if successful, it returns:

```
HTTP/1.0 200 Connection established
Proxy-agent: Netscape-Proxy/1.1
```
