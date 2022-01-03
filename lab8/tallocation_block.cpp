#include "tallocation_block.h"

#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size, size_t count)
   : size_(size), count_(count), budget_(count),
     used_blocks_(new char[size * count])
{
   for (size_t i = 0; i < count; ++i)
      free_blocks_.Emplace((void *)(used_blocks_ + (i * size)));
}

TAllocationBlock::~TAllocationBlock()
{
   delete[] used_blocks_;
}

void TAllocationBlock::_Resize(size_t new_count)
{
   char *newdata = new char[size_ * new_count];
   std::copy(used_blocks_, used_blocks_ + (size_ * count_), newdata);
   delete[] used_blocks_;
   used_blocks_ = newdata;
   count_ = new_count;
}

void *TAllocationBlock::Allocate(size_t size)
{
   if (size != size_) {
      std::cerr << "This block allocates " << size_ << "bytes only. "
                << "You tried to allocate " << size << '\n'; 
      return 0;
   }

   if (!budget_) {
      size_t old_cound = count_;
      _Resize(count_ << 1);
      budget_ += (count_ - old_cound);

      for (size_t i = old_cound; i < count_; ++i)
         free_blocks_.Emplace((void *)(used_blocks_ + (i * size_)));
   }

   --budget_;

   return free_blocks_.Pop();
}

void TAllocationBlock::Free(void *pointer)
{
   free_blocks_.Push(std::make_shared<void *>(pointer));
   ++budget_;
}
