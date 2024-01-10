## Problems
- https://leetcode.com/problems/circular-permutation-in-binary-representation/

## Theory

Gray code, also known as reflected binary code, is an ordering of n-bit binary numbers such that 2 successive values differ by only 1 bit.

Example of 3-bit gray code: `000`, `001`, `011`, `010`, etc.

Algorithm for generating n-bit gray code:
- n-bit gray code can be generated recursively from (n-1)-bit gray code by following these steps:
    - Reflect (n-1)-bit gray code: e.g., `00`, `01`, `11`, `10` is reflected as `10`, `11`, `01`, `00`.
    - Prefix original entries with 0: `000`, `001`, `011`, `010`.
    - Prefix reflected entries with 1: `110`, `111`, `101`, `100`.
    - Concatenated: `000`, `001`, `011`, `010`, `110`, `111`, `101`, `100`.
