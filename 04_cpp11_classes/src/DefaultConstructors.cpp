#include "./Examples.hpp"

#include <iomanip>
#include <iostream>

class DefaultConstructors
{
public:
    int Add()
    {
        return m_a + m_b;
    }

    void Print()
    {
        std::cout << "  string: " << std::quoted(m_string) << ", a: " << m_a << ", b: " << m_b << std::endl;
    }

private:
    std::string m_string{"Hello"};
    int m_a = 1;
    int m_b = 10;
};

void DoDefaultMoveConstructors()
{
    std::cout << std::endl
              << "#### Default Move Construcors ####" << std::endl;
    std::cout << "Move Constructors transfer the owner ship of resources and nullifies the sources." << std::endl;

    DefaultConstructors constructors;
    DefaultConstructors targetToMove = std::move(constructors);
    std::cout << std::endl;

    constructors.Print();
    targetToMove.Print();
}

void DoDefaultCopyConstructors()
{
    std::cout << std::endl
              << "#### Default Copy Constructors ####" << std::endl;
    std::cout << "Copy Constructors copy resources and leave the soruces intact." << std::endl;
    DefaultConstructors constructors;
    DefaultConstructors copy(constructors);
    DefaultConstructors copy2 = constructors;
    std::cout << std::endl;

    constructors.Print();
    copy.Print();
    copy2.Print();
}

void DoDefaultConstructors()
{
    std::cout << std::endl
              << "### Default Constructors ### " << std::endl;
    std::cout << "Constructors are used to create an object" << std::endl;

    DefaultConstructors defaultConstructor;
    DefaultConstructors unifiedIntializer{};
    std::cout << std::endl;

    defaultConstructor.Print();
    unifiedIntializer.Print();

    DoDefaultCopyConstructors();
    DoDefaultMoveConstructors();
}
