#include "bitstring.h"

#include <iostream>

BitString &BitString::ShiftLeft(std::size_t n)
{
   hi_ = (hi_ << n) | ((n < 32) ? (lo_ >> (32 - n)) : ((uint64_t)lo_ << (n - 32)));
   if (n < 32)
      lo_ <<= n;
   else
      lo_ = 0;
   return *this;
}

BitString &BitString::ShiftRight(std::size_t n)
{
   lo_ = ((n < 32) ? ((lo_ >> n) | (hi_ << (32 - n))) : (hi_ >> (n - 32)));
   
   if (n < 64)
      hi_ >>= n;
   else
      hi_ = 0;

   return *this;
}

std::size_t BitString::GetSetBitsCount() const
{
#ifdef __GNUG__
   return __builtin_popcount(lo_) + __builtin_popcountll(hi_);
#else
   uint32_t lo = this->lo_;

   lo = (lo & 0x55555555) + ((lo >> 1)  & 0x55555555);
   lo = (lo & 0x33333333) + ((lo >> 2)  & 0x33333333);
   lo = (lo & 0x0F0F0F0F) + ((lo >> 4)  & 0x0F0F0F0F);
   lo = (lo & 0x00FF00FF) + ((lo >> 8)  & 0x00FF00FF);
   lo = (lo & 0x0000FFFF) + ((lo >> 16) & 0x0000FFFF);

   uint64_t hi = this->hi_;
   hi = (hi & 0x5555555555555555) + ((hi >> 1)  & 0x5555555555555555);
   hi = (hi & 0x3333333333333333) + ((hi >> 2)  & 0x3333333333333333);
   hi = (hi & 0x0F0F0F0F0F0F0F0F) + ((hi >> 4)  & 0x0F0F0F0F0F0F0F0F);
   hi = (hi & 0x00FF00FF00FF00FF) + ((hi >> 8)  & 0x00FF00FF00FF00FF);
   hi = (hi & 0x0000FFFF0000FFFF) + ((hi >> 16) & 0x0000FFFF0000FFFF);
   hi = (hi & 0x00000000FFFFFFFF) + ((hi >> 32) & 0x00000000FFFFFFFF);

   return lo + hi;
#endif
}

std::ostream &operator<<(std::ostream &os, const BitString &bitstring)
{
   for (ssize_t i = (sizeof(bitstring.hi_) << 3) - 1; i >= 0; --i)
      os << "01"[(bitstring.hi_ >> i) & 1];

#ifdef _DEBUG
   os << '|';
#endif

   for (ssize_t i = (sizeof(bitstring.lo_) << 3) - 1; i >= 0; --i)
      os << "01"[(bitstring.lo_ >> i) & 1];

   return os;
}

BitString operator "" _bitstr(const char *str, size_t n)
{
   uint32_t lo = 0;
   uint64_t hi = 0;

   size_t cnt = 0;

   ssize_t i;
   for (i = n - 1; i >= 0 && cnt < 32; --i, ++cnt)
      lo |= ((str[i] - '0') << cnt);

   for (cnt = 0; i >= 0 && cnt < 64; --i, ++cnt)
      hi |= ((uint64_t)(str[i] - '0') << cnt);
   
   return BitString(lo, hi);
}
