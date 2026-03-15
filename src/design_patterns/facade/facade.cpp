/*  Copyright (C) 2026 cpp-knowledge-base project
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the Apache License Version 2.0.
 */

#include <iostream>

class SubsystemA {
public:
    void operationA()
    {
        std::cout << "SubsystemA operationA" << std::endl;
    }
};

class SubsystemB {
public:
    void operationB()
    {
        std::cout << "SubsystemB operationB" << std::endl;
    }
};

class Facade {
public:
    void operation()
    {
        std::cout << "Facade operation" << std::endl;
        subsystemA.operationA();
        subsystemB.operationB();
    }

private:
    SubsystemA subsystemA;
    SubsystemB subsystemB;
};

int main()
{
    Facade facade;
    facade.operation();

    return 0;
}