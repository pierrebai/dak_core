// File: dak/any_ops.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_ops.h>
#include <dak/core/name.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>

namespace dak_ns::core_ns
{
   void initialize_convert_ops();
   void initialize_is_compatible_ops();
   void initialize_to_text_ops();

   void initialize_ops()
   {
      // Needed so that the global operations are initialized in the tests.
      // All that is needed is to enter this file to create the globals.
      initialize_convert_ops();
      initialize_is_compatible_ops();
      initialize_to_text_ops();
   }
}
