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

Why we usually use O notation to evaluate the time/space complexity of algorithms?

Since O-notation describes an **upper bound**, when we use it to bound the **worst-case** running time of an algorithm, we have a bound on the running time of the algorithm of **every input**. For example, the O(n<sup>2</sup>) bound on worst-case running time of insertion sort applies to its running time on every input.

---

References:
  - [Big O notation - Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation).
  - Introduction to Algorithms book.
