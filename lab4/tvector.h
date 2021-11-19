#pragma once

#include <ostream>
#include <memory>

template <typename T>
class TVector {
public:
   TVector();
   TVector(const TVector &);

   virtual ~TVector();

   inline size_t Length()
   {
      return length_;
   }

   inline bool Empty()
   {
      return !length_;
   }

   inline const std::shared_ptr<T> &operator[](const size_t index)
   {
      return data_[index];
   }

   inline std::shared_ptr<T> Last()
   {
      return data_[length_ - 1];
   }

   void InsertLast(const std::shared_ptr<T> &);
   void EmplaceLast(const T &&);

   void Remove(const size_t index);

   inline T RemoveLast()
   {
      return *data_[--length_];
   }

   void Clear();

   template <typename TF> friend std::ostream &operator<<(
      std::ostream &, const TVector<TF> &);

private:
   void _Resize(const size_t new_capacity);
   
   std::shared_ptr<T> *data_;
   size_t length_, capacity_;

   enum { INITIAL_CAPACITY = 32 };
};

#include <cstdlib>

template <typename T>
TVector<T>::TVector()
   : data_(new std::shared_ptr<T>[INITIAL_CAPACITY]), 
     length_(0), capacity_(INITIAL_CAPACITY) {}

template <typename T>
TVector<T>::TVector(const TVector &vector)
   : data_(new std::shared_ptr<T>[vector.capacity_]),
     length_(vector.length_), capacity_(vector.capacity_)
{
   std::copy(vector.data_, vector.data_ + vector.length_, data_);
}

template <typename T>
TVector<T>::~TVector()
{
   delete[] data_;
}

// NOTE: Very hacky, because C++ has no `realloc`
template <typename T>
void TVector<T>::_Resize(const size_t new_capacity)
{
   std::shared_ptr<T> *newdata = new std::shared_ptr<T>[new_capacity];
   std::copy(data_, data_ + capacity_, newdata);
   delete[] data_;
   data_ = newdata;
   capacity_ = new_capacity;
}

#define _EXTEND_VECTOR_IF_NEEDED \
   if (length_ >= capacity_) \
      _Resize(capacity_ << 1);

template <typename T>
void TVector<T>::InsertLast(const std::shared_ptr<T> &item)
{
   _EXTEND_VECTOR_IF_NEEDED
   data_[length_++] = item;
}

template <typename T>
void TVector<T>::EmplaceLast(const T &&item)
{
   _EXTEND_VECTOR_IF_NEEDED
   data_[length_++] = std::make_shared<T>(item);
}

#undef _EXTEND_VECTOR_IF_NEEDED

template <typename T>
void TVector<T>::Remove(const size_t index)
{
   std::copy(data_ + index + 1, data_ + length_, data_ + index);
   --length_;
}

template <typename T>
void TVector<T>::Clear()
{
   delete[] data_;
   data_ = new std::shared_ptr<T>[INITIAL_CAPACITY];
   length_ = 0;
   capacity_ = INITIAL_CAPACITY;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const TVector<T> &vector)
{
   const size_t last = vector.length_ - 1;

   for (size_t i = 0; i < vector.length_; ++i)
      os << *vector.data_[i] << ((i != last) ? '\n' : '\0');

   return os;
}
