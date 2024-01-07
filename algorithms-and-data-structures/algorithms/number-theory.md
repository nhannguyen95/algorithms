If d | a (read d **divides** a) and d ≥ 1, d is a **divisor** of a.

Every a > 0 has 2 **trivial divisors**: 1 and a.
The non-trivial divisors of a are the **factors** of a.

---

An integer a > 1 is a **composite** (number) if it's not a **prime** (number).

Negative integers, 0 and 1 are neither prime nor composite.

---

2 integers a and b are **relatively prime** if gcd(a, b) = 1.

---

Pay attention to modulo of a negative number:
- -10 % 7 = 4 in Python.
- -10 % 7 = -3 in C++/Java.

To be safer, if we need to find a non-negative result of a % m, we use ((a % m) + m) % m.

---

**Modular multiplicative inverse** (Nghịch đảo modulo): x is
a multiplicative inverse of a, modulu n (x là nghịch đảo của
a theo modulo n) if: a<sup>-1</sup> ≡ x (mod n) or ax ≡ 1 (mod n).

This helps us define a / b (mod n).