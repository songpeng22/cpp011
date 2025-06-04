#include <stdio.h>
#include <glob.h>
#include <unistd.h>

#include "logTest.h"

namespace A::B::C
{
    class ITest
    {
    public:
        //keep default constructor clearly to avoid hidden risk.
        ITest()                         = default;
        virtual ~ITest()                = default;
        ITest(const ITest&)             = default;
        ITest(ITest &&)                 = default;
        ITest& operator=(const ITest&)  = default;
        ITest& operator=(ITest&&)       = default;

    };

    class Test : public ITest
    {
    public:
        Test(){
            printf("A::B::C::Test -> this is test().\n");
        }
        ~Test(){
            printf("A::B::C::Test -> this is ~test().\n");
        }
    };    
}

namespace
{
    A::B::C::Test test;
}

int main()
{
    printf("this is main().\n");

    logTest();

    return 0;
}

