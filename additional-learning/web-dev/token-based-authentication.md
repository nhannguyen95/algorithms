## The most basic Token-based authentication

Client exchanges its credentials (like username, password, etc.) for a token.

This token is usually stored in [`localStorage`](https://www.quora.com/What-is-the-difference-between-sessionstorage-localstorage-and-Cookies).

Whenever the client performs authorized actions, it can send this token to the server so that the server can verify the client. The token is attached in the request header:

```
Authorization: Token c0329145a7b076835688ef1e246c9f85016463c8
```

This token can be expired or newly-created when the user logins again.

In the most basic mechanism token-based authentication:
- The token is a randomly-generated string.
- The token is saved in the server's database (maps 1-1 with the user's id), the verifying procedure therefore looks up the database to find the corresponding user.

In an advanced mechanism _(is this Json Web Token?)_:
- The token is generated based on user's information (like username, password, email etc.) and the token's metadata (expire_date, issue_at, etc.)
- The client's credential is encrypted into the token itself, therefore the server doesn't need to store the token in the db but perform an encryption algorithm to retrieve back the user's credentials.

References:
- https://www.youtube.com/watch?v=xgkNe6R4Un0
- https://medium.com/@sherryhsu/session-vs-token-based-authentication-11a6c5ac45e4
- https://www.youtube.com/watch?v=BxzO2M7QcZw
- https://www.youtube.com/watch?v=wupTjPTvovI
