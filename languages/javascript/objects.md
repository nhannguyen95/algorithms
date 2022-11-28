## `this`

`this` is neither a reference to a function itself, nor is it a reference to the function's lexical scope.

`this` is actually a binding that is made when a fuction is invoked, and what it references is determined by the call-site where the function is called. The call-site is the second item from the top of the shown call stack if you set a break point at where the function gets called (the first item being the fuction call itself).

### Rules of call-site

#### Default binding

Default binding applies when none of the other rules do (think of this as the fallback case).

Global object is eligible for default binding only in non-strict mode:

```js
function nonStrictFoo() {
    this.a;
}

function strictFoo() {
    "use strict";
    this.a;
}

var a = 2;

nonStrictFoo();  // a = 2
strictFoo();     // TypeError: this is undefined
```

One of many reasons that your program should be either strict or non-strict.

#### Implicit binding

Happens when the call-site has a context object:

```js
function foo() { console.log(this.a); }

var obj1 = { a: 2, foo: foo };

ob1.foo();  // 2
```

Only the last level of an object property reference chain matters to the call-site:

```js
function foo() { console.log(this.a); }

var obj1 = { a: 2, foo: foo };

var obj2 = { a: 3, obj1: obj1 };

obj2.obj1.foo();  // 2
```

Note that an implicit bound can lose its binding, call-site is all that matters:

```js
function foo() { console.log(this.a); }

function hoc(fn) {
    fn();  // <-- actual call-site
}

var obj1 = { a: 2, foo: foo };

hoc(obj1.foo);  // undefined (fallback to global object)

// Similarly:
setTimeout(obj1.foo, 100);  // undefined (fallback to global object)
// since internal implementation of setTimeout could
// be something like this:
// function setTimeout(fn, delay) {
//   // wait for `delay` ms
//   fn();  
// }
```

From the above example, we understand that "implicit" means we are not really in control of the call-site to give the intended binding.

#### Explicit binding

Explicit binding is used when you want to force a function call to use a particular object for the `this` binding:

```js
function foo() { console.log(this.a); }

var obj = { a: 2 };

foo.call( obj );
```

The problem with this is that whenever you invoke `foo` with obj `context`, you have to explicitly write `foo.call(obj)`.

#### Hard binding

Hard binding solves the problem of explicit binding by wrap the manual call to `foo` with a high order function:

```js
function foo(something) {
    console.log(this.a, something);
}

function bind(fn, obj) {
    return function() {
        return fn.apply(obj, arguments);
    }
}

var obj = { a: 2 };

var bar = bind(foo, obj);
bar(3);  // 2 3
```

Since this is such a common pattern, `bind` helper is provided as a built-in utility as of ES5 (`Function.prototype.bind`):

```js
// bind returns a new function that is hardcoded to 
// call the original function with the this context
// set as you specified.
var bar = foo.bind(obj);
bar(3);  // 2 3
```

Many new built-in functions provide an optional "context" parameter to ensure your callback function uses a particular `this` without having to use `bind`:

```js
function foo(n) {
    console.log(n, this.id);
}

var obj = { id: 'id' };

// 1 id, 2 id, 3 id
[1, 2, 3].forEach(foo, obj);
```

#### `new` Binding

In JS, constructors are just functions that happen to be called with the `new` operator in front of them. They are not attached to a class, nor are they instantiating a class. So there's really no such thing as "constructor functions", but rather construction calls of functions.

When a function is invoked with a `new` in front of it, the following things are done automatically:
- A brand new object is created out of thin air.
- The newly created object is Prototype-linked.
- The newly created object is set as the `this` binding for that function call.
- Unless the function returns its own alternate object, the `new`-invoked function call will automatically return the newly created/constructed object.

```js
function foo(a) { this.a = a; }

// By calling foo with `new` in front of it, we've
// constructed a new object as the `this` for the
// call of foo.
var bar = new foo(2);
bar.a;  // 2
```

### Determining this

Now we can summarize the rules for determine `this` from a function's call-site. Following these rules from top to bottom and stop when the 1st one applies:

