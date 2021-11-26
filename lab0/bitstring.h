#pragma once

#include <cstdint>
#include <ostream>

class BitString {
public:
   inline BitString()
      : lo_(0), hi_(0) {}

   inline BitString(const BitString &other)
      : lo_(other.lo_), hi_(other.hi_) {}

   inline BitString(uint32_t val32)
      : lo_(val32), hi_(0) {}

   inline BitString(uint64_t val64)
      : lo_(val64 & 0xFFFF), hi_(val64 >> 32) {}

   inline BitString(uint32_t lo, uint64_t hi)
      : lo_(lo), hi_(hi) {}

   inline BitString &And(const BitString &other)
   {
      lo_ &= other.lo_;
      hi_ &= other.hi_;
      return *this;
   }

   inline BitString &Or(const BitString &other)
   {
      lo_ |= other.lo_;
      hi_ |= other.hi_;
      return *this;
   }

   inline BitString &Xor(const BitString &other)
   {
      lo_ ^= other.lo_;
      hi_ ^= other.hi_;
      return *this;
   }

   // NOTE: Modifies current bit-string
   inline BitString &Not()
   {
      lo_ = ~lo_;
      hi_ = ~hi_;
      return *this;
   }

   static inline BitString And(const BitString &lhs, const BitString &rhs)
   {
      return BitString(lhs).And(rhs);
   }

   static inline BitString Or(const BitString &lhs, const BitString &rhs)
   {
      return BitString(lhs).Or(rhs);
   }

   static inline BitString Xor(const BitString &lhs, const BitString &rhs)
   {
      return BitString(lhs).Xor(rhs);
   }

   // NOTE: Does not modify current bit-string
   static inline BitString Not(const BitString &bitstring)
   {
      return BitString(bitstring).Not();
   }

   inline BitString &operator&=(const BitString &other)
   {
      return this->And(other);
   }

   inline BitString &operator|=(const BitString &other)
   {
      return this->Or(other);
   }

   inline BitString &operator^=(const BitString &other)
   {
      return this->Xor(other);
   }

   // NOTE: Does not modify current bit-string
   inline BitString operator~() const
   {
      return BitString(*this).Not();
   }

   inline BitString operator&(const BitString &other) const
   {
      return BitString(*this).And(other);
   }

   inline BitString operator|(const BitString &other) const
   {
      return BitString(*this).Or(other);
   }

   inline BitString operator^(const BitString &other) const
   {
      return BitString(*this).Xor(other);
   }

   BitString &ShiftLeft(std::size_t n);
   BitString &ShiftRight(std::size_t n);

   static inline BitString ShiftLeft(const BitString &bitstring, std::size_t n)
   {
      return BitString(bitstring).ShiftLeft(n);
   }

   static inline BitString ShiftRight(const BitString &bitstring, std::size_t n)
   {
      return BitString(bitstring).ShiftRight(n);
   }

   inline BitString &operator<<=(std::size_t n)
   {
      return this->ShiftLeft(n);
   }

   inline BitString &operator>>=(std::size_t n)
   {
      return this->ShiftRight(n);
   }

   inline BitString operator<<(std::size_t n) const
   {
      return BitString(*this).ShiftLeft(n);
   }

   inline BitString operator>>(std::size_t n) const
   {
      return BitString(*this).ShiftRight(n);
   }

   inline BitString &operator=(const BitString &other)
   {
      lo_ = other.lo_;
      hi_ = other.hi_;
      return *this;
   }

   std::size_t GetSetBitsCount() const;

   // NOTE: Equality of two BitStrings happens, when 
   //       they have the same count of set bits
   inline bool Equals(const BitString &other) const
   {
      return (this->GetSetBitsCount() == other.GetSetBitsCount());
   }

   inline bool operator==(const BitString &other) const
   {
      return this->Equals(other);
   }

   inline bool operator!=(const BitString &other) const
   {
      return !(*this == other);
   }

   // NOTE: (A & B) == B
   inline bool Includes(const BitString &other) const
   {
      BitString temp(*this);
      temp.And(other);
      return ((temp.lo_ == other.lo_) && (temp.hi_ == other.hi_));
   }

   friend std::ostream &operator<<(std::ostream &, const BitString &);

private:
   uint32_t lo_;
   uint64_t hi_;
};
