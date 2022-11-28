## Event Loop

JS has never had any direct notion of asynchronous built into it. 1 common thing of all JS hosting environments (browsers, servers, etc.) is that they have a mechanism in them that handles executing (invoking JS engine) multiple chunks/functions of a program over time, called the event loop.

Event loop acts as a FIFO queue of events (program chunks/functions). For example, `setTimeout` does not put the callback on the event loop queue, instead it sets up a timer and when the timer expires, the hosting environment places the callback into the event loop. If there are already some items in the event loop at that moment, the callback will have to wait. That explaines why `setTimeout` might not fire with perfect temporal accuracy, but it's guaranteed (generally speaking) that the callback won't fire before the specified time interval, it can happen at or after that time, depending on the state of the event queue.

The event loop breaks its work into tasks and executes them in serial, all of them share the same access to the program scope and state, so each modification to state is made on top of the previous one. Because of JS's single-threading (traditionally JS is single-threaded language), the code for each executed task is atomic (the entirety of its code will finish before any of the code in another task can run).

Whenever there are tasks to run, the event loop runs until the queue is empty. Each iteration of the event loop is a tick. User interactions, IO and timers enqueue events on the event queue.

Concurrency is when 2 or more chains of events/tasks interleave over time, such that from a high-level perspective they appear to be running simultaniously (even at any given moment only one event is being processed).

If a task takes too long to run, it can block other tasks/chains of events such as UI updates, user events handling, etc. An example of such a task is:

```js
function response(data) {
    // Can be a problem with data has millions of elements.
    res = res.concat(data.map(val => val *2));
}

ajax("https://...", response);
```

To make `response` a more friendly cooperatively concurrent task so other concurrent tasks have a chance to interleave their operations into the event loop queue:

```js
function response(data) {
    // Process 1000 elements at a time.
    var chunk = data.splice(0, 1000);

    res = res.concat(chunk.map(val => val * 2));

    if (data.length > 0) {
        // The setTimeout(.., 0) hack to put the callback
        // at the end of the current event loop queue.
        setTimeout(() => response(data), 0);
    }
}
```

Not that `setTimeout(.., 0)` is not technically inserting a callback directly onto the event loop queue, but the timer will insert the callback at its next oppoturnity. This means 2 subsequent `setTimeout(.., 0)` calls would not be strictly guaranteed to be processed in call order.

## Job Queue

As of ES6, there's a new concept layered on top of the event loop queue, called the Job queue.


## Promises