- If the function is called with `new` (`new` binding), `this` is the newly constructed object:
  ```js
  var bar = new foo();  // `this` = bar
  ```
- If the function is called with `call` or `apply` (explicit binding), even hidden inside a `bind` hard binding, `this` is the explicitly specified object:
  ```js
  var bar = foo.call(obj2);  // `this` is obj2
  ``` 
- If the function is called with a context (implicit binding) otherwise known as an owning or containing object, `this` is that context object:
  ```js
  var bar = obj1.foo();  // `this` is obj1
  ```
- Otherwise, default the `this`. If in strict mode, pick `undefined`, otherwise pick the `global` object:
  ```js
  var bar = foo();  // `this` is undefined (strict mode) or global object (non-strict mode)
  ```

### Binding Exceptions

If you pass `null` or `undefined` as a `this` parameter to `call`, `apply` or `bind` (all these utilities require a `this` binding for the first parameter), those values are effectively ignored, and instead the default binding rule applies to the invocation:

```js
function foo() { console.log(this.a); }

var a = 2;

foo.call(null);  // 2
```

This can create problematic side effects in your program (cause the method can modify global object without your awareness), it's safer to use an empty object instead.

### Lexical `this`

Arrow-functions introduced in ES6 do not use the above rules:

```js
function foo() {
  return (a) => {
    // `this` here is lexically inherited from `foo()`
    console.log(this.a);
  }
}

var obj1 = { a: 1 };
var obj2 = { a: 2 };

var bar = foo.call(obj1);
bar.call(obj2);  // 1, not 2, since the lexical binding of an
                 // arrow function cannot be overriden (even with new!)
```

The most common use case will likely be the use of callbacks without having to use `bind`:

```js
// Pre ES6, common pattern to capture lexical this is:
function foo() {
  var self = this;  // lexical capture of `this`
                    // (or `bind` could be used here)
  setTimeout(function() {
    console.log(self.a);
  }, 100);
}

// With arrow functions, `this` is lexically captured
// automatically as shown above:
function foo() {
  setTimeout(() => {
    // `this` here is lexically inherited from `foo()`
    console.log(this.a);
  }, 100);
}
```

The above approaches (`self=this` or arrow functions) are essentially fleeing from `this` instead of understanding and embracing it (using `bind`...)

---

## Objects

Objects come in 2 forms: declarative (literal) form `var myObj = {}` and constructed form `var myObj = new Object()`. They result in exactly the same sort of object.

Objects are one of the 6 primitive types in JS:
- `string`
- `number`
- `boolean`
- `null`
- `undefined`
- `object` (`typeof null` resulting  in `"object"` is a bug in JS).

There are several built-in object subtypes:
- `String` (`string`/`String` is like `int`/`Integer` in Java)
- `Number`
- `Boolean`
- `Object`
- `Function`
- `Array`
- `Date`
- `RegExp`
- `Error`

In JS these are actually just built-in functions thus can be used as a constructor (called with `new` operator to construct new objects):
```js
var strPrimitive = 'abc';
typeof strPrimitive;  // "string"

var strObject = new String('abc');
typeof strObject; // "object"
```

To perform operations on primitive values (`strPrimitive`) such as checking its length, accessing character contents etc. a corresponding object wrapper form (`String`) is required. Luckily JS automatically coerces a primitive to its corresponding object wrapper form:
```js
"abc".length;       // OK
69.123.toFixed(2);  // OK
```

Notes:
- `null` and `undefined` have no object wrapper form, only their primitive values.
- `Dates` can only be created with constructed object form, as they have no literal form counterpart.
- `Objects`, `Arrays`, `Functions`, `RegExps` are all objects regardless of whether the literal or constructed form is used.

In objects, property names are always strings. If you use any other value besides a string, it will first be converted to a string:
```js
var myObj = {};
myObj[true] = 'foo';
myObj[3] = 'bar';
myObj[myObj] = 'baz';

/*
myObj = {
  'true': 'foo',
  '3': 'bar',
  '[object Object]': 'baz'
}
*/
```

