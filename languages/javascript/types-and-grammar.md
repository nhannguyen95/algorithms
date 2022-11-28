## Types and values

JS defines 7 built-in types, all of these types except `object` are called primitives:
- null
- undefined
- boolean
- number
- string
- object
- symbol (added in ES6)

In JS, variables don't have types, values do. Variables can hold any value at any time. A variable doesn't have to always holds values of the same initial type that it starts out with. If you use `typeof` against a variable, it's asking the type of the value in the variable.

The `typeof` operator always returns a string.

Any mathematic operation you perform without both operands being `number`s will result in the operation failing to produce a valid `number`, in which case you will get the `NaN` value.

Simple values (scalar primitives) are always assigned/passed by value-copy: null, undefined, string, number, boolean and symbol.

Compound values such as objects (including arrays, and all boxed object wrappers) and `function`s always create a copy of the reference on assignment or passing. To effectively pass a compound value by value-copy, you need to manually make a copy of it, so that the reference passed doesn't still point to the original:
```js
foo(a.slice());  // make a (shallow) copy of array a
```

## Natives

A list of most commonly used natives:
- String()
- Number()
- Boolean()
- Array()
- Object()
- Function()
- RegExp()
- Date()
- Error()
- Symbol()

These natives are actually built-in functions.

The result of the constructor form of value creation (`new String("abc")`) is an object wrapper around the primitive (`"abc"`) value.

## Internall `[[Class]]`

Values that are `typeof` of `"object"` (such as an array) are additionally tagged with an internal `[[Class]]` property (think of this more as an internal classification rather than related to classes from traditional OOP). This property cannot be accessed directly, but can generally be revealed indirectly by using `Object.prototype.toString(...)` method:
```js
Object.prototype.toString.call([1, 2, 3]);
// "[object Array]"  // The internal [[Class]] value of [1, 2, 3] is "Array"
```

## Boxing Wrappers

These object wrappers are very important, it provides access to properties and methods for wrapped primitive. Thanksfully JS automatically wraps (boxes) primitive values to fulfill such access:
```js
var a = "abc";

a.length;  // 3
a.toUpperCase();  // "ABC"
```

Browsers long ago performance-optimized the common cases like these, so in general there's basically no reason to use the object form directly. It's better to just let the boxing happen implicitly where neccessary. In other words, never do things like `new String("abc")` or `new Number(42)`.

The `valueOf` method is to unbox an object wrapper to get the underlying primitive value out:
```js
var a = new String("abc");
a.valueOf();  // "abc"
```

The `Date(..)` and `Error(..)` native constructors are much more useful than other natives (`String(..)`, `Array(..)`, `Function(..)`, etc.), because there is no literal form for either. Most common reason you construct a date object is to get the current Unix timestamp value (`(new Date()).getTime()`), but an easier way is to just call the static helper function defined as of ES5: `Date.now()`.

For `Error(..)` and `Array(..)` constructor, `new` and without `new` are the same.

In addition to the general `Error(..)` native, there are several other specific-error-type natives: `EvalError(..)`, `RangeError(..)`, `ReferenceError(..)`, `SyntaxError(..)`, etc. But it's rare to manually use these specific error natives. They are automatically used if your program actually suffers from a real exception.

## Symbol(..)

`Symbol` is an additional primitive value type which has been added in ES6.

`Symbol`s are special "unique" (not strictly-guaranteed) values that can be used as properties on objects with little fear of any collision.

There are several predefined symbols in ES6, accessed as static properties of the `Symbol` function object: `Symbol.create`, `Symbol.iterator`:
```js
obj[Symbol.iterator] = function () { /*... */ }
```

To define your own custom symbols:
```js
var mysym = Symbol("my own symbol");  // You're not allowed to use new with Symbol(..) native constructor.

// Symbols can be used as properties on objects.
var a = {};
a[mysym] = "foobar";
```

Using `symbol`s for private or special properties is likely their primary use case.

## Native Prototypes

Each of the built-in native constructors has its own `.prototype` object (`Array.prototype`, `String.prototype`, etc.). These objects contain behavior unique to their particular object subtype.

For string methods such as `String.substr(..)`, `String.trim(..)`; they don't modify the string in place, instead they create new value from the existing one. Similarly, all functions have access to `apply(..)`, `call(..)`, and `bind(..)` because `Function.prototype` defines them.

