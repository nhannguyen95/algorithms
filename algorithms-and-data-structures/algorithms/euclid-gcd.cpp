/* Greatest Common Divisor - Euclid's algorithm

Input: a, b not both zero.
Output: gcd(a, b) > 0

Some properties:
gcd(a, b) = gcd(g, a)
gcd(a, b) = gcd(-a, b)
gcd(a, b) = gcd(|a|, |b|)
gcd(a, 0) = |a|
gcd(a, ka) = |a| for any k in Z

Euclid's algorithm for computing gcd(a, b) relies on the
following theorem:
gcd(a, b) = gcd(b, a mod b)

Proof: We prove gcd(a, b) and gcd(b, a mod b) divides each other:

- gcd(a, b) | gcd(b, a mod b): denote d = gcd(a, b), thus d | a
and d | b. Since by definition, a mod b = a - kb => d | (a mod b)
=> d | a and d | (a mod b) => d | gcd(b, a mod b)

- gcd(b, a mod b) | gcd(a, b): denote d = gcd(b, a mod b), thus
d | b and d | (a mod b). Since a = kb + (a mod b) => d | a
=> d | (a mod b) and d | a => d | gcd(b, a mod b)

So we have the pseudo-code for the Euclid's algorithm:

EUCLID(a, b) = GCD(a, b)
    if b == 0 return a
    return EUCLID(b, a mod b)

Time complexity: O(logb)

Finding Least Common Multiple (LCM) is simple:

LCM(a, b)
    return a / GCD(a, b) * b

The GCD/LCM of more than 2 numbers can be found via multiple calls
of GCD/LCM of 2 numbers e.g. GCD(a, b, c) = GCD(a, GCD(b, c)).

*/