#include "./Examples.hpp"

#include <iostream>

class CppClass
{
public:
    int m_a = 1;
    int m_b = 10;

    int Add();

    // in class definition
    // compiler adds this-pointer
    void Print(/* CppClass* this */)
    {
        std::cout << "  a: " << m_a
                  << ", b: " << std::endl;
    }
};

// definition out of class
// compiler adds this-pointer
int CppClass::Add(/* CppClass* this */)
{
    return this->m_a + this->m_b;
}

void DoCppClass()
{
    std::cout << std::endl
              << "### CppClass ###" << std::endl;
    std::cout << "  CppClass cClass;\n  cppClass.Add(/* &cppClass as this-pointer */);" << std::endl;

    CppClass cppClass;
    int returnVal = cppClass.Add();

    std::cout << "  returnVal = " << returnVal << std::endl;

    CppClass* ptr;
    ptr = &cppClass;
    ptr->Print();

    CppClass& ref = cppClass;
    ref.Print();
    ptr == &ref;
}
