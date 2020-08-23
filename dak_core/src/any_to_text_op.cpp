// File: any_to_text_op.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_to_text_op.h>
#include <dak/core/name.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>
#include <dak/core/stream.h>

#include <sstream>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Conversion to text.

   namespace
   {
      struct to_text_op_init_t
      {
         to_text_op_init_t()
         {
            make_unary_op<to_text_op_t, text_t, bool     >([](bool arg_a            ) -> text_t { return arg_a ? L"true" : L"false"; });
            make_unary_op<to_text_op_t, text_t, char     >([](char arg_a            ) -> text_t { wchar_t text[2] = { wchar_t(arg_a), 0 }; return text; });
            make_unary_op<to_text_op_t, text_t, wchar_t  >([](wchar_t arg_a         ) -> text_t { wchar_t text[2] = { arg_a, 0 }; return text; });
            make_unary_op<to_text_op_t, text_t, int8_t   >([](int8_t arg_a          ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, int16_t  >([](int16_t arg_a         ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, int32_t  >([](int32_t arg_a         ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, int64_t  >([](int64_t arg_a         ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, uint8_t  >([](uint8_t arg_a         ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, uint16_t >([](uint16_t arg_a        ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, uint32_t >([](uint32_t arg_a        ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, uint64_t >([](uint64_t arg_a        ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, name_t   >([](name_t arg_a          ) -> text_t { return arg_a.as_text(); });
            make_unary_op<to_text_op_t, text_t, float    >([](float arg_a           ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, double   >([](double arg_a          ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, text_t   >([](const text_t& arg_a   ) -> text_t { return arg_a; });
            make_unary_op<to_text_op_t, text_t, array_t  >([](const array_t& arg_a  ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, dict_t   >([](const dict_t& arg_a   ) -> text_t { std::wostringstream os; os << arg_a; return os.str(); });
            make_unary_op<to_text_op_t, text_t, str_ptr_t>([](str_ptr_t arg_a       ) -> text_t { return arg_a ? arg_a : L""; });
         }
      };

      to_text_op_init_t to_text_op_init;
   }

   void to_text_op_t::register_ops()
   {
      // Needed so that the global operations are initialized in the tests.
      // All that is needed is to enter this file to create the globals.
   }
}
