#include "octagon.h"

octagon::octagon(std::istream& is)
{
    std::cin >> a_ >> b_ >> c_ >> d_;
    std::cin >> e_ >> f_ >> g_ >> h_;
}

size_t octagon::VertexesNumber()
{
    return (size_t)8;
}

double octagon::Area()
{
    return 0.5 * abs((a_.getX() * b_.getY() + b_.getX() * c_.getY() + c_.getX() * d_.getY() + d_.getX() * e_.getY() + e_.getX() * f_.getY() +
    f_.getX() * g_.getY() + g_.getX() * h_.getY() + h_.getX() * a_.getY() - (b_.getX() * a_.getY() + c_.getX() * b_.getY() + 
    d_.getX() * c_.getY() + e_.getX() * d_.getY() + f_.getX() * e_.getY() + g_.getX() * f_.getY() + h_.getX() * g_.getY() +
    a_.getX() * h_.getY())));
}

void octagon::Print(std::ostream& os)
{
    std::cout << "Octagon: " << a_ << " " << b_ << " ";
    std::cout << c_ << " " << d_ << " " << e_ << " ";
    std::cout << f_ << " " << g_ << " " << h_ << "\n";
}