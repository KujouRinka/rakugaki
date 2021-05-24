#include <iostream>
#include <string>
#include <cmath>

class Figure {
public:
    virtual ~Figure() = default;
};

class Figure_2D : public Figure {
public:
    Figure_2D(double x = 0.0, double y = 0.0) :
            xSize(x), ySize(y) {}
    virtual double area() = 0;
    virtual double pcrimeter() = 0;

protected:
    double xSize, ySize;
};

class Figure_3D : public Figure {
public:
    Figure_3D(double x = 0.0, double y = 0.0, double z = 0.0) :
            xSize(x), ySize(y), zSize(z) {}
    virtual double volume() = 0;

protected:
    double xSize, ySize, zSize;
};

class Rectangle : public Figure_2D {
public:
    Rectangle(double x, double xl, double y, double yl) :
            Figure_2D(x, y), xLen(xl), yLen(yl) {}
    double area() override { return xLen * yLen; }
    double pcrimeter() override { return 2 * (xLen + yLen); }

private:
    double xLen, yLen;
};

class Circle : public Figure_2D {
public:
    Circle(double x, double y, double r) :
            Figure_2D(x, y), radius(r) {}
    double area() override { return pow(M_PI, 2) * radius; }
    double pcrimeter() override { return 2 * M_PI * radius; }

private:
    double radius;
};

class Sphere : public Figure_3D {
public:
    Sphere(double x, double y, double z, double r) :
            Figure_3D(x, y, z), radius(r) {}
    double volume() override { return 4.0 / 3 * M_PI * pow(radius, 3); }

private:
    double radius;
};

class Cone : public Figure_3D {
public:
    Cone(double x, double y, double z, double r, double h) :
            Figure_3D(x, y, z), radius(r), height(h) {}
    double volume() override { return 1.0 / 3 * Circle(xSize, ySize, radius).area() * height; }

private:
    double radius, height;
};

int main() {
    Cone c1(0, 0, 0, 1, 1 / pow(M_PI, 2));
    std::cout << c1.volume() << std::endl;
    return 0;
}
