#include "./Examples.hpp"

#include <iostream>

namespace First
{
    namespace Second
    {
        class Class
        {
        public:
            int m_a = 5;
        };
    }

    class Class
    {
    public:
        int m_a = 10;
    };
}

void DoNamespaces()
{
    std::cout << std::endl
              << "### Namespaces ###" << std::endl;

    First::Second::Class classWithNamespace;

    std::cout << "  First::Second::Class classWithNamespace;" << std::endl;
    std::cout << "    classWithNamespace.a => " << classWithNamespace.m_a << std::endl
              << std::endl;

    using Class = First::Second::Class;
    Class classWithAlias;

    std::cout << "  using Class = First::Second::Class;" << std::endl;
    std::cout << "  First::Second::Class classWithNamespace;" << std::endl;
    std::cout << "    classWithAlias.a => " << classWithAlias.m_a << std::endl
              << std::endl;

    First::Class sameNameOtherNamespace;

    std::cout << "  First::Class sameNameOtherNamespace" << std::endl;
    std::cout << "    sameNameOtherNamespace.a => " << sameNameOtherNamespace.m_a << std::endl
              << std::endl;

    std::cout
        << "Mangeling means, in C++ one can have mutliple symbols of the same name, as long as those are uniquely identifiable."
        << std::endl
        << "For Example Namespaces or Functions with different signatures."
        << std::endl;
}
