Python code runs immediately after it is written. There is no compile-time phase: no creation of functions, classes; no linkage of modules.

```
source   ->  byte code  ->  runtime
m.py         m.pyc          PVM (execute byte code)
```

We can also standalone binary executables from Python programs.

---

CPython is the standard implementation of Python, it is written in ANSI C.

Pypy is an reimplementation of CPython that runs much quicker, space is also optimized.

---

The system path should include Python's install directory. On MAC it's at `/usr/local/bin/python` or `/usr/bin/python3`.

---

`modules`: files imported from another file.

`scripts`: main file.

---

Turn Python files into executable scripts, instead of hardcoding the path to the Python interpreter `#!/usr/local/bin/python`, use Unix env lookup: `#!/usr/bin/env python`.

---

**Import**

Because `import`s are expensive, `import`s of the same module are only imported once, unless you use `reload`.

Whether you use `import` or `from..import`, statements in the imported modules are executed.

Python searches for imported modules in directory listed in `sys.path` (initialized from a `PYTHONPATH` environment variable), plus a set of standard directories.

If you want to import from another directory, that directory must be listed in your `PYTHONPATH` setting.

---

Names with the form *__X__* are built-in names that are always defined by Python and have special meaning to the interpreter
