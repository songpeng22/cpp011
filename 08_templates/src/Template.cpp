#include "./Examples.hpp"

#include <iostream>

// template must be defined where they are used (headers, or cpp local)
template<typename T>
class Template
{
public:
    Template(T a, T b)
    {
        m_a = a;
        m_b = b;
    }

    virtual ~Template() = default;

    T Add()
    {
        return m_a + m_b;
    }

    void Print();

private:
    T m_a;
    T m_b;
};

// if template functions are defined extern
template<typename T>
void Template<T>::Print()
{
    std::cout << "  a: " << m_a << ", b: " << m_b << std::endl;
}

void DoTemplate()
{
    std::cout << std::endl
              << "### Template ###" << std::endl;
    std::cout
        << "Templates are used to generalise classes and specialize them during compiletime." << std::endl
        << "Since tempaltes are a compiler construct, they must be defined where they are used (locally or included via header) and the template functions must be present during compiletime (-> must be defined or included in header)"
        << std::endl
        << "Compiler copies the template everytime the class is instantiatet with <>."
        << std::endl
        << "Here we have 2 different classes Template<int> and Template<double> and even if these classes are similar, one cannot be casted to another"
        << std::endl;

    Template<int> intTemplate{5, 10};

    std::cout << std::endl
              << "  Template<int>::Add() => "
              << intTemplate.Add()
              << std::endl;

    intTemplate.Print();

    Template<double> doubleTemplate{5.234, 10.67};
    std::cout << std::endl
              << "  Template<double>::Add() => "
              << doubleTemplate.Add()
              << std::endl;
    doubleTemplate.Print();

    std::cout << std::endl;
}
