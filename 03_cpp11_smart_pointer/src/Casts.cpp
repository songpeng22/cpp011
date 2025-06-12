#include "./Examples.hpp"

#include <iostream>

class ConstClass
{
public:
    void Print() const
    {
        std::cout << "  ConstClass::Print() const" << std::endl;
    }

    void Print()
    {
        std::cout << "  ConstClass::Print()" << std::endl;
    }
};

class ClassCasting
{
public:
    operator float()
    {
        std::cout << "  ClassCasting::operator float()" << std::endl;
        return 2.5;
    }
};

void TypeConversion()
{
    std::cout << "\"static_cast\" are used for type conversion that relay on static (compile-time) type information" << std::endl;
    int a   = 5;
    float f = (float)a;

    f = static_cast<float>(a);

    ClassCasting classToCast;
    f = static_cast<float>(classToCast);
}

void ConstCast()
{
    std::cout << "\"const_cast\" can be used to remove the \"const\" or \"volatile\" property" << std::endl;
    const int a = 5;

    // a = 6; // Compiler Error
    // int* aPtr = &a; // Compiler Error
    int* aPtr = const_cast<int*>(&a);
    aPtr      = (int*)&a;

    std::cout << "const casts can also be used with classes" << std::endl;
    const ConstClass constClass;
    constClass.Print();
    ConstClass& refConstClass = const_cast<ConstClass&>(constClass);
    refConstClass.Print();

    volatile int v = 4;
    // int *vPtr = &v; // Compiler Error
    int* vPtr      = const_cast<int*>(&v);
    vPtr           = (int*)&v;
}

void ReinterpretCast()
{
    int a = 5;

    std::cout << "\"reinterpret_casts\" are used to cast one type bitwise to another. Anything can be cast to anything!" << std::endl;
    std::cout << "Excamples are:" << std::endl;

    std::cout << "  cast int-pointer to float-pointer" << std::endl;
    float* ptr = (float*)&a;
    // ptr        = static_cast<int*>(&a); // Compiler error
    ptr        = reinterpret_cast<float*>(&a);

    std::cout << "  cast int to int-pointer" << std::endl;
    int* b = (int*)((uint64_t)a);
    b      = reinterpret_cast<int*>(a);
    // b = static_cast<int*>(a); // Compiler error

    std::cout << "  cast int-pointer to int" << std::endl;
    int c        = (uint64_t)b;
    // c = reinterpret_cast<int>(b); // compiler error, because pointers are 8 byte on windows
    // c = static_cast<int>(b); // Compiler error
    auto address = reinterpret_cast<uint64_t>(b);
    c            = static_cast<int>(reinterpret_cast<uint64_t>(b));
}

void DoCasts()
{
    std::cout << std::endl
              << "### Casts ###" << std::endl;

    TypeConversion();
    std::cout << std::endl;

    ConstCast();
    std::cout << std::endl;

    ReinterpretCast();
    std::cout << std::endl;
}
