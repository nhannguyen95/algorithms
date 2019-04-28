## What it's used for?
- allows an object to alter its behaviour when its internal state changes.
  > The pattern encapsulates states into separate classes and delegates to the object represeting the current state, we know that behavior changes along with the internal state.
- The object (The Gullball Machine) will *appear* to change its class.

## How to use?
- UML:
<img src="./pics/state.png" />

## Compare to Strategy Pattern
- Strategy: the client usually specifies the strategy object that the context is composed with. While client can change the strategy object at runtime, often there is a strategy object that is most appropriate for a context object.
  
  Think of Strategy as a flexible alternative to subclassing: if you use inheritance to define the behavior of a class, then you're stuck with that behavior even if you need to change it. With Strategy you can change the behavior by composing with a different object.
- State: we have a set of behaviors encapsulated in state objects; at any time the context is delegating to one of those states. Overtime the current state changes accross the set of state to reflect the internal state of the object, so the context's behavior changes over time as well. The client knows very little, if anything, about the state objects.

  Think of State as an alternative to putting lots of conditionals in your context; by encapsulating the behaviors within the state objects, you can simply change the state object in context to change its behavior.
  
## Other notes
- When the state transitions are fixed, they are appropriate for putting in the Context.

  However when the transitions are more dynamic, they are typically placed in the state classes themselves. Disadvantage: we create dependencies between the state classes, we can minimize this by using getter/setter methods on the Context.
- It's the Context's job to oversee its state, you don't usually want a client changing the state of a Context without that Context's knowledge.
- Your application can have many instances of the Context that share the state objects (change variables that hold states in Context into static one).
- State Pattern introduces many new classes, and that is the trade of for flexibility, easy-to-maintain code.
