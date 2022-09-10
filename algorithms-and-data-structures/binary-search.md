Shift `mi` to the left (flooring): `mi = (lo + hi) / 2 = lo + (hi - lo) / 2`.

Shift `mi` to the right (ceiling): `mi = (lo + hi + 1) / 2 = lo + (hi - lo) / 2 + ((hi - lo) % 2)`.

---

- Ceiling and flooring work fine with `lo = mi + 1` and `hi = mi - 1`.`
- Flooring works fine with `lo = mi + 1` and `hi = mi`.
- Ceiling works fine with `lo = mi` and `hi = mi - 1`.

---

When using ceiling with `lo < hi`, `lo = a`, `lo = b`, `lo = mi` and `hi = mi - 1`: `mi` is in `(a, b]`.

When using flooring with `lo < hi`, `lo = a`, `lo = b`, `lo = mi + 1` and `hi = mi`: `mi` is in `[a, b)`.
