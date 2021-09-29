#pragma once

#include <iostream>

class Point {
public:
   Point();
   Point(std::istream &is);
   Point(double x, double y);

   double CrossProduct(const Point &other);

   friend std::istream &operator>>(std::istream &is, Point &point);
   friend std::ostream &operator<<(std::ostream &is, const Point &point);

private:
   double x_;
   double y_;
};
