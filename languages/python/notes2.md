Python built-in objects:
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

---

Immutable:
- Boolean
- Number
- Tuple: List that cannot be changed.
- String
- Frozenset

---

Non-printables are displayed as `\xNN` hex escapes:

```
>>> S = 'A\0`
>>> S
'A\x00'
```

---

Python supports a _raw_ string literal that turns off the backslash escape mechanism.

```
>>> r'\\'
'\\\\'
```

---

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
>>> len('\U00000061')
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
>>> 'spam'  # Characters can be 1, 2, or 4 bytes in memory
>>> 'spam'.encode('utf8')
b'spam'  # 4 bytes
>>> 'spam'.encode('utf16')
b'\xff\xfes\x00p\x00a\x00m\x00'  # 10 bytes
```

**To decode a byte stream**: Use `bytestream.decode()`

One needs to notice that the notion of bytes doesn't apply to Unicode, since some encodings include character code point too large for a byte:

---

Lists, sets, dicts, generators can all be built with comprehensions:

```
>>> [x for x in [1,2,3]]
>>> {x for x in [1,2,3]}
>>> {x: x for x in [1,2,3]}
>>> (x for x in [1,2,3])
```

---

**Dicts**

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

---

_Sequences_ are positionally ordered collection of objects that support sequence operations such as indexing, slicing.

_Mappings_ denotes objects that map keys to associated values like dict.

An object is _iterable_ if:
- either it is physically stored sequentially in memory - physical sequence.
- or it generates one item - virtual sequence.

An iterable object supports the _iteration protocol_: they respond to the `iter` call with an object that advances in response to `next` calls and raises an exception when finished producing values.

List, set, dict, _generator_, etc. are iterable object.

_TODO: iteration, generator.

---

Some operations on set X and Y:
- `X & Y`: intersection
- `X | Y`: union
- `X - Y`: difference
- `X > Y`: checking if X is superset of Y

---

Comparisions operators can be changed: `X < Y < Z`.

---

An object can have both `str` for general use and `repr` with extra details.
- `repr`: produces results that look as though they were code.
- `str`: produces a more user-friendly format if available.


```
>>> repr('spam')
>>> "'spam'"
>>> print(x)  # we're using print, which uses str(s) instead
>>> 'spam'
```

---

Sets can only contain immutable (a.k.a hashable) object types:

```
>>> s = {}
>>> s.add([1,2,3])  # TypeError: unhashable type: 'list'
>>> s.add({1,2,3})  # TypeError: unhashable type: 'set'
>>> s.add(frozenset([1,2,3]))  # If you need to store a set inside another set, use fronzenset
```

---

Since `bool` is just a subclass of `int`, `True` and `False` behave exactly like integers `1` and `0`, except that they have customized printing logic.
