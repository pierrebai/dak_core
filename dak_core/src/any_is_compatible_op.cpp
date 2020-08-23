// File: any_is_compatible_op.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_is_compatible_op.h>
#include <dak/core/name.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Define which types we consider compatible.

   namespace
   {
      struct is_compatible_op_init_t
      {
         is_compatible_op_init_t()
         {
            make_binary_op<is_compatible_op_t, bool, int8_t, bool>([](int8_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, char>([](int8_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, wchar_t>([](int8_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, int8_t>([](int8_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, int16_t>([](int8_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, int32_t>([](int8_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, int64_t>([](int8_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, uint8_t>([](int8_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, uint16_t>([](int8_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, uint32_t>([](int8_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, uint64_t>([](int8_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, float>([](int8_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int8_t, double>([](int8_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, uint8_t, bool>([](uint8_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, char>([](uint8_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, wchar_t>([](uint8_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, int8_t>([](uint8_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, int16_t>([](uint8_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, int32_t>([](uint8_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, int64_t>([](uint8_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, uint8_t>([](uint8_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, uint16_t>([](uint8_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, uint32_t>([](uint8_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, uint64_t>([](uint8_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, float>([](uint8_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint8_t, double>([](uint8_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, int16_t, bool>([](int16_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, char>([](int16_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, wchar_t>([](int16_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, int8_t>([](int16_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, int16_t>([](int16_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, int32_t>([](int16_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, int64_t>([](int16_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, uint8_t>([](int16_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, uint16_t>([](int16_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, uint32_t>([](int16_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, uint64_t>([](int16_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, float>([](int16_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int16_t, double>([](int16_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, uint16_t, bool>([](uint16_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, char>([](uint16_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, wchar_t>([](uint16_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, int8_t>([](uint16_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, int16_t>([](uint16_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, int32_t>([](uint16_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, int64_t>([](uint16_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, uint8_t>([](uint16_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, uint16_t>([](uint16_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, uint32_t>([](uint16_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, uint64_t>([](uint16_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, float>([](uint16_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint16_t, double>([](uint16_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, int32_t, bool>([](int32_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, char>([](int32_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, wchar_t>([](int32_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, int8_t>([](int32_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, int16_t>([](int32_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, int32_t>([](int32_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, int64_t>([](int32_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, uint8_t>([](int32_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, uint16_t>([](int32_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, uint32_t>([](int32_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, uint64_t>([](int32_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, float>([](int32_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int32_t, double>([](int32_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, uint32_t, bool>([](uint32_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, char>([](uint32_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, wchar_t>([](uint32_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, int8_t>([](uint32_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, int16_t>([](uint32_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, int32_t>([](uint32_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, int64_t>([](uint32_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, uint8_t>([](uint32_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, uint16_t>([](uint32_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, uint32_t>([](uint32_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, uint64_t>([](uint32_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, float>([](uint32_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint32_t, double>([](uint32_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, int64_t, bool>([](int64_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, char>([](int64_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, wchar_t>([](int64_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, int8_t>([](int64_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, int16_t>([](int64_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, int32_t>([](int64_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, int64_t>([](int64_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, uint8_t>([](int64_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, uint16_t>([](int64_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, uint32_t>([](int64_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, uint64_t>([](int64_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, float>([](int64_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, int64_t, double>([](int64_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, uint64_t, bool>([](uint64_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, char>([](uint64_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, wchar_t>([](uint64_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, int8_t>([](uint64_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, int16_t>([](uint64_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, int32_t>([](uint64_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, int64_t>([](uint64_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, uint8_t>([](uint64_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, uint16_t>([](uint64_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, uint32_t>([](uint64_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, uint64_t>([](uint64_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, float>([](uint64_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, uint64_t, double>([](uint64_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, bool, bool>([](bool arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, char>([](bool arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, wchar_t>([](bool arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, int8_t>([](bool arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, int16_t>([](bool arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, int32_t>([](bool arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, int64_t>([](bool arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, uint8_t>([](bool arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, uint16_t>([](bool arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, uint32_t>([](bool arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, uint64_t>([](bool arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, name_t>([](bool arg_a, name_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, float>([](bool arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, double>([](bool arg_a, double arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, text_t>([](bool arg_a, text_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, array_t>([](bool arg_a, array_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, bool, dict_t>([](bool arg_a, dict_t arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, float, bool>([](float arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, float, char>([](float arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, float, wchar_t>([](float arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, float, int8_t>([](float arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, float, int16_t>([](float arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, float, int32_t>([](float arg_a, int32_t arg_b) -> bool { return true; }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_binary_op<is_compatible_op_t, bool, float, int64_t>([](float arg_a, int64_t arg_b) -> bool { return true; }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_binary_op<is_compatible_op_t, bool, float, uint8_t>([](float arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, float, uint16_t>([](float arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, float, uint32_t>([](float arg_a, uint32_t arg_b) -> bool { return true; }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_binary_op<is_compatible_op_t, bool, float, uint64_t>([](float arg_a, uint64_t arg_b) -> bool { return true; }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_binary_op<is_compatible_op_t, bool, float, float>([](float arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, float, double>([](float arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, double, bool>([](double arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, char>([](double arg_a, char arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, wchar_t>([](double arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, int8_t>([](double arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, int16_t>([](double arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, int32_t>([](double arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, int64_t>([](double arg_a, int64_t arg_b) -> bool { return true; }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_binary_op<is_compatible_op_t, bool, double, uint8_t>([](double arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, uint16_t>([](double arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, uint32_t>([](double arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, uint64_t>([](double arg_a, uint64_t arg_b) -> bool { return true; }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_binary_op<is_compatible_op_t, bool, double, float>([](double arg_a, float arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, double, double>([](double arg_a, double arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, text_t, text_t>([](const text_t& arg_a, const text_t& arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, text_t, str_ptr_t>([](const text_t& arg_a, str_ptr_t arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, array_t, array_t>([](const array_t& arg_a, const array_t& arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, dict_t, dict_t>([](const dict_t& arg_a, const dict_t& arg_b) -> bool { return true; });
            make_binary_op<is_compatible_op_t, bool, name_t, name_t>([](const name_t& arg_a, const name_t& arg_b) -> bool { return true; });

            make_binary_op<is_compatible_op_t, bool, array_t, dict_t>([](const array_t& arg_a, const dict_t& arg_b) -> bool { return true; });
         }
      };

      is_compatible_op_init_t is_compatible_op_init;
   }

   void is_compatible_op_t::register_ops()
   {
      // Needed so that the global operations are initialized in the tests.
      // All that is needed is to enter this file to create the globals.
   }
}
