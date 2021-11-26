#pragma once

#include "pentagon.h"

#include <ostream>
#include <memory>

class TVector {
public:
   TVector();
   TVector(const TVector &);

   virtual ~TVector();

   inline size_t Length() const
   {
      return length_;
   }

   inline bool Empty() const
   {
      return !length_;
   }

   inline const std::shared_ptr<Pentagon> &operator[](const size_t index) const
   {
      return data_[index];
   }

   inline std::shared_ptr<Pentagon> Last() const
   {
      return data_[length_ - 1];
   }

   void InsertLast(const std::shared_ptr<Pentagon> &);
   void EmplaceLast(const Pentagon &&);

   void Remove(const size_t index);

   inline Pentagon RemoveLast()
   {
      return *data_[--length_];
   }

   void Clear();

   friend std::ostream &operator<<(std::ostream &, const TVector &);

private:
   void _Resize(const size_t new_capacity);
   
   std::shared_ptr<Pentagon> *data_;
   size_t length_, capacity_;

   enum { INITIAL_CAPACITY = 32 };
};

