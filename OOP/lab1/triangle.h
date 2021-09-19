#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class triangle : figure
{
public:
    triangle(std::istream&);
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);

private:
    Point a_;
    Point b_; 
    Point c_;
};

#endif