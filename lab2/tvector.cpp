#include "tvector.h"

#include <cstring>

enum {
   INITIAL_CAPACITY = 32,
};

TVector::TVector()
   : data_(nullptr), size_(0), capacity_(INITIAL_CAPACITY)
{
   data_ = (Pentagon *)malloc(capacity_ * sizeof(Pentagon));
}

TVector::TVector(const TVector &vector)
   : data_(nullptr), size_(vector.size_), capacity_(vector.capacity_)
{
   data_ = (Pentagon *)malloc(vector.capacity_ * sizeof(Pentagon));
   std::memcpy(data_, vector.data_, capacity_ * sizeof(Pentagon));
}

TVector::~TVector()
{
   free(data_);
   data_ = nullptr;
   size_ = 0;
   capacity_ = 0;
}

size_t TVector::Length()
{
   return size_;
}

bool TVector::Empty()
{
   return !size_;
}

Pentagon &TVector::operator[](const size_t index)
{
   return data_[index];
}

void TVector::InsertLast(const Pentagon &pentagon)
{
   if (size_ >= capacity_) {
      capacity_ <<= 1;
      data_ = (Pentagon *)realloc(data_, capacity_ * sizeof(Pentagon));
   }

   data_[size_++] = pentagon;
}

Pentagon TVector::RemoveLast()
{
   return data_[--size_];
}

const Pentagon &TVector::Last()
{
   return data_[size_ - 1];
}

void TVector::Clear()
{
   size_ = 0;
   capacity_ = INITIAL_CAPACITY;
   data_ = (Pentagon *)realloc(data_, capacity_ * sizeof(Pentagon));
}

std::ostream &operator<<(std::ostream &os, const TVector &vector)
{
   for (size_t i = 0; i < vector.size_; ++i)
      os << vector.data_[i];
   return os;
}
