#pragma once

#include <ostream>

class Figure
{
public:
   virtual constexpr size_t VertexesNumber() = 0;
   virtual double Area() = 0;
   virtual void Print(std::ostream &os) = 0;
};
