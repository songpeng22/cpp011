#include "./Examples.hpp"

#include <iostream>

class Constructors
{
public:
    Constructors()
    {
        std::cout << "  Default Constructor" << std::endl;
    }

    Constructors(int a, int b)
    {
        m_a = a;
        m_b = b;
        std::cout << "  Overloaded Default Constructor" << std::endl;
    }

    Constructors(const Constructors& rValue)
    {
        m_a = rValue.m_a;
        m_b = rValue.m_b;
        std::cout << "  CopyConstructor" << std::endl;
    }

    Constructors(Constructors&& rValue)
    {
        m_a        = rValue.m_a;
        m_b        = rValue.m_b;
        rValue.m_a = 0;
        rValue.m_b = 0;
        std::cout << "  MoveConstructor" << std::endl;
    }

    int Add()
    {
        return m_a + m_b;
    }

    void Print()
    {
        std::cout << "a: " << m_a << ", b: " << m_b << std::endl;
    }

private:
    int m_a = 1;
    int m_b = 10;
};

void DoMoveConstructors()
{
    std::cout << std::endl
              << "#### Move Construcors ####" << std::endl;
    std::cout << "Move Constructors transfer the owner ship of resources and nullifies the sources." << std::endl;

    Constructors constructors;
    Constructors targetToMove = std::move(constructors);
    std::cout << std::endl;

    constructors.Print();
    targetToMove.Print();
}

void DoCopyConstructors()
{
    std::cout << std::endl
              << "#### Copy Construcors ####" << std::endl;
    std::cout << "Copy Construcors copy resources and leave the soruces intact." << std::endl;
    Constructors constructors;
    Constructors copy(constructors);
    Constructors copy2 = constructors;
    std::cout << std::endl;

    constructors.Print();
    copy.Print();
    copy2.Print();
}

void DoConstructors()
{
    std::cout << std::endl
              << "### Constructors ### " << std::endl;
    std::cout << "Constructors are used to create an object" << std::endl;

    Constructors defaultConstructor;
    Constructors unifiedIntializer{};
    Constructors overloadedConstructor(15, 55);
    Constructors overloadedUnifiedInitializer{51, 74};
    std::cout << std::endl;

    defaultConstructor.Print();
    unifiedIntializer.Print();
    overloadedConstructor.Print();
    overloadedUnifiedInitializer.Print();

    DoCopyConstructors();
    DoMoveConstructors();
}
