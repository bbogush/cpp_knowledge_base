/*  Copyright (C) 2026 cpp-knowledge-base project
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the Apache License Version 2.0.
 */

#include <iostream>

class Target {
public:
    virtual ~Target() = default;
    virtual void request() = 0;
};

class Adaptee {
public:
    void specificRequest()
    {
        std::cout << "Adaptee specific request" << std::endl;
    }
};

class Adapter : public Target {
public:
    Adapter(Adaptee *adaptee) : adaptee(adaptee)
    {
    }
    void request() override
    {
        adaptee->specificRequest();
    }

private:
    Adaptee *adaptee;
};

int main()
{
    Adaptee adaptee;
    Adapter adapter(&adaptee);
    adapter.request();

    return 0;
}