#include "tvector.h"

#include <cstdlib>

TVector::TVector()
   : data_(new std::shared_ptr<Pentagon>[INITIAL_CAPACITY]), 
     length_(0), capacity_(INITIAL_CAPACITY) {}

TVector::TVector(const TVector &vector)
   : data_(new std::shared_ptr<Pentagon>[vector.capacity_]),
     length_(vector.length_), capacity_(vector.capacity_)
{
   std::copy(vector.data_, vector.data_ + vector.length_, data_);
}

TVector::~TVector()
{
   delete[] data_;
}

// NOTE: C++ has no `realloc`, so this is a workaround:
void TVector::_Resize(const size_t new_capacity)
{
   std::shared_ptr<Pentagon> *newdata = 
      new std::shared_ptr<Pentagon>[new_capacity];
   std::copy(data_, data_ + capacity_, newdata);
   delete[] data_;
   data_ = newdata;
   capacity_ = new_capacity;
}

#define _EXTEND_VECTOR_IF_NEEDED \
   if (length_ >= capacity_) \
      _Resize(capacity_ << 1);

void TVector::InsertLast(const std::shared_ptr<Pentagon> &item)
{
   _EXTEND_VECTOR_IF_NEEDED
   data_[length_++] = item;
}

void TVector::EmplaceLast(const Pentagon &&item)
{
   _EXTEND_VECTOR_IF_NEEDED
   data_[length_++] = std::make_shared<Pentagon>(item);
}

#undef _EXTEND_VECTOR_IF_NEEDED

void TVector::Remove(const size_t index)
{
   std::copy(data_ + index + 1, data_ + length_, data_ + index);
   --length_;
}

void TVector::Clear()
{
   delete[] data_;
   data_ = new std::shared_ptr<Pentagon>[INITIAL_CAPACITY];
   length_ = 0;
   capacity_ = INITIAL_CAPACITY;
}

std::ostream &operator<<(std::ostream &os, const TVector &vector)
{
   const size_t last = vector.length_ - 1;

   os << '[';
   for (size_t i = 0; i < vector.length_; ++i)
      os << (*vector.data_[i]).Area() << ((i != last) ? ' ' : '\0');
   os << ']';

   return os;
}
