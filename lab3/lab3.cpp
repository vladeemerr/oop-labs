///usr/bin/g++ -o "${0%.cpp}" *.cpp && exec "./${0%.cpp}"
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"

#include <iostream>

#define newl '\n'

int main()
{
   Pentagon p(std::cin);
   p.Print(std::cout);
   std::cout << p.Area() << newl;

   Hexagon h(std::cin);
   h.Print(std::cout);
   std::cout << h.Area() << newl;
   
   Octagon o(std::cin);
   o.Print(std::cout);
   std::cout << o.Area() << newl;

   return 0;
}
