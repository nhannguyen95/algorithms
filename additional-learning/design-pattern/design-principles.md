**Encapsulate what varies**: Take the parts that vary and encapsulate them, so that later you can alter or extends the parts that vary without affecting those that don't.

---

**Programming to an supertype (interface, abstract class), not an implementation**: the declared type of the variables should be a supertype, usually an abstract class or interface, so that the objects assigned to those variables can be of any concrete implementation of the supertype, which means the class declaring them doesn’t have to know about the actual object types.

---

**Favor composition over inheritance**: HAS-A can be better than IS-A

---

**Open-Closed**: Classes should be open for extension, but closed for modification => the goal is to allow classes to be easily extended to incorporate new behaviour without modyfing existing code.

Can be understood as:
- close for modification: not allow anyone to touch your working code.
- open for extension: allow classes to be subclasses and extended.
- of course change is a constant factor in software development, but OCP encourages change through extension rather than going back and modifying your existing code.

Inheritance is often the easiest way to implement OCP (superclass is close and subclasses are extensible), but OCP goes beyond that: rather than let one dive into your code and make a bunch of changes, he should be able to extend your code without changing that.

Apply to areas that are most likely to change, not everywhere.

---

**Dependency Inversion**: Depend upon abstractions, do not depend upon concrete classes.

  Read Head-First p.139-143.
  
  A few guidelines to help you follow the principle (strive for rather than a rule that you follow all the time):
  - No variable should hold a reference to a concrete class. (use factory to get around that)
  - No class should derive from a concrete class. (derive from an abstraction instead)
  - No method should override an implemented method of any of its base classes.
  
---

**Least Knowledge**: talk only to your immediate friends.
  - When you are designing a system, for any object, be careful of the number of classes it interacts with and also how it comes to interact with those classes.
  - This principle prevents us from having a large number of classes coupled together so that changes in one part of the system cascade to other parts.
  
The guidelines to help you follow this principle: take any object; from any method in that object, we should invoke methods that belong to:
  - The object it self.
  - Object passed in a parameter to the method.
  - Any object the method creates or instantiates.
  - Any components of the object.
  
  Note that we shouldn't call methods on objects that were returned from calling other methods:
  
  Without principle:
  ```
  getTemp()
    Thermometer thermometer = station.getThermometer();
    return thermometer.getTemperature();
  ```
  
  With principle, ask the station object to make request for us:
  ```
  getTemp()
    return station.getTemperature();
  ```

Read more in Facade Pattern.

---

**Hollywood**: Don't call us, we'll call you.

We allow low-level components to hook themselves into a system, but the high-level components determine when they are needed, and how. In other words, the high-level components give the low-level ones a "don't call us, we'll call you" treatment.

Appear in Template Method, Factory, Observer.

---

**Single Responsibility Principle / A class should have only 1 reason to change**. The principle guides us to assign each responsibility to 1 class, and only 1 class (do 1 thing and do it well).

You can spot classes that aren't using the SRP with a simple test:
```
For every method in a class, write down these lines:

The <CLASS_NAME>, <METHOD_NAME> (the <METHOD_PARAMS>) it self

and read them out loud. If what you've just said doesn't make sense,
the method might belong to a different class => think about moving it.
```

---

**Don't Repeat Yourself**: avoid duplicate code by abstracting out things that are common and placing those things in a *single, sensible place*.

DRY is a lot more than just code: a requirement should be implemented one time, use cases shouldn't have overlap, etc.

---

**Liskov Substitution Principle (LSP)**: Subtypes must be substitutable for their base types.

```
2DBoard <|---- 3DBoard: Violate
2DBoard <*---- 3DBoard: OK
```

To reuse behavior from other classes, besides inheritance, (or when you violate LSP) you can use (favor these over inheritance, your software will usually be more flexible, easier to maintain, extend and reuse):
- delegate
- composition
- aggregation

Inheritance is still usefull, the key is know WHEN to subclass.
