## What it's used for?
- Define an interface (interface or abstract class) for creating an object, but let subclasses decide which class to instantiate. Abstract Factory lets a class defer instantiation to subclasses.

## How to use?
- UML class:
<img src="./pics/abstract-factory.png" />

- Example:
<img src="./pics/abstract-factory-example" />

The method `orderPizza` uses `createPizza`, the PizzaStore abstract class defers the instantiation of pizza in the method `createPizza` for its subclasses (like NYPizzaStore).

The defered method is called **factory method** (`createPizza` in this case).

## Compare with Simple Factory
- Abstract Factory provides a general framework for creating pizzas that relies on a factory method to actually create concrete classes that go into making Pizza.
- Simple Factory gives you a way to encapsulate object creation (by composition), but doesn't give you the flexibility of the Factory Method because there is no way to vary the products you're creating.

## Which principles it derives?
- Same as Simple Factory.
