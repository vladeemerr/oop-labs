///usr/bin/g++ -g -o "${0%.cpp}" *.cpp -static-libasan -fsanitize=leak,address && exit
#include <iostream>

#include "tvector.h"
#include "pentagon.h"

#define newl '\n'

int main()
{
   TVector<Pentagon> t;

   {
      auto p = std::make_shared<Pentagon>(Point{52.f, 1.3f}, Point{41.f, 34.f},
         Point{16.f, 17.f}, Point{123.f, 43.f}, Point{126.f, 173.f});
      t.InsertLast(p);
   }

   t.InsertLast(std::make_shared<Pentagon>(Point{1.f, 2.f}, Point{3.f, 4.f}, 
      Point{5.f, 6.f}, Point{7.f, 8.f}, Point{9.f, 10.f}));

   t.EmplaceLast(Pentagon({10.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f}));

   t.Clear();

   t.EmplaceLast(Pentagon({1.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f}));
   t.EmplaceLast(Pentagon({2.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f}));
   t.EmplaceLast(Pentagon({3.f, 9.f}, {8.f, 7.f}, {6.f, 5.f}, {4.f, 3.f}, {2.f, 1.f}));

   std::cout << t.Length() << ' ' << t.Empty() << std::endl;

   std::cout << t << std::endl;
   
   return 0;
}
