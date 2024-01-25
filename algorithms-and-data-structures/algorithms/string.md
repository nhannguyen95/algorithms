## Problems
- [Longest Common Substring (LCS)](https://practice.geeksforgeeks.org/problems/longest-common-substring/0): this can be solved using DP, Trie or Suffix Array.
- [Implement Atoi](https://www.interviewbit.com/problems/atoi/)
- https://leetcode.com/problems/compare-version-numbers
- Palindrome:
    - https://leetcode.com/problems/palindromic-substrings
    - https://leetcode.com/problems/find-palindrome-with-fixed-length

## Theory

### Preprocessing and matching times of some string-matching algorithms

n = |T| = Length of text

m = |P| = Length of pattern

|Algorithm|Preprocessing time|Matching time|
|-|-|-|
|Naive|0|O((n - m + 1)m)|
|Rabin-Karp|Θ(m)|O((n - m + 1)m)|
|KMP|O(m)|O(n)|

### Why is naive algorithm inefficient?

Because it ignores the information of times it wrongly matches P with T. Those information may be useful.

### Gap characters in P

An interesting and practical problem: P has gap characters `.`that can match to an arbitrary string of characters of length ≥ 0, for example P = ab`.`ba`.`c can match to ab`abc`ba`dsf`c or abbac.

We can determine whether P in T in O(nm) time.
