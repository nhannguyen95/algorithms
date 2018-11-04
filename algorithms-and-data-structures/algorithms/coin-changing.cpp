/* Coin Changing problem

Problem statement:
Given a set of coins (infinite ammount) and M cents
Making change for M cents using the fewest number of coins.


-------- GREEDY ALGORITHM ---------

Making change in decreasing coin values.

However the greedy algorithm doesn't work in all cases.

Suppose that the denominations of the coins are
c^0, c^1 .. , c^k for some integers c > 1 and k >= 1.
Greedy algorithm yields optimal solution for this case.

-------- DYNAMIC PROGRAMMING -------

This work in general cases.

Just DP

*/