///usr/bin/g++ -g -o "${0%.cpp}" *.cpp -static-libasan -fsanitize=address && exit
#include <iostream>

#include "tvector.h"

#define newl '\n'

int main()
{
   { // NOTE: TVector storage manipulation
      TVector t0;
      std::cout << "`t0` has " << t0.Length() << " elements and is "
                << (t0.Empty() ? "empty" : "not empty") << newl;

      t0.InsertLast(std::shared_ptr<Pentagon>(new Pentagon(
         {1., 2.}, {3., 4.}, {0., 5.}, {6., 7.}, {10., 9.})));
   } std::cout << newl;
   
   return 0;
}
