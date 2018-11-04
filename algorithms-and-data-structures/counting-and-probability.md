A **k-permutation** of S is an ordered sequence of k elements of S, with no element appearing more than once in the sequence. (i.e. 2-permutations of the set {a, b, c, d} are ab, ac, ad, ba, bc, bd, ca, cb, cd, da, db, dc). The number of k-permutations of an n-set is:

```
n(n-1)(n-2)..(n-k+1) = n! / (n-k)!
```

---

A **k-combination** of an n-set S is simply a k-subset of:

```
(n, k) = n! / (k!(n-k)!)
```

This formula is symmetric in k and n - k:

```
(n, k) = (n, n - k)
```

This number is also known as **binomial coefficients**, due to their appearance in the binomial expansion:


(x + y)<sup>n</sup> = Σ<sub>k=0..n</sub>(n, k)x<sup>k</sup>y<sup>n-k</sup>

Special case when x = y = 1:

2<sup>n</sup> = Σ<sub>k=0..n</sub>(n, k)
