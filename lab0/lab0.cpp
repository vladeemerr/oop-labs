///bin/g++ -D_DEBUG -o ${0%.cpp} *.cpp && exit
#include "bitstring.h"

#include <iostream>

int main()
{
   BitString s(0x12381493ul, 0xF000000000000000 | 0xea81894bcca922ull);

   std::cout << s << std::endl;
   for (int i = 0; i < 96; ++i) { 
      s.ShiftRight(1);
      std::cout << s << std::endl;
   }

   return 0;
}
