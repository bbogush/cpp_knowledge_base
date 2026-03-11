/*  Copyright (C) 2026 cpp-knowledge-base project
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the Apache License Version 2.0.
 */

#include <iostream>

class A;
class B;

class Visitor {
public:
    virtual void visit(A &a) = 0;
    virtual void visit(B &b) = 0;
};

class A {
public:
    std::string name() { return "A"; }
    void accept(Visitor &v) { v.visit(*this); }
};

class B {
public:
    std::string name() { return "B"; }
    void accept(Visitor &v) { v.visit(*this); }
};

class ABVisitor : public Visitor {
public:
    void visit(A &a) {
        std::cout << a.name() << '\n';
    }

    void visit(B &b) {
        std::cout << b.name() << '\n';
    }
};

int main()
{
    ABVisitor v;
    
    A a;
    a.accept(v);

    B b;
    b.accept(v);

    return 0;
}