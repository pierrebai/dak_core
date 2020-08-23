// File: any_size_op.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_size_op.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Size of containers.

   namespace
   {
      struct size_op_init_t
      {
         size_op_init_t()
         {
            make_unary_op<size_op_t, index_t, text_t   >([](const text_t& arg_a  ) -> index_t { return arg_a.size(); });
            make_unary_op<size_op_t, index_t, array_t  >([](const array_t& arg_a ) -> index_t { return arg_a.size(); });
            make_unary_op<size_op_t, index_t, dict_t   >([](const dict_t& arg_a  ) -> index_t { return arg_a.size(); });
            make_unary_op<size_op_t, index_t, str_ptr_t>([](str_ptr_t arg_a      ) -> index_t { return arg_a ? wcslen(arg_a) : 0; });
         }
      };

      size_op_init_t size_op_init;
   }

   void size_op_t::register_ops()
   {
      // Needed so that the global operations are initialized in the tests.
      // All that is needed is to enter this file to create the globals.
   }
}
