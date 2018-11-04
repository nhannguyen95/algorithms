/* Knapsack problem

Problem: Given n items, ith item is worth v[i] dollars and weights
w[i] pounds. There's a snapsack that has capacity W pounds. Which
items should be taken in the snapsack to maximize the total money?

In this problem, we assume that the weight is integer. If it's
decimal number, we can convert them to integer by multiplication.

----------- FRACTIONAL SKNAPSACK -----------

In this version, we can take fractions of items, it means with item
i-th we can take 1 weight from it that is worth v[i] / w[i].

Solution: Greedy.
We begin with items that have the largest v / w ratio (values per pound)
then put into the knapsack until it reaches W.


--------------- 0-1 KNAPSACK ---------------

Solution: DP

Optimal structure property: When we put i-th item into the knapsack,
the problem is reduced to picking (n - 1) remaining items into 
W - w[i] capacity knapsack.

for i = 1 to n
    for j = 1 to W

A variant that can use greedy: n items are sorted by increasing weight
and decreasing value.

--------------- 0-∞ KNAPSACK ---------------

Solution: DP

for j = 1 to W
    for i = 1 to n

*/
