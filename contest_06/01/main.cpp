#include <cmath>
class Shape {
protected:
    double perimeter;

public:
    virtual double getPerimeter() = 0;
};

class Rectangle : public Shape {
private:
    int a;
    int b;

public:
    Rectangle(int a, int b) : a(a), b(b) {}

    double getPerimeter() override {
        return 2 * (a + b);
    }
};

class Circle : public Shape{
private:
    int r;
public:
    Circle(int r) : r(r) {}

    double getPerimeter() override {
        return 2 * M_PI * r;
    }
};

class Triangle : public Shape{
private:
    int a;
    int b;
    int c;
public:
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {}

    bool TrianglePossible(){
        return (a + b > c && a + c > b && b + c > a);
    }

    double getPerimeter() override {
        if (TrianglePossible()) {
            return a + b + c;
        }   
        else {
            return 0;
        }
    }
};
