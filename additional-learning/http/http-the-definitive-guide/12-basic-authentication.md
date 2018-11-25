Authentication means showing some proof of your identity.

---

**HTTP's naive challenge/response framework**: Whenever a web application receives an HTTP request message, instead of acting on the request, the server can respond with an "authentication challenge," challenging the user to demonstrate who she is by providing some secret information (username/password).

---

**Basic authentication**

HTTP defines 2 official authentication protocols: **basic authentication** and **digest authentication** (chapter 13).

4 phases of basic authentication:
- Client *requests*:

```
GET /family/jeff.jpg HTTP/1.0
```

- Server *challenges*:

```
HTTP/1.0 401 Authorization Required (rejected status)
WWW-Authenticate: Basic realm="Family" (web servers group protected documents into security realms . Each security realm can have different sets of authorized users.)
```

- *Authorization*: client retries with credentials (the browser opens a dialog asking for username:password)

```
GET /family/jeff.jpg HTTP/1.0
Authorization: Basic base64-username-and-password (username and password are joined together by a colon :, then converted to base-64 encoding
```

- *Success*:

```
HTTP/1.0 200 OK
Content-type: image/jpeg
...<image data included>
```

---

Authentication also can be done by intermediary proxy servers. Some organizations use proxy servers to authenticate users before letting them access servers, LANs, or wireless networks.

---

The Security Flaws of Basic Authentication:

- Base 64-encoded username and password can be easily decoded => send all your HTTP transactions over SSL encrypted channels, or use more secure authentication protocol like digest authentication.
- Even if username and password encoding scheme is difficult to decode, a 3rd party can capture/steal it in the middle and send to the origin server to gain access over time (since the digest is unchanged if the password is unchanged).
- A user can be led to believe that he is connecting to a valid host protected by basic authentication when, in fact, he is connecting to a hostile server or gateway, the attacker can request a password, store it for later use, and feign an error.

That is to say, basic authentication is still useful in situations where privacy is desired but not necessary.



