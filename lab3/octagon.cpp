#include "octagon.h"

Octagon::Octagon()
   : points_{} {}

Octagon::Octagon(Point p0, Point p1, Point p2, Point p3,
                 Point p4, Point p5, Point p6, Point p7)
   : points_{p0, p1, p2, p3, p4, p5, p6, p7} {}

Octagon::Octagon(const Octagon &octagon)
   : points_(octagon.points_) {}

Octagon::Octagon(std::istream &is)
{
   for (size_t i = 0; i < VertexesNumber(); ++i)
      is >> points_[i];
}

size_t Octagon::VertexesNumber()
{
   return sizeof(points_) / sizeof(points_[0]);
}

double Octagon::Area()
{
   double s = points_[VertexesNumber() - 1].CrossProduct(points_[0]);
   for (size_t i = 0; i < VertexesNumber() - 1; ++i)
      s += points_[i].CrossProduct(points_[i + 1]);
   return abs(s) / 2.;
}

void Octagon::Print(std::ostream &os)
{
   os << "Octagon: ";
   for (size_t i = 0; i < VertexesNumber(); ++i)
      os << points_[i] << ' ';
   os << '\n';
}
