///usr/bin/g++ -g -o "${0%.cpp}" *.cpp -static-libasan -fsanitize=leak,address && exit
#include <iostream>

#include "tvector.h"
#include "pentagon.h"

#define newl '\n'

int main()
{
   TVector<Pentagon> t;

   t.InsertLast(std::shared_ptr<Pentagon>(new Pentagon(
      {1.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f})));

   t.InsertLast(std::shared_ptr<Pentagon>(new Pentagon(
      {1.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f})));

   t.InsertLast(std::shared_ptr<Pentagon>(new Pentagon(
      {1.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f})));

   std::cout << t << std::endl;

   for (auto i = t.begin(); i != t.end(); ++i)
      std::cout << *i << std::endl;
   
   return 0;
}
