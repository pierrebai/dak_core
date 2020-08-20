// File: dak/any_compare_op.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_compare_op.h>
#include <dak/core/name.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>

#include <cwchar>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Compare two values.

   namespace
   {
      struct compare_op_init_t
      {
         compare_op_init_t()
         {
            make_binary_op<int32_t,  bool,      bool,     compare_op_t>([](bool      arg_a, bool      arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  char,      char,     compare_op_t>([](char      arg_a, char      arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  wchar_t,   wchar_t,  compare_op_t>([](wchar_t   arg_a, wchar_t   arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  int8_t,    int8_t,   compare_op_t>([](int8_t    arg_a, int8_t    arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  int16_t,   int16_t,  compare_op_t>([](int16_t   arg_a, int16_t   arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  int32_t,   int32_t,  compare_op_t>([](int32_t   arg_a, int32_t   arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  int64_t,   int64_t,  compare_op_t>([](int64_t   arg_a, int64_t   arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  uint8_t,   uint8_t,  compare_op_t>([](uint8_t   arg_a, uint8_t   arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  uint16_t,  uint16_t, compare_op_t>([](uint16_t  arg_a, uint16_t  arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  uint32_t,  uint32_t, compare_op_t>([](uint32_t  arg_a, uint32_t  arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  uint64_t,  uint64_t, compare_op_t>([](uint64_t  arg_a, uint64_t  arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  name_t,    name_t,   compare_op_t>([](name_t    arg_a, name_t    arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  float,     float,    compare_op_t>([](float     arg_a, float     arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  double,    double,   compare_op_t>([](double    arg_a, double    arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  text_t,    text_t,   compare_op_t>([](text_t    arg_a, text_t    arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  array_t,   array_t,  compare_op_t>([](array_t   arg_a, array_t   arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  dict_t,    dict_t,   compare_op_t>([](dict_t    arg_a, dict_t    arg_b) -> int32_t { if (arg_a < arg_b) return -1; if (arg_a > arg_b) return 1; return 0; });
            make_binary_op<int32_t,  str_ptr_t, str_ptr_t,compare_op_t>([](str_ptr_t arg_a, str_ptr_t arg_b) -> int32_t { return std::wcscmp(arg_a, arg_b); });
         }
      };

      compare_op_init_t compare_op_init;
   }

   void compare_op_t::register_ops()
   {
      // Needed so that the global operations are initialized in the tests.
      // All that is needed is to enter this file to create the globals.
   }
}
