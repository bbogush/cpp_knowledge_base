# C++ Code Style Guide

This document defines the coding style for this C++ project. The goal is **readability, consistency, and safety**.

---

## Table of Contents

- [Background](#background)
  - [Goals of the Style Guide](#goals-of-the-style-guide)
- [C++ Version](#c-version)
- [Formatting](#formatting)
  - [Line Length](#line-length)
  - [Indentation](#indentation)
  - [Spaces](#spaces)
  - [Brackets](#brackets)
  - [Parentheses](#parentheses)
  - [Non-ASCII Characters](#non-ascii-characters)
  - [Function Declarations and Definitions](#function-declarations-and-definitions)
  - [Lambda Expressions (Formatting)](#lambda-expressions-formatting)
  - [Floating-point Literals](#floating-point-literals)
  - [Function Calls](#function-calls)
  - [Braced Initializer List Format](#braced-initializer-list-format)
  - [Conditionals](#conditionals)
  - [Loops and Switch Statements](#loops-and-switch-statements)
  - [Pointer and Reference Expressions](#pointer-and-reference-expressions)
  - [Boolean Expressions](#boolean-expressions)
  - [Return Values](#return-values)
  - [Variable and Array Initialization](#variable-and-array-initialization)
  - [Preprocessor Directives](#preprocessor-directives)
  - [Class Format](#class-format)
  - [Constructor Initializer Lists](#constructor-initializer-lists)
  - [Namespace Formatting](#namespace-formatting)
  - [Horizontal Whitespace](#horizontal-whitespace)
  - [Vertical Whitespace](#vertical-whitespace)
- [Header Files](#header-files)
  - [Self-contained Headers](#self-contained-headers)
  - [The #define Guard](#the-define-guard)
  - [Include What You Use](#include-what-you-use)
  - [Forward Declarations](#forward-declarations)
  - [Defining Functions in Header Files](#defining-functions-in-header-files)
  - [Names and Order of Includes](#names-and-order-of-includes)
- [Scoping](#scoping)
  - [Namespaces](#namespaces)
  - [Internal Linkage](#internal-linkage)
  - [Nonmember, Static Member, and Global Functions](#nonmember-static-member-and-global-functions)
  - [Local Variables](#local-variables)
  - [Static and Global Variables](#static-and-global-variables)
  - [thread_local Variables](#thread_local-variables)
- [Classes](#classes)
  - [Doing Work in Constructors](#doing-work-in-constructors)
  - [Implicit Conversions](#implicit-conversions)
  - [Copyable and Movable Types](#copyable-and-movable-types)
  - [Structs vs. Classes](#structs-vs-classes)
  - [Structs vs. Pairs and Tuples](#structs-vs-pairs-and-tuples)
  - [Inheritance](#inheritance)
  - [Operator Overloading](#operator-overloading)
  - [Access Control](#access-control)
  - [Declaration Order](#declaration-order)
- [Functions](#functions)
  - [Inputs and Outputs](#inputs-and-outputs)
  - [Write Short Functions](#write-short-functions)
  - [Function Overloading](#function-overloading)
  - [Default Arguments](#default-arguments)
  - [Trailing Return Type Syntax](#trailing-return-type-syntax)
- [Other C++ Features](#other-c-features)
  - [Rvalue References](#rvalue-references)
  - [Friends](#friends)
  - [Exceptions](#exceptions)
  - [noexcept](#noexcept)
  - [Run-Time Type Information (RTTI)](#run-time-type-information-rtti)
  - [Casting](#casting)
  - [Streams](#streams)
  - [Preincrement and Predecrement](#preincrement-and-predecrement)
  - [Use of const](#use-of-const)
  - [Use of constexpr](#use-of-constexpr)
  - [Integer Types](#integer-types)
  - [64-bit Portability](#64-bit-portability)
  - [Preprocessor Macros](#preprocessor-macros)
  - [0 and nullptr/NULL](#0-and-nullptrnull)
  - [sizeof](#sizeof)
  - [Type Deduction](#type-deduction)
  - [Class Template Argument Deduction](#class-template-argument-deduction)
  - [Designated Initializers](#designated-initializers)
  - [Lambda Expressions](#lambda-expressions)
  - [Template Metaprogramming](#template-metaprogramming)
  - [Boost](#boost)
  - [std::hash](#stdhash)
  - [Nonstandard Extensions](#nonstandard-extensions)
  - [Aliases](#aliases)
- [Inclusive Language](#inclusive-language)
- [Naming](#naming)
  - [General Naming Rules](#general-naming-rules)
  - [File Names](#file-names)
  - [Type Names](#type-names)
  - [Variable Names](#variable-names)
  - [Constant Names](#constant-names)
  - [Function Names](#function-names)
  - [Namespace Names](#namespace-names)
  - [Enumerator Names](#enumerator-names)
  - [Macro Names](#macro-names)
  - [Exceptions to Naming Rules](#exceptions-to-naming-rules)
- [Comments](#comments)
  - [Comment Style](#comment-style)
  - [File Comments](#file-comments)
  - [Class Comments](#class-comments)
  - [Function Comments](#function-comments)
  - [Variable Comments](#variable-comments)
  - [Implementation Comments](#implementation-comments)
  - [Punctuation, Spelling, and Grammar](#punctuation-spelling-and-grammar)
  - [TODO Comments](#todo-comments)
  - [Deprecation Comments](#deprecation-comments)
- [Exceptions to the Rules](#exceptions-to-the-rules)
  - [Existing Non-conformant Code](#existing-non-conformant-code)
  - [Windows Code](#windows-code)
- [Tooling](#tooling)
- [References](#references)

---

## Background

### Goals of the Style Guide

- Maximize readability for the next engineer reading the code
- Minimize common C++ pitfalls (UB, memory leaks, data races)
- Enforce consistency so diffs are clean and reviews are fast

---

## C++ Version

- Preferred C++ version C++20.

---

## Formatting

### Line Length

- Max **100 characters** per line

```c
// OK
log_info("parameter1: %d parameter2: %d parameter3: %d parameter4: %d", parameter1,
    parameter2, parameter3, parameter4);

// Wrong
log_info("parameter1: %d parameter2: %d parameter3: %d parameter4: %d", parameter1, parameter2, parameter3, parameter4);
```

- Constant strings longer than one line should be closed on each line by a quote and opened again on the next line.
```c
// OK
log_info("This is a long string that we want to print and is more than 100 chars long so we need "
         "to split it");

// Wrong
log_info("This is a long string that we want to print and is more than 100 chars long so we need \
         to split it");
```

### Indentation

- Indentation is 4 spaces, no tabs
- Single indentation after breaking up line.

```c
// OK
if (parameter1 != nullptr && parameter2 != nullptr && parameter3 != nullptr &&
    parameter4 != nullptr) {
    return 0;
}

// OK
log_info("parameter1: %d parameter2: %d parameter3: %d parameter4: %d", parameter1,
    parameter2, parameter3, parameter4);

// OK
void func(long int parameter1, const char *parameter2, double parameter3, int *parameter4,
    int parameter5);

// Wrong
if (parameter1 != nullptr && parameter2 != nullptr && parameter3 != nullptr &&
        parameter4 != nullptr) {
    return 0;
}

// Wrong
void func(long int parameter1, const char *parameter2, double parameter3, int *parameter4,
          int parameter5);

// Wrong
log_info("parameter1: %d parameter2: %d parameter3: %d parameter4: %d", parameter1,
         parameter2, parameter3, parameter4);

```

- Indentation is required for every opening bracket.
```c
// OK
if (a) {
    do_a();
} else {
    do_b();
    if (c) {
        do_c();
    }
}
```

## Spaces

- Single space between `if/while/for/do` keyword and opening parenthesis.
```c
// OK
if (condition)
while (condition)
for (init; condition; step)
do {} while (condition)

// Wrong
if(condition)
while(condition)
for(init;condition;step)
do {} while(condition)
```

- Single space before and after an assignment, binary and ternary operators (=  +  -  <  >  *  /  %  |  &  ^  <=  >=  ==  !=  ?  :).
```c
int32_t a;

a = 3 + 4;              // OK
for (a = 0; a < 5; a++) // OK
bits |= BIT5;           // OK

a=3+4;                  // Wrong
a = 3+4;                // Wrong
for (a=0;a<5;a++)       // Wrong
bits|=BIT5;             // Wrong
```

- No space after unary operators (&  *  +  -  ~  !).
- No space around the . and -> structure member operators.
- No space before the postfix increment / decrement unary operators and after the prefix increment / decrement unary operators.
```c
res = !x;               // OK
ptr->x;                 // OK
++i;                    // OK

res = ! x;              // Wrong
ptr -> x;               // Wrong
++ i;                   // Wrong
```

- No space between function name and opening parenthesis.
- No space between opening parenthesis and first parameter.
- Single space after every comma.
```c
int32_t a = sum(4, 3);              // OK

int32_t a = sum (4, 3);             // Wrong
int32_t a = sum( 4, 3 );            // Wrong
int32_t a = sum(4,3);               // Wrong
```
- No trailing spaces.

## Brackets

- Opening curly bracket is always at the same line as reserved keyword (`for`, `while`, `do`, `switch`, `if`, ...).
```c
size_t i;

for (i = 0; i < 5; i++) {           // OK
}

for (i = 0; i < 5; i++){            // Wrong
}

for (i = 0; i < 5; i++)             // Wrong
{
}
```

- `if/for/while` statement should have brackets if it takes more than one line.
```c
// OK
if (c) {
    for (int i = 0; i < 10; i++)
        do_a();
}

// OK
if (a)
    do_a();

// OK
if (c) {
    a = 12;
} else {
    for (int i = 0; i < 10; i++)
        do_a();    
}

// Wrong
if (c)
    for (int i = 0; i < 10; i++)
        do_a();

// Wrong
if (c)
    a = 12;
else {
    for (int i = 0; i < 10; i++)
        do_a();    
}
```

- In case of `if` or `if-else-if` statement, `else` must be in the same line as closing bracket of first statement.
```c
// OK
if (a) {
} else if (b) {
} else {
}

// Wrong
if (a) {
}
else {
}

// Wrong
if (a) {
}
else
{
}
```

- In case of `do-while` statement, `while` part must be in the same line as closing bracket of `do` part.
```c
// OK
do {
    int32_t a;
    a = do_a();
    do_b(a);
} while (check());

// Wrong
do
{
// logic
} while (check());

// Wrong
do {
// logic
}
while (check());
```

- Then part of `if` statement should be in a separate line.
```c
// OK
if (fd) {
    fclose(fp);
}

// Wrong
if (fd) fclose(fp);
```

- Opening curly bracket for function should be on the same level as closing.
```c
// OK
void my_func(void)
{
}

// Wrong
void my_func(void) {
}
```

- for and while without a statement should be in one-line with empty brackets.
```c
// OK
for (i = 0; i < *p; i++) {}

// Wrong
for (i = 0; i < *p; i++);
```

## Parentheses

- Do not overuse parentheses.
```c
// OK
if ((a & b) > 0 && c > 0 && d) {
}

// Wrong
if ((a & b) > 0 && (c > 0) && (d)) {
}

// Wrong
if ((my_func(a))) {
}

// Wrong
ptr = &(p->next);
```

- Use parentheses when assigning in a condition expression of if/for/while.
```c
// OK
for (i = 0; (ret = my_func()); i++)

// Wrong
for (i = 0; ret = my_func(); i++)
```

- Use sizeof with parentheses.
```c
// OK
sizeof(a)

// Wrong
sizeof a
```

### Non-ASCII Characters

- Source files must be UTF-8; avoid non-ASCII in identifiers and comments unless necessary (e.g., units)

```cpp
// OK
constexpr double micros_per_second = 1e6; // µs
```

### Function Declarations and Definitions

- Return type on the same line as function name

```cpp
void process_order(const Order& order, ExecutionCallback callback);
```

### Lambda Expressions (Formatting)

- Short lambdas inline; multi-line lambdas indented like a function body

```cpp
auto f = [](int x) { return x * 2; };

auto g = [&](const Order& o) {
    validate(o);
    submit(o);
};
```

### Floating-point Literals

- Always include a decimal point to make the type explicit

```cpp
double ratio = 1.0 / 3.0;
float scale = 0.5f;
```

### Function Calls

- Fit arguments on one line or break after the opening parenthesis with 4-space indent

```cpp
result = long_function_name(
    first_argument,
    second_argument);
```

### Braced Initializer List Format

- Short lists inline; longer lists one element per line

```cpp
std::vector<int> v = {1, 2, 3};

std::vector<std::string> names = {
    "alice",
    "bob",
    "charlie",
};
```

### Conditionals

- K&R brace style; always use braces, even for single-statement bodies

```cpp
if (condition) {
    do_something();
} else {
    do_other();
}
```

### Loops and Switch Statements

- Always brace loop bodies; label `default:` in every `switch`
- Use `[[fallthrough]]` to mark intentional fall-through

```cpp
switch (side) {
    case OrderSide::Buy:
        handle_buy();
        break;
    case OrderSide::Sell:
        handle_sell();
        break;
    default:
        break;
}
```

### Pointer and Reference Expressions

- Attach `*` and `&` to the type, not the variable name

```cpp
int* ptr;
const std::string& ref;
```

### Boolean Expressions

- Break long boolean expressions before the operator; align operators

```cpp
if (is_valid_order(order) &&
    has_sufficient_balance(account) &&
    market_is_open()) {
    submit(order);
}
```

### Return Values

- No parentheses around return values unless needed for clarity

```cpp
return result;          // not return (result);
return (a > b) ? a : b; // parens OK for ternary
```

### Variable and Array Initialization

- Use brace initialization `{}` to prevent narrowing conversions

```cpp
int x{42};
std::vector<int> v{1, 2, 3};
```

### Preprocessor Directives

- Preprocessor directives start at column 0, regardless of indentation

```cpp
#ifdef DEBUG
log_debug("state=", state);
#endif
```

### Class Format

- Access specifiers at the same indentation as `class`; members indented 4 spaces

```cpp
class Foo {
public:
    explicit Foo(int id);
    [[nodiscard]] int id() const noexcept;

private:
    int id_;
};
```

### Constructor Initializer Lists

- One initializer per line, aligned after the colon

```cpp
Foo::Foo(int id, std::string name)
    : id_{id}
    , name_{std::move(name)} {}
```

### Namespace Formatting

- No extra indentation inside namespaces; label closing braces

```cpp
namespace myproject {

class Bar {};

} // namespace myproject
```

### Horizontal Whitespace

- Space after keywords (`if`, `for`, `while`), not after function names
- Space around binary operators; no space around unary operators

```cpp
if (x > 0) { ... }
int y = x * 2 + 1;
++i;
```

### Vertical Whitespace

- One blank line between method definitions; two blank lines between top-level declarations
- No trailing whitespace; no more than one consecutive blank line inside a function

---

## Header Files

### Self-contained Headers

- Headers must be **self-contained** — compilable on their own
- Include all headers the file directly depends on; do not rely on transitive includes

### The #define Guard

- Use `#pragma once`

```cpp
#pragma once
```

### Include What You Use

- Include every header whose symbols you directly use
- Do not rely on a symbol being available through another header's includes

```cpp
// BAD: relying on <vector> being pulled in by <algorithm>
#include <algorithm>
std::vector<int> v; // might break if <algorithm> stops including <vector>

// GOOD
#include <algorithm>
#include <vector>
std::vector<int> v;
```

### Forward Declarations

- Prefer forward declarations over includes in headers to reduce compile-time coupling
- Use full includes in `.cpp` files

```cpp
// In foo.hpp — forward declare instead of including bar.hpp
class Bar;

class Foo {
    Bar* bar_;
};
```

### Defining Functions in Header Files

- Only define functions in headers if they are `inline`, `constexpr`, or templates
- Avoid non-trivial function bodies in headers; put them in `.cpp`

```cpp
// OK in header
inline int square(int x) { return x * x; }

template <typename T>
T clamp(T val, T lo, T hi) { return std::max(lo, std::min(val, hi)); }
```

### Names and Order of Includes

```cpp
// 1. Standard library
#include <algorithm>
#include <vector>

// 2. Third-party libraries
#include <spdlog/spdlog.h>

// 3. Project headers
#include "order_book.hpp"
```

---

## Scoping

### Namespaces

- Wrap all project code in a named namespace; avoid `using namespace` in headers
- Close braces with a comment

```cpp
namespace myproject {

class Foo {};

} // namespace myproject
```

### Internal Linkage

- Use anonymous namespaces (or `static`) for file-local helpers instead of exposing them in headers

```cpp
namespace {

void helper() { /* only visible in this TU */ }

} // namespace
```

### Nonmember, Static Member, and Global Functions

- Prefer free functions over static member functions when they don't need class internals
- Group related free functions in a namespace

```cpp
namespace math {
double lerp(double a, double b, double t) noexcept;
} // namespace math
```

### Local Variables

- Declare variables in the narrowest scope possible, as close to first use as possible
- Local variables: **snake_case**

```cpp
int order_count = 0;
for (const auto& order : orders) {
    ++order_count;
}
```

### Static and Global Variables

- Avoid mutable global state; prefer `constexpr` constants
- Upper snake case for constants

```cpp
constexpr int MAX_RETRIES = 5;
```

### thread_local Variables

- Use `thread_local` only when per-thread state is genuinely required
- Name with a `tl_` prefix to make the storage class visible at the call site

```cpp
thread_local std::mt19937 tl_rng{std::random_device{}()};
```

---

## Classes

### Doing Work in Constructors

- Keep constructors lightweight; avoid operations that can fail or throw
- Use factory functions or `init()` methods for complex initialization

```cpp
// BAD
Foo::Foo() { connect_to_database(); } // can throw, hard to recover

// GOOD
static std::expected<Foo, Error> create();
```

### Implicit Conversions

- Mark single-argument constructors `explicit` to prevent unintended implicit conversions

```cpp
class Buffer {
public:
    explicit Buffer(std::size_t size);
};
```

### Copyable and Movable Types

- Explicitly declare or delete copy/move operations (Rule of Five / Rule of Zero)
- Resource-owning classes should implement move; value types should support copy

```cpp
class Socket {
public:
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;
    Socket(Socket&&) noexcept;
    Socket& operator=(Socket&&) noexcept;
};
```

### Structs vs. Classes

- Use `struct` for passive data holders with no invariants
- Use `class` when data has invariants enforced by methods

```cpp
struct Point { double x, y; };

class Circle {
    Point center_;
    double radius_; // invariant: radius_ > 0
};
```

### Structs vs. Pairs and Tuples

- Prefer named structs over `std::pair` / `std::tuple` when fields have semantic meaning

```cpp
// BAD
std::pair<double, double> get_range();

// GOOD
struct Range { double low, high; };
Range get_range();
```

### Inheritance

- Prefer composition over inheritance
- Use `override` and `final` explicitly; never omit them on virtual overrides
- Virtual destructors are required in polymorphic base classes

```cpp
class Base {
public:
    virtual ~Base() = default;
    virtual void process() = 0;
};

class Derived : public Base {
public:
    void process() override;
};
```

### Operator Overloading

- Only overload operators when the meaning is obvious and conventional (e.g., `==`, `<`, `<<`)
- Prefer non-member operators for symmetry; implement `==` and `<=>` (C++20)

```cpp
[[nodiscard]] bool operator==(const Price& lhs, const Price& rhs) noexcept;

// C++20 spaceship
auto operator<=>(const Price&) const = default;
```

### Access Control

- Default to `private`; expose only what callers need
- Keep data members `private`; provide accessors if needed

```cpp
class Order {
public:
    [[nodiscard]] int id() const noexcept { return id_; }
private:
    int id_;
};
```

### Declaration Order

- `public` → `protected` → `private`
- Within each section: types, constants, constructors, methods, data

```cpp
class Foo {
public:
    using Id = int;
    explicit Foo(Id id);
    [[nodiscard]] Id id() const noexcept;

private:
    Id id_;
};
```

---

## Functions

### Inputs and Outputs

- Prefer return values over output parameters
- Take inputs by value when you need a copy, by `const&` when you only read
- Use `std::optional` for nullable returns instead of pointer + bool pairs

```cpp
// BAD
void get_name(std::string* out);

// GOOD
[[nodiscard]] std::string get_name();
[[nodiscard]] std::optional<Order> find_order(int id);
```

### Write Short Functions

- Keep functions focused on a single responsibility; prefer ≤ 40 lines
- Extract helpers when logic can be named meaningfully

### Function Overloading

- Overload only when functions are truly equivalent in behavior for different types
- Avoid overloads that differ only in subtle conversion rules

```cpp
void print(int value);
void print(double value);  // OK: same semantics, different type
```

### Default Arguments

- Use default arguments only for trailing parameters with stable defaults
- Avoid mutable or complex expressions as default values

```cpp
void connect(std::string_view host, uint16_t port = 8080);
```

### Trailing Return Type Syntax

- Use trailing return types when the return type depends on parameters or improves readability in templates

```cpp
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b);
```

---

## Other C++ Features

### Rvalue References

- Use `&&` parameters for move constructors and move assignment operators
- Use forwarding references (`T&&`) in templates with `std::forward`

```cpp
template <typename T>
void push(T&& value) {
    data_.emplace_back(std::forward<T>(value));
}
```

### Friends

- Minimize `friend` declarations; they break encapsulation
- Use `friend` only for operators that genuinely need private access

```cpp
class Money {
    friend bool operator==(const Money&, const Money&) noexcept;
    int cents_;
};
```

### Exceptions

- Use exceptions only for truly exceptional cases
- Never throw from destructors
- Document which functions throw with `noexcept` or comments

### noexcept

- Mark functions `noexcept` when they cannot throw; this enables optimizer and move semantics
- Move constructors and move assignment operators should almost always be `noexcept`

```cpp
Socket(Socket&&) noexcept;
Socket& operator=(Socket&&) noexcept;
```

### Run-Time Type Information (RTTI)

- Avoid `dynamic_cast` and `typeid`; redesign using virtual dispatch or `std::variant`
- If `dynamic_cast` is unavoidable, always check the result before use

```cpp
// BAD
Derived* d = dynamic_cast<Derived*>(base_ptr);
d->foo(); // crash if null

// GOOD
if (auto* d = dynamic_cast<Derived*>(base_ptr)) {
    d->foo();
}
```

### Casting

- Use C++ named casts — never C-style casts
- `static_cast` for safe conversions, `reinterpret_cast` only for low-level bit manipulation, `const_cast` almost never

```cpp
auto x = static_cast<double>(integer_value);
// NOT: (double)integer_value
```

### Streams

- No `std::cout` in production code; use the project logger
- Prefer structured logging over stream concatenation

```cpp
// BAD
std::cout << "price=" << price << "\n";

// GOOD
log_info("price={}", price);
```

### Preincrement and Predecrement

- Prefer `++i` over `i++` for non-primitive types to avoid unnecessary copies

```cpp
for (auto it = v.begin(); it != v.end(); ++it) { ... }
```

### Use of const

- Mark everything `const` where possible — parameters, local variables, member functions

```cpp
const std::string& symbol() const;
void process(const Order& order);
```

### Use of constexpr

- Use `constexpr` for values and functions computable at compile time
- Prefer `constexpr` over `#define` for constants

```cpp
constexpr double PI = 3.14159265358979;
constexpr int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }
```

### Integer Types

- Use fixed-width types (`int32_t`, `uint64_t`) when size matters
- Use `std::size_t` for sizes and indices into containers
- Avoid bare `int` for domain values with implicit semantics

```cpp
#include <cstdint>
uint64_t order_id;
std::size_t count = vec.size();
```

### 64-bit Portability

- Do not assume `int`, `long`, or pointer size; use `<cstdint>` types
- Use `%zu` / `PRId64` format specifiers or structured logging

```cpp
int64_t value = ...;
log_info("value={}", value); // not printf with %ld
```

### Preprocessor Macros

- Avoid macros for constants and inline functions; use `constexpr` and `inline` instead
- Reserve macros for guards and platform/debug conditionalization

```cpp
// BAD
#define MAX_SIZE 256
#define SQ(x) ((x)*(x))

// GOOD
constexpr int MAX_SIZE = 256;
constexpr int sq(int x) { return x * x; }
```

### 0 and nullptr/NULL

- Use `nullptr` for null pointers, never `0` or `NULL`

```cpp
int* p = nullptr;
if (p != nullptr) { ... }
```

### sizeof

- Use `sizeof(variable)` rather than `sizeof(type)` to stay correct if the type changes

```cpp
// BAD
memset(buf, 0, sizeof(char) * N);

// GOOD
memset(buf, 0, sizeof(buf));
```

### Type Deduction

- Use `auto` when the type is obvious from context or verbose to write
- Avoid `auto` when the type is important to the reader

```cpp
auto it = map.find(key);          // OK: type is clear from context
auto result = compute();          // BAD: return type hidden from reader
std::optional<Order> result = compute(); // GOOD
```

### Class Template Argument Deduction

- Use CTAD (C++17) to avoid redundant template arguments when deduction is unambiguous

```cpp
std::pair p{1, 2.0};          // deduced std::pair<int, double>
std::vector v{1, 2, 3};       // deduced std::vector<int>
```

### Designated Initializers

- Use designated initializers (C++20) for structs to make initialization self-documenting

```cpp
struct Config { int port; bool tls; std::string host; };
Config cfg{.port = 8080, .tls = true, .host = "localhost"};
```

### Lambda Expressions

- Prefer explicit capture lists over `[=]` or `[&]` to make captured variables obvious
- Keep lambda bodies short; extract named functions for complex logic

```cpp
auto is_valid = [threshold](const Order& o) {
    return o.quantity() > threshold;
};
```

### Template Metaprogramming

- Use `if constexpr`, `std::enable_if`, or concepts (C++20) instead of complex SFINAE
- Prefer concepts for readable constraints

```cpp
template <std::integral T>
T clamp(T val, T lo, T hi);
```

### Boost

- Prefer standard library equivalents over Boost when available in C++17/20
- Use Boost only when the standard has no suitable alternative; document why

### std::hash

- Provide a `std::hash` specialization for custom key types used in unordered containers

```cpp
template <>
struct std::hash<OrderId> {
    std::size_t operator()(OrderId id) const noexcept {
        return std::hash<int>{}(id.value());
    }
};
```

### Nonstandard Extensions

- Avoid compiler-specific extensions (`__attribute__`, `__declspec`) unless wrapping them in macros that degrade gracefully

```cpp
#if defined(__GNUC__) || defined(__clang__)
#define LIKELY(x)   __builtin_expect(!!(x), 1)
#else
#define LIKELY(x)   (x)
#endif
```

### Aliases

- Use `using` instead of `typedef`; prefer aliases in the narrowest applicable scope

```cpp
using OrderMap = std::unordered_map<int, Order>;
using Callback = std::function<void(const Event&)>;
```

---

## Inclusive Language

- Avoid terms with exclusionary connotations: prefer `allowlist`/`denylist` over `whitelist`/`blacklist`, `primary`/`replica` over `master`/`slave`

---

## Naming

### General Naming Rules

- Prefer **clarity over cleverness**
- Names should be descriptive at their scope: short for loop counters, verbose for public APIs

### File Names

- Headers: `snake_case.hpp`
- Sources: `snake_case.cpp`
- One primary class per file (when reasonable)

```
order_book.hpp
order_book.cpp
```

### Type Names

- Classes / Structs / Enums: **PascalCase**

```cpp
class OrderBook;
struct TradeEvent;
enum class OrderSide;
```

### Variable Names

- Local variables: **snake_case**
- Member variables: **snake_case_** (trailing underscore)

```cpp
int order_count;
std::string symbol_;
```

### Constant Names

- Upper snake case

```cpp
constexpr int MAX_RETRIES = 5;
```

### Function Names

- Functions & methods: **snake_case**

```cpp
void update_order_book();
bool is_valid() const;
```

### Namespace Names

- All lowercase, short, no underscores

```cpp
namespace myproject {}
namespace net {}
```

### Enumerator Names

- Use `enum class`; enumerator values in **PascalCase**

```cpp
enum class OrderSide { Buy, Sell };
```

### Macro Names

- All caps with underscores; prefix with project name to avoid collisions

```cpp
#define MYPROJECT_ASSERT(x) ...
```

### Exceptions to Naming Rules

- Standard library–style types (`iterator`, `value_type`) may use lowercase to satisfy concept requirements
- Third-party API callbacks may match the API's convention

---

## Comments

- Explain **why**, not **what**
- Keep comments up to date

### Comment Style

- Use `//` for all comments; reserve `/* */` only for disabling blocks temporarily

```cpp
// Adjust price to avoid crossing the spread
int adjusted = price - spread;
```

### File Comments

- Include a brief one-line description of the file's purpose at the top

```cpp
// order_book.hpp — limit order book with O(log n) insert/cancel
```

### Class Comments

- Document the class's invariants and intended usage; skip obvious boilerplate

```cpp
// Thread-safe order book. All public methods lock mutex_.
class OrderBook { ... };
```

### Function Comments

- Document non-obvious preconditions, postconditions, and ownership semantics

```cpp
// Returns the best bid price, or std::nullopt if the book is empty.
[[nodiscard]] std::optional<Price> best_bid() const;
```

### Variable Comments

- Only comment member variables when their purpose or units are non-obvious

```cpp
double tick_size_;  // minimum price increment, in USD
```

### Implementation Comments

```cpp
// Price is adjusted to avoid crossing the spread
```

### Punctuation, Spelling, and Grammar

- Write complete sentences with proper capitalization and punctuation
- Use American English spelling

### TODO Comments

- Include an owner or ticket reference so TODOs don't rot

```cpp
// TODO(alice): replace with lock-free queue — see JIRA-1234
```

### Deprecation Comments

- Mark deprecated APIs with `[[deprecated]]` and a migration note

```cpp
[[deprecated("Use new_api() instead")]]
void old_api();
```

---

## Exceptions to the Rules

### Existing Non-conformant Code

- Be consistent with existing code in the same file; prefer a single cleanup commit over mixing style in a functional PR

### Windows Code

- Use `_WIN32` guards for Windows-specific code; abstract platform differences behind an interface

```cpp
#ifdef _WIN32
#include <windows.h>
#endif
```

---

## Tooling

Recommended tools:

- `clang-format`
- `clang-tidy`
- `cppcheck`

Formatting must pass:
```
clang-format --style=file
```

Use project logging facilities. Debug-only code must be guarded:

```cpp
#ifdef DEBUG
log_debug("state=", state);
#endif
```

---

## References

- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html)

---

**Any deviation from this style must be justified and documented.**
