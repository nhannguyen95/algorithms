Digest authentication tries to fix security flaws in basic authentication.

Digest authentication is not the most secure protocol possible: there are TLS ans HTTPs.

Digest authentication never sends credentials in clear. In this scheme, both client and server keep the secret password, client use a digest function to hash the password and sends it to server, server can hash the secret password and match it with the digest it received from the client.

---

Disgest functions are designed to be *one-way*, meaning that given the output digest, one cannot find the input that digest(input) = output in reasonable time.

One popular digest function is MD5 (Message Digest #5), it converts any arbitrary sequence of bytes (characters) of any length into a 128-bit digest. The 128 bits of MD5 output often are written as 32 hexadecimal characters:

```
C1A5298F939E87E8F962A5EDFC206918
```

Another popular digest function is SHA (Secure Hash Algorithm).

**Digest functions** are sometimes called **cryptographic checksums**, **one-way hash functions**, or **fingerprint functions**.

---

One-way digests save us from having to send passwords in the clear, but obscured passwords alone do not protect us from man in the middle attack (ie. some bad guy can capture the digest and relay it to the server).

To prevent such relay attacks

---

## Digest Calculations

The heart of digest authentication is the one-way digest of the mix of public information, secret information, and a time-limited nonce value.

Digest Algorithm Input Data:
- A one-way hash function H(d) and digest KD(s, d), s stands for secret, d stands for data.
- A chunk of data containing security information, including the secret password, called A1.
- A chunk of data containing nonsecret attributes of the request message, called A2.

...

