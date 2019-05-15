Duplication code? Aim for **encapsulation**.

Encapsulation is when you separate or hide one part of your code from the rest of your code.

The simplest form of encapsulation is when you make the variables of your classes private, and only expose that data through methods.

You can also encapsulate groups of data, or even behavior, to control how they are accessed.

---

When making changes, think of how many components/classes are affected? How to reduce that numbers? Aim for **delegation**.

Delegation helps the application become **loosely coupled**, it shields your objects from implementation changes to other objects.

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

Solving big problems:
- Gather feature lists: they are about understanding what your software is supposed to do (reflect functionality).
- Use cases diagrams: they let you start thinking about how your software will be used, without getting into a bunch of unnecessary details (reflect usage), one use case can match to multiple features.
- Gather requirements.
  > Use case is a requirement for how people and things (actors) interact with your system.
  >
  > Feature is a requirement about things that your system must do.
- Break the big system into smaller pieces of functionality (understand the problem).
- Iterate through each problem:
  - Textual Analysis: looking at the nouns (and verbs) in the use cases to figure out classes and methods.
  - Preliminary Design: use the nouns and verbs and draw use case diagrams.
  - Implementation: use OOAD principles and design patterns to solve those small problems.

---

Where to start from smaller problems in a big one? The most architecturely important features.

How to know a feature is architecturely important? 3 Qs of architecture:
- Can you imagine the system without that feature? (essence at the most basic level).
- If you're now sure what the feature's description really means.
- If it's hard to implement / new programming task.

---

While you have a set of important features; you can start with any of them, as long as you're working towards reducing the RISKs. (each feature introduces risks to your project, they can cause you problems, or delay you getting the project done).

---

When use cases are too formal, or developers don't have the time to write one, you can come up with a scenario (a path in a use case) and make sure the system handle the case.

A scenario is used to avoid getting into lots of unneccessary details of writing a full use case at the early design stage => reduce risks.

---

To develop a feature:
- Ask customers for clarifications.
- Use commonality analysis to build flexible software solutions.
- Implementation plan.

---

Great software > great code.

Customers don't pay you for great code, they pay you for great software (and on time).
