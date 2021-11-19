#include "pentagon.h"

#include <cstring>

Pentagon::Pentagon()
   : points_{} {}

Pentagon::Pentagon(Point p0, Point p1, Point p2, Point p3, Point p4)
   : points_{p0, p1, p2, p3, p4} {}

Pentagon::Pentagon(const Pentagon &pentagon)
   : points_(pentagon.points_) {}

Pentagon::Pentagon(std::istream &is)
{
   is >> *this;
}

size_t Pentagon::VertexesNumber()
{
   return sizeof(points_) / sizeof(points_[0]);
}

double Pentagon::Area()
{
   double s = points_[VertexesNumber() - 1].CrossProduct(points_[0]);
   for (size_t i = 0; i < VertexesNumber() - 1; ++i)
      s += points_[i].CrossProduct(points_[i + 1]);
   return abs(s) / 2.;
}

void Pentagon::Print(std::ostream &os)
{
   os << *this;
}

std::istream &operator>>(std::istream &is, Pentagon &pentagon)
{
   for (size_t i = 0; i < pentagon.VertexesNumber(); ++i)
      is >> pentagon.points_[i];
   return is;
}

std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon)
{
   os << "Pentagon: ";
   for (size_t i = 0; i < 5; ++i)
      os << pentagon.points_[i] << ((i != 4) ? ' ' : '\0');

   return os;
}

Pentagon &Pentagon::operator=(const Pentagon &other)
{
   std::memcpy(points_, other.points_, sizeof(points_));
   return *this;
}

bool Pentagon::operator==(const Pentagon &other)
{
   return std::memcmp(points_, other.points_, sizeof(points_)) == 0;
}

bool Pentagon::operator!=(const Pentagon &other)
{
   return !(*this == other);
}
