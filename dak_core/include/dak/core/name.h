// File: dak/name.h
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
   // Many well-known names are predefined.

   enum class name_t : uint32_t
   {
      invalid = 0,
      #define DAK_CORE_INTERNAL_NAME_DECL(n) n
      #include <dak/core/internal_names.h>
      #undef DAK_CORE_INTERNAL_NAME_DECL
   };

   using n = name_t;

   //////////////////////////////////////////////////////////////////////////
   //
   // Run-time generated names.

   name_t make_name(const text_t& name);

   //////////////////////////////////////////////////////////////////////////
   //
   // Hashes the name.

   struct name_hasher
   {
      inline int32_t operator ()(const name_t a_name) const
      {
         return int32_t(a_name);
      }
   };
}

#endif /* DAK_CORE_NAME_H */
