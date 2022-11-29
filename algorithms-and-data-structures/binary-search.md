Shift `mi` to the left (flooring): `mi = (lo + hi) / 2 = lo + (hi - lo) / 2` (`mi` never equals `hi` if `lo < hi`).

Shift `mi` to the right (ceiling): `mi = (lo + hi + 1) / 2 = lo + (hi - lo) / 2 + ((hi - lo) % 2)` (`mi` never equals `lo` if `lo < hi`).

---

Ceiling and flooring work fine with `lo = mi + 1` and `hi = mi - 1`.

Flooring works fine with `hi = mi` and `lo = mi + 1` (to avoid an otherwise infinite loop where `lo = mi = lo`).

Ceiling works fine with `lo = mi` and `hi = mi - 1` (to avoid and otherwise infitnte lopp where `hi = mi = hi`).

---

When using ceiling with `while(lo < hi)`, `lo = a`, `hi = b`, `lo = mi` and `hi = mi - 1`: `mi` is in `(a, b]`, `lo` (and `hi`) is in `[a, b]`.

When using flooring with `while(lo < hi)`, `lo = a`, `hi = b`, `lo = mi + 1` and `hi = mi`: `mi` is in `[a, b)`, `hi` (and `lo`) is in `[a, b]`.

---

Loop condition for non-exact match binary search is `while (lo < hi)`, this means when the loop stops, `lo = hi`, so it doesn't matter whether `lo` or `hi` is chosen to be the result (choose whatever makes more sense).

---

If a binary search problem can be solved using flooring, it can also be solved using ceiling and vice-versa.
