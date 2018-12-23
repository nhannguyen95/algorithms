## On-Site Request Forgery (OSRF)

Consider that an application `bank.com` lets you submit items that are viewed by other users, you want to exploit a stored XSS vulnerability by submitting with the content `src=question.gif`. Let say the response is:

```
<img src="/img/question.gif" />
```

You later found out that the application is properly HTML-encoding any ", < and > characters it inserts into the page; your malicious script can't be executed at victims' browser; thus the application is not vulnerable to an XSS attack.

However, you control part of the target of the `<img>` tag. Although you cannot break out of the quoted string, you can *modify the URL* to cause any user who views your message to make an arbitrary on-site GET request, for example to perform a fund to your bank account like this:

```
<img src="https://www.bank.com/func?src=me&des=attacker&ammount=100USD
```

The attack succeeds even if victims take the precaution of disabling JavaScript.

## Cross-Site Request Forgery (CSRF)

The attacker creates an innocuous-looking website that causes the user's browser to submit a request directly to the vulnerable application to perform some unintended action that is beneficial to the attacker:

```
In www.attacker.com/index.html:

<form action="https://www.bank.com/fund..." method="POST">
  <input type="hidden" .. />
</form>

<script>
document.forms[0].submit();
</script>
```

When the victim visits the attacker's site, victim's browser will automatically add the user's cookies for the target domain and submits the form, and the application processes the request in the usual way.

**Important note**: In CSRF, the victim's browser perform a cross-site request from `attacker.com` to `bank.com`, you may wander why this is possible while we have same-origin policy. Answer: same-origin policy prevents `attacker.com` *read the response* from `bank.com` after it processes the `request`, it still allows cross-domain requests and form submissions to be performed ([read more](https://security.stackexchange.com/a/157065)).

### Preventing CSRF Flaws

CSRF vulnerabilities arise because of how *browsers automatically submit cookies back to the issuing web server with each subsequent request*. If a web application relies solely on HTTP cookies as its mechanism for tracking sessions, it is inherently at risk from this type of attack.

To prevent this, the application can provide a unique token for each user. When the user sends any request, the request needs to have that token value inside its URL so that the application can confirm the action and perform the request. There is no way the hacker can get this token and therefore he can’t design the URL.

---

How does Django protect the site against most types of CSRF attacks?:
- https://docs.djangoproject.com/en/2.1/topics/security/#cross-site-request-forgery-csrf-protection
- https://docs.djangoproject.com/en/2.1/ref/csrf/#how-csrf-works
- By default, Django checks for the csrf token in all POST request.

