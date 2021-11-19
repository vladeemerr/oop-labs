#pragma once

#include "point.h"
#include "figure.h"

class Pentagon : public Figure {
public:
   inline Pentagon()
      : points_{} {}

   inline Pentagon(Point p0, Point p1, Point p2, Point p3, Point p4)
      : points_{p0, p1, p2, p3, p4} {}

   inline Pentagon(const Pentagon &pentagon)
      : points_(pentagon.points_) {}

   inline Pentagon(std::istream &is)
   {
      is >> *this;
   }

   size_t VertexesNumber() const override
   {
      return sizeof(points_) / sizeof(points_[0]);
   }

   double Area() const override;

   void Print(std::ostream &os) const override
   {
      os << *this;
   }

   friend std::istream &operator>>(std::istream &, Pentagon &);
   friend std::ostream &operator<<(std::ostream &, const Pentagon &);

   Pentagon &operator=(const Pentagon &);

   bool operator==(const Pentagon &) const;

   inline bool operator!=(const Pentagon &other) const
   {
      return !(*this == other);
   }

private:
   Point points_[5];
};
