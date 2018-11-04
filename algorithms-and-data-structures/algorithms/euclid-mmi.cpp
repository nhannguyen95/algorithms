/* Modular Multiplicative Inverse - Extended Euclid's algorithm

Read this first:
what-to-prepare/algorithms/euclid-gcd.cpp

Previously given a and b, we compute d = gcd(a, b).
Now we want to compute also x and y such that:
d = gcd(a, b) = ax + by (x and y maybe 0 and negative)

It's very similar to the Euclid algorithm to compute
gcd. Instead of ony returning d, we now return the triplet
(d, x, y):

(d , x , y ) = gcd(a, b)
(d', x', y') = gcd(b, a mod b) - Result from the recursive
call

We have d = d'
<=> ax + by = bx' + (a mod b)y'
<=> ax + by = bx' + (a - b*floor(a/b))y'
<=> ax + by = ay' + b(x' - y'*floor(a/b))
So we can compute x and y recursively if we choose:
x = y'
y = x' - y' * floor(a / b)

The pseudo code:

EXTENDED-EUCLID(a, b)
    if b == 0 return (a, 1, 0)
    (d', x', y') = EXTENDED-EUCLID(b, a mod b)
    (d, x, y) = (d', y', x - y' * floor(a / b))
    return (d, x, y)

Time complexity: same as EUCLID O(logb)

If we have gcd(a, b) = 1 (a and b are relatively prime), then:
ax + by = 1
<=> ax = 1 - by AND by = 1 - ax
<=> ax ≡ 1 (mod b) AND by ≡ 1 (mod a)
<=> x is multiplicative inverse of a, modulo b
AND y is multiplicative inverse of b, modulo a


*/