Even if a promise is resolved immediately (e.g. the one such as `new Promise(function(resolve){ resolve(1); }))`, the `then` callback will always be called asynchronously.

When a promise is resolved, all `then` registered callbacks on it will be called, in order, immediately at the next asynchronous opportunity:
```js
p.then(function () {
    p.then(function () {
        console.log('C');
    });
    console.log('A');
});

p.then(function () {
    console.log('B');
});

// A B C
```

If 2 promises `p1`, `p2` are already resolved, `p1.then(cb1); p2.then(cb2)` will end up calling `cb1` for `p1` before the ones for `p2`. But there are many subtle cases where that might not be true. Thus you should never rely on any thing about ordering/scheduling of callbacks across Promises.

In case a promise never gets resolved, we are provided with a higher level abstraction called `race` to prevent it from haning our program indefinitely:
```js
function timeoutPromise(delay) {
    return new Promise(function(resolve, reject) {
        setTimeout(function() {
            reject('Timeout!');
        }, delay);
    });
}

Promise.race([
    foo(),
    timeoutPromise(3000)
]).then(
    function() {},     // foo is fulfilled in time.
    function(erro) {}  // either foo is rejected, or didn't finish in time.
)
```

A promise gets resolved or rejected only once, if `resolve()` or `reject()` are called multiple times, the promise only accepts the first resolution and silently ignore any subsequent attempts. As a result, each `then` registered callback will only ever be called once.

if `resolve()` and `reject()` are called with multiple parameters, all subsequent parameters beyond the first will be silently ignored.

If at any point in the creation of a Promise, a JS exception error occurs, that exception will be caught and it will force the Promise in question to become rejected.

If the JS exception error occurs during the observation (in a `then` registered callback), the exception is listend in the promise that is returned by the `then(...)` call.

If you pass a genuine Promise to `Promise.resolve()`, you get the same promise back:
```js
var p1 = Promise.resolve(42);
var p2 = Promise.resolve(p1);
// p1 === p2
```

If you pass a non-genuine thenable object to `Promise.resolve()`, the Promise returned adopts the final resolution of the thenable you passed in:
```js
var fulfilledTh = {
    then: function(cb) { cb(42); };
};
var rejectedTh = {
    then: function(cb, errCb) { errCb('Ooops'); };
}

var p1 = Promise.resolve(fulfilledTh);  // p1 is a fulfilled promise.
var p2 = Promise.resolve(rejectedTh);   // p2 is a rejected promise.
```

The key to making a Promise Chain Flow is built on some behaviors intrinsic to Promises:
- Calling `then()` on a Promise creates and returns a new Promise which we can chain with.
- Inside the fulfillment/rejection hanlders, if you return a value or an exception is thrown, the new returned (chainable) Promise is resolved accordingly.
- If the fulfillment or rejection handler returns a Promise, it is (recursively) unwrapped so that whatever its resolution is will become the resolution of the chained Promise returned from the current `then()`:
  ```js
  var p = Promise.resolve(21);
  p.then(function(v) {
      console.log(v);  // 21;
      return new Promise(function(resolve, reject) {
          resolve(v * 2);
      });
  })
  .then(function(v) {
      console.log(v);  // 42;
  });
  ```

Note that the `reject()` does not do the unwrapping that `resolve()` does: if you pass a Promise/thenable value to `reject()`, that untouched value will be set as the rejection reason, a subsequent rejection handler would receive the actual Promise/thenable you passed to `reject()`, not its underlying immediate value.

If a proper valid function is not passed as the fulfillment handler parameter to `then()`, a default handler is assumed:
```js
var p = Promise.then(42);

p.then(
    // Assumed function:
    // function(v) {
    //    return v;   
    // }
    null,
    function rejected(err) {

    }
);
```

This pattern has a shortcut API: `catch(function(err) {...})`.

The reason why promises are uncancelable is because it would let one consumer/observer of a promise affect other consumer's ability to observe that same promise. 

### Terminology


Fulfill and reject:
```js
new Promise(function(resolve, reject) {
    resolve();  // fulfillment
    reject();   // rejection
});
```

Resolve is meant either fulfilling or rejecting the promise.

So why the first parameter is usually called `resolve` instead of `fulfill`. This is because:
- `Promise.resolve()` API can result in either fulfillment or rejection:
  ```js
  // rejectedPr is a rejected promised.
  var rejectedPr = Promise.resolve(Promise.reject('Error'));
  ```
- Similarly, the first parameter in `Promise` construction can also result in either fulfillment or rejection:
  ```js
  var rejectedPr = new Promise(function(resolve, reject) {
      // resolve this promise with a rejected promise.
      resolve(Promise.reject('Error'));
  });
  ```

But the callbacks provided to `then()` can be called `fulfilled()` and `rejected()`:
```js
function fulfilled(msg) {}

function rejected(err) {}

somePromise.then(
    fulfilled,
    rejected
);
```

As a side note, ES6 specification uses `onFulfilled()` and `onRejected()` to label these to callbacks, so they are accurate terms.

### Promise Patterns

`Promise.all([...])`:
- fulfilled if and when all constituent promises are fulfilled.
- rejected if any one of those promises is instead rejected.

`Promise.race([...])`
- fulfilled if and when any Promise is fulfilled.
- rejected if and when any Promise is rejected.
- If an empty array is passed, the promise will never resolve.

## Iterables

An `iterator` is an object that has the `next()` method on its interface.

An `iterable` is an object that contains an `iterator` that can iterate over its values (by calling `next()`).

As of ES6, the way to retrieve an `iterator` from an `iterable` is that the `iterable` must have a function on it , with the name being the special ES6 symbol value `Symbol.iterator`. When this function is called, it returns an `iterator`. Generally each call should return a fresh new `iterator` though not required.

An `iterable` can be looped through using `for..of` loop:
```js
var positiveNumbers = (function() {
    var nextNumber;

    // return an iterable object:
    return {
        [Symbol.iterator]: function(){ return this; },
        next: function() {
            if (nextNumber === undefined)
                nextNumber = 1;
            else
                nextNumber = nextNumber + 1;

            return {
                done: false,  // used to mark the end iterable's complete status
                value: nextNumber
            }
        }
    };
})();

// The for..of loop accepts an iterable object,
// so that it can first retrieves the iterable's iterator object
// by doing: iterator = positiveNumbers[Symbol.iterator]().
//
// In this case, the iterable can return itself (this) as the
// iterator because it has the next() method defined.
// 
// Then, the for..of loop through the iterable's values
// by calling next on the iterator:
// number = iterator.next().value
// number = iterator.next().value
for(var number of positiveNumbers) {
    console.log(v);

    // since done is always false,
    // we need to terminate the loop manually.
    if (v > 10) {
        break;
    }
}
// prints 1 2 3 4 5 6 7 8 9 10
```

## ES6 Generators

Normally, JS functions run until its completion, and no other code can interrupt and run in between.

ES6 introduces a new type of function called generators that can be paused while running:

```js
function *foo() {  // syntax
    console.log('top');
    yield;  // pause
    console.log('mid');
    yield;
    console.log('bot');
}

var it = foo();  // not executed yet, but create an iterator object instead
it.next();  // "top"
it.next();  // "mid"
it.next();  // "bot"
it.next();  // already reach the end of foo, do nothing
```

`next()` can also accept input:

```js
function *foo(x) {
    var y = x * (yield);
    return y;
}

var it = foo(6);

// The first next is called to start the function.
// Argument passed to next() is provided to the previous
// paused yield, there is no paused yield yet at this point
// so any argument passed to the first next() is discarded.
it.next();       

// At this point, foo is paused at the first (and only) yield,
// so argument passed to the subsequent next() will be passed
// as the result to that paused yield.

// 7 is passed as the result to the paused yield, foo will
// also continue its execution.
var res = it.next(7);
res.value  // 42
```

`yield` can also accept an argument:

```js
function *foo(x) {
    var y = x * (yield "Hello");
    return y;
}

var it = foo(6);

var res = it.next();
res.value  // "Hello"

res = it.next(7);
res.value  // 42
```

In short:
- `next(..)` provide its argument as the result to the previous paused `yield`.
- `next(..)` returns the value yielded by next `yield` (the one that will cause it to paused), or returned value of the function if there's no next `yield`. 

Each time you construct an iterator, you are implicitly constructing an instance of the generator controlled by that iterator. Thus you can have multiple instances of the same generator running at the same time.

A common design pattern is to step through a series of values from a producer, in which the next value won't actually be calculated until the next calculation call happens (because in general pre-computing all values can be resource-leaky for producers).

A generator can be treated as a producer of values that we extract one at a time through an iterator interface's `next()` call:
```js
function *something() {
    var nextVal;

    try {
    // Since JS is single-threaded, generally using while..true loop is
    // a bad idea if it does not have break or return in it, as it would
    // likely run forever synchronously and block the UI.
    // However, using it in a generator is totally ok if it has a yield
    // in it, as the generator will pause at each iteration, yielding back
    // to the main program and/or the event loop queue.
        while(true) {
            if (nextVal == undefined) {
                nextVal = 1;
            } else {
                nextVal = (3 * nextVal) + 6;
            }

            yield nextVal;
        }
    }
    // This try..finally clause will always be run when the iterator is
    // completed. This is useful if you need to clean up resources (db
    // connections, etc.) 
    finally {
        console.log('cleaning up!');
    }
}

// As mentioned, for..of accept an iterable, while something()
// returns an iterator. This is possible because generator's
// iterator also has a Symbol.iterator function on it, which
// basically does a return this, which makes it also an iterable.
var it = something();
for(var v of it) {
    console.log(v);

    if (v > 500) {
        // Normal and abnormal completion of the for..of loop (generally caused
        // by a break, return, or an uncaught exception) send a signal
        // to the generator's iterator for it to terminate.
        break;

        // We can also choose to send this termination signal manually by
        // calling return(..) on the iterator (no need the break above):
        console.log(it.return("Hello world!").value);
    }
}
// 1 9 33 105 321 969
// cleaning up!
// Hello world
```

## Program Performance

### Web Workers

JS is single threaded, but browser environment can easily provide multiple instances of the JS engine, each on its own thread, and let you run different program in each thread. Each of those separated (single) threaded pieces of your program is called a Web Worker. This type of parallelism is called task parallelism, as the emphasis is on splitting up chunks of your program to run in parallel.

From the main JS program (or another Worker), you instantiate a Worker like so:
```js
var w1 = new Worker('path/to/a/js/file/worker.js');
```

The browser will then spin up a separated thread and let that file run as an independent program inside that thread.

Workers do not share any scope or resources with each other or the main program. But instead have a event messaging mechanism connecting them.

To kill a Worker immediately from the program that created it, call `terminate()` on the Worker object.

Inside the Worker, you do not have any access to the main program's resources (global variables, page's DOM, etc.).

