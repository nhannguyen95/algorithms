**Master theorem**

Let a ≥ 1, b > 1 be constants, let _f(n)_ be an asymptotic positive function, and let _T(n)_ be defined on the nonnegative integers by the recurrence:

```
T(n) = aT(n/b) + f(n)
```

Then _T(n)_ has the following asymptotic bounds:

  1. If _f(n)_ = O(n<sup>log<sub>b</sub>a - ϵ</sup>) for some constants ϵ > 0, then _T(n)_ = Θ(n<sup>log<sub>b</sub>a</sup>)
  2. If _f(n)_ = Θ(n<sup>log<sub>b</sub>a</sup>), then _T(n)_ = Θ(n<sup>log<sub>b</sub>a</sup> lg n) = Θ(_f(n)_ lg n)
  3. If _f(n)_ = Ω(n<sup>log<sub>b</sub>a + ϵ</sup>) for some constants ϵ > 0, and if _af(n/b) ≤ cf(n)_ for some constant c < 1 and all sufficiently large _n_, then _T(n)_ = Θ(_f(n)_)

---

Solving the equality `T(n) = aT(n/b) + f(n)` gives us the tight bound for _T(n)_, i.e. _T(n)_ = Θ(_g(n)_).

Solving the inequality `T(n) ≤ aT(n/b) + f(n)` (or `≥`) gives us the upper bound O (or lower bound Ω).

---

**Understanding master theorem**:

Basically in all 3 cases, the result is determined by the larger of the 2 functions _f(n)_ and _n<sup>log<sub>b</sub>a</sup>_.

Need to notice that in case #1, not only must _f(n)_ be smaller than _n<sup>log<sub>b</sub>a</sup>_, it must be polynomial smaller (asymptotically smaller by a factor of _n<sup>ϵ</sup>_ for some constant ϵ > 0).  Similarly for case #3.

Note also that the above 3 cases do not cover all possibilities for _f(n)_. There is a gap between cases 1 and 2 when _f(n)_ is smaller than _n<sup>log<sub>b</sub>a</sup>_ but not polynomial smaller. Similarly the gap between cases 2 and 3 when _f(n)_ is larger than _n<sup>log<sub>b</sub>a</sup>_ but not polynomial larger. The master theorem can't be used in those scenarios.

---

**Examples**

There's solution for each example, solve for yourself =)

T(n) = 9T(n/3) + n => T(n) = Θ(n<sup>2</sup>)

T(n) = 2T(2n/3) + 1 => T(n) = Θ(lgn)

T(n) = 3T(n/4) + nlgn => T(n) = Θ(nlgn)

T(n) = 2T(n/2) + nlogn => Can't be solved using master theorem
