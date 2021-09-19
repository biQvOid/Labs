#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "octagon.h"

int main()
{
    std::cout << "Enter the points' coordinates of triangle:\n";
    triangle a(std::cin);
    std::cout << "Triangle's number of vertexes: " << a.VertexesNumber() << "\n";
    std::cout << "Triangles's area: " << a.Area() << "\n";
    std::cout << "Figure type:\n";
    a.Print(std::cout);

    std::cout << "Enter the points' coordinates of square:\n";
    square b(std::cin);
    std::cout << "Square's number of vertexes: " << b.VertexesNumber() << "\n";
    std::cout << "Square's area: " << b.Area() << "\n";
    std::cout << "Figure type:\n";
    b.Print(std::cout);

    std::cout << "Enter the points' coordinates of octagon:\n";
    octagon c(std::cin);
    std::cout << "Octagon's number of vertexes: " << c.VertexesNumber() << "\n";
    std::cout << "Octagon's area: " << c.Area() << "\n";
    std::cout << "Figure type:\n";
    c.Print(std::cout);
    return 0;
}