Some common uses for Web Workers:
- Processing intensive math calculations.
- Sorting large data sets.
- Data operations (compression, audio analysis, image pixel manipulations, etc.).
- High-traffic network communications.

A common thing of most of those uses is that they require a large amount of information to be transferred across the barrier between threads using the event machanism, perhaps in both direction. Some solutions:
- Serializing all data to a string value.
- Using the [structured clone algorithm](https://developer.mozilla.org/en-US/docs/Web/API/Web_Workers_API/Structured_clone_algorithm) to copy/duplicate the object on the other side (when you pass an object).
- Using the [Transferable Objects](https://developer.chrome.com/blog/transferable-objects-lightning-fast/) option for large data sets, what happens is that the object's ownership is transferred, but the data itself is not moved.

If your site or app allows for loading multiple tabs of the same page, you may very well want to reduce the resource usage of their system by preventing duplicate dedicated Workers; the most common limited resource in this respect is a socket network connection, as browsers limit the number of simultaneous connections to a single host.

In this case, creating a single centralized Worker that all the page instances of your site or app can share is quite useful.

That's called a SharedWorker, which can be created like so:
```js
var w1 = new SharedWorker('path/to/a/js/file/worker.js');
```

Because a shared Worker can be connected to or from more than one program instance or page on your site, the Worker needs a way to know which program a message comes from. This unique identification is called port. So the calling program must use the `port` object of the Worker for communication.

### SIMD

Single instruction, multiple data is a form of data parallelism, as contrasted to task parallelism with Web Workers, because the emphasis is not really on program logic chunks being parallelized, but rather multiple bits of data being processed in parallel.