## Coercion

Converting a value from one type to another is often called "type casting" when done explicitly, and "coercion" when done implicitly.

JavaScript coercions always result in one of the scalar primitive values (`string`, `number`, `boolean`), not complex value like `object` or `function`.

### Abstract Value Operations

#### ToString

When any non-string value is coerced to a `string` representation, the conversion is handled by the `ToString` abstract operation. For regular objects, unless you specify your own, the default `toString()` (located in `Object.prototype.toString()`) will return the internal `[[Class]]`, for instance `[object Object]` (if an object has its own `toString()` method on it, and you use that object in a `string`-like way, its `toString()` will automatically be called, and the `string` result of that call will be used instead):
```js
var obj = { toString: function() { return "obj"; } }
obj + "abc";  // "objabc"
```

`JSON.stringify(...)` is used to serialize a JSON-safe value to a JSON-compatible `string` value. JSON-safe values do not contain `undefined`s, `function`s, (ES6+) `symbol`s and `object`s with circular references. `JSON.stringify(..)` will omit `undefined`, `function`, and `symbol` values when it comes across them. If such a value is found in an array, that value is replaced by `null`. If found as a property of an object, that property is excluded.

If an `object` value has a `toJSON()` method defined, this method will be called first to get **a value to use for serialization**.
```js
var obj = {
    key: 42,
    func: function() {},
    toJSON: function() {
        return {
            key: 41
        };
    }
};
JSON.stringify(obj);  // '{"key":41}'
```

#### ToNumber

When any non-string value is coerced to a `string` representation, the conversion is handled by the `ToNumber` abstract operation. For objects and arrays, they will first be converted to their primitive value equivalent, and the resulting value is coerced to a `number` according to the `ToNumber` operation.

To convert to this primitive value equivalent, the `ToPrimitive` abstract operation will consult the value in question to see if it has a `valueOf()` method. If `valueOf()` is available and it returns a primitive value, that value is used for coercion. If not, `toString()` will provide the value for the coercion, if present. If neither operation can provide a primitive value, a `TypeError` is thrown.

#### ToBoolean

In JS 0, 1 are not identical to false, true. While that may be true in other languages, in JS the numbers are `number`s and the booleans are `boolean`s.

All of JS's values can be divided into 2 categories:
- Values that will become `false` if coerced to `boolean`.
- Everything else (which will obviously become `true`).

In the first category, we get the following as the so-called "falsy" values list:
- `undefined`.
- `null`.
- `false`.
- `+0`, `-0` and `NaN`.
- `""`.

Note that `Boolean` object wrapper around a falsy value does not get resolved to `false`:
```js
var a = new Boolean(false);
a;  // true
```

In the first category, we also have "falsy objects" which are values that look and act like a normal object but when you coerce it to a boolean, it coerces to a `false` value.

### Explicit Coercion

#### string <-> number
To coerce between strings and numbers, we use the built-in `String(..)` and `Number(..)` functions (which we referred to as "native constructors"), but **very importantly** we do not use the `new` keyword in front of them:
```js
var piStr = "3.14";
var pi = Number(piStr);
pi;  // 3.14
```

`String(..)` coerces from any other value to a primitive `string` value using the rule of the `ToString` operation discussed earlier.

`Number(..)` coerces from any other value to a primitive `number` value using the rule of the `ToNumber` operation discussed earlier.

Besides `String(..)` and `Number(..)` there are other ways to explicitly convert these values between `string` and `number`:
```js
var a = "42".toString();  // number -> string

var c = "3.14";
var d = +c;
d;  // 3.14, string -> number
```

#### Date to number

The unary `+` operator can also be used to coerce a `Date` object into a `number`, because the result is the Unix timestamp representation of the date/time value:
```js
var d = new Date("Mon, 18 Aug 2013 00:00:00 CDT");
+d;  // 1376802000000
```

There are also several different ways to convert a Date to a number as mentioned above.

#### Parsing Numeric Strings

Unlike corercion, parsing a numeric value out of a string is tolerant of non-numeric characters:
```js
var a = "42px";

Number(a);    // NaN
parseInt(a);  // 42 (parsing from left to right)
```

`parseFloat(..)` is a twin of `parseInt(..)`.

If you pass a non-`string`, the value you pass will automatically be coerced to a `string` first.

