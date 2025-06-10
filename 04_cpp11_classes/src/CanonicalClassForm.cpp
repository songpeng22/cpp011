#include "./Examples.hpp"

#include <iostream>

class CanonicalClassForm
{
public:
    CanonicalClassForm()                                     = default; // default constructor
    CanonicalClassForm(const CanonicalClassForm&)            = delete;  // copy constructor
    CanonicalClassForm(CanonicalClassForm&&)                 = delete;  // move constructor
    CanonicalClassForm& operator=(const CanonicalClassForm&) = delete;  // copy assignment operator
    CanonicalClassForm& operator=(CanonicalClassForm&&)      = delete;  // move assignment operator

    int Add()
    {
        return m_a + m_b;
    }

    void Print()
    {
        std::cout << "a: " << m_a << ", b: " << m_b << std::endl;
    }

private:
    int m_a{5};
    int m_b{6};
};

class CanonicalClassForm2
{
public:
    CanonicalClassForm2()
    {
        std::cout << "  CanonicalClassForm::Default Constructor" << std::endl;
    }
    CanonicalClassForm2(const CanonicalClassForm2&)
    {
        std::cout << "  CanonicalClassForm::Copy Constructor" << std::endl;
    }
    CanonicalClassForm2(CanonicalClassForm2&&)
    {
        std::cout << "  CanonicalClassForm::Move Constructor" << std::endl;
    }
    CanonicalClassForm2& operator=(const CanonicalClassForm2&)
    {
        std::cout << "  CanonicalClassForm::Copy assignment operator" << std::endl;
        return *this;
    }
    CanonicalClassForm2& operator=(CanonicalClassForm2&&)
    {
        std::cout << "  CanonicalClassForm::Move assignment operator" << std::endl;
        return *this;
    }
};

void DoCanonicalClassForm()
{
    std::cout << std::endl
              << "### CanonicalClassForm ###" << std::endl;
    std::cout
        << "CanonicalClassForm can be used to limit Movement and Creation of an object. " << std::endl
        << "Here are two excamples: one restricted to Creation and one unrestricted to Copying and Moving."
        << std::endl
        << "Limitations can be mixed (eg. Moving allowed, but not copying)"
        << std::endl
        << std::endl;

    CanonicalClassForm ccf{};
    CanonicalClassForm ccf2{};

#if 1
    // CanonicalClassForm copy  = ccf;            // error: use of deleted function ‘CanonicalClassForm::CanonicalClassForm(const CanonicalClassForm&)
    // CanonicalClassForm moved = std::move(ccf); // error: use of deleted function ‘CanonicalClassForm::CanonicalClassForm(const CanonicalClassForm&)
    
    // ccf2 = ccf;            			// error: use of deleted function ‘CanonicalClassForm::CanonicalClassForm(const CanonicalClassForm&)
    // ccf2 = std::move(ccf); 			// error: use of deleted function ‘CanonicalClassForm::CanonicalClassForm(const CanonicalClassForm&)
#else
    // CanonicalClassForm copy  = ccf;            // copy constructor will be called
    // CanonicalClassForm moved = std::move(ccf); // move constructor will be called

    // ccf2 = ccf;            // copy Assignment operator will be called
    // ccf2 = std::move(ccf); // move assignment operator will be called
#endif
    CanonicalClassForm2 defaults{};
    CanonicalClassForm2 defaults2{};

    CanonicalClassForm2 copyDefault = defaults;
    CanonicalClassForm2 moveDefault = std::move(defaults);
    defaults2                       = defaults;
    defaults2                       = std::move(defaults);

    std::cout << std::endl;
}
