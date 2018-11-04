## Optimization and Decision Problems

**Optimization problems**: each feasible solution has an associated value, we wish to find a feasible solution with the best value. For example the _single-source shortest path_ problem.

**Decision problems**: Problems whose answer is YES or NO. For example the [partition problems](https://en.wikipedia.org/wiki/Partition_problem).

The classification of problems focuses on decision problems since:
- Other problems can be reduced/casted to a decision one.
- Decision problems are simple.

From this point on, _problems_ refers to decision problems.


## Polynomial-time algorithms

**Polynomial-time algorithms**: algorithms whose worst-case running time is O(n<sup>k</sup>).


## P vs NP

3 classes of problems:
- **P**: problems that are solvable in polynomial time (**polynomial-time solvable**).
- **NP**: problems that we can check/verify a given proof/certificate/witness is correct or not in polynomial time (**polynomial-time verifiable**).
- **NPC**: We will discuss this class later.

We can see that P ⊂ NP, since if a problem can be solved in polynomial time, it can also be verified in polynomial time.

The millennium unsolved problem is whether **P = NP**, or in other words: **does NP \ P exist?**.

All sort of problems were born from here, because of all NP problems (polynomial-time verifiable) that haven't been solvable by a polynomial-time algorithm that we have discovered so far, we haven't been able to prove if there exists such a algorithm to solve them or not.

Therefore, the best algorithms we know of for solving an **arbitrary problem in 𝖭𝖯** are brute-force/exhaustive-search algorithms.

Notice that the word "arbitrary" is emphasized, because a problem in NP can have much faster algorithm (i.e. in case if it is in P, since P ⊆ NP). In other words, if you just tell me that your problem is in 𝖭𝖯 **(and nothing else about the problem)** then the fastest algorithm that we know of for solving it takes exponential time.

If one can prove P = NP, the world will change a lot. For example, the RSA public-key cryptography that have been using in electronic transaction bases on the belief: it is easy to compute the product of 2 big prime numbers; but given such a product, finding back 2 prime numbers is hard. We can state that problem in the form of a decision one: given a number X, can we find 2 prime numbers whose product equals X? This is an NP problem, since we can verify it quickly (given 2 prime numbers, we can find their product and then compare to X). If P = NP, meaning that this problem has a polynomial time algorithm to find 2 prime numbers from X. And then the RSA algorithm (and maybe more) becomes vulnerable.

## NP-Completeness / NP-Hardness

### Reducibility

Before defining NP-Completeness, we need a notion that we can use to say a problem is easier or more difficult than the other. That's _reducibility_.

Given a problem P<sub>1</sub> in NP, we say P<sub>1</sub> is polynomial-time reducible to an NP problem P<sub>2</sub> if there exists a polynomial-time computable function _f_ such that for all input _x_ of P<sub>1</sub>, _f(x)_ is input of P<sub>2</sub> and P<sub>1</sub>(x) = 0/1 if and only if P<sub>2</sub>(_f(x)_) = 0/1.

We denote that P<sub>1</sub> ≤ <sub>P</sub> P<sub>2</sub> and say that P<sub>1</sub> is not more than a polynomial factor harder than P<sub>2</sub> (which makes sense, since if we reduce P<sub>1</sub> to P<sub>2</sub>, and if we can solve P<sub>2</sub>, then we can also solve P<sub>1</sub>).

### NP-complete Problems

Mathematicians observe that there exist problems called **NP-complete**, which is the _hardest problem_ among all NP problems, or mathematically a problem P is NP-complete if:
- It is NP and (1)
- P' ≤<sub>P</sub> P for all P' in NP (2)

This means that:
- NP-complete ⊆ NP
- All NP problems can be polynomial-time reducible to an NP-complete problems, and therefore:
- If one NP-complete problem is solved with a polynomial-time algorithm, then all NP problems can be solve in polynomial-time, thus P = NP.

There are many problems that are NP-complete (with the natural statement) but noone has ever found a polynomial-time solution for only one of them. See [list of NP-complete problems](https://en.wikipedia.org/wiki/List_of_NP-complete_problems).

### NP-hard Problems

Every problem satisfies (2) condition is NP-hard problem, it doesn't matter if it belongs to NP or not (polynomial-time verifiable or not).

### NP-Completeness proofs

Given an NP-complete problem P, then we can prove some other problem S is NP-complete (or NP-hard) by showing that P ≤<sub>P</sub> S.

Our first NP-complete problem to prove is [Circuit satisfiability problem](https://en.wikipedia.org/wiki/Circuit_satisfiability_problem).

You can read more in CLRS, 3rd, Chapter 34.