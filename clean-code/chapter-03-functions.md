Functions should be short and small.

---

Blocks within `if`, `else`, `while`, etc. should be one line long.

Functions should not be large enough to hold nested structures (the indent level of a function should not be greater than 1 or 2).

---

Functions should only do "one thing", they should do it well. They should do it only.

What does "one thing" mean? It means that if a function only does those steps that are **one level below the (stated) name of the function**, then the function is doing one thing.

Then the function can be described as a brief TO paragraph:

```
TO do X (X is the function name), we do Y, then Z then W.
```

---

The reason to write functions: to decompose a larger concept (i.e., the name of the function) into a set of steps at the next level of abstraction.

---

Object-oriented principle: **SOLID**
- Single responsibility
- Open Closed
