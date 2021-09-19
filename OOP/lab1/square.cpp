#include "square.h"

square::square(std::istream& is)
{
    std::cin >> a_ >> b_ >> c_ >> d_;
}

size_t square::VertexesNumber()
{
    return (size_t)4;
}

double square::Area()
{
    int a = a_.dist(b_);
    return a * a;
}

void square::Print(std::ostream& os)
{
    std::cout << "Square: " << a_ << " " << b_ << " " << c_ << " " << d_ << "\n";
}