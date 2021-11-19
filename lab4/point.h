#pragma once

#include <iostream>

struct Point {
   Point();
   Point(std::istream &);
   Point(double x, double y);

   double CrossProduct(const Point &);

   friend std::istream &operator>>(std::istream &, Point &);
   friend std::ostream &operator<<(std::ostream &, const Point &);

   double x, y;
};
