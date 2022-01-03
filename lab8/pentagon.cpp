#include "pentagon.h"

#include <cstring>

TAllocationBlock Pentagon::_alloc_block(sizeof(Pentagon), 32);

double Pentagon::Area() const
{
   double s = points_[VertexesNumber() - 1].CrossProduct(points_[0]);
   for (size_t i = 0; i < VertexesNumber() - 1; ++i)
      s += points_[i].CrossProduct(points_[i + 1]);
   return abs(s) / 2.;
}

std::istream &operator>>(std::istream &is, Pentagon &pentagon)
{
   for (size_t i = 0; i < pentagon.VertexesNumber(); ++i)
      is >> pentagon.points_[i];
   return is;
}

std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon)
{
   const size_t last = pentagon.VertexesNumber() - 1;
   
   os << "Pentagon: ";
   for (size_t i = 0; i < pentagon.VertexesNumber(); ++i)
      os << pentagon.points_[i] << ((i != last) ? ' ' : '\0');

   return os;
}

Pentagon &Pentagon::operator=(const Pentagon &other)
{
   std::memcpy(points_, other.points_, sizeof(points_));
   return *this;
}

bool Pentagon::operator==(const Pentagon &other) const
{
   return std::memcmp(points_, other.points_, sizeof(points_)) == 0;
}
