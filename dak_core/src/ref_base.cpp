// File: ref_base.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include "dak/core/ref.h"
#include "dak/core/ref_counted.h"

namespace dak_ns::core_ns
{
   ref_base_t::ref_base_t(ref_counted_t* an_object)
   : my_object(an_object)
   {
      if (an_object)
         an_object->add_ref();
   }

   ref_base_t::ref_base_t(const ref_base_t& another)
   : my_object(another.my_object)
   {
      if (my_object)
         my_object->add_ref();
   }

   ref_base_t& ref_base_t::operator =(ref_counted_t* an_object)
   {
      if (my_object != an_object)
      {
         clear();
         my_object = an_object;
         if (an_object)
            an_object->add_ref();
      }
      return *this;
   }

   ref_base_t& ref_base_t::operator =(const ref_base_t& another)
   {
      return operator =(another.my_object);
   }

   ref_base_t::~ref_base_t()
   {
      clear();
   }

   void ref_base_t::clear()
   {
      if (!my_object)
         return;

      auto oldmy_object = my_object;
      my_object = nullptr;
      oldmy_object->remove_ref();
   }

   bool ref_base_t::is_valid() const
   {
      return my_object != 0;
   }

   bool ref_base_t::is_null() const
   {
      return my_object == 0;
   }
}

