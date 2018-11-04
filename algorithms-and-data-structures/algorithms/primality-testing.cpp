/* Primality testing

FERMAT'S THEOREM:
If p is prime, then:
a^(p-1) ≡ 1 (mod p) for all a in {1,2..p-1}

This tells us a way to test for primality of a number n:
- If there exists some a in {1,2..p-1} such that
a^(n-1) !≡ 1 (mod p), then n is certainly a composite.
- Surprisingly, the converse almost holds. We can test
whether n satisfies a^(p-1) ≡ 1 (mod p) for a = 2. If
n does, we guess with high probability that n is prime.

The pseudo code for testing primality:

PSEUDOPRIME(n):
    if 2^(n-1) !≡ 1 (mod n)
        return COMPOSITE  // Definitely
    return PRIME  // We hope!

The probability that this program makes an error on a
randomly chosen b-bit number goes to zero as b -> oo.

Using more precise estimates show us that:
- The probability that PSEUDOPRIME(n) == PRIME when
in fact n is a composite is < 1 / 10^20 when n is
a randonly-chosen 512-bit number.
- If n is a randomly-chosen 1024-bit number, the probability
is < 1 / 10^41.

To improve the above test, we use the:
Miller-Rabin randomized primality test.

Read more: CLRS, 3rd, Chapter 31 p.968.

*/