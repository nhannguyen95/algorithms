## Scope

Scope is (usually, see below) determined as compile time and is not actually created until runtime. In non-strict mode it can be also modified at runtime by using `eval` and `with`, this is bad practice and should be avoided:

```js
// By using eval:
// Modifying badIdea's scope at runtime.
function badIdea() {
    eval("var str = 'abc';");
    console.log(str);  // "abc"
}
badIdea();

// By using with:
// scopeObj is turned into a scope at runtime.
var scopeObj = { str: "abc" };
with (scopeObj) {
    console.log(abc);
}
```

Each scope has a Scope Manager instance that keeps a list of all identifiers (variables) declared in that scope and is responsible for looking them up when asked.

If the variable is a target (being assigned value to) and strict-mode is not in effect. The global scope's Manager will create an accidental global variable if that target variable is not declared:

```js
function getStudentName() {
    // a nextStudent variable is created at global scope.
    // A ReferenceError will be thrown if in strict mode.
    nextStudent = "Suzy";
}
getStudentName();
console.log(nextStudent);  // Suzy
```

Variable not found is not necessarily an error, another file in the runtime might already declare that variable in the shared global scope. So the ultimate determination of whether the variable was ever appropriately declared in some scope may need to be deferred to the runtime.

The pattern of defining a `function` expression then immediately invoke it is called **Immediately Invoked Function Expression (IIFE)**. IIFE is useful when we want to create a scope to hide variables/functions:

```js
// outer scope

(function() {
    // inner hidden scope
})();

// outer scope
```

