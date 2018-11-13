URLs describe resources by where they are located.

URNs describe resources by their names.

---

URLs can direct you to resources available through protocols other than HTTP:
- a person's mail account `mailto:president@whitehouse.gov`.
- File Transfer Protocol (FTP): `ftp://ftp.books.com/pub/http.xls`

Broswers can often use other applications to handle specific resources. For example it can open email application to handle the first URL.

---

Most URL schemes base their URL syntax on this 9-part general format:

```
<scheme>://<user>:<password>@<host>:<port>/<path>;<params>?<query>#<frag>
```

- params: give applications the input they need in order to talk to the server correctly, `http://www.joes-hardware.com/hammers;sale=false/index.html;graphics=true`
- query: used to pass parameters to active application (such as databases, search engines etc.)
- frag: a name for a piece or part of the resource. Note that HTTP servers generally deal only with only entire objects, so your browser will get the entire resource from the server, then it uses the fragment to display the part of interest; thus the framement is NOT sent to the server.

---

Say you have a HTMl document that contains relative URLs, the browser can find their **Base URL** (to forms their absolute form) in some ways:
- We explicitly provide the Base URL in the resource, an html document may include a <BASE> tag to define the Base URL for all relative URLs in that document.
- If no explicit Base URL is provided, the browser extracts it from URL of the resource (the HTML document).

---

URLs are wanted to be designed as *readable*, URLs are permitted to contain only universally safe characters (a defined set of unreserved characters):

```
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9 - _ . ~
```

To support reserved/unsafe characters (those have speacial meaning inside of a URL: `! * ' ( ) ; : @ & = + $ , / ? % # [ ]`), an encoding mechanism is used. This encoding mechanism escapes the character by the percent sign `%` followed by 2 hexadecimal digits that is the ASCII code of the character.

```
For example to escape SPACE character:
ASCII code of SPACE character: 32 = 0x20
=> Encoded string: %20
```

RFC 3986 does not define according to which character encoding table non-ASCII characters, they propose to use the UTF-8 character encoding table for them.

Once all unsafe characters have been encoded, the URL is in a **canonical form** that can be shared between applications.

---

Some scheme formats:

|Scheme|Description|
|-|-|
|http|`http://<host>:<port>/<path>?<query>#<frag>`|
|https|Same as http|
|mailto|`mailto:<RFC-822-addr-spec>`|
|ftp|`ftp://<user>:<password>@<host>:<port>/<path>;<params>`|
|file|`file://<host>/<path>`, e.x `file://OFFICE-F5/books/http.pdf`|

---

URLs are addresses of resources, not true names. It provides you with the name of a specific server on a specific port, we you can find the resource.

Thus its downfall is when the resource is moved, the URL is no longer valid.

To address this issue, uniform resource names (URNs) standard is being developed, but for the foreseeable future, URLs are the way to name resources on the Internet.
