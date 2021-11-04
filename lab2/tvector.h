#pragma once

#include "pentagon.h"

class TVector {
public:
   TVector();
   TVector(const TVector &vector);

   virtual ~TVector();

   void InsertLast(const Pentagon &pentagon);
   Pentagon RemoveLast();

   const Pentagon &Last();
   Pentagon &operator[](const size_t index);
   
   size_t Length();
   bool Empty();

   void Clear();

   friend std::ostream &operator<<(std::ostream &os, const TVector &vector);

private:
   Pentagon *data_;
   size_t size_, capacity_;
};
