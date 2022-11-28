## JavaScript origin

Oracle owns the official trademark for the name "JavaScript", this trademark is almost never enforced.

Further distancing from this Oracle-owned trademark, the official name for the language specified by TC39 and formalized by the ECMA standards is **ECMAScript** (ES). Since 2019, it is suffixed by the revision year (ES2019, etc.).

In other words, the JS that runs in your browser is an implementation of the ES standards.

TC39 is the technical steering committee that manages JS. They submit agreed changes to ECMA, the standards organization.

---

## JS Environments

JS environments: browsers, servers (Node.js), robots, etc. The web is dominant one.

There are some JS APIs exist in this environment but not in others (for example `alert`, `console.*` only exist in web env). So the claim "JS is so inconsistent!" is not due to the language itself, but due to different environment behaviors.

---

## JS's backward and forward compatibility

JS offers backward, but not forward compatibility. 

Two mechanisms to support forward compatibility are:
- Transpiling (most popular tool is Babel): convert source code from one form to another. This solves forward-compatibility problems related to syntax.
- Polyfill: the pattern of providing a definition of a new API for an older environment that does not support it. Transpilers like Babel detects which polyfills your code needs and provide them automatically for you.

---

## Is JS a interpreted or compiled language?

Interpreted (scripted) languages are executed in a top-down and line-by-line fashion; there's typically not extra step to process the source code before execution begins. Errors in some line of code won't be discovered until that code is executed.

Compiled languages go through 2 phases before execution: parsing and compilation.

JS source is a parsed language, then go through a "compilation" phase to produce a binary byte code, which is handled to the JS virtual machine to execute (some like to say this VM is "interpreting" the byte code). So we can say JS is a compiled language.

---

## JS program's flow
2 phase processing (parsing/compilation -> execution):
- The source gets transpiled (e.g. by Babel), then packed by Webpack, then it gets delivered to a JS engine.
- JS engine parses the code to an Abstract Syntax Tree.
- JS engine converts/"compiles" the AST to kind-of byte code (a binary intermediate representation).
- The byte code is refined/converted further by the optimizing Just-In-Time compiler.
- JS virtual machine executes the program.

Note: JS engines don't have the luxury of an abundance of time to perform their work and optimizations because JS compilation does not happen in a build step ahead of time (as with other compiled languages). It usually must happen in mere microseconds right before the code gets executed. To ensure the fastest performance under these constraints, JS engines use all kinds of trics (like JITs, which lazy compile and even hot recompile).

---

## Web Assembly (WASM)

WASM's original intent was to provide a path to convert non-JS programs to a form that could run in the JS engine.

WASM is a representation format that can be process by JS engine by skippping parsing/compilation (that the JS engine normally does). The parsing/compilation of a WASM-targeted program happen ahead of time, JS engine just receives binanry-packed program ready to be executed with minimal processing.

WASM motivation:
- Improve JS runtime.
- Bring features from other languages to JS.
- Become a cross-platform VM (where programs can be compiled once and run in different environments).

---

## Strict mode

Strict mode can be turned on per file or function basis. It is vastly better to turn it on for the entire file.

