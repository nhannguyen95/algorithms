## Access identifier

Default **access identifier** of class members are **private**, for struct member it's **public**.

## Member function

Class methods can be defined outside of class by using the following syntax:

```c++
// <return_type> ClassName::<method_name>(args) {
//   // implementation
// }
//
// For example:
void Rectangle::set_values(int x, int y) {
    // The scope operator :: grants the same scope properties
    // as if this method is defined inside Rectangle, such as
    // accessing private members like width and height.
    width = x;
    height = y;
}
```

The only difference between outside/inside definition is that inside definition is automatically considered **inline member function** by the compiler. This causes no difference in behavior, but only on possible compiler optimizations.

## Constructor

**Default constructor** is the one that takes no parameters, it is special because it is called when an object is declared but is not initialized with any arguments (not even by using empty parentheses).

There are many ways to call constructor:

```c++
Rectangle rect (w, h);
Rectangle rect {w, h};
Rectangle rect = {w, h};
Circle cir = r;  // Single parameter.
```

When using constructors to initialize members, **member initialization** can be used to initialize them directly:

```c++
// Normal
Rectangle (int w, int h) {
    width = w;
    height = h;
}

// Member initialization
Rectangle (int w, int h) : width(x), height(h) { }
```

For member objects, if they are not initialized after the colon, they will be constructed using default construction. This is not always possible if the class of that member object has no default construction.

## Overloading operators

Overloadable operators:
- `+`, `-`, `*`, `/`, `=`, `+=`, `-=`, `*=`, `/=`, `++`, `--`, `%`, `%=`.
- `<`, `>`, `<=`, `>=`, `==`, `!=`, `!`, `&&`, `||`
- `<<`, `>>`, `<<=`, `>>=`, `&`, `^`, `|`, `~`, `&=`, `^=`, `|=`
- `[]`, `()`, `,`
- `->*`, `->`
- `new`, `delete`, `new[]`, `delete[]`

Some operators can be overloaded in 2 forms: member function or non-member function, signature:

|Expression|Operator (@)|Member function|Non-member function|
|-|-|-|-|
|@a|`+ - * & ! ~ ++ --`|`A::operator@()`|`operator@(A)`|
|a@|`++ --`|`A::operator@(int)`|`operator@(A,int)`|
|a@b|`+ - * / % ^ & \| < > == != <= >= << >> && \|\| ,`|`A::operator@(B)`|`operator@(A,B)`|
|a@b|`= += -= *= /= %= ^= &= \|= <<= >>= []`|`A::operator@(B)`|-|
|a(b,c...)|`()`|`A::operator()(B,C...)`|-|
|a@b|`->`|`A::operator->()`|-|
|(TYPE) a|`TYPE`|`A::operator TYPE()`|-|

```c++
class CVector {
private:
    int x, y;
public:
    CVector() {}
    CVector() (int a, int b) : x(a), y(b) {}

    // Inside definition member function:
    CVector operator+(const CVector& param) {
        CVector temp;
        temp.x = x + param.x
        temp.y = y + param.y
        return temp;
    }
}

// Outside definition member function:
CVector CVector::operator+(const CVector& param) {
    //...
}

// Non-member function
CVector operator+(const CVector& lhs, const CVector& rhs) {
    //...
}
```

## `This` pointer

`this` pointer is frequently used in `operator=` that return objects by reference:

```c++
CVector& CVector::operator=(const CVector& param) {
    x = param.x;
    y = param.y;
    return &this;
}
```

## Static members

Static members must be initialized outside the class to avoid them to be declared several times:

```c++
int Dummy::n = 0;
```

## Const member function

When an object of a class is qualified as a `const` object, access to its data members from outside the class is restricted to read-only. Note that the constructor is still called and is allowed to initialize and modify these data members. 

```c++
class MyClass {
public:
    int x;
    MyClass(int val) : x(val) {}
    int get() { return x; }
}

const MyClass foo(10);
foo.get()       // error: x cannot be modified
foo.x = 20;     // error: x cannot be modified
cout << foo.x;  // ok: x can be read
```

Member functions of a `const` object can only be called if they are specified as `const` members:

```c++
int get() const {
    return x;
}
```

`const` member functions cannot modify the state of an object: they cannot modify non-static data members nor call other non-`const` member functions.

Most functions taking classes as parameters actually take them by `const` reference (`const MyClass&`).

Member functions can be overloaded on their constness: 2 member functions with identical signatures except that one is `const` and the other is not. The `const` version is called only when the object is `const`, the non-`const` version is called when the object is non-`const`.

## Class template

Syntax:

```c++
template <class T>
class MyClass {
    //...
}

// Outside definition member function:
template <class T>
T MyClass<T>::some_function() {
    //...
}
```

It is possible to define a different implementation for a template when a specific type is passed as template argument. This is called **template specialization**:

```c++
template <class T>
class MyClass {
    T element;
public:
    T increase() { return ++element; }
}

// class template specialization:
template <>
class MyClass <char> {
    char element;
public:
    char uppercase() {
        // upper element
        return element;
    }
}

MyClass<int> myint(7);
myint.increase();
MyClass<char> mychar('j');
mychar.uppercase();
```

