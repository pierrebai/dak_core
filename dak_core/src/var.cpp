// File: var.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/var.h>
#include <dak/core/any_compare_op.h>
#include <dak/core/any_size_op.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>

#include <typeindex>

namespace dak_ns::core_ns
{
   const any_var_t any_var_t::empty;

   //////////////////////////////////////////////////////////////////////////
   //
   // Comparisons.

   static comparison_t compare_types(const std::type_info& a_type, const std::type_info& other_type)
   {
      if (std::type_index(a_type) < std::type_index(other_type))
         return comparison_t::less;
      else
         return comparison_t::more;
   }

   comparison_t var_t::compare(const var_t& an_other) const
   {
      const std::type_info& my_type = get_type();
      const std::type_info& other_type = an_other.get_type();
      if (my_type != other_type)
         return compare_types(my_type, other_type);
      else
         return compare_same_type(an_other);
   }

   comparison_t any_var_t::compare_same_type(const var_t& an_other) const
   {
      // TODO: optimize with any_var_t to use as_any() instead to avoid copy.
      return compare_op_t::call(get_any(), an_other.get_any());
   }

   //////////////////////////////////////////////////////////////////////////
   //
   // Array conversion + immediate array_t operation.

   any_var_t& any_var_t::operator [](index_t an_index)
   {
      return as<array_t>()[an_index];
   }

   const any_var_t& any_var_t::operator [](index_t an_index) const
   {
      if (!verify<array_t>())
         return empty;

      return const_cast<any_var_t&>(*this).as<array_t>()[an_index];
   }

   bool any_var_t::erase(index_t an_index)
   {
      return as<array_t>().erase(an_index);
   }

   void any_var_t::append(const array_t& an_array)
   {
      return as<array_t>().append(an_array);
   }

   void any_var_t::append(const any_var_t& a_value)
   {
      return as<array_t>().append(a_value);
   }

   any_var_t& any_var_t::insert(index_t an_index)
   {
      return as<array_t>().insert(an_index);
   }

   any_var_t& any_var_t::grow()
   {
      return as<array_t>().grow();
   }

   //////////////////////////////////////////////////////////////////////////
   //
   // Dict conversion + immediate dict_t operation.

   void any_var_t::append(const dict_t& a_dict)
   {
      return as<dict_t>().append(a_dict);
   }

   bool any_var_t::erase(const name_t& a_name)
   {
      return as<dict_t>().erase(a_name);
   }

   bool any_var_t::contains(const name_t& a_name) const
   {
      if (!verify<dict_t>())
         return false;

      return const_cast<any_var_t&>(*this).as<dict_t>().contains(a_name);
   }

   any_var_t& any_var_t::operator [](const name_t& a_name)
   {
      return as<dict_t>()[a_name];
   }

   const any_var_t& any_var_t::operator [](const name_t& a_name) const
   {
      if (!verify<dict_t>())
         return empty;

      return const_cast<const dict_t&>(const_cast<any_var_t&>(*this).as<dict_t>())[a_name];
   }

   index_t any_var_t::size() const
   {
      return size_op_t::call(my_value);
   }

}

