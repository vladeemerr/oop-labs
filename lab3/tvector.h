#pragma once

#include <memory>

#include "pentagon.h"

class TVector {
public:
   TVector();
   TVector(const TVector &vector);

   virtual ~TVector();

   void InsertLast(std::shared_ptr<Pentagon> &&pentagon);
   Pentagon RemoveLast();

   std::shared_ptr<Pentagon> Last();
   const std::shared_ptr<Pentagon> operator[](const size_t index);
   
   size_t Length();
   bool Empty();

   void Clear();

   friend std::ostream &operator<<(std::ostream &os, const TVector &vector);

private:
   std::shared_ptr<Pentagon> *data_;
   size_t size_, capacity_;
};