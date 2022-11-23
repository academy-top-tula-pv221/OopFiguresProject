#include <iostream>
#include "Figure.h"

class Parent
{
public:
    Parent()
    {
        std::cout << "Parent construct\n";
    }

    virtual ~Parent() = default;
    
};

class Child : public Parent
{
public:
    Child()
    {
        std::cout << "Child construct\n";
    }

    ~Child()
    {
        std::cout << "Child destruct\n";
    }
};


int main()
{
    Figure* f1 = new ComplexFigure();

    f1->Add(new Circle(0, 0, 10));
    f1->Add(new Rectangle(0, 0, 10, 20));
    std::cout << f1->Perimetr() << "\n";

    Figure* f2 = new ComplexFigure();
    f2->Add(new Circle(0, 0, 5));
    std::cout << f2->Perimetr() << "\n";

    f2->Add(f1);
    std::cout << f2->Perimetr() << "\n";
}