## Special member functions

Special member functions are member functions that are *implicitly defined* as member of classes under certain circumstances. There are 6 of them.

### Default constructor

Typical form: `C::C()`.

If a class definition has no constructors, the compiler assumes the class to have an implicitly defined default constructor.

As soon as class has some constructor taking any number of parameters, the compiler no longer provides the implicit default constructor. We need to declare it in the class should we need one.

### Destructor

Typical form: `C::~C()`.

### Copy constructor

Typical form: `C::C(const C&)`.

If a class has no custome copy nor move constructors (or assignments) defined, an implicit copy constructor is provided. This copy constructor simply performs a (shallow) copy of its own members.

We can define a custom copy constructor that performs a deep copy.

### Copy assignment

Typical form: `C& operator=(const C&)`.

When an object is already initialized, it can also be copied on any assignment oepration:

```c++
MyClass foo;
MyClass bar (foo);   // copy constructor called.
MyClass bar = foo;   // copy constructor called!
foo = bar;           // copy assignment called.
```

The copy assignment operator is an overload of `operator=` which takes a value or reference of the class itself as parameter. The return value is generally a reference to `*this` (although this is not required).

The copy assignment is defined implicitly if a class has no custom copy nor move assignments defined. The implicitly defined copy assignment also just performs a shallow copy.

### Move constructor and assignment

Similar to copying, moving uses the value of an object to set the value to another object.

Unlike copying, the content is actually transferred from one object to the other. This moving only happend when the source of the value is an **unnamed object**.

**Unnamed objects** are objects that are temporary in nature, for examples return values of functions or type-casts.

Move constructor and move assignments do not really require a (deep) copy, the value can be just moved into the destination object.

The move constructor is called when an object is initialized on construction using an unnamed temporary. The move assignment is called when an object is assigned the value of an unnamed temporary:

```c++
MyClass bar = fn();  // move constructor
bar = MyClass();     // move assignment
```

The move constructor and assignment are members that take a parameter of type **rvalue reference** to the class itself. An rvalue reference is specified by following the type with `&&`:

```c++
C::C(C&&);          // move constructor
C& operator=(C&&);  // move assignment
```

## Friend function

A non-member function can access the private and protected members of a class if it is declared a `friend` of that class. That is done by including a declaration of this external function within the class, and preceding it with the keyword `friend`:

```c++
class Rectangle {
public:
    friend Rectangle duplicate(const Rectangle&);
}

Rectangle duplicate(const Rectangle&) {
    Rectangle rect;
    myClass.width;  // access private members
}

Rectangle rect;
Rectangle rect2 = duplicate(rect);

// some_function is not a member of MyClass!!
rect.duplicate(rect2);  // invalid
```

## Friend class

A friend class is a class whose members have no access to the private or protected members of another class:

```c++
class A {}

class B {
    friend class A;
}
```

Properties:
- In the example above, A is friend of B, so A's members can access private/protected members of B.
- The friend of a friend is not considered a friend (unless explicitly specified).

## Inheritance

Syntax:

```c++
class <derived_class_name>: <access_specifier> <base_class_name> {
    /* ... */
}
```

The access specifier limits the most accessible level for the members inherited from the base class:
- The members with a more accessible level are inhereted with this level instead.
- The members with an equal or more restrictive access level keep their restrictive level in the derived class.

Default value for access specifier is private for class and public for struct.

Most use cases of inheritance in C++ should use public inheritance.

A publicly derived class inherits access to every member of a base class except:
- its constructor and destructor (but are automatically called by the constructors of the derived class).
- its assigment operator members (oeprator=).
- its friends.
- its private members.

By default, constructors of a derived class calls the default constructor of its base classes. Calling a different constructor of a base class is possible using member initialization:

```c++
<derived_constructor_name> (params): <base_constructor_name> (params) {
    /* ... */
}
```

## Polymorphism

Key feature of class inheritance: a pointer to a derived class is a type-compatible with a pointer to its base class. Polymorphism is the art of taking advantage of this simple but powerful and versatile feature.

A **virtual member** is a member function that can be redefined in a derived class, while preserving its calling properties through reference:

```c++
class Polygon {
public:
    virtual int area () {
        return 0;
    }
    
    int perimeter() {
        return 0;
    }
}

class Rectangle: public Polygon {
public:
    int area() {
        return w * h;
    }

    // 1/2: Non-virtual functions can also be redefined in
    // derived class:
    int perimeter() {
        return (w + h) << 1;
    }
}

Polygon* p = new Rectangle(1, 2);
p->area();

// 2/2: But cannot be accessed through a reference of the
// base class:
p->perimeter();  // 0, not 6
```

A class that declares or inherits a virtual function is called a **polymorphic class**.

**Abstract base classes** are classes that contain at least one **pure virtual member functions** (virtual member functions without definition) and thus can only be used as base classes. The syntax is to replace their definition by `= 0`.