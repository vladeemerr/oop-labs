#include "point.h"

Point::Point()
   : x(0.), y(0.) {}

Point::Point(double x, double y)
   : x(x), y(y) {}

Point::Point(std::istream &is)
{
   is >> x >> y;
}

double Point::CrossProduct(const Point &other)
{
   return (x * other.y) - (y * other.x);
}

std::istream &operator>>(std::istream &is, Point &point)
{
   is >> point.x >> point.y;
   return is;
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
   os << '(' << point.x << ", " << point.y << ')';
   return os;
}
