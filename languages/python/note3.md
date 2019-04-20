`a == b` checks if a and b have same value.

`a is b` checks if a and b refer to same object.

---

**Python's dynamic typing model***

3 terms:
- _variables_: entries in system table, with spaces for links to objects.
- _objects_: pieces of allocated memory.
- _references_: automatically followed pointers from variables to objects (the bridge).

When you assign `a = 3`, Python performs these steps:
- Create an object to represent the value 3 (to optimize, Python internally caches and reuses certain kinds of unchangeble objects such as intergers and strings):
  ```
  x = 1, y = 1
  x is y  # True, since 1 is cached
  
  x = [], y = []
  x is y  # False, list is not cached
  ```
- Create the variable `a` if it does not exist.
- Link `a` to `3`.

When you reassign `a = 'spam'`, if the `3` object is garbage-collected if it is not referenced by any other variable or object (actually, as mentioned above, Python caches small intergers and strings, so `3` is not literally reclaimed here; most other kinds of objects are though) .

When you assign `b = a`, `a` and `b` act like pointers, they will now refer to the same object `'spam'`. This is called _shared reference_ or _shared object_.

The type of variables is determined at run time.

---
