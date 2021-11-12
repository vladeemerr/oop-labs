#pragma once

#include "point.h"
#include "figure.h"

class Pentagon : public Figure
{
public:
   Pentagon();
   Pentagon(Point p0, Point p1, Point p2, Point p3, Point p4);
   Pentagon(const Pentagon &pentagon);
   Pentagon(std::istream &is);

   size_t VertexesNumber();
   double Area();
   void Print(std::ostream &os);

   friend std::istream &operator>>(std::istream &is, Pentagon &pentagon);
   friend std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon);

   Pentagon &operator=(const Pentagon &other);

   bool operator==(const Pentagon &other);
   bool operator!=(const Pentagon &other);

private:
   Point points_[5];
};
