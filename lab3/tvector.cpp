#include "tvector.h"

#include <cstring>

enum {
   INITIAL_CAPACITY = 32,
};

TVector::TVector()
   : data_(nullptr), size_(0), capacity_(INITIAL_CAPACITY)
{
   data_ = (std::shared_ptr<TVector::Item> *)malloc(
      capacity_ * sizeof(std::shared_ptr<TVector::Item>));
}

TVector::TVector(const TVector &vector)
   : data_(nullptr), size_(vector.size_), capacity_(vector.capacity_)
{
   data_ = (std::shared_ptr<TVector::Item> *)malloc(
      vector.capacity_ * sizeof(std::shared_ptr<TVector::Item>));
   std::memcpy(data_, vector.data_, capacity_ * sizeof(std::shared_ptr<TVector::Item>));
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

const std::shared_ptr<Pentagon> TVector::operator[](const size_t index)
{
   return data_[index]->GetPtr();
}

void TVector::InsertLast(std::shared_ptr<Pentagon> &&pentagon)
{
   
   if (size_ >= capacity_) {
      capacity_ <<= 1;
      data_ = (std::shared_ptr<TVector::Item> *)realloc(data_, 
         capacity_ * sizeof(std::shared_ptr<TVector::Item>));
   }

   size_t index = size_++;
   data_[index] = std::shared_ptr<TVector::Item>(new TVector::Item(pentagon));
}

Pentagon TVector::RemoveLast()
{
   return *(data_[--size_]->GetPtr());
}

std::shared_ptr<Pentagon> TVector::Last()
{
   return data_[size_ - 1]->GetPtr();
}

void TVector::Clear()
{
   delete[] data_;
   size_ = 0;
   capacity_ = INITIAL_CAPACITY;
   data_ = (std::shared_ptr<TVector::Item> *)malloc(
      capacity_ * sizeof(std::shared_ptr<TVector::Item>));
}

std::ostream &operator<<(std::ostream &os, const TVector &vector)
{
   for (size_t i = 0; i < vector.size_; ++i)
      os << *(vector.data_[i]);
   return os;
}

std::ostream &operator<<(std::ostream &os, const TVector::Item &pentagon)
{
   os << *pentagon.pentagon_;
   return os;
}

TVector::Item::Item(const std::shared_ptr<Pentagon> &pentagon)
{
   pentagon_ = pentagon;
}

std::shared_ptr<Pentagon> TVector::Item::GetPtr()
{
   return pentagon_;
}
