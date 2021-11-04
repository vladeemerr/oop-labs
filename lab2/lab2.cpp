///usr/bin/g++ -g -o "${0%.cpp}" *.cpp && exit
#include <iostream>

#include "tvector.h"

#define newl '\n'

int main()
{
   { // NOTE: TVector constructor
      TVector t0;
      std::cout << "`t0` has " << t0.Length() << " elements and is "
                << (t0.Empty() ? "empty" : "not empty") << newl;

      TVector t3(t0);
      std::cout << "`t3` has copied `t2` (Length = " << t3.Length() << "):"
                << newl << t3;
   } std::cout << newl;

   { // NOTE: TVector storage manipulation
      TVector t0;
      std::cout << "`t0` has " << t0.Length() << " elements and is "
                << (t0.Empty() ? "empty" : "not empty") << newl;

      t0.InsertLast({{1., 2.}, {3., 4.}, {0., 5.}, {6., 7.}, {10., 9.}});
      t0.InsertLast({{3., 1.}, {10., 42.}, {20., 15.}, {76., 27.}, {0., 3.}});
      t0.InsertLast({{128., 391.}, {484., 381.}, {132., 339.}, {93., 415.}, {19., 5.}});
      std::cout << "`t0` has " << t0.Length() << " elements and is "
                << (t0.Empty() ? "empty" : "not empty") 
                << ", has got these elements:" << newl << t0 << newl;

      std::cout << "Extracted element `t0[1]`:" << newl << t0[1] << newl;

      t0.RemoveLast();
      std::cout << "`t0` has " << t0.Length() << " elements and is "
                << (t0.Empty() ? "empty" : "not empty") 
                << ", has got these elements:" << newl << t0 << newl;

      t0[0] = {{10., 9.}, {8., 7.}, {6., 5.}, {4., 3.}, {2., 1.}};
      std::cout << "First element of `t0` has been changed:" << newl << t0 << newl;

      t0.Clear();
      std::cout << "`t0` has " << t0.Length() << " elements and is "
                << (t0.Empty() ? "empty" : "not empty") << newl;
   } std::cout << newl;
   
   { // NOTE: Object copying
      Pentagon p0({1., 2.}, {3., 4.}, {5., 6.}, {7., 8.}, {9., 10.});
      std::cout << "Object to copy " << p0;

      Pentagon p1;
      std::cout << "New object before copying " << p1;

      p1 = p0;
      std::cout << "New object after copying " << p1;
   } std::cout << newl;

   { // NOTE: Equality test
      Pentagon p0({1., 2.}, {3., 4.}, {5., 6.}, {7., 8.}, {9., 10.});
      Pentagon p1({10., 9.}, {8., 7.}, {6., 5.}, {4., 3.}, {2., 1.});
      Pentagon p2 = p0;

      std::cout << "p0 and p1 are " << ((p0 == p1) ? "equal" : "not equal") << newl;
      std::cout << "p0 and p1 are " << ((p0 == p2) ? "equal" : "not equal") << newl;

      std::cout << "p0 and NOT p1 are " << ((p0 != p1) ? "equal" : "not equal") << newl;
      std::cout << "p0 and NOT p1 are " << ((p0 != p2) ? "equal" : "not equal") << newl;
   } std::cout << newl;

   { // NOTE: I/O backwards-compatibility
      std::cout << "Old way of input/output:" << newl;
      Pentagon p0(std::cin);
      p0.Print(std::cout);

      std::cout << newl;

      std::cout << "New way of input/output:" << newl;
      Pentagon p;
      std::cin >> p;
      std::cout << p;
   } std::cout << newl;

   return 0;
}
