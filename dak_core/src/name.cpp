// File: name.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/name.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Well-known names namespace.

   namespace ns
   {
      #define DAK_CORE_INTERNAL_NAME_DECL(n) name_t n(L#n)
      #define DAK_CORE_INTERNAL_NAME_SEP ;
      #define DAK_CORE_INTERNAL_NAME_FINAL ;
      #include <dak/core/internal_names.h>
      #undef DAK_CORE_INTERNAL_NAME_DECL
      #undef DAK_CORE_INTERNAL_NAME_SEP
      #undef DAK_CORE_INTERNAL_NAME_FINAL
   }

   void initialize_names()
   {
      // Needed so that the global well-known names are initialized in the tests.
      // All that is needed is to enter this file to create the globals.
   }
}
