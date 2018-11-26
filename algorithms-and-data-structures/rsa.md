# Introduction

Each participant in public-key cryptosystem has both a **public key** P and a **secret key** S.

We will see later that each key consists a pair of integer.

We assume that secret keys are kept secret, but public keys can be revealed to anyone or even published.

We denote D as the set of finite-length message, and M is a message in D.

From P, S we construct corresponding function P() and S().

We design P and S such that P() and S() are inverses of each other:
```
M = P(S(M))
M = S(P(M))
```

For the system works, we need to ensure that eventhough everyone knows P and thus P(), they cannot compute the inverse function S() efficiently.

Let denote:
- Alice has public key P<sub>A</sub> and secret key S<sub>A</sub>.
- Bob has public key P<sub>B</sub> and secret key S<sub>B</sub>.

# Bob sends message to Alice

Procedure:
- Bob obtains Alice's public key P<sub>A</sub>.
- Bob computes the **cipher text** C = P<sub>A</sub>(M) from the message M that he wants to send to Alice.
- When Alice receives C, she get the original message M using his secret key S<sub>A</sub>: M = S<sub>A</sub>(P<sub>A</sub>(C)).

Some notes:
- If A wants to send some message to B, A needs to use B's public key for encryption.
- Because only Alice has S<sub>A</sub> and thus can compute S<sub>A</sub>(), Alice is the only one who can compute M from C.

# Alice responds to Bob with digital signature

Now that Alice already received the message from Bob and is about to send a response to Bob. How can Bob tell that response is truly Alice's?

Alice will use her **digital signature**, the procedure:
- Alice computes her digital signature σ from the response message M' using S<sub>A</sub>: σ = S<sub>A</sub>(M').
- Alice sends the message/signature pair (M', σ) to Bob.
- When Bob receives (M', σ), he verify that it originated from Alice by using Alice's public key to verify the equation M' = P<sub>A</sub>(σ). If M' ≠ P<sub>A</sub>(σ), Bob conludes either that the message M' or the digital signature σ was corrupted by transmission errors or that the pair (M', σ) is an attempted forgery.

Notes:
- The above procedure doesn't intend to protect the response message M' from disclosure, everyone that has Alice's public key can all verify that M' is written by Alice.
- To protect the response message M', Alice can carry out the similar procedure as Bob sends message to her: encrypt the pair (M', σ) using P<sub>B</sub> and send the result to Bob. Bob can later decrypt using his secret key.

# The RSA cryptosystem

The procedure for a participant to create his or her own public and secret keys:

- Select randompy 2 large primes p and q (p ≠ q) (maybe 1024 bits each)
- Compute n = pq
- Select a small odd integer e that is relatively prime to ϕ(n) = (p-1)(q-1)
- Compute d as the multiplicative inverse of e, modulo ϕ(n) (i.e. e<sup>-1</sup> ≡ d (mod ϕ(n)).
- Publish the pair P = (e, n) as the participant's **RSA public key**. Construct P(M) = M<sup>e</sup> mod n.
- Keep secret the pair S = (d, n) as the participant's **RSA secret key**. Construct S(C) = C<sup>d</sup> mod n.

We can prove that for any M in D, M = P(S(M)) = S(P(M)).

Assume that P<sub>A</sub> = (e, n) and S<sub>A</sub> = (d, n), Alice keeps S<sub>A</sub> secret and publicizes P<sub>A</sub>. Eventhough everyone knows P<sub>A</sub> = (e, n), they can't compute back S<sub>A</sub> efficiently. Why?

To compute S<sub>A</sub> and thus S<sub>A</sub>(), one needs to compute d from e and ϕ(n). If he can **factor n = pq**, then he can follow the aforementioned procedure to generate all information he needs to know.

Fortunately it's surprisingly difficult to refactor n = pq (if p and q are large primes), and the security of the RSA cryptosystem rests in large part on this. By randomly selecting and multiplying together two 1024-bit primes, we can create a public key that cannot be “broken” in any feasible amount of time with current technology.

However, the statement, that if factoring large integers is hard, then break- ing RSA is hard, is unproven.

# Other RSA variations

To make digital signatures efficiently, there's an approach that combines RSA with a **collision-resistant hash function** h - a function that is easy to compute but for which it is computationally infeasible to find two messages M and M' such that h(M) = h(M').

The value h(M) is short, say, 256-bit.

If Alice want to sign a message M and sends to Bob, the procedure is:
- Instead of creating the digital signature σ = S<sub>A</sub>(M); Alice can first compute the fingerprint h(M) (which is fast to compute) and then encrypt with her secret key to obtain S<sub>A</sub>(h(M)) (which is also fast to compute since h(M) is short). 
- Alice sends (M, S<sub>A</sub>(h(M))) to Bob.
- Bob verifies by comparing h(M) = P<sub>A</sub>(S<sub>A</sub>(h(M))).

Why this works? If an adversary alter M, in order to trick Bob, he needs to compute efficiently a message M' such that h(M) = h(M'). Since h is a collision-resistant hash function, this is computationally infeasible.
