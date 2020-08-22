// File: dak/core/name.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_NAME_H
#define DAK_CORE_NAME_H

#include <dak/core/types.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Name. Efficient when used as key.
   //
   // Many well-known names are predefined below.

   struct name_t
   {
      // Constructor.
      //
      // Note: the string pointer *must* be a string literal.
      name_t() = default;
      name_t(str_ptr_t a_name) : my_id(a_name ? a_name : L"") {}

      intptr_t as_id() const { return reinterpret_cast<intptr_t>(my_id); }
      str_ptr_t as_text() const { return my_id; }

      bool is_valid() const { return my_id[0] != 0; }

      bool operator==(const name_t& an_other) const { return my_id == an_other.my_id; }
      bool operator!=(const name_t& an_other) const { return my_id != an_other.my_id; }
      bool operator< (const name_t& an_other) const { return my_id <  an_other.my_id; }
      bool operator<=(const name_t& an_other) const { return my_id <= an_other.my_id; }
      bool operator> (const name_t& an_other) const { return my_id >  an_other.my_id; }
      bool operator>=(const name_t& an_other) const { return my_id >= an_other.my_id; }

   private:
      str_ptr_t my_id = L"";
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Well-known names namespace.

   namespace ns
   {
      #define DAK_CORE_INTERNAL_NAME_DECL(n) extern name_t n
      #define DAK_CORE_INTERNAL_NAME_SEP ;
      #define DAK_CORE_INTERNAL_NAME_FINAL ;
      #include <dak/core/internal_names.h>
      #undef DAK_CORE_INTERNAL_NAME_DECL
      #undef DAK_CORE_INTERNAL_NAME_SEP
      #undef DAK_CORE_INTERNAL_NAME_FINAL
   }

   //////////////////////////////////////////////////////////////////////////
   //
   // Hashes the name.

   struct name_hasher
   {
      inline int32_t operator ()(const name_t& a_name) const
      {
         return int32_t(a_name.as_id());
      }
   };

   void initialize_names();
}

#endif /* DAK_CORE_NAME_H */
