#pragma once

#include <ostream>

class Figure
{
public:
   virtual size_t VertexesNumber() const = 0;
   virtual double Area() const = 0;
   virtual void Print(std::ostream &os) const = 0;
};