Virtually all transpiled code ends up in strict mode (even if original source isn't written as such). ES6 modules assume strict mode, so all code in such files is default to strict mode.

---

## JS Foundation Knowledge

### Each file is a program

In JS, each standalone file is its own separate program. Many projects use build process tools to combine separate files into a single file to be delivered to a web page. When this happens, JS treats this single combined file as the entire program.

The way multiple .js files act as a single program is by sharing their state via the "global scope". They mix together in this global scope namespace.

Modules are supported since ES6, and they are also file-based. A file is treated as a module if it is loaded via module-loading mechanism such as an `import` statement or a `<script type=module>` tag.

You should think each file as its own mini program, which may then cooperate with other (mini) programs.

### === operator

For primitives, `===` operator lies in 2 cases:

```js
NaN === NaN  // false
0 === -0  // true
```

Therefore it's best to avoid `===` for them. For `NaN` use `Number.isNaN` function.

When comparing non-primitives (objects) using `===`, identity equality is used (compared by reference):

```js
[1, 2, 3] === [1, 2, 3]  // false
{ a: 42 } === { a: 42 }  // false
```

JS does not provide a mechanism for structural equality comparision of object values. You'll need to implement it yourself.

### Modules

Modules help group data and behavior together into logic units as classes.

ES modules (ESM) is a module syntax/pattern introduced in ES6. ESMs are:
- File-based: one file, one module.
- `export` keyword is used to add a variable or method to its public API definition. If something is defined in the module but not exported, it stays hidden.
- You don't "instantiate" an ES module, you `import` it to use its single instance. ESMs are in effect "singleton", there's only one instance ever created at first `import` in your program, all other `import`s just receive a reference to that same single instance.


---

## JS Root Knowledge

### Iteration

The protocol for the **iterator** pattern defines a `next` method whose return is an *iterator result* object.

Consuming iterators:

```js
// ** Scenario 1: for of **
var it = someArray.entries();  // an iterator

// loop over all entries one at a time
for(let val of it) {
    // .. 
}

// ** Scenario 2 **
// loop over all value one at a time,
// copy iterated value into vals.
var vals = [ ...it ];

// ** Scenario 3 **
// loop over all value one at a time,
// each iterated value occupies an argument position.
func( ...it )
```

An **iterable** is a value that can be iterated over, this works by creating an iterator instance from the iterable, and consumes that iterator instance to its completion.

ES6 defines basic data structure/collection types in JS as iterables (strings, arrays, maps, sets, etc.):

```js
for (let var of someArray) {
    //...
}

// Shallow copy
var anotherArray = [ ...someArray ];
```

For the most parts, all built-in iterables in JS have 3 iterator forms available: keys-only (`keys()`), values-only (`values()`), and entries (`entries()`).

### Closure

Closure is when a function remembers and continues to access variables from outside its scope, even when the function is executed in a different scope.

Objects don't get closures, functions do.

```js
function greeting(msg) {
    return function who(name) {
        console.log(`${ msg }, ${ name }!`);
    }
}

var hello = greeting("Hello");
hello("Kyle");  // Hello, Kyle!

// ...

// We'd expect that msg is garbage collected after greeting finishes running, but it doesn't.

// This is because the inner function (who) instance is still alive (assigned to hello var), its closure is still preserving the msg variables.
```

Closures are not a snapshot but direct link and preservation of the variable itself. This means it can observe or make updates to these variables over time:

```js
function counter(step) {
    var count = 0;
    return function increaseCount() {
        count += step;
        return count;
    }
}

var incBy1 = counter(1);
incBy1();  // 1
incBy1();  // 2
```

The outer scope is not necessarily always a function:

```js
for (let [idx, btn] of buttons.entries()) {
    btn.addEventListener("click", function onClick() {
        console.log(`${Clicked on button ${ idx }}`);
    });
}
```

With `let` declarations, each iteration gets new block-scoped `idx` and `btn` variables, the inner `onClick` function preserves them for as long as the click handler is set on the `btn`.

### `this` Keyword

Misconceptions:
- A function's `this` refers to the function itself.
- `this` points to the instance that a method belongs to.

Besides their enclosing scope (attached via closure), functions have another charasteristic that influences what they can access: an *execution context*, and it is exposed to the function via its `this` keyword:
- Scope is static, it contains a fixed set of variables available at the moment and location you define a function.
- An execution context is dynamic, entirely dependent on **how it is called**.

Execution context is like a tangible object whose properties are made available to a function (via `this` keyword) while it executes:

```js
function classroom(teacher) {
    return function study() {
        console.log(`${ teacher } says to study ${ this.topic }`);
    }
}

// Inner function study access this object,
// so this is a this/context-aware function.

// Example 1
var assignment = classroom("Kyle");
// "Kyle says to study undefined".
// This program is not in strict mode, context-aware functions
// called with no context specified default the context to
// the global object. As there is no global variable named
// topic, this.topic resolved to undefineds.
assignment();

// Example 2
var homework = { topic: "JS", assignment: assigment };
// "Kyle says to study JS".
// This for assignment function call will be homework object.
homework.assignment();

// Example 3
var otherHomework = { topic: "Math" };
// "Kyle says to study Math".
// call() method takes otherHomework object to use for
// setting the this reference for the function call.
assignment.call(otherHomework);
```

Benefit of context-aware functions is the ability to more flexibily re-use a single function with data from different objects.

### Prototypes

Where `this` is a charasteristic of function execution, a `prototype` is a charasteristic of an object, and specifically resolution of a property access.

Prototype is like a linkage between 2 objects; the linkage is hidden behind the scene, but there are ways to expose and observe it. This linkage occurs when an object is created, it is linked to another object that already exists.

A series of objects linked together via prototypes is called the **prototype chain**.

The purpose of this prototype linkage (from object B to A) is so that accesses against B for properties/methods that B does not have, are delegated to A to handle.

```js
// homework object's default property linkage connects
// to Object.prototype object, which has built-in methods
// such as toString(), valueOf(), etc.
var homework = {
    topic: "JS"
};

// Linkage delegation to Object.prototype.toString()
homework.toString();  // [object Object]
```

`Object.create(...)` was added in ES5 and can be used to define an object prototype linkage:

```js
// First argument is the object to link the newly created one to.
// Return the newly created and linked object.
var otherHomework = Object.create(homework);

// Linkage chain:
// otherHomework
//    -prototype-> homework
//    -prototype-> Object.prototype.
otherHomework.topic;  // "JS"
```

One of reason `this` supports (or `this` being dynamic) dynamic context based on how the function is called is so that method calls on objects which delegate through the prototype chain still maintain the expected `this`. This is a critical component of allowing prototype delegation, and indeed `class` to work as expected.

```js
var homework = {
    study() {
        console.log(`${ this.topic }`);
    }
}

var jsHomework = Object.create(homework);
jsHomework.topic = "JS";

// study is delegated to homework object through prototype chain.
// this resolves to jsHomework because of how the function is called (called on jsHomework).
jsHomework.study();  // "JS"
```

For many years, people implemented class design pattern on top of prototypes - so-called "prototypal inheritance" and then with the advent of ES6's `class` keyword, the language is more inclined toward OOP.

All functions by default reference an empty object at a property named `prototype`. This is the prototype object linked to the function when objects are created by calling the function with `new`. This "prototype class" pattern is now strongly discouraged in favor of using ES6's `class` mechanism:

```js
function Classroom() {}

Classroom.prototype.welcome = function hello() {}

var mathClass = new Classroom();
mathClass.welcome();
```

`Classroom` itself (and functions themselves) is not constructors. Putting `new` in front of a normal function call sort of hijacks it and calls it in a fashion that constructs an object as a side effect, that makes that function call a "constructor call".

In short, in JS functions aren't constructors, but function calls are "constructor calls" if and only if `new` is used.