// File: dak/any_stream_op.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_stream_op.h>
#include <dak/core/name.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>
#include <dak/core/stream.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Conversion from a type to another.

   namespace
   {
      struct stream_op_init_t
      {
         stream_op_init_t()
         {
            make_binary_op<bool, std::wostream*, bool, stream_op_t>([](std::wostream* a_stream, bool arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, char, stream_op_t>([](std::wostream* a_stream, char arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, wchar_t, stream_op_t>([](std::wostream* a_stream, wchar_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, int8_t, stream_op_t>([](std::wostream* a_stream, int8_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, int16_t, stream_op_t>([](std::wostream* a_stream, int16_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, int32_t, stream_op_t>([](std::wostream* a_stream, int32_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, int64_t, stream_op_t>([](std::wostream* a_stream, int64_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, uint8_t, stream_op_t>([](std::wostream* a_stream, uint8_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, uint16_t, stream_op_t>([](std::wostream* a_stream, uint16_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, uint32_t, stream_op_t>([](std::wostream* a_stream, uint32_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, uint64_t, stream_op_t>([](std::wostream* a_stream, uint64_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, name_t, stream_op_t>([](std::wostream* a_stream, name_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, float, stream_op_t>([](std::wostream* a_stream, float arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, double, stream_op_t>([](std::wostream* a_stream, double arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, text_t, stream_op_t>([](std::wostream* a_stream, text_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, array_t, stream_op_t>([](std::wostream* a_stream, array_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, dict_t, stream_op_t>([](std::wostream* a_stream, dict_t arg_b) -> bool { *a_stream << arg_b; return true; });
            make_binary_op<bool, std::wostream*, str_ptr_t, stream_op_t>([](std::wostream* a_stream, str_ptr_t arg_b) -> bool { *a_stream << (arg_b ? arg_b : L""); return true; });
         }
      };

      stream_op_init_t stream_op_init;
   }

   std::wostream& operator<<(std::wostream& a_stream, const std::any& a_value)
   {
      return stream_op_t::call(a_stream, a_value);
   }

   void stream_op_t::register_ops()
   {
      // Needed so that the global operations are initialized in the tests.
      // All that is needed is to enter this file to create the globals.
   }
}
