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
    /*Circle* figure = new Circle(1, 2, 5);
    std::cout << figure->GetX() << " " << figure->GetY();*/

    Parent* parent = new Child();

    delete parent;
}
