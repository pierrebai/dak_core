// File: any_ops.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_convert_op.h>
#include <dak/core/any_is_compatible_op.h>
#include <dak/core/any_to_text_op.h>

namespace dak_ns::core_ns
{
   void initialize_ops()
   {
      // Needed so that the global operations are initialized in the tests.
      convert_op_t::register_ops();
      is_compatible_op_t::register_ops();
      to_text_op_t::register_ops();
   }
}
