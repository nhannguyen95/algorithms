Details: http://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/

```
Let's say 2 way partition for simplicity:

Given an 0, 1 array; this algorithm arranges 0s to left, 1s to right
(or vice versa):

Input: 0 1 1 0 0 1
Output: 0 0 0 | 1 1 1


Generally, given an arbitrary array, it can divide the array into
two set of elements that satisfy a couple of complementary conditions:

Output: X | Y
with elements in X <= some value,
 and elements in Y > that value.

```
