#include "./Examples.hpp"
#include <iostream>

//To avoid calling wrong constructor, We need explicit
//Using explicit, to forbit implicit conversion
/*
class Str{
public:
    Str(int x){
	cout<<"我是想把整数变字符串"<<endl;
    }
    Str(const char* a){
	cout<<"我是想把字符数组变字符串"<<endl;
    }
};
int main( ){
    Str s='c'; 
    // 输出："我是想把整数变字符串"
    // 它把'c'的ASCII码传进去了，如果这样变成字符串那就得到一个数字，
    // 而我们期待的是把'c'变成字符串。
    return 0;
}
*/

class ExplicitConstructor
{
public:
    ExplicitConstructor(int a)
    {
        std::cout << "  ExplicitConstructor::ExplicitConstructor m_a: " << a << std::endl;
        m_a = a;
    }
#if 0
    ExplicitConstructor(int a, int b)
    {
        std::cout << "  ExplicitConstructor::ExplicitConstructor m_a: " << a << ", m_b: " << b << std::endl;
        m_a = a;
        m_b = b;
    }
#else
    explicit ExplicitConstructor(int a, int b)
    {
        std::cout << "  ExplicitConstructor::ExplicitConstructor m_a: " << a << ", m_b: " << b << std::endl;
        m_a = a;
        m_b = b;
    }
#endif
private:
    int m_a;
    int m_b;
};

void DoSomething(ExplicitConstructor c)
{
}

void DoExplicitConstructor()
{
    std::cout << std::endl
              << "### Excplicit Constructors ###" << std::endl;
    std::cout << "Constructors may be called by c++ when it implicit converts types to objects." << std::endl;
    std::cout << "The \"explicit\"-keyword prevents the implicit converseion" << std::endl;
#if 0
    ExplicitConstructor explicitConstructor = {5, 3}; //error: converting to ‘ExplicitConstructor’ from initializer list would use explicit construct
    DoSomething({5,4});
#endif
    DoSomething(5);
}
