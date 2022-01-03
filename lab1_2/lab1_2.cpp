///bin/g++ -D_DEBUG -o ${0%.cpp} *.cpp && exit
#include "bitstring.h"

#include <iostream>

int main()
{
   BitString s = "10101010101010101010101010101010101010101010101010101011001100110011001100110011001100"_bitstr;
   
   std::cout << s << std::endl;
   for (int i = 0; i < 96; ++i) { 
      s.ShiftRight(1);
      std::cout << s << std::endl;
   }

   return 0;
}
