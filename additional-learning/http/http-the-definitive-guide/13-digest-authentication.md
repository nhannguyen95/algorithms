Digest authentication tries to fix security flaws in basic authentication.

Digest authentication is not the most secure protocol possible: there are TLS ans HTTPs.

Fact: Digest authentication still hasn’t gained major traction. The Basic authentication is much simpler and combined with SSL still more secure than the Digest authentication.

## How Digest Authentication works?

**Step 1**: First, the client asks for a page that requires authentication without providing username and password:

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
nonce="5eb63bbbe01eeed093cb22bb8f5acdc3"  // nonce save us from replay attacks since its value is changed frequently,
                                           it ensure that each request is unique thus an attacker can't replay a
                                           request in a different context. The client will send this value back to
                                           the server later, so the server need to save this in database such as
                                           session of this particular client.
                                           RFC 2617 suggests nonce formulation:
                                           BASE64(time-stamp H(time-stamp ":" ETag ":" private-key))
                                           (private-key is data known only to the server)
```

**Step 2**: The client's browser opens a dialog for entering username and password, with a response which is computed as folow:

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
    
  - The client then send the request again to the client with authentication header:
  
    ```
    GET /dir/amy.jpeg HTTP/1.1
    Host: www.example.com
    Authorization: Digest username="Amy"
                          realm="Family Pictures"
                          nonce="5eb63bbbe01eeed093cb22bb8f5acdc3"
                          uri="/dir/any.jpeg"
                          qop="auth"
                          nc=00000001        // The request counter
                          cnonce="0a4f113b"  // nonce value that client generate (read more about these at https://code-maze.com/http-series-part-4/)
                          response="6629fae49393a05397450978507c4ef1"

    cnonce is there to provice symmetric authentication: allow the client to authenticate the server,
    the server generates a correct response digest based on correct knowledge of the shared secret information,
    it then returns this digest to the client in the Authorization-Info header.
    ```
  
**Step 3**: The server receives the request from the client, its get needed information from HTTP request's header and its own database (username, thus password, and nonce value) to perform a similar hashing procedure as the client's and match with client's response. If the result is matched, then it returns response with information for the next client's queries in the `Authorization-Info` header:

```
HTTP/1.1 200 OK
Authorization-Info: nextnonce=...
                    qop="auth"
                    cnonce="0a4f113b"
                    rspauth=...  // symmetric authentication mentioned in step 2
```

---

From previous sections, we can see:

Some advantages of Digest authentication:
  - It never sends credentials in clear.
  - Prevents replay attacks.
  - Guard against message tampering.

Disadvantages:
- Vulnerable to Man in the Middle Attack (https://stackoverflow.com/a/3690823)
- A hacker can capture client's request and perform a dictionary attack on password against nconce/response pairs.
- Vulnerable to Chosen Plaintext Attacks: assume that a malicious proxy can intercept the response from the server to the client and thus can impersonate the server to decide the nonce value that client will use to generate the response, this may make the cryptanalysis of the response easier. This is called chosen plaintext attack. With this knowledge, a hacker can combine Dictionary Attacks and Chosen Plaintext Attacks to build a set of predetermined nonces and a dictionary of corresponding password/response, he then can intercept the network and sends to the user a predetermined nonce and perform dictionary attack on the client's reponse.
- Prevents the use of strong password hashing algorithms when storing passwords (since either the password, or the digested username, realm and password must be recoverable for hashing, since the digest authentication mechanism compares the user response to what is stored internally by the server)

Read more: https://en.wikipedia.org/wiki/Digest_access_authentication
