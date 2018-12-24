**What is clickjacking (UI Redress)?**

Clickjacking attacks are designed to allow a third-party site to induce user actions on another domain *even if anti-CSRF tokens are being used*.

The 3rd party site here can be the web site of the attacker:
- First he embed the website that he wants to attack using the `iframe` tag.
- Then he overlays the iframe with his own design to induce victims (say) to click to some button. The victims will think they are just clicking a normal button on the attacker's site, but in fact that button overlays a different button of the site that is being attacked (this button may be a fund transfer button from a bank site).

The reason this attack succeeds, where a pure CSRF attack would fail, is that the anti-CSRF token used by the application (if there's any) is processed in the normal way.

---

**Preventing clickjacking**

The developers can prevent the site from being framed by using the `X-Frame-Options` response header.

---

How Django protects the app against clickacking attack?
- https://docs.djangoproject.com/en/2.1/topics/security/#clickjacking-protection
- https://docs.djangoproject.com/en/2.1/ref/clickjacking/#clickjacking-prevention
