HTTP transactions are stateless. Each request/response happens in isolation.

Web servers often want to keep track of who they are talking to, rather than treating all requests as anonymous clients.

To identify users:
- HTTP headers that carry information about user.
- Client IP address.
- User login.
- Fat URLs: embedding identity in URLs.
- Cookies.

## HTTP Headers

`From`: User's email address (few browsers send this).

`User-Agent`: User's browser software (this doesn't help much with user identity).

```
User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)
```

`Referer`: Page user came from by following link (this tells what page the user previously visited).

`Client-ip`: extension header (not part of HTTP standard).

`X-Forward-For`: extension header.

`Cookie`: extension header.

## Client IP Address

This works if each user has a distinct IP address, and if the IP address rarely changes.

While the client IP address typically is not present in the HTTP request headers, web servers can find the IP address of the other side of the TCP connection carrying the HTTP request.

Limitations:
- IP address describe the computer being used, not the user.
- Many Internet services providers dynamically assign IP addresses to users when they login.
- To enhance security and manage scarce addresses, many users browse the Internet through **Network Address Translation (NAT)** firewalls. These NAT devices obscure the IP addresses of the real clients behind the firewall, converting the actual client IP address into a single, shared firewall IP address (and different port numbers).
- HTTP proxies and gateways typically open new TCP connections to the origin server. The web server will see the IP address of the proxy server instead of that of the client. Some proxies attempt to work around this problem by adding special `Client-ip` or `X-Forwarded-For` HTTP extension headers to preserve the original IP address. But not all proxies support this behavior.

## User Login

Rather than passively trying to guess the identity of a user from his IP address, a web server can explicitly ask the user who he is by requiring him to authenticate (log in) with a username and password.

To pass username information:

```
GET /index.html HTTP/1.1
Host: www.example.com
Authorization: username password
```

After sending the request, web browsers can store the credential information and automatically issue them when asked.

## Fat URLs

Fat URLs = URL + some user state information added to the start or end (can be the ID).

A unique ID is generated the first time a user visits the website, it is added to the URL. Whenever the server receives request for a fat URL, it can look up the state with that user ID and rewrites all outgoing hyperlinks to make them maintain that ID.

Problems with Fat URLs:
- Ugly
- Can't share
- Breaks caching
- Extra server load (servers need to rewrite HTML pages to fatten URLs)
- Users may lose their progress if they don't follow the premodified links.

## Cookies

The basic idea of cookies is to let the browser accumulate a set of server-specific information, and provide this information back to the server each time you visit.

Because the browser is responsible for storing the cookie information, this system is called **client-side state**.

2 types of cookies:
- **Session cookies**: a temporary cookie that keeps track of an user settings and prefs when navigating a site, and is deleted when he exits the browser. Session cookies has no Expires or Max-Age parameters.
- **Persistent cookies**: persistent cookies can live longer, *they are stored on disk and survive browser exits and computer restarts*, they are often used to retain a configuration profile or login name for a site that a user visits periodically.

The first time an user visits a website, the web server doesn't know anything about him. The web server expects that this user will come again, so it wants to assign a unique cookie into the user so it can identify him in the future by using `Set-Cookie` or `Set-Cookie2` HTTP response extension headers:

```
200 OK HTTP/1.1
Set-Cookie: session_id=xxx; expires = abc
Set-Cookie: another=yyy (another cookie is set)
```

The client browser store this information received by this server and will attach them in the `Cookie` request header for every future requests to the same server:

```
GET ...
Cookie: session_id=xxx; another=yyy
```

2 versions of cookies:
- Version 0 (Netscape version): is used widely, use `Set-Cookie` header.
- Version 1 (RFC 2965): use `Set-Cookie2`.

Some version 0 cookies' attributes:
- name
- value
- domain: a server generating a cookie can control which sites get to see that cookie (or which sites the browser sends this cookie to) by using this attribute.
- path: the path prefix in the domain associated with the cookie, lets you associate cookies with portions of web sites.
- expires
- secure: a cookie will be sent only if HTTP is using an SSL secure connection.

