/* Rabin-Karp algorithm for string-matching problem
https://nhannguyen95.github.io/rabin-karp-algorithm/

Let assume P and T are in Σ* where Σ = {0, 1, .., 9},
so that each character is a decimal digit.
(In general case, we can represent each character is
a digit in radix-d notation, where d = |Σ|).

Denote decimal number p = string_to_decimal(P)
and t(s) = string_to_decimal(T[s+1..s+m]), s = 0..n-m.

So P = T[s+1..s+m] if p = t(s).

We can compute p in Θ(m).
We can compute all t(s) in Θ(n-m+1) (running hash/rolling hash):
t(s+1) = 10(t(s) - 10^(m-1)T[s+1]) + T[s+m+1]
We can compare p and t(s) in O(1) time.

So running time:
T(n) = 2*Θ(m)    // compute p and t(0)
     + O(logm)   // compute 10^(m-1)
     + O(n-m+1)  // compute all t(s >= 1) and match with p
     = O(n+m)
(This running time has not solved the problem of spurious hit
as we will see shortly)

If p and t(s) are large, we can compute them modulo
a suitable modulus q.
(In general, we choose q as a prime number such that |Σ|q
fits within one computer word).

This solution is not perfect:

- To determine P = T[s+1..s+m], we check if:
t(s) = p (mod q)
BUT THIS DOES NOT IMPLY THAT:
t(s) = p.

- But if t(s) ≠ p (mod q), then we have t(s) ≠ p.

If t(s) = p (mod q) and t(s) ≠ p, we can this a spurious hit.

To solve this problem, whenever we have a hit (i.e. t(s) = p (mod q)),
we need to check explicitly if P = T[s+1..s+m].

This makes the Rabin Karp algorithm have the worst case of
Θ((n-m+1)m) (happen when we have a hit at all n - m + 1 position
in T).

But in many application, Rabin Karp yields a good running
time because:
- If t(s) ≠ p (mod q), we can determine immediately this
is an invalid match because t(s) ≠ p, avoid unnecessary
comparisons as in naive problem.
- In pratice, we expect only a few hit in total, maybe some
constant c of them. Running time in this case:
O((n-m+1) + cm) = O(n+m)

*/