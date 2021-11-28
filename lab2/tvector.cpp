#include "tvector.h"

TVector::TVector()
   : data_(new Pentagon[INITIAL_CAPACITY]), 
     size_(0), capacity_(INITIAL_CAPACITY) {}

TVector::TVector(const TVector &vector)
   : data_(new Pentagon[vector.capacity_]), 
     size_(vector.size_), capacity_(vector.capacity_)
{
   std::copy(vector.data_, vector.data_ + vector.size_, data_);
}

TVector::~TVector()
{
   delete[] data_;
}

void TVector::_Resize(const size_t new_capacity)
{
   Pentagon *newdata = new Pentagon[new_capacity];
   std::copy(data_, data_ + capacity_, newdata);
   delete[] data_;
   data_ = newdata;
   capacity_ = new_capacity;
}

size_t TVector::Length() const
{
   return size_;
}

bool TVector::Empty() const
{
   return !size_;
}

Pentagon &TVector::operator[](const size_t index) const
{
   return data_[index];
}

void TVector::InsertLast(const Pentagon &&pentagon)
{
   if (size_ >= capacity_)
      _Resize(capacity_ << 1);

   data_[size_++] = pentagon;
}

Pentagon TVector::RemoveLast()
{
   return data_[--size_];
}

const Pentagon &TVector::Last() const
{
   return data_[size_ - 1];
}

void TVector::Clear()
{
   delete[] data_;
   data_ = new Pentagon[INITIAL_CAPACITY];
   size_ = 0;
   capacity_ = INITIAL_CAPACITY;
}

std::ostream &operator<<(std::ostream &os, const TVector &vector)
{
   const size_t last = vector.size_ - 1;

   os << '[';
   for (size_t i = 0; i < vector.size_; ++i)
      os << vector.data_[i].Area() << ((i != last) ? ' ': '\0');
   os << ']';

   return os;
}
