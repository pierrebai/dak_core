// File: any_stream_op.cpp
//
// Dak Copyright � 2012-2020. All Rights Reserved.

#include <dak/core/any_stream_op.h>
#include <dak/core/name.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>
#include <dak/core/stream.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Write to an output text stream.

   namespace
   {
      struct stream_op_init_t
      {
         stream_op_init_t()
         {
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, bool      >([](std::wostream& a_stream, bool arg_b           ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, char      >([](std::wostream& a_stream, char arg_b           ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, wchar_t   >([](std::wostream& a_stream, wchar_t arg_b        ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, int8_t    >([](std::wostream& a_stream, int8_t arg_b         ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, int16_t   >([](std::wostream& a_stream, int16_t arg_b        ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, int32_t   >([](std::wostream& a_stream, int32_t arg_b        ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, int64_t   >([](std::wostream& a_stream, int64_t arg_b        ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, uint8_t   >([](std::wostream& a_stream, uint8_t arg_b        ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, uint16_t  >([](std::wostream& a_stream, uint16_t arg_b       ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, uint32_t  >([](std::wostream& a_stream, uint32_t arg_b       ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, uint64_t  >([](std::wostream& a_stream, uint64_t arg_b       ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, name_t    >([](std::wostream& a_stream, name_t arg_b         ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, float     >([](std::wostream& a_stream, float arg_b          ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, double    >([](std::wostream& a_stream, double arg_b         ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, text_t    >([](std::wostream& a_stream, const text_t& arg_b  ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, array_t   >([](std::wostream& a_stream, const array_t& arg_b ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, dict_t    >([](std::wostream& a_stream, const dict_t& arg_b  ) -> bool { a_stream << arg_b; return true; });
            unary_op_t<stream_op_t, std::wostream&>::make_op<bool, str_ptr_t >([](std::wostream& a_stream, str_ptr_t arg_b      ) -> bool { a_stream << (arg_b ? arg_b : L""); return true; });
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
