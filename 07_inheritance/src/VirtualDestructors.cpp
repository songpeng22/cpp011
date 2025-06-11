#include "./Examples.hpp"

#include <iostream>

class IVirtualDestructor
{
public:
    IVirtualDestructor()
    {
        std::cout << "  IVirtualDestructor::Constructor" << std::endl;
    }
    virtual ~IVirtualDestructor()
    {
        std::cout << "  IVirtualDesctructor::~Destructor" << std::endl;
    }
};

class VirtualDestructor: public IVirtualDestructor
{
public:
    VirtualDestructor()
    {
        std::cout << "  VirtualDestructor::Constructor" << std::endl;
    }
    ~VirtualDestructor() override
    {
        std::cout << "  VirtualDestructor::~Destructor" << std::endl;
    }
};

class INonVirtualDestructor
{
public:
    INonVirtualDestructor()
    {
        std::cout << "  INonVirtualDestructor::Constructor" << std::endl;
    }
    ~INonVirtualDestructor()
    {
        std::cout << "  INonVirtualDestructor::~Destructor" << std::endl;
    }
};

class NonVirtualDestructor: public INonVirtualDestructor
{
public:
    NonVirtualDestructor()
    {
        std::cout << "  NonVirtualDestructor::Constructor" << std::endl;
    }
    ~NonVirtualDestructor()
    {
        std::cout << "  NonVirtualDestructor::Destructor" << std::endl;
    }
};

void DoVirtualDestructors()
{
    std::cout << std::endl
              << "### Virtual Destructors ###" << std::endl;

    std::cout << "Destructor must be virtual, so that child destructors can be called via vTable." << std::endl;
    IVirtualDestructor* virtualDestructor = new VirtualDestructor{};
    delete virtualDestructor;

    std::cout << std::endl;

    std::cout << "If Destructor is not virtual, child will not be destructed and memory is leaked!." << std::endl;
    INonVirtualDestructor* nonVirtualDestructor = new NonVirtualDestructor{};
    delete nonVirtualDestructor;
}
