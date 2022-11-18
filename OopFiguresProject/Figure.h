#pragma once
class Figure
{
protected:
    double x, y;
public:
    Figure(double x, double y) : x{ x }, y{ y } {}
    virtual double Perimetr() = 0;
    virtual double Square() = 0;

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

};


