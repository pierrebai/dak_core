// File: any_op_selector.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_compare_op.h>
#include <dak/core/any_convert_op.h>
#include <dak/core/any_dominant_op.h>
#include <dak/core/any_is_compatible_op.h>
#include <dak/core/any_size_op.h>
#include <dak/core/any_stream_op.h>
#include <dak/core/any_to_text_op.h>

namespace dak_ns::core_ns
{
   void register_ops()
   {
      // Needed so that the global operations are initialized in the tests.
      compare_op_t::register_ops();
      convert_op_t::register_ops();
      dominant_op_t::register_ops();
      is_compatible_op_t::register_ops();
      size_op_t::register_ops();
      stream_op_t::register_ops();
      to_text_op_t::register_ops();
   }
}
