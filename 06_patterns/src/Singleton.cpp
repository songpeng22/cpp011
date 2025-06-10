#include "./Examples.hpp"

#include <iostream>

class Singleton
{
public:
    static Singleton& GetInstance()
    {
        static Singleton theInstance;
        return theInstance;
    }

    Singleton(const Singleton&)            = delete;
    Singleton(Singleton&&)                 = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&)      = delete;
    ~Singleton()                           = default;

private:
    Singleton()
    {
        std::cout << "  Singleton::Singleton" << std::endl;
    }
};

void DoSingleton()
{
    std::cout << std::endl
              << "### Singleton ###" << std::endl;

    std::cout << "Singleton are classes with private constructors and a static GetInstance method to make sure, only one instance of this class will be created." << std::endl;
    std::cout << "It is important to implement the Canonical Class Form with Copy and Move constructors/assignment operators deleted to make sure the object cannot be copied/moved." << std::endl; 
             
    // Singleton singleton{};
    Singleton& singletonRef = Singleton::GetInstance();
    // Singleton no2 = singletonRef;
}
