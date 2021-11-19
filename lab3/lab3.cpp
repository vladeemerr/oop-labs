///usr/bin/g++ -g -o "${0%.cpp}" *.cpp -static-libasan -fsanitize=leak && exit
#include <iostream>

#include "tvector.h"

#define newl '\n'

int main()
{
   { // NOTE: TVector storage manipulation
      TVector t0;
      t0.InsertLast(std::shared_ptr<Pentagon>(new Pentagon(
            {1.f, 2.f}, {3.f, 4.f}, {5.f, 6.f}, {7.f, 8.f}, {9.f, 10.f})));
      t0.InsertLast(std::shared_ptr<Pentagon>(new Pentagon));

      std::cout << *t0.Last() << newl;
   } std::cout << newl;
   
   return 0;
}
