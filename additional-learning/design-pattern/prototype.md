## What it's used for?
- Specify the kinds of objects to create using a prototypical instance, and create new objects by copying this prototype.
- Should be considered when a system must create new objects of many types in a complex class hierarchy.
- In Java this pattern typically means using the clone() method.

## How to use?
- UML:
<img src="./pics/prototype.png" />

- Example:
<img src="./pics/protytype-example.png" />

## Benefits
- Hides the complexities of making new instances from the client.
- In some circumstances, copying an object can be more efficient than creating a new object.

## Drawbacks
- Making a copy of an object (implementing the clone() method) can sometimes be complicated.
