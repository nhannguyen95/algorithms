Same-Origin Policy: content received from one site is allowed to read and modify other content received from the same site but not allowed to access content received from other sites.

If this policy does not exist, and an unwitting user browsed to a malicious website, script code running on that site could access the data and functionality of any other website also visited by the user.

For example: 
The url that returns your credit card information under json format on bank.com is https://bank.com/card-info.
When you’re at bank.com and perform a GET request to that URL, you will receive back you card information since the the request comes from the same origin back.com.
Assume that at the malicious website malicious.com, there is a script that automatically performs the GET request to that URL whenever you visit the website (the script is performing a cross-origin HTTP request). The data that is returned to the hacker can be empty, since the GET request has the different origin (malicious.com) from bank.com, the SOP takes effect. The hacker thus fails to hijack your credit card data.
Note: bank.com can allow the hacker’s site to perform the GET request to successfully get your card data by adding the site to ‘Access-Control-Allow-Origin’ (i.e. a list of origins that is authorized to make cross-site HTTP requests to bank.com).

Some key features of SOP:
A page residing on one domain can cause an arbitrary request to be made to another domain (for example, by submitting a form or loading an image). But it cannot itself process the data returned from that request.
A page residing on one domain can load a script from another domain and execute this within its own context. This is because scripts are assumed to contain code, rather than data, so cross-domain access should not lead to disclosure of any sensitive information.
A page residing on one domain cannot read or modify the cookies or other DOM data belonging to another domain.

An ‘Access-Control-Allow-Origin’ header will be included the the response headers:

```
▼ Response Headers
   Access-Control-Allow-Origin: *  # controlled by CORS (Cross Origin Resource Sharing)
   Allow: GET, POST, HEAD, OPTIONS
   Content-Length: 156
```
