## What it's used for?
- provides a way to access the elements of an aggregate (collection) object sequentially without exposing its underlying representation.
- it also places the task of traversal on the iterator object, not on the aggregate.  

## How to use?
- UML:
<img src="./pics/iterator.png" />

- Example:
<img src="./pics/iterator-example.png" />

## What principles it derives?
- A class should have 1 reason to change: by delegating the traversal of objects to the Iterator but not implenting that responsibility in the aggregate object itself.
