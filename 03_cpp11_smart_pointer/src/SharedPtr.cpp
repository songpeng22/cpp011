#include <iostream>
#include <memory>

class SharedPtr
{
public:
    SharedPtr()
    {
        std::cout << "  SharedPtr::Constructor" << std::endl;
    }

    virtual ~SharedPtr()
    {
        std::cout << "  SharedPtr::Destructor" << std::endl;
    }
};

std::shared_ptr<SharedPtr> GetSptr()
{
    std::shared_ptr<SharedPtr> original = std::make_shared<SharedPtr>();
    std::shared_ptr<SharedPtr> second   = (original);

    if(original == nullptr)
    {
        std::cout << "original is nullptr" << std::endl;
    }
    else
    {
        //std::cout << "  GetSptr() original use_count:" << original.use_count() << std::endl;
    }

    return (second);
}

void DoSharedPtr()
{
    std::cout << std::endl
              << "### Shared Pointer ###" << std::endl;
    std::cout << "SharedPointer creates an object on the heap and counts the number of pointers to this object."
              << std::endl
              << "If this counter reaches 0, the object will be deleted" << std::endl;

    {
        std::shared_ptr<SharedPtr> sptr2;
        {
            std::shared_ptr<SharedPtr> sptr = GetSptr();
            sptr2                           = sptr;
        }
        std::cout << "SharedPtr will be deleted when program leaves this block" << std::endl;
    }
}
