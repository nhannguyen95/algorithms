Digest authentication tries to fix security flaws in basic authentication.

Digest authentication is not the most secure protocol possible: there are TLS ans HTTPs.

Fact: Digest authentication still hasn’t gained major traction. The Basic authentication is much simpler and combined with SSL still more secure than the Digest authentication.

## How Digest Authentication works?

First, the client asks for a page that requires authentication without providing username and password:

```
GET /dir/amy.jpeg HTTP/1.1
Host: www.example.com
```

Then, the server responses with 401 Unauthorized response code, providing the authentication realm, qop (quality of protection) and a server-generated nonce (number that is used only once):

```
HTTP/1.1 401 Unauthorized
WWW-Authenticate: Digest
realm="Family Pictures"
qop="auth,auth-int"
nonce="cmFuZG9tbHlnZW5lcmF0ZWRub25jZQ"  // nonce save us from replay attacks since its value is changed frequently,
                                           it ensure that each request is unique thus an attacker can't replay a
                                           request in a different context. The client will send this value back to
                                           the server later, so the server need to save this in database such as
                                           session of this particular client.
```

The client's browser opens a dialog for entering username and password, with a response which is computed as folow:

  - Digest Authentication saves us from having to send passwords in the clear
(like basic authentication) by hashing information before sending to the
server using Digest Functions.

Disgest functions are designed to be *one-way*, meaning that given the
output digest, one cannot find the input that digest(input) = output in
reasonable time.

One popular digest function is MD5 (Message Digest #5), it converts any
arbitrary sequence of bytes (characters) of any length into a 128-bit digest.
The 128 bits of MD5 output often are written as 32 hexadecimal characters:

C1A5298F939E87E8F962A5EDFC206918

(MD5 is one of the fastest-to-compute digest functions)

Another popular digest function is SHA (Secure Hash Algorithm).

**Digest functions** are sometimes called **cryptographic checksums**,
**one-way hash functions**, or **fingerprint functions**.

```
// HA1 stores security information
HA1 = MD5(username:realm:password)                   if algorithm = md5
    = MD5(MD5(username:realm:password):nonce:cnonce) if algorithm = md5-sess

// HA2 stores nonsecret attributes
HA2 = MD5(method:requestURI)                 if qop = "auth" or unspecified
    = MD5(method:requestURL:MD5(entitybody)) if qop = "auth-int"
    
response = MD5(HA1:nonce:HA2)                   if qop = unspecified
         = MD5(HA1:nonce:nonceCount:cnonce:HA2) if qop = "auth" or "auth-int"
```
  - 
