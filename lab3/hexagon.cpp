#include "hexagon.h"

Hexagon::Hexagon()
   : points_{} {}

Hexagon::Hexagon(Point p0, Point p1, Point p2,
                 Point p3, Point p4, Point p5)
   : points_{p0, p1, p2, p3, p4, p5} {}

Hexagon::Hexagon(const Hexagon &hexagon)
   : points_(hexagon.points_) {}

Hexagon::Hexagon(std::istream &is)
{
   for (size_t i = 0; i < VertexesNumber(); ++i)
      is >> points_[i];
}

size_t Hexagon::VertexesNumber()
{
   return sizeof(points_) / sizeof(points_[0]);
}

double Hexagon::Area()
{
   double s = points_[VertexesNumber() - 1].CrossProduct(points_[0]);
   for (size_t i = 0; i < VertexesNumber() - 1; ++i)
      s += points_[i].CrossProduct(points_[i + 1]);
   return abs(s) / 2.;
}

void Hexagon::Print(std::ostream &os)
{
   os << "Hexagon: ";
   for (size_t i = 0; i < VertexesNumber(); ++i)
      os << points_[i] << ' ';
   os << '\n';
}
