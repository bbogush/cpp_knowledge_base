# Bridge Pattern

## Description

The **Bridge** pattern decouples an abstraction from its implementation so that the two can vary independently.
Instead of using inheritance to extend both dimensions, Bridge uses composition to delegate implementation work to a separate hierarchy.

---

## Key Features

- **Independent Variation**: Abstraction and implementation hierarchies can grow independently without combinatorial class explosion.
- **Open/Closed Principle**: New abstractions and implementations can be added without modifying existing code.
- **Composition Over Inheritance**: The abstraction holds a pointer to the implementation rather than inheriting from it.

---

## Participants

| Role | In `bridge.cpp` | Responsibility |
|---|---|---|
| `Implementation` | `Implementation` | Declares the interface for concrete implementations via `operation()` |
| `ConcreteImplementation` | `ConcreteImplementationA`, `ConcreteImplementationB` | Provides a specific platform/variant implementation |
| `Abstraction` | `Abstraction` | Holds a reference to an `Implementation` and delegates calls to it |
| Client | `main()` | Creates a concrete implementation and injects it into the abstraction |

---

## Advantages

- Avoids a permanent binding between abstraction and implementation.
- Hides implementation details from clients completely.
- Enables runtime switching of implementations.

---

## Disadvantages

- Increases overall design complexity with two separate class hierarchies.
- Indirection through the bridge can be harder to follow when debugging.
- Can be overkill when only one implementation is ever needed.

---

## UML Diagram

```mermaid
classDiagram
    direction LR

    class Implementation {
        <<interface>>
        +operation() void*
    }

    class ConcreteImplementationA {
        +operation() void
    }

    class ConcreteImplementationB {
        +operation() void
    }

    class Abstraction {
        -implementation : Implementation*
        +operation() void
    }

    Implementation <|-- ConcreteImplementationA
    Implementation <|-- ConcreteImplementationB
    Abstraction o--> Implementation : delegates to
```
