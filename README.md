# C++ Design Patterns, vol 1 — source code

This repository holds the example C++ code for the book
**[C++ Design Patterns, vol 1: Creational, Structural, Behavorial (1.0)](https://www.amazon.co.uk/Design-Patterns-vol-Creational-Structural-ebook/dp/B07T2RNTR6/ref=sr_1_1)**
by Damien Loison and Brian Gabillet.

Each `.cpp` file in `Project1/` is a focused, self-contained program illustrating one
pattern (a few patterns have more than one variant). The code is organised as a
Visual Studio solution (`DP.sln` + `Project1/Project1.vcxproj`).

## What the book is

A short, hands-on guide — around 80 pages covering roughly 25 patterns, each with a
working C++ code example. It is aimed at getting you productive with the classic
Gang-of-Four catalogue quickly rather than at exhaustive theory.

## What readers say

Readers rate it well (~4.1/5 on Amazon; 4.0 on Goodreads):

- **Accessible and clear.** Reviewers describe it as a quick, approachable guide —
  great for learning the patterns the first time and for refreshing them later, with
  the hands-on code examples called out as a highlight.
- **Efficient.** Its brevity (≈25 patterns in ≈80 pages) is praised as ideal for a
  fast, practical overview.
- **A great starting point.** Reviewers recommend it as an entry into the patterns,
  to be followed up with the original Gang-of-Four book for deeper, production-grade
  study.

## Patterns covered

### Creational

| Pattern           | File(s)                                                                 |
|-------------------|-------------------------------------------------------------------------|
| Abstract Factory  | `AbstractFactory.cpp`, `AbstractFactory_Builder.cpp`                    |
| Builder           | `Builder3.cpp`, `Factory_Builder1.cpp`, `Factory_Builder2.cpp`          |
| Factory Method    | `Factory1.cpp`, `Factory2.cpp`                                          |
| Prototype / Clone | `Clone1.cpp`, `Clone_withCloneDetails.cpp`, `Clone_withInheritance.cpp` |
| Singleton         | `Singleton.cpp`                                                         |

### Structural

| Pattern   | File(s)         |
|-----------|-----------------|
| Adapter   | `Adapter.cpp`   |
| Bridge    | `Bridge.cpp`    |
| Composite | `Composite.cpp` |
| Decorator | `Decorator.cpp` |
| Facade    | `Facade.cpp`    |
| Flyweight | `Flyweight.cpp` |
| Proxy     | `Proxy.cpp`     |
| Pimpl     | `Pimpl.cpp`     |

### Behavioral

| Pattern                 | File(s)                       |
|-------------------------|-------------------------------|
| Chain of Responsibility | `ChainOfResponsability.cpp`   |
| Command                 | `Command.cpp`                 |
| Mediator                | `Mediator.cpp`                |
| Memento                 | `Memento.cpp`, `Memento2.cpp` |
| Observer                | `Observer.cpp`                |
| State                   | `State.cpp`                   |
| Template Method         | `TemplateMethod.cpp`          |
| Visitor                 | `Visitor.cpp`                 |

### Also included

| Topic               | File(s)   |
|---------------------|-----------|
| MVC (architectural) | `MVC.cpp` |

`Print.h` is a small shared helper used by several examples.

## Building

Open `DP.sln` in Visual Studio and build the `Project1` project. Each pattern lives in
its own `.cpp` with a `main`, so compile/run the one you want to study (the project is
set up to build the examples individually).

Any standards-compliant C++ compiler works too, e.g.:

```sh
g++ -std=c++17 Project1/Singleton.cpp -o singleton && ./singleton
```
