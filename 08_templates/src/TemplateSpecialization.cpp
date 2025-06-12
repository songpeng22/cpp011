#include "./Examples.hpp"

#include <iostream>

template<typename T>
T Add(T a, T b)
{
    return a + b;
}

template<>
std::string Add(std::string a, std::string b)
{
    return a.append(b);
}

void DoTemplateSpecialization()
{
    std::cout << std::endl
              << "### Template Specialization ###" << std::endl;
    std::cout << "TemplateSpecialization is used to implement some functionality which cannot be generalized."
              << std::endl
              << "Here, the default is a + b. But is a + b is not defiend template specialization can be used (here with st::string)"
              << std::endl
              << std::endl;

    std::cout << "  Add<int>(5, 9) => " << Add<int>(5, 9) << std::endl;
    std::cout << "  Add<std::string>(\"Hello\", \"World\") => " << Add<std::string>("Hello", "World") << std::endl;
}
