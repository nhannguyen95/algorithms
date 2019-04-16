**Encapsulate what varies**: Take the parts that vary and encapsulate them, so that later you can alter or extends the parts that vary without affecting those that don't.

---

**Programming to an supertype (interface, abstract class), not an implementation**: the declared type of the variables should be a supertype, usually an abstract class or interface, so that the objects assigned to those variables can be of any concrete implementation of the supertype, which means the class declaring them doesn’t have to know about the actual object types.

---

**Favor composition over inheritance**: HAS-A can be better than IS-A

---

**Open-Closed**: Classes should be open for extension, but closed for modification => the goal is to allow classes to be easily extended to incorporate new behaviour without modyfing existing code.

Apply to areas that are most likely to change, not everywhere.
