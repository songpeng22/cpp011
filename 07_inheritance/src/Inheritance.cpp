#include "./Examples.hpp"

#include <iostream>

namespace Inheritance
{
    class Parent
    {
    public:
        Parent()          = default;
        // virtual destructor is needed, to delete child from an parent pointer
        virtual ~Parent() = default;

        // final prohibits overrides
        virtual int Add() final
        {
            return m_a + m_b;
        }

        virtual void Print()
        {
            std::cout << "  Parent::Print: " << "a: " << m_a << ", b: " << m_b << std::endl;
        }

    protected:
        void Set(int par1, int par2)
        {
            m_a = par1;
            m_b = par2;
        }

    private:
        int m_a{1};
        int m_b{10};
    };

    class Child: public Parent
    {
    public:
        Child()           = default;
        ~Child() override = default;

        // override implies virtual
        void Print() override
        {
            Parent::Print();
            std::cout << "  Child::Print";
        }

        // Add cannot be overriden, because in Parent it is declared final
        // int Add() override {}

        void Initialize()
        {
            Set(100, 1000);
        }
    };
}

void DoInheritance()
{
    std::cout << std::endl
              << "### Inheritance ###" << std::endl;
    std::cout
        << "Child inherits 'Add' and 'Print' from Parent and does not need to implement them."
        << std::endl
        << "However Child wants to override 'Print' to change the printing style."
        << std::endl
        << std::endl;

    Inheritance::Child child;
    child.Print();
    std::cout << std::endl;

    child.Initialize();
    std::cout << "  child.Initialize() to set m_a = 100, m_b = 1000 " << std::endl;
    std::cout << "  child.Add() => " << child.Add() << std::endl;
}
