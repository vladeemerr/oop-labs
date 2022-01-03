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

private:
   Point points_[5];
};
