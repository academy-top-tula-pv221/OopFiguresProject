#include <vector>
#pragma once

class Figure
{
protected:
    double x, y;
public:
    Figure(double x, double y) : x{ x }, y{ y } {}
    virtual double Perimetr() = 0;
    virtual double Square() = 0;
    virtual void Add(Figure*) {};

    void SetPoint(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    double GetX() { return x; }
    double GetY() { return y; }
};

class Circle : public Figure
{
    const double PI{ 3.14156 };
    double radius;
public:
    Circle(double x, double y, double radius)
        : Figure(x, y), radius{ radius } {}

    double Perimetr() override
    {
        return 2 * PI * radius;
    }

    double Square() override
    {
        return PI * radius * radius;
    }
};

class Rectangle : public Figure
{
protected:
    double width;
    double height;
public:
    Rectangle(double x, double y, double width, double height)
        : Figure(x, y), width{ width }, height{ height } {}

    double Perimetr() override
    {
        return (width + height) * 2;
    }

    double Square() override
    {
        return height * width;
    }

};


class ComplexFigure : public Figure
{
    std::vector<Figure*> figures;
public:
    ComplexFigure() : Figure(0,0) {}

    void Add(Figure* figure)
    {
        figures.push_back(figure);
    }

    double Perimetr() override
    {
        double result{ 0 };
        for (int i = 0; i < figures.size(); i++)
            result += figures[i]->Perimetr();
        
        return result;
    }

    double Square() override
    {
        double result{ 0 };
        for (int i = 0; i < figures.size(); i++)
            result += figures[i]->Square();

        return result;
    }
};