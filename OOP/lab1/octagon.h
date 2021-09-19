#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

class octagon : figure
{
public:
    octagon(std::istream& is);

    size_t VertexesNumber();
    double Area();
    void Print(std::ostream& os);

private:
    Point a_, b_, c_, d_;
    Point e_, f_, g_, h_;
};

#endif