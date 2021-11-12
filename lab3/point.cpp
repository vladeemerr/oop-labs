#include "point.h"

Point::Point()
   : x_(0.), y_(0.) {}

Point::Point(double x, double y)
   : x_(x), y_(y) {}

Point::Point(std::istream &is)
{
   is >> x_ >> y_;
}

double Point::CrossProduct(const Point &other)
{
   return (x_ * other.y_) - (y_ * other.x_);
}

std::istream &operator>>(std::istream &is, Point &point)
{
   is >> point.x_ >> point.y_;
   return is;
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
   os << '(' << point.x_ << ", " << point.y_ << ')';
   return os;
}
