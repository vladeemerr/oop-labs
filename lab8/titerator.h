#pragma once

#include <memory>

// NOTE: This implementation of iterator is based on STL C++ iterator prototype
// NOTE: This can be converted to use shared node pointers instead, if necessary
template <typename T>
class TIterator {
public:
   inline TIterator(std::shared_ptr<T> *iter)
      : iter_(iter) {}

   inline T operator*() const
   {
      return *(*iter_);
   }

   inline T operator->() const
   {
      return *(*iter_);
   }

   inline void operator++()
   {
      iter_ += 1;
   }

   inline TIterator operator++(int)
   {
      TIterator iter(*this);
      ++(*this);
      return iter;
   }

   inline bool operator==(TIterator const &iterator) const
   {
      return iter_ == iterator.iter_;
   }

   inline bool operator!=(TIterator const &iterator) const
   {
      return !(*this == iterator);
   }

private:
   std::shared_ptr<T> *iter_;
};
