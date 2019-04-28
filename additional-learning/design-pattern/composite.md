## What it's used for?
- it allows you to compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

## How to use?
- UML:
<img src="./pics/composite.md" />

- Example: Submenu in menu
  <img src="./pics/composite-example.md" />
  
  The Composite Pattern (MenuComponent interface) violates the Single Responsibility principle (since it contains operation of the composite and the leaf), the pattern trades that principle for transparency (client can treat both composites and leaf nodes uniformly).
  
  We lose a bit of safety as well since user might try to do something inappropirate or meaningless on an element, we could separate out the responsibilites into interfaces but we'd lose transparency since our code need conditionals and the *instance of* operator.
  
  So that's the design decision and trade off.
  
## Excercise
- Try to implement the Iterator for the Composite object.
