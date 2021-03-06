#pragma once

#include "point.h"
#include "figure.h"

class Hexagon: public Figure
{
public:
   Hexagon();
   Hexagon(Point p0, Point p1, Point p2,
           Point p3, Point p4, Point p5);
   Hexagon(const Hexagon &hexagon);
   Hexagon(std::istream &is);

   size_t VertexesNumber();
   double Area();
   void Print(std::ostream &os);

private:
   Point points_[6];
};
