**Web robots** are software programs that automate a series of web transactions without human interaction.

Many robots wander automatically from web site to web site, fetching content, following hyperlinks, and processing the data they find.

These kinds of robots are given colorful names such as "crawlers," "spiders," "worms," and "bots.

Some examples:
- Search-engine robots collect all the documents they find to create search databases.
- Stock-graphing robots issue HTTP GETs to stock market servers to build stock price trend graphs.

---

**Web crawlers** are robots that recursively traverse information webs”

Web crawler initial URLs are called the *root set* => choose a good root set to cover a large portion of the web.

To avoid loop, we need to keep track of visited URLs, trees and hash tables can be used. Overall this requires a lot of memory space since the number of URLs is huge.

2 URLs are **aliases** if the ULRs look different but really refer to the same resource:
- `example.com/index.html` and `example.com:80/index.html`.
- `example.com/index.html` and `example.com/INDEX.HTML`. (*)
- `example.com/~index.html` and `example.com/%7Findex.html`.
- `example.com` and `example.com/index.html`. (**)

Solution: the robots convert URL into a **canonical form**:
- adding :80 to hose name.
- converting all %xx escaped characters into their character equavalents.
- remove # tags.
- etc.

But some cases like (*) and (**), the robot may not be able to convert since it needs to know the information about the server => the solution is not perfect.

Cycles can come from *filesystem link cycles* and *dynamic virtual web spaces*, to avoid those loop (not perfectly, and you can ignore valid content):
- Canonicalizing URLs.
- Do BFS instead of DFS, so that even if the robot goes in to the loop, it can crawl many pages from other sites before it fetches pages from the cycle.
- **Throttling**: Limit the number of pages the robot can fetch from a web site in a period of time.
- Limit URL size: The robot may refuse to crawl URLs beyond a certain length (1KB is common).
- URL/site blacklist: this requires human action.
- Content fingerprinting: compute checksum of content of a page.
- etc.

---

Robots are no different from any other HTTP client program. They too need to abide by the rules of the HTTP specification.

Most of robots implement and send some indentification headers:
- `User-Agent`: tells the server name of the robot making the request.
- `From`: email address of robot's user/admin.
- `Accept`: tells the server what media type are okay to send (to the robot).
- `Referer`: the URL of the document that contains the current request-URL.
- `Host`: if the server uses Virtual Hosting.

---

Misbehaving Robots:
- issue HTTP requests much faster than human => cause intense load against a web server if enter a loop.
- visit old/non-existing URLs when the website changes its content.
- request large, non-sense URLs from websites => reduce performance of the webserver, clutter the server logs.
- access and publish data that the owner doesn't actively intend to reveal it.
- fetch URL content from a gateway application.

---

To better control robots' behaviour => "Robot Exclusion Standard" or **robots.txt**.

Before visiting any URLs, robots fetch the robots.txt resource using HTTP GET method:
- 200 OK: the robot adheres the rule in robots.txt file.
- 404 Not found: the robot assumes there's no rule.
- 401 or 403: access to the site is completely restricted.

Instead of fetching robots.txt before every file access, robots can fetch periodically and cache the results, fetch again if the document is expired.

---

Modern Search Engine architecture build complicated local databases call **Full-text indexes** (ie. a data base that takes a word and immediately tells you all the documents that contain that word) about the web pages around the world and what they contain.

``` 
Documents                Words:       Appear in:
Doc A: We have a         We           A B
Doc B: We know that  ->  have         A
Doc C: One of            a            A
                         that         B
                         one          C
                         of           C
```

Search-Engine crawlers gather up web pages and bring them home, adding them to the full-text index.

At the same time, Search-Engine users issues queries against the full-text index, since web pages changing all the time (because of the amount time it can take to crawl a large chunk of the web), *the full-text index is at best a snapshot of the Web*.

**relevancy ranking** — the process of scoring and ordering a list of search results.
