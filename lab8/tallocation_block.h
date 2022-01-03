#pragma once

#include "tstack.h"

class TAllocationBlock {
public:
   TAllocationBlock(size_t size, size_t count);
   ~TAllocationBlock();

   void *Allocate(size_t size);
   void Free(void *pointer);

   inline bool FreeBlocksAvailable() const
   {
      return budget_;
   }

private:
   void _Resize(size_t new_count);
   
   size_t size_;
   size_t count_;
   size_t budget_;

   char *used_blocks_;
   TStack<void *> free_blocks_;
};
