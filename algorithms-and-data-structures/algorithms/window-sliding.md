## Problems
- Shrinkable:
    - https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
    - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element
    - https://leetcode.com/problems/get-equal-substrings-within-budget/
- Non-Shrinkable:
    - https://leetcode.com/problems/jump-game-vi/

## Theory

Idea: "slide" a sub-array ("window", which can have a dynamic or
static length) in linear fashion from left to right over the
original array of n elements in order to compute something.

### Template 1: Shrinkable Sliding Window

```java
int i = 0, j = 0, ans = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    for (; invalid(); ++i) { // when invalid, keep shrinking the left edge until it's valid again
        // CODE: update state using A[i]
    }
    ans = max(ans, j - i + 1); // the window [i, j] is the maximum window we've found thus far
}
return ans;
```

### Template 2: Non-Shrinkable Sliding Window

```java
int i = 0, j = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    if (invalid()) { // Increment the left edge ONLY when the window is invalid. In this way, the window GROWs when it's valid, and SHIFTs when it's invalid
        // CODE: update state using A[i]
        ++i;
    }
    // after `++j` in the for loop, this window `[i, j)` of length `j - i` MIGHT be valid.
}
return j - i; // There must be a maximum window of size `j - i`.
```

## References
- https://github.com/lzl124631x/algorithm