Shallow copy is fairly understandable and has far fewer issues than deep copy, so ES6 defined `Object.assign()` for this task:
```js
var newObj = Object.assign( {}, myObj );
/*
newObj = {
  'true': 'foo',
  '3': 'bar',
  '[object Object]': 'baz'
}
```

As of ES5, all properties are described in terms of a property descriptor:
```js
var myObject = { a: 2 };

Object.getOwnPropertyDescriptor(myObject, 'a');
/*
{
  value: 2,
  writable: true,
  enumerable: true,
  configurable: true
}
*/
```

We can also use `Object.defineProperty()` to add new property:
```js
var myObject = {};

Object.defineProperty(myObject, 'a', {
  value: 2,
  writable: true,
  enumerable: true,
  configurable: true
});

myObject.a;  // 2
```

Notes:
- `writable`: control whether the property's value can be changed (via assignment for example). You can set `writable=false` to make a property *constant* (*immutable*), which means cannot be changed, redefined, or deleted.
- `configurable`: control whether the property can be modified using the same `Object.defineProperty` utility. `configurable=false` also prevents `delete` operator from removing an existing property.
- `enumerable`: control whether the property will show up in certain object-property enumerations such as `for...in` loop. Properties with `enumerable=false` won't show up in `Object.keys()`, to get all properties use `Object.getOwnPropertyNames(...)` (both inspect only the direct object specified without consulting the `[[Prototype]]` chain).

To make a property of an object *constant* or *immutable*, beside setting `writable=false`, we can also use the following functionalities:
- using `Object.preventExtensions(obj)`: it just prevents new properties from being added to the object, existing properties can still be modified..
- using `Object.seal(obj)`: like `Object.preventExtensions`, and also marks all its existing properties as `configurable=false`, which means you cannot re-configure or delete them, but can still modify their values.
- using `Object.freeze(obj)`: like `Object.seal`, but also marks all properties as `writable=false`. This approach is the highest level of immutability you can attain for an object itself.

### Getters and Setters

When accessing/assigning a property by `obj.a`/`obj.a=1`, the object's (default) implicit `[[Get]]` and `[[Put]]` are invoked.

ES5 introduced a way to override these default operations on a per-property level through the use of getters and settesr. Getters and setters are properties that actually call a hidden function to retrieve/set a value:
```js
var myObject = {
  // define a getter for a.
  get a() {
    return this._a_;  // nothing special about _a_ name
  },

  // define a setter for a.
  set a(val) {
    this._a_ = val * 2;
  }
}

Object.defineProperty(myObject, 'b', {
  get: function() { return this.a * 2 },
  enumerable: true
});

myObject.a = 2; 
myObject.a;  // 4
myObject.b;  // 8
```

To check if an object has a property, we can use:
- `in` operator: this checks if a property is in an object, or if it exists at any higher level of the `[[Prototype]]` chain object traversal.
- `obj.hasOwnProperty()`: this checks if a property is in an object without consulting the `[[Prototype]]` chain. Note that `obj` might be created without being linked to `Object.prototype`, in that case `obj.hasOwnProperty()` call will fail. A more robust call is `Object.prototype.hasOwnProperty.call(obj, ...)`.

### Enumeration & iteration

The `for..in` loop will enumerate through properties whose's `enumerable` is true.

`for..in` loop used on arrays will include not only all the numeric indicies, but also any enumerable properties. So we should only use `for..in` loop on objects, and traditional for loops with numeric index iteration for arrays.

The order of iteration over an object's properties is not guaranteed and vary between different JS engines, so do not rely on any observed ordering for anything that requires consistentcy among environments.

ES6 adds the `for..of` loop that will help iterate over the values of arrays/objects (instead of array indicies/object properties).

## Class

Even JS has had some class-like syntactic elements (such as `class` keyword in ES6), JS don't actually have classes. Since classes are a design patter, prior to ES6 we can implement approximations for much of classical class functionality.

### ES6 Class

