/* 2D Rabin Karp

Problem:
P = Pattern matrix of m x m
T = Text matrix of n x n
Find all occurrences of P in T

2D Rabin Karp is similar to 1D Rabin Karp, let us first
hash P by "expand" the matrix P to 1D, then hash 1D version
of P as normal. That is we assign each character in P
with a unique d^i.

To avoid division when moving right and down, we distribute
d in a 2 x 2 matrix P like this:
1 0
3 2

These number is the i in d^i, this tells us also the position
of character at that position in the hash value, for example
we have P:
4 6
5 2

Then hash(P) = 5 2 4 6
(For simplicity, we don't count modulo for now, modulo should
work similarly)

We compute all hash value of T like follow, assume T is:
3 2 5
4 5 2
2 5 1

The first hash value is T(1,1) = 4 5 3 2,
we want to compute hash value T(1,2) (that is, moving right)
= 5 2 2 5.

This rolling hash is computed similarly as 1D:
- First we subtract values in left column:
4 5 3 2 - 4*10^3 - 3*d^1 = 0 5 0 2
- Then multiple the result with d^(difference of d
between right and left column):
0 5 0 2 * 10 = 5 0 2 0
- In the new position of T(1, 2), 5 is at d^0 and 2 is at
d^2, so hash value of T(1, 2) obtained by adding value of
right column:
5 0 2 0 + 2*10^2 + 5*d^0 = 5 2 2 5.
That's it.

Now it takes O(m) to compute rolling hash values of T 
instead of O(1) like as 1D Rabin Karp. Since the number 
of in and out entries is 2m = O(2m) = O(m)

*/