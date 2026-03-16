/*  Copyright (C) 2026 cpp-knowledge-base project
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the Apache License Version 2.0.
 */

#include <iostream>

class AbstractProductA {
public:
    virtual ~AbstractProductA() = default;
    virtual void operationA() = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    void operationA() override
    {
        std::cout << "ConcreteProductA1 operationA" << std::endl;
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    void operationA() override
    {
        std::cout << "ConcreteProductA2 operationA" << std::endl;
    }
};

class AbstractProductB {
public:
    virtual ~AbstractProductB() = default;
    virtual void operationB() = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
    void operationB() override
    {
        std::cout << "ConcreteProductB1 operationB" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    void operationB() override
    {
        std::cout << "ConcreteProductB2 operationB" << std::endl;
    }
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual AbstractProductA *createProductA() = 0;
    virtual AbstractProductB *createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA *createProductA() override
    {
        return new ConcreteProductA1();
    }
    AbstractProductB *createProductB() override
    {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA *createProductA() override
    {
        return new ConcreteProductA2();
    }
    AbstractProductB *createProductB() override
    {
        return new ConcreteProductB2();
    }
};

int main()
{
    AbstractFactory *factory1 = new ConcreteFactory1();
    AbstractProductA *productA1 = factory1->createProductA();
    AbstractProductB *productB1 = factory1->createProductB();
    productA1->operationA();
    productB1->operationB();
    delete productA1;
    delete productB1;
    delete factory1;

    AbstractFactory *factory2 = new ConcreteFactory2();
    AbstractProductA *productA2 = factory2->createProductA();
    AbstractProductB *productB2 = factory2->createProductB();
    productA2->operationA();
    productB2->operationB();
    delete productA2;
    delete productB2;
    delete factory2;

    return 0;
}