Classes in traditional class-oriented languages produce a copy action from parent to child to instance, whereas in Prototype, the action is not copy, but rather a delegation link. Since the `class` keyword introduced in ES6 is mostly just syntactic surgar on top of the existing Prototype mechianism, the child class (or instance) is just linked to the parent class (or class) rather than a copy:

```js
class C {
  hello() {
    console.log("original hello");
  }
}

var c = new C();
c.hello();  // "original hello"

C.prototype.hello = function() {
  console.log("modified hello");
}
c.hello();  // "modified hello"
```

`class` syntax do not provide a way to declare class member properties, only methods. So if you need to track shared states among instances, then you end up going back to the ugly `.prototype` syntax, like this:

```javascript
class C {
  constructor() {
    C.prototype.count++;
  }
}
C.prototype.count = ;

var c1 = new C();
var c2 = new C();

// Event worse, this would implicitly create a separate
// shadowed `.count` property on both c1 and c2, rather
// than updating the shared state.
c1.count === c2.count;  // true
```

`class` offers very little support for any of the pitfalls that this dynamicism can bring, as if it is telling you: "Dynamic is too hard, so it's probably not a good idea. Here'a a static-looking syntax, so code your stuff statically".

## Prototypes

Objects in JS have an internal property: `[[Prototype]]`, which is simply a reference to another object. Almost all objects are given a non-null value for this property at the time of their creation.

When a property on an object is invoked, the first step is to check if the object has that property, if not the prototype chain will be consulted up to the top end, this is called prototype chain lookup process.

`for..in` loop will iterate any property of an object that can be reached via its chain, not only direct properties on it.

The top end of every normal property chain is the built-in `Object.prototype`. This object includes common builtin utilities used all over JS (e.g. `toString()`, `.valueOf()`, `hasOwnProperty()`).

Consider the assignment `myObj.foo = "bar"`, there are 3 possible scenarios if `foo` is not directly on `myObj` but at a higher level of its prototype chain:
- If there exists a normal data accessor named `foo` found anywhere on the prototype chain, and is not marked as read-only, then a new property `foo` is added directly to `myObj`. This results in a shadowed property.
- If `foo` is found on the prototype chain, but is marked as read-only, then the assigment is not allowed, error will be thrown in strict mode.
- If `foo` is found on the prototype chain, and is a setter, then the setter will be called, no `foo` is added to `myObj`.

If you want to shadow `foo` in last 2 cases, you must use `Object.defineProperty(...)`.

`a instanceof Foo` checks if the object arbitrarily pointed to by `Foo.prototype` (not `Foo`!, hence the name `instanceof` is a bit confusing) ever appear in the entire prototype chain of `a`.

`b.isPrototypeOf(c)` checks if b appears anywhere in c's prototype chain.

`Object.create(null)` creates an object that has an empty (null) prototype linkage, and thus the object can't delegate anywhere. Since such an object has no prototype chain, the `instanceof` operator always returns false. These special empty-prototype objects are called "dictionaries" and are used for storing data in properties, mostly because they have no surprise effects from any delegated properties/functions on the prototype chain, and are thus purely flat data storage.

Type introspection means to reason about the structure/capabilities of an object on how it was created. For example to check if object `a1` has the ability to call `something`:
- We can check for the relationship between `a1` and an object/class that holds the delegatable `something` function (say Foo): `a1 instanceof Foo` or `Foo.prototype.isPrototypeOf(a1)` or `Foo.isPrototypOf(a1)`.
- "Duck typeing": `if (a1.something) { a1.something() }`, this introduces risk. For example in ES6 Promises, there's a need to check if an object is a Promise, the way that test is done is to check if the object happends to have a `then()` function present on it. If you have any non-Promise object that happens to have a `then()` method on it for whatever reason you are strongly advised to keep it far away from ES6 Promise mechanism to avoid broken assumption.
  > Duck typing is the general term for type checks that make assumptions about a value's type based on its shape (what properties are present): "If it looks like a duck, and quacks like a duck, it must be a duck".

