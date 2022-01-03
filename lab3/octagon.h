#pragma once

#include "point.h"
#include "figure.h"

class Octagon: public Figure
{
public:
   Octagon();
   Octagon(Point p0, Point p1, Point p2, Point p3,
           Point p4, Point p5, Point p6, Point p7);
   Octagon(const Octagon &octagon);
   Octagon(std::istream &is);

   size_t VertexesNumber();
   double Area();
   void Print(std::ostream &os);

private:
   Point points_[8];
};
