#pragma once

#include "pentagon.h"

class TVector {
public:
   TVector();
   TVector(const TVector &vector);

   virtual ~TVector();

   void InsertLast(const Pentagon &&pentagon);
   Pentagon RemoveLast();

   const Pentagon &Last() const;
   Pentagon &operator[](const size_t index) const;
   
   size_t Length() const;
   bool Empty() const;

   void Clear();

   friend std::ostream &operator<<(std::ostream &os, const TVector &vector);

private:
   void _Resize(const size_t new_capacity);

   Pentagon *data_;
   size_t size_, capacity_;

   enum { INITIAL_CAPACITY = 32 };
};