Prior to ES5, if you didn't pass a second argument to indicate which numeric base to use for interpreting the numeric `string` contents, `parseInt(..)` would look at the first character to make a guess:
- If it was `x` or `X`, the guess is to parse to a hexadecimal number.
- It it was `0`, the guess is to parse to an octal number.

As of ES5, the default numeric base is 10.

#### non-boolean -> boolean

Just like with `String(..)` and `Number(..)`, `Boolean(..)` (without the `new`) is an explicit way of forcing the `ToBoolean` coercion:
```js
Boolean([]);    // true
Boolean(null);  // false
```

Just like the unary `+` operator coerces a value to a `number`, the unary `!` negate operator explicitly coerces a value to a `boolean`, the problem is that it also flips the value from truthy to falsy or vice versa, so JS developers commonly use the `!!` double-negate operator.

Any of these `ToBoolean` coercions would happen implicitly without the `Boolean(..)` or `!!` if used in a `boolean` context such as an `if (..)` statement. But the goal here is to explicitly force the value to a `boolean` to make it clearer that the `ToBoolean` coercion is intended.

### Operator || and &&

These operators aren't actually "logical operators", it's more like "selector operators" or more completely "operand selector operators". This is because they don't actually result in a logic value (`boolean`) in JS, instead they result in the value of one (and only one) of their two operands.

Both operands perform a `boolean` test on the first operand. If the operand is not already `boolean`, a normal `ToBoolean` coercion occurs so that the test can be performed:
- For the `||` operator, if the test is `true`, it returns the value of the first operand otherwise the second operand's.
- For the `&&` operator, if the test is `true`, it returns the value of the second operand and otherwise first operand's.

```js
var a = 42;
var b = "abc";
var c = null;

a || b;  // 42
a && b;  // "abc"
c || b;  // "abc"
c && b;  // null
```

### Symbol Coercion

Gotcha:
- explicit coercion of a `symbol` to a `string` is allowed.
- implicit coercion of the same is disallowed and throws an error.

```js
var s1 = Symbol("cool");
String(s1);  // "Symbol(cool)"

var s2 = Symbol("not cool");
s2 + "";  // TypeError
```

`symbol` cannot coerce to `number` at all, but can both explicitly and implicitly coerce to `boolean` (always `true`).

### Loose Equals Versus Strict Equals

Loose equal (`==`) allows coercion in the equality comparision while strict equal disallows it. The implication here is that both operators check the types of their operands, the difference is in how they respond if the types don't match.

```js
var a = 42;
var b = "42";
var c = true;

a === b;  // false
a == b;   // true
b == c;   // false, according to spec: "42" == true -> "42" == 1 -> 42 == 1.
          // So under any circumstances, never ever use == true or == false, ever.
null == undefined;  // true
```

More ES5 specs for comparing objects to nonobjects:
- If Type(x) is String/Number and Type(y) is Object, return the result of the comparision x == toPrimitive(y).
- If Type(x) is Object and Type(y) is String/Number, return the result of the comparision toPrimitive(x) == y.

```js
var a = 42;
var b = [ 42 ];

a == b;  // true, since toPrimitive([ 42 ]) = "42"
```

The most common complaint against implicit coercion in `==` comparisons comes from how falsy values behave surprisingly when compared to each other, some examples:
```js
"0" == false;  // true
false == 0;    // true
false == "";   // true
false == [];   // true
"" == [];      // true
"" == 0;       // true
0 == [];       // true
//...
```

To effectively avoid issues with comparisons, some heuristic rules to follow:
- If either side of the comparison can have `true` or `false` values, don't ever use `==`.
- If either side of the comparison can have `[]`, `""`, or `0`, seriously consider not using `==`.

There's only loose relational comparison (`a < b`, `a <= b`, ..) but no strict relational comparison as there is for equality.

The matching that occurs between a `switch`'s expression and each `case` expression is identical to the `===` (strict equal) algorithm. However if you wish to allow coercive equality (`==`), you need to hack the `switch` statement a bit:
```js
var a = "42";
switch (true) {
    case a == 10:
        break;
    case a == 42:
        break;
    default:
}
```

This works because the `case` clause can have any expression, not just simple values.

## Grammar

### Completion value

All statements have completion values, for example:
- `var` statement results in `undefined`.
- Regular `{..}` block has a completion value of the completion value of its last contained statement/expression.
- Assignment statement's completion value is the assigned value.