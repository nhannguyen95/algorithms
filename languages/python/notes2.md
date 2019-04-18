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
- Tuple
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
- `\x`: 8-bit unicode character.
- `\u`: 16-bit unicode character.
- `\U`: 32-bit unicode character.

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
