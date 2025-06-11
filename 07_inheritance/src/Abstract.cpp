#include "./Examples.hpp"

#include <iostream>

class AbstractClass
{
public:
    AbstractClass(int a, int b)
    {
        std::cout << "  AbstractClass Constructor " << std::endl;
        m_a = a;
        m_b = b;
    }

    virtual ~AbstractClass() = default;

    virtual int Add() = 0;

    virtual void Print() final
    {
        std::cout << "  Abstract Clas::Print: a:  " << m_a << ", b:" << m_b << std::endl;
    }

private:
    int m_a{0};
    int m_b{0};
};

class ConcreteClass: public AbstractClass
{
public:
    ConcreteClass():
        AbstractClass(515, 183) // constructor chaining
    {
        std::cout << "  ConcreteClass Constructor " << std::endl;
    }
    virtual ~ConcreteClass() = default;

    int Add() override
    {
        return 1 + 2;
    }
};

void DoAbstract()
{
    std::cout << std::endl
              << "### Abstract ### " << std::endl;
    std::cout
        << "Abstract Classes are classes to be inherited, where some functions are declared, but not implemented (pure virtual)."
        << std::endl
        << "Children are forced to implement those functions, otherwise they cannot be instantiated."
        << std::endl
        << std::endl;

    // abstract classes cannot be instantiatet, because some Methods are pure virtual (not defined)
    // here int Add() is not defined!
    // AbstractClass abstractClass;

    ConcreteClass concreteClass;
    concreteClass.Print();
    std::cout << std::endl;

    std::cout << "concreteClass.Add() => " << concreteClass.Add() << std::endl;
}
