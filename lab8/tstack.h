#pragma once

#include <ostream>
#include <memory>

template <typename T>
class TStack {
public:
   TStack();
   TStack(const TStack &);

   virtual ~TStack();

   inline size_t Length() const
   {
      return length_;
   }

   inline bool Empty() const
   {
      return !length_;
   }

   inline std::shared_ptr<T> &Top() const
   {
      return data_[length_ - 1];
   }

   void Push(const std::shared_ptr<T> &);
   void Emplace(const T &&);

   inline T Pop()
   {
      return *data_[--length_];
   }

   void Clear();

   template <typename TF> friend std::ostream &operator<<(
      std::ostream &, const TStack<TF> &);

private:
   void _Resize(const size_t new_capacity);
   
   std::shared_ptr<T> *data_;
   size_t length_, capacity_;

   enum { INITIAL_CAPACITY = 32 };
};

#include <cstdlib>

template <typename T>
TStack<T>::TStack()
   : data_(new std::shared_ptr<T>[INITIAL_CAPACITY]), 
     length_(0), capacity_(INITIAL_CAPACITY) {}

template <typename T>
TStack<T>::TStack(const TStack &vector)
   : data_(new std::shared_ptr<T>[vector.capacity_]),
     length_(vector.length_), capacity_(vector.capacity_)
{
   std::copy(vector.data_, vector.data_ + vector.length_, data_);
}

template <typename T>
TStack<T>::~TStack()
{
   delete[] data_;
}

// NOTE: C++ has no `realloc`, so this is a workaround:
template <typename T>
void TStack<T>::_Resize(const size_t new_capacity)
{
   std::shared_ptr<T> *newdata = new std::shared_ptr<T>[new_capacity];
   std::copy(data_, data_ + capacity_, newdata);
   delete[] data_;
   data_ = newdata;
   capacity_ = new_capacity;
}

#define _EXTEND_STACK_IF_NEEDED \
   if (length_ >= capacity_) \
      _Resize(capacity_ << 1);

template <typename T>
void TStack<T>::Push(const std::shared_ptr<T> &item)
{
   _EXTEND_STACK_IF_NEEDED
   data_[length_++] = item;
}

template <typename T>
void TStack<T>::Emplace(const T &&item)
{
   _EXTEND_STACK_IF_NEEDED
   data_[length_++] = std::make_shared<T>(item);
}

#undef _EXTEND_STACK_IF_NEEDED

template <typename T>
void TStack<T>::Clear()
{
   delete[] data_;
   data_ = new std::shared_ptr<T>[INITIAL_CAPACITY];
   length_ = 0;
   capacity_ = INITIAL_CAPACITY;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const TStack<T> &stack)
{
   os << "<=";
   for (size_t i = stack.length_ - 1; i >= 0; --i)
      os << (*stack.data_[i]).Area() << ((i != 0) ? ' ' : '\0');
   os << "<=";

   return os;
}
