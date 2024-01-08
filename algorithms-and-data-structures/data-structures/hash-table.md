### Introduction

Dictionary operations:
  - INSERT
  - DELETE
  - SEARCH

A hash table is an effective data structure for implementing dictionaries.

---

### Direct-address tables

If keys are drawn from U = {0, 1, .., k - 1}, where k is not too large, then we can use a direct-address table T of size m = k to store the objects. That means:

```
T[k] = object{k, a pointer to satellite data}
```

---

### Hash tables

If k is very large, then allocating a huge direct-address table T is not practical. Instead, we try to map key into some value in [0..m-1] by a **hash function** _h_, ie. _h_ maps a key into the indices (or the slots) of **hash table** T.

```
hk = h(k)
T[hk] = object{k, a pointer to satellite data}
```

Hash tables are used to implement _unordered_set_, _unordered_map_ in C++; _HashSet_, _HashMap_ in Java.

---

### Collision resolution

Two different keys can possibly have the same hash value, we call this situation **collision**.

#### Chaining

One of the approaches to solve the collision problem is that we place all elements of the same hash value into a linked list, ie. T[j] = pointer to the head of the linked list of all stored elements that hash to j.

Let denote `n` is the number of keys (elements) in the hash table. In the worst case, all keys will have the same hash value and thus be placed in the same linked list, then:

  - INSERT(k/x) takes O(1) if we allow the set to contain elements of the same key, O(n) otherwise
  - DELETE(x) takes O(1) if the linked list is a doubly one, takes O(n) if the linked list is singly OR DELETE(k)
  - SEARCH(k) takes O(n)

Clearly, we don't use hash tables for their worst-case performance. So let denote `m` is the size of hash table T, we define **load factor** `α` as `n/m`. If our hash function _h_ is a _good_ one, the _expected_ size of the linked list at each slot in T will be `α`.

Thus on average: INSERT, DELETE, SEARCH will be expected to be O(α); and to emphasize that we also count the time complexity of hashing the key which we will assume that it costs O(1); the overall time complexity will be O(1 + α).

That means if the number of hash-table slots `m` is at least proportional to the number of elements `n` in the table, then n = O(m), thus α = n / m = O(m) / m = O(1) (expectation).

#### Open addressing

In this technique, each slot stores either the key or `NULL`.

To insert a key, we produce a **probe sequence** by hashing h(key, i _in_ [0..m-1]) = j _in_ [0..m-1] (input of hashing function now receives one more index `i`). Then we examine sequentially this probe sequence, refer to T[j] until we can find a `NULL` slot to insert key into.


```
INSERT(T, k)
for i = 0 to m-1
  j = h(k, i)
  if T[j] == NULL
    T[j] = k
    return
error "hash table overflow"
```

Searching for a key is similar, if we examine all the probe sequence and have yet to find the key OR we find T[j] = NULL, then key is not present in the hash table:

```
SEARCH(T, k)
  i = 0
  do
    j = h(k, i)
    if T[j] == k
      return True
    i = i + 1
  while T[j] != NULL and i < m
  return NULL
```

Deletion is tricky, since we cannot just set T[j] = NULL: Let say we have key k that produces a probe sequence that j is in the middle, then if k is stored in a slot past j, then it will never be retrieved because the searching stops at T[j] = NULL.

One solution is to set T[j] = DELETE status, however the search time no longer depends on the load factor α. So chaining is more commonly selected as a collision resolution technique when keys must be deleted.

##### Linear probing

```
i = 0..m-1
h(k,i) = (h'(k) + i) mod m
```

Probe sequence: `h'(k), h'(k) + 1.., h'(k) + m - 1`.

Problem:
  - **Primary clustering**: Given a probe sequence had already been examined and a new key. If the initial position of this new key falls into anywhere in the given probe sequence, the 2 probe sequences (the cluster) will collapse and increase in size.
  - **Secondary clustering** (less severe): If 2 keys have the same initial position, they have the same probe sequence.

##### Quadratic probing

```
c1, c2 > 0; i = 0..m-1
h(k,i) = (h'(k) + c1*i + c2*i^2) mod m
```

Problem:
  - **Secondary clustering**: as linear probing.

##### Double hashing

```
h(k,i) = (h1(k) + ih2(k)) mod m
```

---

### What makes a good hash function?

**Simple uniform hashing**: each key is equally to be hashed to any of the slots in the hash table.

A good hash function satisfies (approximately) the assumption of simple uniform hashing.

Furthermore, in some applications, we might want keys that are "close" in some sense to yield values that are far apart.

Unfortunately, we typically have no way to check this condition, since we rarely know the probability distribution from which the keys are drawn.

---

### Design hash functions

Most hash functions assume that the universe of keys is the set of natural numbers. Thus if the keys are not natural numbers, we find a way to interpret them as natural numbers.

#### The division method

```
h(k) = k mod m
```

We usually avoid certain values of `m`. For example m should not be a power of 2, since if m = 2<sup>p</sup> then `h(k)` is just the _p_ lowest-order bits of `k` (we are better off designing the hash function to depend on all the bits of the key).

A prime not too close to the form 2<sup>p</sup> is often a good choice for `m`. For example, suppose we wish to allocate a hash table to hold roughly n = 2000 elements, and we don't mind having 3 as the maximum size of the linked list in case of collision. We could choose m = 701 since its a prime number near 2000/3 but not near any power of 2.

If the set of keys is random and is uniformly distributed, then the choice of `m` is not so critical. But if keys have some pattern, then you should choose a prime value for `m`. Let's say most of the keys have the form `k = ac + b`, and `h(k) = k mod m = (ac + b) mod m`. If c is a factor of m, then these keys will go to a small subset of the slots in the hash table.

Therefore, to minimize collision, we can choose `m` to be a number that has very few factors: a prime number.

#### The multiplication method

#### Universal hashing

Problem: if we use a fix hash function, an adversary can choose a series of keys that hash to the same slot to make the operations perform inefficiently.

To avoid such attack, we choose randomly some hash function from a set of hash functions at the initial time, so that the attacker doesn't know which hash function is being used and thus cannot produce the desired series of keys.

This approach is called **universal hashing**.

This approach is proved to give a good average-case behavior.

**Design a universal class of hash functions**

Let denote `p` as a large enough prime number so that every key `k` is in range 0 to p-1, number of slots in hash table as `m` (normally p > m), Z<sub>p</sub> = {0..p-1}, Z<sub>p</sub><sup> * </sup> = Z<sub>p</sub> \ {0}. The family of hash functions is defined by:

```
h[ab](k) = ((ak + b) mod p) mod m
H = {h[ab] | a in Zp* and b in Zp}
```

---

### Perfect hashing

?? :D ??

---
