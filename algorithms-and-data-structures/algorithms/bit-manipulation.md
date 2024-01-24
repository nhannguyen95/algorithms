## Problems
- https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

## Theory

To multiply x by 2: 

```
x << 1
```

To divide x by 2:

```
x >> 1
```

To set the i-th bit of x:

```
x |= (1 << i)
```

To check if the i-th bit of x is on:

```
if (x & (1 << i)) == 0 then i-th bit is off
```

To clear the i-th bit of x:

```
x &= ~(1 << i)
```

To toggle the i-th of x:

```
x ^= (1 << i)
```

To get the value of the least significant bit of x that is on:

```
x & (-x)

Example:
    x = 10100
    -x = ~x + 1 (2's complement) = 01011 + 1 = 01100
    x & -x = 00100
```

To obtain the remainder of x when it is divided my N (N is a power of 2)

```
x & (N - 1)
```

To determine if x is a power of 2 (x > 0):

```
(x & (x − 1)) == 0
```

To clear the least significant bit of x that is on:

```
x &= (x - 1)
```

To set the least significant bit of x that is off:

```
x |= (x + 1)
```

To clear the least significant consecutive run of 1s in x (starting from 0):

```
x &= (x + 1)

For example:
x = 10111
x + 1 = 11000
=> x & (x + 1) = 10000
```

To set the least significant consecutive run of 0s in x (starting from 0):

```
x |= (x - 1)
```

To turn on all bits in a set of size n:

```
(1 << n) - 1
```

To enumerate all proper subsets of a given bitmask (e.g. proper subsets of `10010` are {`10010`, `10000`, `00010`}):

```
for(int subset = bitmask; subset; subset = (bitmask & (subset - 1)))
    cout << subset
```
