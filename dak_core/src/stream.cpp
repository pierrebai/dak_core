// File: stream.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_to_text_op.h>
#include <dak/core/stream.h>
#include <dak/core/types.h>
#include <dak/core/dict.h>
#include <dak/core/array.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Stream operations.

   std::wostream& operator <<(std::wostream& o, const name_t& a_name)
   {
      o << a_name.as_text();
      return o;
   }

   std::wostream& operator <<(std::wostream& o, const var_t& a_var)
   {
      o << to_text_op_t::call(a_var.get_any());
      return o;
   }

   std::wostream& operator <<(std::wostream& o, const array_t& an_array)
   {
      o << L"[ ";
      for (const var_t& e : an_array)
         o << e << L" , ";
      o << L"]";
      return o;
   }

   std::wostream& operator <<(std::wostream& o, const dict_t& a_dict)
   {
      o << L"{ ";
      for (const auto& [n, e] : a_dict)
         o << n << L" : " <<  e << L" , ";
      o << L"}";
      return o;
   }
}
