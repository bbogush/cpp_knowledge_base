# Visitor Pattern

## Description

The **Visitor** pattern lets you add new operations to existing class hierarchies **without modifying those classes**.
It separates an algorithm from the object structure it operates on by placing the algorithm in a separate *visitor* object.

---

## Key Features

- **Double Dispatch**: The correct `visit()` overload is selected based on both the visitor type and the element type.
- **Open/Closed Principle**: New operations are added via new visitor classes; element classes stay untouched.
- **Separation of Concerns**: Data structure (elements) and algorithms (visitors) live independently.

---

## Participants

| Role | In `visitor.cpp` | Responsibility |
|---|---|---|
| `Visitor` | `Visitor` | Declares a `visit()` overload for each element type |
| `ConcreteVisitor` | `ABVisitor` | Implements the operation for each element type |
| `Element` | `A`, `B` | Declares `accept(Visitor&)` |
| Client | `main()` | Constructs elements and visitors, triggers traversal |

---

## How It Works

1. The client calls `element.accept(visitor)`.
2. Inside `accept`, the element calls `visitor.visit(*this)` — passing itself.
3. Because `*this` is a concrete type, C++ static overload resolution picks the right `visit()` overload.
4. The visitor executes its operation on the element.

This two-step dispatch (virtual `accept` + overloaded `visit`) is the core of the pattern.

---

## Advantages

- Add new operations without changing element classes.
- Related behaviour is co-located inside one visitor class.
- Visitors can accumulate state across multiple elements.

---

## Disadvantages

- Adding a new element type requires updating **every** visitor.
- Breaks encapsulation if visitors need access to private element state.
- Can become verbose when many element types exist.

---

## UML Diagram

```mermaid
classDiagram
    direction LR

    class Visitor {
        <<interface>>
        +visit(A& a)*
        +visit(B& b)*
    }

    class ABVisitor {
        +visit(A& a)
        +visit(B& b)
    }

    class A {
        +name() string
        +accept(Visitor& v)
    }

    class B {
        +name() string
        +accept(Visitor& v)
    }

    Visitor <|-- ABVisitor
    A ..> Visitor : accept calls visit
    B ..> Visitor : accept calls visit
```
