Web caches are HTTP devices that automatically keep copies of popular documents

---

Caches' benefits:
- reduce redundant data transfers: document that is requested multiple times will be cached at the first server response => subsequent requests can get the copy from the web cache.
- reduce network bottlenecks => pages load faster without more bandwidth: many networks provide more bandwidth to local network clients than to remote servers => having a cache on a fast LAN can boost performance.
- reduce demand on origin servers.
- reduce distance delays.

---

Note: **round-trip delay time (RTD)** or **round-trip time (RTT)** is the length of time it takes for a signal to be sent plus the length of time it takes for an acknowledgement of that signal to be received.

---

If a request arrives at a cache and the requested document is available, we call that a **cache hit**.

Otherwise, the cache forwards the request to the origin server to get the document, we call that a **cache miss**.

---

We say the cache revalidates a document copy if it checks if the document is still fresh from the origin server. To revalidate, the cache sends a small revalidation request to the server, the server responses with 304 Not Modified if the content hasn't changed. The cache learns that the copy is still valid and servers it to clients. We call this a **revalidate hit** or a **slow hit** (it's faster than a cache miss).

The most popular tool to revalidate cache object is the `If-Modified-Since` header, when a cache sends a GET `If-Modified-Since` request to the server, 3 circumstances can happen:
- The server object isn't modified, the server responses 304 Not Modified.
- The server object is modifed, the server responses 200 OK with full content.
- The server object is deleted, the server responses 404 Not Found, the cache deletes the copy.

---

**cache hit ratio**: the fraction of requests that are served from caches (0% - every request is a cache miss, 100% - every request is a cache hit).

The actual cache hit ratio depends on:
- how big the cache is
- how similar the interests of cache users are (do they frequently access same object?)
- how frequently the cache data is changing or personalized
- how the caches are configured

---

Document hit ratio doesn't tell the whole story: Some large objects might be accessed less often but contribute more to overall data traffic, because of their size => people prefer the **byte hit ratio** metric: the fraction of all bytes transferred that were served from cache.

Improving cache hit ratio => optimize overall latency reduction.

Improving byte hit ratio => optimize for band-width savings.

---

**Private caches**: dedicated caches, containing popular pages for a single user. They don't need much horsepower or storage space => can be made small and cheap. Web browsers have cache built-in, popular documents saved in disk and memory of you pc.

**Public caches**: or proxy caches, you can configure your browser to use a proxy cache or even force HTTP requests through caches using *intercepting proxies*.

---

In practice, it often makes sense to deploy a hierarchy of caches: place small, inexpensive caches near the clients and more powerful caches up the hierarchy to hold documents shared by many users.

```
          etc
           |
   more powerful cache
           | 
   _________________
  |                 |
small caches   small caches
  |                 | 
clients          clients

Hopefully most clients will get cache hits on the nearby caches. If not, larger parent caches may be able to handle their requests.
```

Some network architects build complex *cache meshed* instead of simple cache hierarchy. These proxy caches talk to each other in a more sophisticated way, make dynamic cache communication decisions, deciding which parent caches to talk to, or deciding to bypass caches entirely and direct themselves to the origin server. Such proxy caches can be described as content routers , because they make routing decisions about how to access, manage, and deliver content. 

---

## Cache Processing Steps

### 1. Receiving requests

Receiving HTTP requests.

### 2. Parsing

The cache parses the request message into pieces, place the headers in easy-to-manipulate data structures, solves cases if the request contains full absolute URL or partial URL with a `Host` header, etc.

### 3. Lookup

The cache takes the URL and checks for a local copy stored in memory, local disk or nearby computers.

If the document is not available, it will be fetched from the origin server or a parent proxy, or return a failure.

When the origin server sends a document back to the cache, it can attach a HTTP/1.0+ `Expires` header or HTTP/1.1 `Cache-Control: max-age` header:

```
HTTP/1.0+:
Expires: Fri, 05 Jul 2002, 5:00:00 GMT

HTTP/1.1:
Cache-Control: max-age=484200 (seconds since the document is first generated)
OR:
Cache-Control: s-max-age=484200 (for shared caches, overriding max-age)
```

Until a cache document expires, it can serve the document as often as it wants.

Some more header can be attached in server's response to control the cachability:
- `Cache-Control: no-store` or `Pragma: no-cache`: this document is uncachable.
- `Cache-Control: must-revalidate`: revalidate this document on every request.

### 4. Freshness check/Revalidation

If the document is available and has expired (indicating it's time to check), a revalidation with the server might be performed.

> To know whether the document has expired or is still fresh enough to serve, the cache check:
> ```
> is_fresh_enough = (age < freshness_lifetime)
> ```
> 
> The basic computation of age is simple (behind the scene there are details for clock skew and network delays):
> ```
> age = age_when_document_arrived_at_our_cache (*) (since the server response that contains the document is issued)
>     + how_long_copy_has_been_in_our_cache
> (*): this can be computed using Age or Date headers in the response message
> ```
>
> freshness_lifetime can be computed from `Cache-Control: max-age` or `Expires` header in the server response

If the revalidation shows the document has changed, the cache gets a new copy of the document, stores it in place of the old data.

If revalidation shows the content has not changed, the cache only gets new headers, including a *new expiration date*, and updates the headers in the cache.

The cache can revalidate with the server using *Conditional Methods* (attached in a GET request) (these methods help caches avoid always fetching data from servers whenever the document expired and only fetch when the document actually changed, because the document expired doesn't mean it's currently different from its version stored on the server, it's just indicate that it's time to check):
- `If-Modified-Since` (the most common cache revalidation header)
- `If-None-Match`: return new document if on-server tags document differ from tags in this header (eg. "v2.5" and "v2.6").

> The If-Modified-Since header works in conjunction with the Last-Modified server response header. The origin server attaches the last modification date to served documents. When a cache wants to revalidate a cached document, it includes an If-Modified-Since header with the date the cached copy was last modified.

> The If-None-Match header can be used instead of the If-Modified-Since if some documents may be rewritten periodically but actually often contain the same data; or they maybe changed but it's not that important to update the cache.

### 5. Response Creation

Because we want the cached response to look like it comes from the origin server, the caches will use the *cached server response headers* for the response headers. These base headers are then modified an augmented by the cache.

Note that the cache shouldn't modify `Date` header which represents the data of the object when it was originally generated at the origin server.

### 6. Sending

The cache sends response back to the server

### 7. Logging

After each cache transaction is complete, the cache updates statistics like cache hit and miss, inserts an entry into a log file showing the request type, URL and what happened.

---

Note: all HTTP dates and times are expressed in Greenwich Mean Time (GMT).







