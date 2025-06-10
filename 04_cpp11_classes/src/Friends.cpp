#include "./Examples.hpp"

#include <iostream>

class PrivateSetter;
class EverythingPrivate
{
public:
    void Print()
    {
        std::cout << "  EverythingPrivate::Print: m_a " << m_a << std::endl;
    }

private:
    int m_a;
    int m_b;

    friend PrivateSetter;
};

class PrivateSetter
{
public:
    PrivateSetter(int a, int b)
    {
        m_a = a;
        m_b = b;
    }

    void Set(EverythingPrivate& everythingPrivate)
    {
        everythingPrivate.m_a = m_a;
        everythingPrivate.m_b = m_b;
    }

private:
    int m_a;
    int m_b;
};

void DoFriends()
{
    std::cout << std::endl
              << "### Friends ###" << std::endl;
    std::cout << "Friends are a method, to grant a foreign Class or Method access to private members" << std::endl;

    EverythingPrivate p;
    p.Print();

    PrivateSetter setter{6, 4};
    setter.Set(p);
    p.Print();
}
