#include "./Examples.hpp"

#include <iostream>

#define MAGIC_DEFINE_NUMBER 48.7

static constexpr int MAGIC_CONSTEXPR_NUMBER{48};

constexpr int GetDefaultWert(int a, int b)
{
    return a + b;
}

void DoConstexpr()
{
    std::cout << std::endl
              << "### Constexpr @###" << std::endl;

    std::cout << "Contexpr are like defines, but are parsed during compiletime and have a type." << std::endl;
    std::cout << "Functions may be conexpr, too and the compiler tries to solve those." << std::endl;
    std::cout << "Note: If constexpr are needed during runtime, the compiler treats them as const." << std::endl;

    constexpr int MAGIC_NUMBER_FUNCTION{33};

    std::cout << "magic:" << MAGIC_NUMBER_FUNCTION << std::endl;
    char test = MAGIC_DEFINE_NUMBER;
    std::cout << "test:" << test << std::endl;

    std::cout << GetDefaultWert(1, 6) << std::endl;
}
