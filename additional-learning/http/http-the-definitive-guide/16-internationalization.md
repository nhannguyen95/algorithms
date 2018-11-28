There are many different alphabets, and many different ways of encoding characters into bits, we need a standard way to describe and apply the bits-to-character decoding algorithm. This is standardized via **[MIME charset tag](https://www.iana.org/assignments/character-sets/character-sets.xhtml)** (example of some tags: `US-ASCII`, `ISO-8859-1`, etc.).

Each MIME charset tag describes these 2 steps:
- *character encoding scheme*: how to convert bits from a document into a character code (that identifies a particular numbered character in a particular coded character set).
  > For example: The *`iso-8859-6` encoding scheme* maps 8 bit-values of 11100001 into character code 225.
- *coded character set* (tập ký tự được mã hoá): map a character code to a particular element of the coded character set.
  > For example: the *`iso-8859-6` coded character set* maps 65 to Latin letter 'A', 225 to Arabic letter Feh (ف).

The final result will be displayed using fonts and formatting software (handled by the user's graphics display software like browser).

---

In a HTTP request, clients can tell the server which languages they understand and which alphebetic coding algorithms the browser has installed:

```
Accept-Language: fr, en;q=0.8
Accept-Charset: iso-8859-1, utf-8
```

In response, servers send the requested content along with the MIME charset tag:

```
Content-Type: text/html; charset=iso-8859-1
```

---

8 terms about electronic character systems:
- **Character**.
- **Glyph**: chữ tương hình, it's a particular way you draw each character. a character may have multiple glyphs if it can be written different ways.
- **Coded character**: a unique number assigned to a character so that we can work with it.
- **Coding space**: a range of integers that we plan to use as character code values.
- **Code width**: the number of bits in each (fixed-size) character code.
- **Character repertoire**: a particular working set of characters (a subset of all the characters in the world).
- **Coded character set**: a set of coded characters that takes a character repertoire and assigns each character a code from a coding space (it maps numeric character codes to real characters), for example `ASCII`.
  > UCS (Universal Character Set) is a worldwide standards effort to combine all the world's characters into a single coded character set (millions of characters)
- **Character encoding scheme**: an algorithm to encode numeric character codes into a sequence of content bits (*and* to decode them back), there are 3 broad classes of character encoding scheme: fixed width (each coded character is represented with a fixed number of bits, variable width (nonmodel), variable width (model)
  > UTF-8 is a popular encoding scheme designed for UCS, it's a nonmodel, variable-length encoding scheme.
  
---

**Language Tags**: `en`, `de` (German), `en-US` (U.S. English). This information is in `Content-Language` header field:

```
Content-Language: fr
It isn't limited to text documents, can be used for audio, movies, etc.
```

A client can request content in a specific language:

```
Accept-Language: es
```

