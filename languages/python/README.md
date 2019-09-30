Content:
- [Python is an interpreter language](#python-is-an-interpreter-language)
- [Python implementations](#python-implementations)
- [Python installation](#python-installation)
- [Import in Python](#import-in-python)
- [Python data types](#python-data-types)
- [Python's dynamic typing model](#pythons-dynamic-typing-model)
- [Python syntax](#python-syntax)
- [Python naming convention](#python-naming-convention)
- [Type](#type)
- [Boolean](#boolean)
- [String](#string)
- [Tuple](#tuple)
- [List](#list)
- [Set](#set)
- [Dict](#dict)
- [Iteration](#iteration)
- [Generator](#generator) TODO
- [Comprehension](#comprehension)
- [Operation](#operation)
- [Function](#function)
- [Scope](#scope)

---

## Python is an interpreter language

Python code runs immediately after it is written. There is no compile-time phase: no creation of functions, classes; no linkage of modules.

```
source   ->  byte code  ->  runtime
m.py         m.pyc          PVM (execute byte code)
```

We can also standalone binary executables from Python programs.

## Import in Python

- `modules`: files imported from another file.
- `scripts`: main file.

Because `import`s are expensive, `import`s of the same module are only imported once, unless you use `reload`.

Whether you use `import` or `from..import`, statements in the imported modules are executed.

Python searches for imported modules in directory listed in `sys.path` (initialized from a `PYTHONPATH` environment variable), plus a set of standard directories.

If you want to import from another directory, that directory must be listed in your `PYTHONPATH` setting.

## Python implementations

CPython is the standard implementation of Python, it is written in ANSI C.

Pypy is an reimplementation of CPython that runs much quicker, space is also optimized.

## Python installation

The system path should include Python's install directory. On MAC it's at `/usr/local/bin/python` or `/usr/bin/python3`.

Turn Python files into executable scripts, instead of hardcoding the path to the Python interpreter `#!/usr/local/bin/python`, use Unix env lookup: `#!/usr/bin/env python`.

Names with the form *__X__* are built-in names that are always defined by Python and have special meaning to the interpreter

## Python data types

**Python built-in objects**:
- Numbers (including `3 + 3j`)
- Strings (including `b'a\x01c`, `u'sp\xc4m'`
- Tuples
- Lists
- Dicts
- Files
- Sets
- Other core types: boolean, types, None
- Program unit types: Functions, modules, classes
- Implementation-related types: compiled code, stack tracebacks

**Categorized by mutability**:

Immutable (hashable):
- Boolean
- Number
- Tuple: List that cannot be changed.
- String
- Frozenset

Mutable (unhashable):
- List
- Set
- Dict
- Bytearray
- etc.

**Categorized by categories**:

Numbers (numeric):
- integer
- floating-point
- decimal
- fraction
- etc.

_Sequences_: are positionally ordered collection of objects that support sequence operations such as indexing, slicing.
- string
- list
- tuple
- bytearray

_Mappings_ denotes objects that map keys to associated values.
- dict

Callables:
- Function
- Generator
- Class
- Method: Bound, Unbound

Internals:
- Type
- Code
- Frame
- Traceback

Other:
- Module
- Instance
- File
- None
- View

For example: strings are immutable sequences - they cannot be changed in place (immutable), and they are positionally ordered collections that are accessed by offset (sequence).

Immutable objects don't allow modification after creation:
```python
L = [1, 2, 3]
for x in L:
  x += 1  # Won't update L, since Number is immutable
          # When x is assigned with an integer in L, it's
          # creating a copy of that integer.
```

The bindings (pointers) in an immutable object are unchangable, not the objects they are bound to:
```python
t = ('abc', [1, 2, 3])
t[1].append(4)
# Now t = ('abc', [1, 2, 3, 4])
```

## Python's dynamic typing model

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

## Python syntax

Multiple statements in one line:
```
a = 1; b = 2
```

Single line if statement:
```
if x > y: print(x)
```

**Extended Sequence Unpacking in Python3**

A single _starred name_, `*X` is assigned a list which collects all items in the sequence not assigned to other names:
```
>>> a, *b = 'spam'
>>> b
['p', 'a', 'm']
```

**Loop syntax**:
```
while test:
  statements
else:  # Run if didn't exit loop with break
  statements
  
for target in object:
  statements
else:
  statements  # As above
```

Built-ins that allow you to specialize the iteration in a `for`:
- `range`: an iterable that generates items on demand
  > In Python 2.X, `xrange` can be used in place of `range` for space optimization since `range` build the result list in memory all at once. In Python 3.X, `range` behaves like `xrange`.

- `zip`: takes 1 or more sequences as arguments and returns a series of tuples that pair up parrallel items taken from those sequences:
  ```
  >>> list(zip([1, 2], [3, 4, 5]))
  [(1, 3), (2, 4)]  # zip truncates result tuples at the length of the shortest sequence
  ```

- `enumerate` function returns a generator object that generate (index, value) tuple each time through the loop, allows us to loop through both offsets and items.

`for` loops may run quicker than `while`-based counter loops.

## Python naming convention

- `_X` are not imported by `from module import *`
- `__X__` are system-defined names that have special meaning
- `__X` are localized to enclosing classes
- `_` retains the last result when you're working interactively

## Type

The type of an object is an object of type `type`: a call to `type(X)` returns a type object of object `X`.

Because types can be subclassed in nowadays Python, it is recommended to use `isinstance` to check type of object.

## Boolean

Since `bool` is just a subclass of `int`, `True` and `False` behave exactly like integers `1` and `0`, except that they have customized printing logic.

More generally, every objects in Python are either `True` or `False`:
- Numbers are `False` if 0, `True` otherwise
- Other objects are `False` if empty, `True` otherwise
- `None` object is `False`

Magnitude comparisions return the value `True` or `False`:
```
2 < 3
>>> True
```

But `and` and `or` operators always return an object:
- `or`: returns the first operand that is true.
- `and`: stops as soon as the result is known and return the last operand on the right.
  ```
  [] and {}
  >>> []

  2 and []
  >>> []

  [] and {}
  >>> []
  ```

## String

Non-printables are displayed as `\xNN` hex escapes:
```
>>> S = 'A\0`
>>> S
'A\x00'
```

**raw**: Python supports a _raw_ string literal that turns off the backslash escape mechanism.
```
>>> r'\\'
'\\\\'
```

Despite its role, even a raw string cannot end in a single backslash (or more generally, an odd number of blachslashes), because the backslash escapes the following quote characters (quote characters needs to be escaped to embed it in the string):
```
>>> r'\'  # SyntaxError
```

Automatic concatenation of adjacent strings:
```
>>> name = 'Nhan\n''Nguyen'
>>> print(name)
Nhan
Nguyen
```

Use with parenthesis to allow line spans:
```
name = (
    'Nhan\n'
    'Nguyen'
)
```

**Python string representation, Python 3 perspective**

In Python 3, string literals (or the normal `str` string) handles Unicode text by default, this means `u''` is `''`.

```
>>> len(‘😀’) (*)
1
```

When stored in a file, an Unicode string needs to be translated into a _sequence of bytes_, this process is called *encoding*. In order to do that, each character in the Unicode standard are represented by a *code points*, which is an integer in the range 0 to 0x10FFFF.

The indication for the start of a code point is specified by 3 escape sequences:
- `\x`: 8-bit (2-digit) unicode escape.
- `\u`: 16-bit (4-digit) unicode escape.
- `\U`: 32-bit (8-digit) unicode escape.
- Some characters even use single-letter escapes: `\n` for newline, `\t` for a tab.

```
>>> 'a' === '\x61'
True
>>> 'a' === '\u0061'
True
>>> 'a' == '\U00000061'
True
>>> len('\U00000061')  # string content and length both reflect code points in Unicode-speak
1
```

You can use this syntax to define Unicode string in your code if you want the code is still readable in an ASCII editor:

```
>>> x = '😀'       # instead of this
>>> x = '\u1F600'  # you can use this
>>> print(x)
😀
```

When Unicode characters are read back from files into memory, it is *decoded* into characters (code points). Once it is loaded, we usually process text as strings in decoded form only (the reason why we've got (*).

```
>>> '😀'.encode('utf8')  # utf8 is Python's default encoding
b'\xf0\x9f\x98\x80'
>>> 
```

- `chr(o)`: get the *ch*a*r*acter whose ordinal number (Unicode code point) is `i`.
- `ord(c)`: get the *ord*inal number of the character `c`.

**To encoding a string**: Use `string.encode()`, this returns a byte stream. In a byte string you can only creates bytes in the range of 0 - 255, so a byte stream uses the `\x` notation even when you can't use the full range available to that notation.

```
>>> '\u1F600'.encode()  # utf8 by default
b'\xe1\xbd\xa00'
```

```
>>> 'spam'  # Characters can be 1, 2, or 4 bytes in memory; not necessarily map directly to a single byte.
            # This depends on both external encoding type (see below) and the internal storage scheme used.
>>> 'spam'.encode('utf8')
b'spam'  # 4 bytes
>>> 'spam'.encode('utf16')
b'\xff\xfes\x00p\x00a\x00m\x00'  # 10 bytes
```

**To decode a byte stream**: Use `bytestream.decode()`

One needs to notice that the notion of bytes doesn't apply to Unicode, since some encodings include character code point too large for a byte. So think _characters_ instead of _bytes_ for Python string.

In Python, a zero (null) character (`\0`) does not terminate a string the way a null byte in C does. In fact, no character terminates a string in Python.


An object can have both `str` for general use and `repr` with extra details.
- `repr`: produces results that look as though they were code.
- `str`: produces a more user-friendly format if available.

```
>>> repr('spam')
>>> "'spam'"
>>> print(x)  # we're using print, which uses str(s) instead
>>> 'spam'
>>>
>>> path = r'C:\new\text.dat'
>>> path
>>> 'C:\\new\\text.dat'  # repr
>>> print(path)
>>> C:\new\text.dat      # str, more user-frienly
```

## Tuple

Differentiate: `(4)` is an integer, `(4,)` is a tuple containing an integer.

The immutability of tuples provide some integrity, you can be sure a tuple won't be changed through another reference elsewhere in a program.

## List

We can insert and delete list in-place with *slice assignment*: it performs 2 steps - delete the slice to the left of `=` and the insert the object to the right of `=`.
```
>>> L = [1, 2, 3, 7]
>>> L[1:3] = [4, 5, 6]  # Replacement
[1, 4, 5, 6, 7]
>>> L[1:1] = [2, 3]     # Insertion after index 1
[1, 2, 3, 4, 5, 6, 7]
>>> L[3:] = []          # Deletion
[1, 2, 3]
```

```
>>> L = L + [1, 2]    # Concatenation, slow
>>> L.extend([1, 2])  # Faster, inplace
>>> L += [1, 2]       # Use extend
```

## Set

Some operations on set X and Y:
- `X & Y`: intersection
- `X | Y`: union
- `X - Y`: difference
- `X > Y`: checking if X is superset of Y


Sets can only contain immutable (a.k.a hashable) object types:
```
>>> s = {}
>>> s.add([1,2,3])  # TypeError: unhashable type: 'list'
>>> s.add({1,2,3})  # TypeError: unhashable type: 'set'
>>> s.add(frozenset([1,2,3]))  # If you need to store a set inside another set, use fronzenset
```

## Dict

Fetching a missing key in a dict is not allowed:
```
>>> D = {'a': 1}
>>> D['b']  # KeyError
>>> D['b'] = 2  # It's ok if we assign
```

To avoid this, we use `get` method:
```
>>> D.get('b', 2)
```

Any immutable objects can be keys of dictionary, not only string.

Default dict for a common pattern when we access the key for the first time:

```
from collection import defaultdict

d = defaultdict(int)
d['a'] += 1
```

## Iteration

An object is _iterable_ if:
- either it is physically stored sequentially in memory - physical sequence.
- or it generates one item - virtual sequence.

An iterable object supports the _iteration protocol_: they respond to the `iter` call with an object that advances in response to `next` calls and raises an exception when finished producing values.

List, set, dict, _generator_, enumerate, zip, range, etc. are iterable object.
> Note: only range supports multiple active iterators on the same result.
> Dictionary keys, values and items method return iterable view objects that regenerate items one at a time instead of producing result lists all at once in memory. This means its iterator does not support len() and index.

The iteration protocol based on 2 objects:
- _The iterable object_ you request iteration for, whose `__iter__` is run by `iter`
- _The iterator object_ returned by the iterable that actually produces values during the iteration, supports `__next__` (run by `next`) and raises `StopIteration` exeption when finished producing results.

Behind the scene:
```python
# Top level syntax
for x in L:
  print(x)

# Corresponding underscore method
I = iter(L)
while True:
  try:
    x = next(I)
  except StopIteration:
    break
  print(x)
```

Some built-ins that support the iteration protocol:
- `sum` 
- `max`
- `min`
- `any`: any items of the iterable are true
- `all`: all items of the iterable are true


## Comprehension

Lists, sets, dicts, generators can all be built with comprehensions:

```
>>> [x for x in [1,2,3]]
>>> {x for x in [1,2,3]}
>>> {x: x for x in [1,2,3]}
>>> (x for x in [1,2,3])
```

List comprehension might run faster than manual `for` loop statement (roughly twice as fast) because their iterations are performed at C language speed inside the interpreter

## Operation

`a == b` checks if a and b have same value.

`a is b` checks if a and b refer to same object.

Comparisions operators can be changed: `X < Y < Z`.

**Extended slicing**: `X[I:J:K]`: with a negative K, I must > J.
```
special case when reverse the string
str[::-1]
```

## Function

When Python reaches and runs a `def` statement, it generates a new function object and assigns it to the function's name.

**Enclosing functions**:


## Scope

LEGB rule: when you use an unqualified name inside a function, Python searches up to 4 scopes:
- Local (L) scope
- Enclosing (E) scope: function that contains other functions
- Global (G) scope
- Built-in (B) scope: `import builtins; dir(builtins)`

_global_: refer to variables at the top level of the enclosing module file
```python
y, z = 1, 2
def func():
  global x
  x = y + z
func()
print(x)  # 3
```
