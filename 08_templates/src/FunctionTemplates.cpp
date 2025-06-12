#include "./Examples.hpp"

#include <iostream>

template<typename T, T value>
T TemplateFunction()
{
    return value;
}

void DoFunctionTemplate()
{
    std::cout << std::endl
              << "### Function Template ###" << std::endl;
    std::cout << "Functiontemplate are similar to class templates, but only the function is copied."
              << std::endl
              << "Function templates may be part of an class or in global space."
              << std::endl
              << "Templated functions must be defined where they are used."
              << std::endl
              << std::endl;

    std::cout << "  TemplateFunction<int, 5>() => " << TemplateFunction<int, 5>() << std::endl;
    //std::cout << "  TemplateFunction<double, 84.43>() => " << TemplateFunction<double, 84.43>() << std::endl;
}
