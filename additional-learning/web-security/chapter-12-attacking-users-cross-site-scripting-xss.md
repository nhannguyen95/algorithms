This is a client-side attacking technique.

## Reflected XSS

The server that hosts the web aplication takes the parameter from the URL that is requested from the client (user) and simply render the parameter's content back to the user:

```
http://www.example.com/error.html?msg=<script>alert(1);</script>
```

And we say the site is vulnerable to XSS.

An attacker can [exploit this vulnerability](images/reflected-xss.png)
