/*  Copyright (C) 2026 cpp-knowledge-base project
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the Apache License Version 2.0.
 */


#include <iostream>

class Implementation
{
public:
    virtual ~Implementation() = default;
    virtual void operation() = 0;
};

class ConcreteImplementationA : public Implementation
{
public:
    void operation() override
    {
        std::cout << "ConcreteImplementationA operation" << std::endl;
    }
};

class ConcreteImplementationB : public Implementation
{
public:
    void operation() override
    {
        std::cout << "ConcreteImplementationB operation" << std::endl;
    }
};

class Abstraction
{
public:
    Abstraction(Implementation* impl) : implementation(impl) {}
    virtual ~Abstraction() = default;
    virtual void operation()
    {
        implementation->operation();
    }
private:
    Implementation* implementation;
};


int main()
{
    ConcreteImplementationA implA;
    Abstraction abstractionA(&implA);
    abstractionA.operation();

    ConcreteImplementationB implB;
    Abstraction abstractionB(&implB);
    abstractionB.operation();

    return 0;
}