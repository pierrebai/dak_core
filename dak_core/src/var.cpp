// File: var.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/var.h>

#include <typeindex>

namespace dak_ns::core_ns
{
   const any_var_t any_var_t::empty;

   //////////////////////////////////////////////////////////////////////////
   //
   // Comparisons.

   static int32_t compare_types(const std::type_info& a_type, const std::type_info& other_type)
   {
      if (std::type_index(a_type) < std::type_index(other_type))
         return -1;
      else
         return 1;
   }

   int32_t var_t::compare(const var_t& an_other) const
   {
      const std::type_info& my_type = get_type();
      const std::type_info& other_type = an_other.get_type();
      if (my_type != other_type)
         return compare_types(my_type, other_type);
      else
         return compare_same_type(an_other);
   }

   int32_t any_var_t::compare_same_type(const var_t& an_other) const
   {
      // TODO
      return 0;
   }
}