In general, any `{...}` curly-brace pair which is a statement will act as a block, but not necessarily as a scope. A block only becomes a scope if necessary (for example when there's a `let/const` variable declaration in the block). However note that:
- `class`'s `{...}` is not a block or scope.
- `switch`'s `{...}` does not define a block/scope.

Arrow functions also create scopes.

---

## Shadowing

`let` can shadow `var`, but `var` cannot shadow `let` unless there is a function boundary in between:

```js
function something() {
    var special = "js";
    {
        let special = 42;  // shadowing var
    }
}

function another() {
    let special = "js";
    {
        var special = "js";  // syntax error

        ajax("url", function callback() {
            var special = "js";  // shadowing var
        });
    }
}
```

JS is full of strange scoping behaviors for backward-compatibility reason. To avoid them:
- Never shadow parameters with local variables.
- Never shadow function name identifiers.
- Avoid using a default parameter function that closes over any of the parameters:
  ```js
  // Don't to this!
  function someFunction(id, default = () => id) {

  }
  ```

---

## Global scope

In addition to accounting for how different modules/pieces of code are able to access other pieces to cooperate, the global scope is also where:
- JS exposes its built-ins: primitive types, natives (`Date()`, `Object()`, etc.), global funcitons (`parseInt()`), namespaces (`Math`, `JSON`), friends of JS (`WebAssembly`).
- The environment hosting the JS engine exposes its own built-ins: `console`, the DOM (`window`, `document`, etc.) timers (`setTimeout`), web platform APIs (`natigator`, `history`, `WebRTC`, etc.).

Different JS environments handle scopes, especially global scope differently. A program may or may not:
- declare a global variable in the top-level scope with `var` or `function` declarations - or `let`, `const` and `class`.
- add global variables as properties of the global scope object if `var` or `function` are used for declaration.
- refer to global scope object with `window` (browser), `self` or `global` (Node).

As of ES2020, JS has finally defined a standardized reference to the global scope object, called `globalThis`.

---

## Hoisting

`Hoisting` is the most commonly used term for a variable (**identifier**) being visible from the begining of its enclosing/function scope, even though its declaration may appear further down in the scope.

`function` hoisting and `var`-flavored variable hoisting attach their name identifiers to the nearest enlosing **function scope** (or global scope), this is called function-scoped. While `let` and `const` hoisting attach to their **enclosing block scope**, this is called block-scoped.

With formal `function` declaration, beside the function identifier, the assignment value (initialization) is also hoisted. This is not true for `function` expression assignments:

```js
greeting();   // TypeError (means greeting variable was found
              // but not identified as a function, variables
              // declared with var are automatically initilized
              // to undefined at the beginning of their scope)

greeting2();    // OK (greeting2 is hoisted and initialized to
                // its function value)
              
                // In all cases, the identifiers are hoisted.

var greeting = function greeting() {};
function greeting2() {};
```
`let/const` declarations do not automaically initialize at the begining of the scope, the way `var` declaration do. The period of time from the entering of a scope to where the auto-initialization of the variable occurs is called **Temporal Dead Zone (TDZ)**. The TDZ is the time window where a variable exists but it still uninitialized, and therefore cannot be accessed in any way:

```js

console.log(x);  // undefined.
                 // Declaration/Registration for x is hoisted,
                 // then x is initialized with undefined.

var x = "abc";   // Assign x with "abc".

var x;
console.log(x);  // Should print "abc", since due to hoisting,
                 // the order is:
                 // var x;  // hoisted
                 // var x;  // hoisted
                 // x = "abc";
                 // console.log(x);

console.log(z)   // Reference error, since while let (and const) variables are hoisted,
                 // they are not initialized with a default value like var (undefined).
                 // So an exception will be thown if let (and const) variables are read
                 // before they are initialized.
let z = 10;      // Initialization for z happens here.
console.log(z);  // Now we can read it.
```


A (variable declared with) `var` has a TDZ whose length is zero, and thus unobservable to our programs, only `let` and `const` have an observable TDZ.

To avoid TDZ error, always put `let` and `const` declarations at the top of any scope to shrink TDZ window to 0.

Note that `function` declarations in Blocks (FiB) behave differently from `var`, `let` and `const` declarations:

```js
if (false) {  // if block
    function ask() {}
}
ask();

// Depending on JS environments, 3 outcomes are possible:
// - JS specification: function declarations inside of blocks are 
//   block-scoped, so ask() will throw a ReferenceError exeption.
// - Browser-based JS engine: ask identifier is scoped outside the
//   if block but the function value is not automatically initialized,
//   so it's undefined. ask() will throw a TypeError exeption (
//   (undefined is not a callable function).
// - ask() call runs correctly.

// Due to this deviation, declaration (not assignment expression)
// should be avoided in practice of functions inside blocks.
```

---

## Closure

Closure is observed when a function uses variable(s) from outer scope(s) even while running in a scope where those variable(s) wouldn't be accessible.

Closure is a behavior of functions and only functions. If you are not dealing with functions, closure does not apply.

For closure to be observed, a function must be invoked, and specifically it must be invoked in a different branch of the scope chain from where it was originally defined (see 1st case below).

Closure is associated with an instance of a function, rather than its single definition:

```js
function counter(step) {
    var count = 0;
    return function increaseCount() {
        count += step;
        return count;
    }
}

var incBy1 = counter(1);  // a new closure associated with incBy1 is created
incBy1();  // 1
incBy1();  // 2, closures are like live links, preserving access to
           // the (count) variable itself.

var incBy2 = counter(2);  // a new closure associated with incBy2 is created
incBy2();  // 2
```

Cases that are not closure:

```js
// All these cases behave the same whether JS functions
// support closure or not.

// 1
function say(myName) {
    var greeting = "Hello";
    // This is lexical scoping, not closure, since the
    // output() call here don't need closure to access
    // myName and greeting.
    output();

    function output() { // use myname and hello }
}

// 2
var students = [...];
function getFirstStudent() {
    return function firstStudent() {
        return students[0].name;
    }
}
// Dont' create closure, since students global variable
// is accessable to all functions.
getFirstStudent()();

// 3
function lookupStudent(studentID) {
    return function nobody() {
        console.log("Nobody");
    }
}

// Don't create closure, since studentID is not accessed.
lookupStudent(1)();
```

Since closure is tied to a function instance, the closure is gone when that instance is garbage collected.

---

## Module pattern

A module is a collection of related data and functions, characterized by a division between hidden private details and public accessible details.

**A module is stateful**, it maintains some information over time, along with functionality to access and update that information.

### Classic module

Construct a "classic module" in the early 2000s using IIFE:

```js
var Student = (function defineStudent() {
    // private details:
    var records = [/* ... */];

    // public accessible details:
    var publicAPI = {
        getName
    };

    function getName(studentID) {
        var student = records.find(
            student => student.id === studentID
        );
        return student.name;
    }
})();

Student.getName(69);
```

### Node's CommonJS

CommonJS are file-based, one module per file.

```js
// Public API is included in module.exports object
// Avoid defining new module.exports = {...} to prevent
// multiple modules circularly depend on each other.
Object.assign(module.exports, {

});

var records = [/*...*/]

function getName(studentID) {
    /* ... */
}

// Use require to include another module instance:
var Student = require("/path/to/student.js");
Student.getName(69);

// To access only part of the API:
var getName = require("/path/to/student.js").getName;
// or:
var { getName } = require("/path/to/student.js");
// The getName method holds closures over the internal
// module details.
```

CommonJS modules behave as singleton instances, similar to the IIFE classic module definition. No matter how many times `require` is called to a module, we just get back the single shared module instance.

Similar to to the classic module format, the publicly exported methods of a CommonJS module's API hold closures over the internal details. That's how the module singleton state is maintained across the lifetime of your program.

### Modern ES Module (ESM)

ESM is also file-based. ESM files are assumed to be strict-mode, without needing a `"use strict"` pragma. There's no way to define a non-strict ESM.

ESM uses an `export` keyword to export its public API. The `import` keyword is like `require` of CommonJS.

The `import` keyword must be used only at the top level of an ESM outside of any blocks or functions.