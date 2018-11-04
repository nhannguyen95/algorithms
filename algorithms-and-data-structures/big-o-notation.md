To describe the running times or space complexity (complexity in general) of algorithms, we use 3 **Asymptotic notations (Big-O Notation)**:

  - Θ-notation.
  - O-notation.
  - Ω-notation.

These Big-O notations are used to **express a bound on the difference** between an arithmetical function _f_ and a better understood approximation _g_:

 - Θ(_g_) = _f_ : _g_ is an **asymptotic tight bound** for _f_.
 - O(_g_) = _f_ : _g_ is an **asymptotic upper bound** for _f_.
 - Ω(_g_) = _f_ : _g_ is an **asymptotic lower bound** for _f_.

Or more mathematically:

 - Θ(_g(n)_) = { _f(n)_ | ∃ c<sub>1</sub> > 0, c<sub>2</sub> > 0, n<sub>0</sub> > 0 : 0 ≤ c<sub>1</sub>_g(n)_ ≤ _f(n)_ ≤ c<sub>2</sub>_g(n)_ ∀ n ≥ n<sub>0</sub> }
 - O(_g(n)_) = { _f(n)_ | ∃ c > 0, n<sub>0</sub> > 0 : 0 ≤ _f(n)_ ≤ c _g(n)_ ∀ n ≥ n<sub>0</sub> }
 - Ω(_g(n)_) = { _f(n)_ | ∃ c > 0, n<sub>0</sub> > 0 : 0 ≤ c _g(n)_ ≤ _f(n)_ ∀ n ≥ n<sub>0</sub> }

Because Θ(_g(n)_) is a set, we write _f(n)_ ∈ O(_g(n)_). To express the same notion, we will usually write _f(n)_ = O(_g(n)_); similarly to the other 2 notations.

---

Why we usually use O notation to evaluate the time/space complexity of algorithms?

First one needs to understand that:

  - n<sup>2</sup> ∈ O(n<sup>2</sup>) and n ∈ O(n<sup>2</sup>). (This means the bound provided by O notation may or may not be asymptotically tight)
  - n<sup>2</sup> ∈ Θ(n<sup>2</sup>) but n ∉ Θ(n<sup>2</sup>).

Since O-notation describes an **upper bound**, when we use it to bound the **worst-case** running time of an algorithm, we have a bound on the running time of the algorithm of **every input**. For example, the O(n<sup>2</sup>) bound on worst-case running time of insertion sort applies to its running time on every input.

What does it mean **every input**?

If the array (the input) is already sorted, insertion sort runs in O(n). Otherwise in average and worst case, it runs in O(n<sup>2</sup>). Both can be described by O(n<sup>2</sup>).

The Θ notation can only describe the running time in average and worst case: Θ(n<sup>2</sup>), it can't if the array (the input) is already sorted, the running time described by Θ notation should now be Θ(n).

To summary, when we say the running time is O(n<sup>2</sup>), we meant that there is a function _f(n)_ that is O(n<sup>2</sup>) such that for any value of _n_, no matter what particular input of size _n_ is chosen, the running time on that input is bounded from above by the value _f(n)_. **Eventually, we mean that the worst-case running time is O(n<sup>2</sup>).**.

---

**Theorem**: For any two functions _f(n)_ and _g(n)_, we have _f(n)_ = Θ(_g(n)_) if and only if _f(n)_ = O(_g(n)_) and _f(n)_ = Ω(_g(n)_).

And notice: the running time of insertion sort is not Ω(n<sup>2</sup>), try to explain why.

---


References:
  - [Big O notation - Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation).
  - Introduction to Algorithms book.
