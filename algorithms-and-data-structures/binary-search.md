Shift `mi` to the left: `mi = (lo + hi) / 2 = lo + (hi - lo) / 2`.

Shift `mi` to the right: `mi = (lo + hi + 1) / 2 = lo + (hi - lo) / 2 + ((hi - lo) % 2)`.

---

It's crutial to determine the value range of `mi`. If we have `lo = a`, `hi = b` and `while(lo < hi)`:
- If `mi` is shifted to the left, `mi` is in `[a, b)`.
- If `mi` is shifted to the right, `mi` is in `(a, b]`.
