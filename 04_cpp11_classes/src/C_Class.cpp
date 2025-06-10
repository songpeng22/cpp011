#include "./Examples.hpp"

#include <iostream>

struct C_Class
{
    int m_a = 1;
    int m_b = 10;
};

int Add(struct C_Class* _this)
{
    return _this->m_a + _this->m_b;
}

void DoC_Class()
{
    struct C_Class cClass;
    int returnVal = Add(&cClass);

    std::cout << std::endl
              << "### C_Class ###" << std::endl;
    std::cout << "  struct C_Class cClass;\n  Add(&cClass);" << std::endl;
    std::cout << "  returnVal = " << returnVal << std::endl;
}
