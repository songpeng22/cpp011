#include "./Examples.hpp"

#include <iostream>

class Part
{
public:
    void Print()
    {
        std::cout << "  Part::Print()" << std::endl;
    }
};

class Aggregation
{
public:
    Aggregation(Part* part)
    {
        m_part = part;
    }

    void SetPart(Part* part)
    {
        m_part = part;
    }

    void Print()
    {
        m_part->Print();
    }

private:
    Part* m_part;
};

class Composition
{
public:
    Composition() = default;
    void Print()
    {
        m_part.Print();
    }

private:
    Part m_part;
};

void DoAggregation()
{
    std::cout << std::endl << "In an aggregation, a object may only contain a reference or an pointer to an part-of object and does not have lifetime responsibilites for it." << std::endl;

    // das Teil Objekt ohne das Ganze lebensfähig
    Part p;
    Aggregation a{&p};
    a.Print();
}

void DoComposition()
{
    std::cout << std::endl <<"In an composition, a object has lifetime responsibilities to its part-of object. This includes creation and destruction." << std::endl;

    // das Teil Objekt kann nicht ohne das Ganze Objekt existieren
    Composition c{};
    c.Print();
}

void DoAssociation()
{
    std::cout << std::endl
              << "### Associations ###" << std::endl;
    std::cout << "There are two Associations: Aggregations and Composition" << std::endl;

    DoAggregation();
    DoComposition();
}
