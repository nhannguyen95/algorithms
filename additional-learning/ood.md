Duplication code? Aim for **encapsulation**.

---

When making changes, think of how many components/classes are affected? How to reduce that numbers? Aim for **delegation**.

Delegation helps the application become **loosely coupled**, it shields your objects from implementation changes to other objects.

---

**Textual analysis**: Looking at the nouns (and verbs) in the use cases to figure out classes and methods.

---

OO Principles:
- Encapsulate what varies.
- Code to an interface rather than to an implementation.
- Each class in your application should have only 1 reason to change.

---

**Cohesive**: methods of a class all relate to the name of that class.

Highly cohesive = Loosly coupled.

---

Subclasses provide different behaviors from the superclass, the superclass in this case could be abstract.

If behaviors of subclasses are the same, we should consider making the superclass "un-abstract".

---

When you have a set of properties that vary accross your objects, use a collection data structure like Map.

---

Class = Attributes + Methods.

Object = Data + Processing of data.

---

OOAD Activities:
- Requirements gathering.
- Analysis: the emphasis on finding and describing objects or concepts in the problem domain.
- Design: the emphasis on defining objects, how the collaborate to fulfull the requirements.

---

If you need to know what a system does, but don't want ot get into all the detail that use cases require, a use case diagram could be what you need. (Since use cases are much more detail-oriented, and don't help you figure out the big picture).

---

**Domain Analysis**: the process of putting together things about the system in a way the customers understand.

---

Solving big problems:
- Gather requirements.
- Draw up blueprints for the system: use case diagram, class diagram.
- Break the big system into smaller pieces of functionality.
- Use OOAD principles and design patterns to solve those small problems.
