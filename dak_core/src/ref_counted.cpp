// File: ref_counted.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/ref_counted.h>

#include <limits>

namespace dak_ns::core_ns
{
   ref_counted_t::ref_counted_t(const ref_counted_t &)
   : my_ref_count(0)
   {
   }

   ref_counted_t& ref_counted_t::operator =(const ref_counted_t &)
   {
      return *this;
   }

   void ref_counted_t::add_ref() const
   {
      ++my_ref_count;
   }

   void ref_counted_t::remove_ref() const
   {
      if ( --my_ref_count == 0 )
      {
         my_ref_count = std::numeric_limits<int64>::min() / 2;
         delete this;
      }
   }
}
