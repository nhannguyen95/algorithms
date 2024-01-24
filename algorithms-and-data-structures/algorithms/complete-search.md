## Problems
- https://leetcode.com/problems/longest-palindromic-substring/

## Theory

Complete search tips:
- Immediately prune invalid partial solutions (branch and bound). The earlier you prune, the better.
- Utilize symmetries.
- Pre-computation: sometimes it is helpful to generate tables or other data structures that accelerate the lookup of a result prior to the execution of the code.
- Try solving the problem backwards.
- Optimize your source code:
    - Use expected O(NlogN) cache-friendly sorting algorithms rather than the true O(NlogN) but non cache-friendly ones (e.g. heapsort).
    - Access 2D arrays in row-major order rather than in column-major order to increase probability of cache hit (as multidimension arrays are sorted in a row-major order in memory).