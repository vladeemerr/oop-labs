#pragma once

#include "point.h"
#include "figure.h"

class Pentagon : public Figure {
public:
   Pentagon();
   Pentagon(Point p0, Point p1, Point p2, Point p3, Point p4);
   Pentagon(const Pentagon &);
   Pentagon(std::istream &);

   size_t VertexesNumber();
   double Area();
   void Print(std::ostream &os);

   friend std::istream &operator>>(std::istream &, Pentagon &);
   friend std::ostream &operator<<(std::ostream &, const Pentagon &);

   Pentagon &operator=(const Pentagon &);

   bool operator==(const Pentagon &);
   bool operator!=(const Pentagon &);

private:
   Point points_[5];
};
