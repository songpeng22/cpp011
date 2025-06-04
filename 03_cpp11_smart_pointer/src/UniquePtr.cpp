#include <iostream>
#include <memory>

class UniquePtr
{
public:
    UniquePtr()
    {
        std::cout << "  UniquePtr::Constructor" << std::endl;
    }

    virtual ~UniquePtr()
    {
        std::cout << "  UniquePtr::Destructor" << std::endl;
    }
};

std::unique_ptr<UniquePtr> GetUPtr()
{
    std::unique_ptr<UniquePtr> original = std::make_unique<UniquePtr>();
    std::unique_ptr<UniquePtr> second   = std::move(original);

    if(original == nullptr)
    {
        std::cout << "Original is nullptr" << std::endl;
    }

    return (second);
}

void DoUniquePtr()
{
    std::cout << std::endl
              << "### Unique Pointer ###" << std::endl;
    std::cout
        << "UniquePointer Create object on heap, but make sure only one pointer to this object ever exists."
        << std::endl
        << "If the last pointer is deleted, the object destructor will be called.";

    {
        std::unique_ptr<UniquePtr> uptr = GetUPtr();
        std::cout << "UniquePtr will be deleted when program leaves this block" << std::endl;
    }
}