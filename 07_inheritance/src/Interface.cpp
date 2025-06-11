#include "./Examples.hpp"

#include <iostream>

class Interface
{
public:
    Interface()          = default;
    virtual ~Interface() = default;

    virtual int Add()    = 0;
    virtual void Print() = 0;
};

class Implementation: public Interface
{
public:
    Implementation()          = default;
    virtual ~Implementation() = default;

    int Add() override
    {
        m_sum = 1 + 2;
        return m_sum;
    }

    void Print() override
    {
        std::cout << "  Implementation::Print: " << m_sum << std::endl;
    }

private:
    int m_sum{0};
};

class OtherImplementation: public Interface
{
public:
    OtherImplementation()          = default;
    virtual ~OtherImplementation() = default;

    int Add() override
    {
        m_sum = 100 + 200;
        return m_sum;
    }

    void Print() override
    {
        std::cout << "  OtherImplementation::Print: " << m_sum << std::endl;
    }

private:
    int m_sum{0};
};

void DoInterface(Interface& interface)
{
    interface.Add();
    interface.Print();
}

void DoInterface()
{
    std::cout << std::endl
              << "### Interface ### " << std::endl;

    std::cout
        << "Interfaces are special Abstract Classes, where all functions (except Constructor and Destructor) are pure virtual."
        << std::endl
        << "Interfaces are used to enforce implemented functions and to hide some functionality."
        << std::endl
        << std::endl;

    Implementation implementation;
    OtherImplementation otherImplementation;

    DoInterface(implementation);
    DoInterface(otherImplementation);
}
