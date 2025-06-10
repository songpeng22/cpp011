#include "Examples.hpp"

#include <iostream>

int main()
{
    std::cout << std::endl
              << std::endl;
#if 1
    //
    DoCppClass();
    //Constructor
    DoDefaultConstructors();
    DoConstructors();
    DoCanonicalClassForm();

    DoExplicitConstructor();
    //Design Pattern
    DoAssociation();
#else
    DoC_Class();
    DoCppClass();
    DoDefaultConstructors();
    DoConstructors();
    DoCanonicalClassForm();
    DoNamespaces();
    DoInheritance();
    DoAbstract();
    DoInterface();
    DoMemory();
    DoTemplate();
    DoFunctionTemplate();
    DoTemplateSpecialization();
    DoUniquePtr();
    DoSharedPtr();

    DoVirtualDestructors();
    DoCasts();
    DoIterators();
    DoCMixer();
    DoExplicitConstructor();

    DoConstCorrectness();
    DoConstexpr();
    DoFriends();
    DoAssociation();
    DoDependencyInjection();
    DoSingleton();
#endif
    std::cout << std::endl
              << "Destructoren of static Memory objects: " << std::endl;

    return 0;
}
