#include "./Examples.hpp"

#include <iostream>

class IDependencyInjection
{
public:
    IDependencyInjection()          = default;
    virtual ~IDependencyInjection() = default;

    virtual void Print() = 0;
};

class DependencyImplementation: public IDependencyInjection
{
public:
    DependencyImplementation()           = default;
    ~DependencyImplementation() override = default;

    void Print() override
    {
        std::cout << "  DependencyImplementation::Print" << std::endl;
    }
};

class DependencyImplementation2: public IDependencyInjection
{
public:
    DependencyImplementation2()           = default;
    ~DependencyImplementation2() override = default;

    void Print() override
    {
        std::cout << "  DependencyImplementation2::Print" << std::endl;
    }
};

class Consument
{
public:
    void SetDep(IDependencyInjection* dep)
    {
        m_impl = dep;
    }

    void Print()
    {
        m_impl->Print();
    }

private:
    IDependencyInjection* m_impl;
};

void DoDependencyInjection()
{

    std::cout << std::endl << "### Dependency Injection ###" << std::endl;

    Consument c1;
    Consument c2;
    DependencyImplementation imp1;
    DependencyImplementation2 imp2;

    c1.SetDep(&imp1);
    c2.SetDep(&imp2);

    c1.Print();
    c2.Print();
}
