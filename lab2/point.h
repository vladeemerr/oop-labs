#pragma once

#include <iostream>

struct Point {
   inline Point()
      : x(0.), y(0.) {}

   inline Point(double x, double y)
      : x(x), y(y) {}

   inline Point(std::istream &is)
   {
      is >> x >> y;
   }

   inline double CrossProduct(const Point &other) const
   {
      return (x * other.y) - (y * other.x);
   }

   inline friend std::istream &operator>>(std::istream &is, Point &point)
   {
      is >> point.x >> point.y;
      return is;
   }

   inline friend std::ostream &operator<<(std::ostream &os, const Point &point)
   {
      os << '(' << point.x << ", " << point.y << ')';
      return os;
   }

   double x, y;
};
