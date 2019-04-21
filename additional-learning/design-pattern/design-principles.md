**Encapsulate what varies**: Take the parts that vary and encapsulate them, so that later you can alter or extends the parts that vary without affecting those that don't.

---

**Programming to an supertype (interface, abstract class), not an implementation**: the declared type of the variables should be a supertype, usually an abstract class or interface, so that the objects assigned to those variables can be of any concrete implementation of the supertype, which means the class declaring them doesn’t have to know about the actual object types.

---

**Favor composition over inheritance**: HAS-A can be better than IS-A

---

**Open-Closed**: Classes should be open for extension, but closed for modification => the goal is to allow classes to be easily extended to incorporate new behaviour without modyfing existing code.

Apply to areas that are most likely to change, not everywhere.

---

**Dependency Inversion**: Depend upon abstractions, do not depend upon concrete classes.

  Read Head-First p.139-143.
  
  A few guidelines to help you follow the principle (strive for rather than a rule that you follow all the time):
  - No variable should hold a reference to a concrete class. (use factory to get around that)
  - No class should derive from a concrete class. (derive from an abstraction instead)
  - No method should override an implemented method of any of its base classes.
  
  
