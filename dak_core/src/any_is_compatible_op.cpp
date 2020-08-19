// File: dak/any_ops.h
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
            make_binary_op<bool, int8_t, bool, is_compatible_op_t>([](int8_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, char, is_compatible_op_t>([](int8_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, wchar_t, is_compatible_op_t>([](int8_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, int8_t, is_compatible_op_t>([](int8_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, int16_t, is_compatible_op_t>([](int8_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, int32_t, is_compatible_op_t>([](int8_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, int64_t, is_compatible_op_t>([](int8_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, uint8_t, is_compatible_op_t>([](int8_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, uint16_t, is_compatible_op_t>([](int8_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, uint32_t, is_compatible_op_t>([](int8_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, uint64_t, is_compatible_op_t>([](int8_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, float, is_compatible_op_t>([](int8_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, int8_t, double, is_compatible_op_t>([](int8_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, uint8_t, bool, is_compatible_op_t>([](uint8_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, char, is_compatible_op_t>([](uint8_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, wchar_t, is_compatible_op_t>([](uint8_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, int8_t, is_compatible_op_t>([](uint8_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, int16_t, is_compatible_op_t>([](uint8_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, int32_t, is_compatible_op_t>([](uint8_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, int64_t, is_compatible_op_t>([](uint8_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, uint8_t, is_compatible_op_t>([](uint8_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, uint16_t, is_compatible_op_t>([](uint8_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, uint32_t, is_compatible_op_t>([](uint8_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, uint64_t, is_compatible_op_t>([](uint8_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, float, is_compatible_op_t>([](uint8_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, uint8_t, double, is_compatible_op_t>([](uint8_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, int16_t, bool, is_compatible_op_t>([](int16_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, char, is_compatible_op_t>([](int16_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, wchar_t, is_compatible_op_t>([](int16_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, int8_t, is_compatible_op_t>([](int16_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, int16_t, is_compatible_op_t>([](int16_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, int32_t, is_compatible_op_t>([](int16_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, int64_t, is_compatible_op_t>([](int16_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, uint8_t, is_compatible_op_t>([](int16_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, uint16_t, is_compatible_op_t>([](int16_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, uint32_t, is_compatible_op_t>([](int16_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, uint64_t, is_compatible_op_t>([](int16_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, float, is_compatible_op_t>([](int16_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, int16_t, double, is_compatible_op_t>([](int16_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, uint16_t, bool, is_compatible_op_t>([](uint16_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, char, is_compatible_op_t>([](uint16_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, wchar_t, is_compatible_op_t>([](uint16_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, int8_t, is_compatible_op_t>([](uint16_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, int16_t, is_compatible_op_t>([](uint16_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, int32_t, is_compatible_op_t>([](uint16_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, int64_t, is_compatible_op_t>([](uint16_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, uint8_t, is_compatible_op_t>([](uint16_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, uint16_t, is_compatible_op_t>([](uint16_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, uint32_t, is_compatible_op_t>([](uint16_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, uint64_t, is_compatible_op_t>([](uint16_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, float, is_compatible_op_t>([](uint16_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, uint16_t, double, is_compatible_op_t>([](uint16_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, int32_t, bool, is_compatible_op_t>([](int32_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, char, is_compatible_op_t>([](int32_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, wchar_t, is_compatible_op_t>([](int32_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, int8_t, is_compatible_op_t>([](int32_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, int16_t, is_compatible_op_t>([](int32_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, int32_t, is_compatible_op_t>([](int32_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, int64_t, is_compatible_op_t>([](int32_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, uint8_t, is_compatible_op_t>([](int32_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, uint16_t, is_compatible_op_t>([](int32_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, uint32_t, is_compatible_op_t>([](int32_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, uint64_t, is_compatible_op_t>([](int32_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, float, is_compatible_op_t>([](int32_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, int32_t, double, is_compatible_op_t>([](int32_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, uint32_t, bool, is_compatible_op_t>([](uint32_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, char, is_compatible_op_t>([](uint32_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, wchar_t, is_compatible_op_t>([](uint32_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, int8_t, is_compatible_op_t>([](uint32_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, int16_t, is_compatible_op_t>([](uint32_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, int32_t, is_compatible_op_t>([](uint32_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, int64_t, is_compatible_op_t>([](uint32_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, uint8_t, is_compatible_op_t>([](uint32_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, uint16_t, is_compatible_op_t>([](uint32_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, uint32_t, is_compatible_op_t>([](uint32_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, uint64_t, is_compatible_op_t>([](uint32_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, float, is_compatible_op_t>([](uint32_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, uint32_t, double, is_compatible_op_t>([](uint32_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, int64_t, bool, is_compatible_op_t>([](int64_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, char, is_compatible_op_t>([](int64_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, wchar_t, is_compatible_op_t>([](int64_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, int8_t, is_compatible_op_t>([](int64_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, int16_t, is_compatible_op_t>([](int64_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, int32_t, is_compatible_op_t>([](int64_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, int64_t, is_compatible_op_t>([](int64_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, uint8_t, is_compatible_op_t>([](int64_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, uint16_t, is_compatible_op_t>([](int64_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, uint32_t, is_compatible_op_t>([](int64_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, uint64_t, is_compatible_op_t>([](int64_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, float, is_compatible_op_t>([](int64_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, int64_t, double, is_compatible_op_t>([](int64_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, uint64_t, bool, is_compatible_op_t>([](uint64_t arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, char, is_compatible_op_t>([](uint64_t arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, wchar_t, is_compatible_op_t>([](uint64_t arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, int8_t, is_compatible_op_t>([](uint64_t arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, int16_t, is_compatible_op_t>([](uint64_t arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, int32_t, is_compatible_op_t>([](uint64_t arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, int64_t, is_compatible_op_t>([](uint64_t arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, uint8_t, is_compatible_op_t>([](uint64_t arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, uint16_t, is_compatible_op_t>([](uint64_t arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, uint32_t, is_compatible_op_t>([](uint64_t arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, uint64_t, is_compatible_op_t>([](uint64_t arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, float, is_compatible_op_t>([](uint64_t arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, uint64_t, double, is_compatible_op_t>([](uint64_t arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, bool, bool, is_compatible_op_t>([](bool arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, bool, char, is_compatible_op_t>([](bool arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, bool, wchar_t, is_compatible_op_t>([](bool arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, int8_t, is_compatible_op_t>([](bool arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, int16_t, is_compatible_op_t>([](bool arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, int32_t, is_compatible_op_t>([](bool arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, int64_t, is_compatible_op_t>([](bool arg_a, int64_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, uint8_t, is_compatible_op_t>([](bool arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, uint16_t, is_compatible_op_t>([](bool arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, uint32_t, is_compatible_op_t>([](bool arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, uint64_t, is_compatible_op_t>([](bool arg_a, uint64_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, name_t, is_compatible_op_t>([](bool arg_a, name_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, float, is_compatible_op_t>([](bool arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, bool, double, is_compatible_op_t>([](bool arg_a, double arg_b) -> bool { return true; });
            make_binary_op<bool, bool, text_t, is_compatible_op_t>([](bool arg_a, text_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, array_t, is_compatible_op_t>([](bool arg_a, array_t arg_b) -> bool { return true; });
            make_binary_op<bool, bool, dict_t, is_compatible_op_t>([](bool arg_a, dict_t arg_b) -> bool { return true; });

            make_binary_op<bool, float, bool, is_compatible_op_t>([](float arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, float, char, is_compatible_op_t>([](float arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, float, wchar_t, is_compatible_op_t>([](float arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, float, int8_t, is_compatible_op_t>([](float arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, float, int16_t, is_compatible_op_t>([](float arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, float, int32_t, is_compatible_op_t>([](float arg_a, int32_t arg_b) -> bool { return true; }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_binary_op<bool, float, int64_t, is_compatible_op_t>([](float arg_a, int64_t arg_b) -> bool { return true; }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_binary_op<bool, float, uint8_t, is_compatible_op_t>([](float arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, float, uint16_t, is_compatible_op_t>([](float arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, float, uint32_t, is_compatible_op_t>([](float arg_a, uint32_t arg_b) -> bool { return true; }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_binary_op<bool, float, uint64_t, is_compatible_op_t>([](float arg_a, uint64_t arg_b) -> bool { return true; }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_binary_op<bool, float, float, is_compatible_op_t>([](float arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, float, double, is_compatible_op_t>([](float arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, double, bool, is_compatible_op_t>([](double arg_a, bool arg_b) -> bool { return true; });
            make_binary_op<bool, double, char, is_compatible_op_t>([](double arg_a, char arg_b) -> bool { return true; });
            make_binary_op<bool, double, wchar_t, is_compatible_op_t>([](double arg_a, wchar_t arg_b) -> bool { return true; });
            make_binary_op<bool, double, int8_t, is_compatible_op_t>([](double arg_a, int8_t arg_b) -> bool { return true; });
            make_binary_op<bool, double, int16_t, is_compatible_op_t>([](double arg_a, int16_t arg_b) -> bool { return true; });
            make_binary_op<bool, double, int32_t, is_compatible_op_t>([](double arg_a, int32_t arg_b) -> bool { return true; });
            make_binary_op<bool, double, int64_t, is_compatible_op_t>([](double arg_a, int64_t arg_b) -> bool { return true; }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_binary_op<bool, double, uint8_t, is_compatible_op_t>([](double arg_a, uint8_t arg_b) -> bool { return true; });
            make_binary_op<bool, double, uint16_t, is_compatible_op_t>([](double arg_a, uint16_t arg_b) -> bool { return true; });
            make_binary_op<bool, double, uint32_t, is_compatible_op_t>([](double arg_a, uint32_t arg_b) -> bool { return true; });
            make_binary_op<bool, double, uint64_t, is_compatible_op_t>([](double arg_a, uint64_t arg_b) -> bool { return true; }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_binary_op<bool, double, float, is_compatible_op_t>([](double arg_a, float arg_b) -> bool { return true; });
            make_binary_op<bool, double, double, is_compatible_op_t>([](double arg_a, double arg_b) -> bool { return true; });

            make_binary_op<bool, text_t, text_t, is_compatible_op_t>([](const text_t& arg_a, const text_t& arg_b) -> bool { return true; });
            make_binary_op<bool, text_t, str_ptr_t, is_compatible_op_t>([](const text_t& arg_a, str_ptr_t arg_b) -> bool { return true; });

            make_binary_op<bool, array_t, array_t, is_compatible_op_t>([](const array_t& arg_a, const array_t& arg_b) -> bool { return true; });
            make_binary_op<bool, dict_t, dict_t, is_compatible_op_t>([](const dict_t& arg_a, const dict_t& arg_b) -> bool { return true; });
            make_binary_op<bool, name_t, name_t, is_compatible_op_t>([](const name_t& arg_a, const name_t& arg_b) -> bool { return true; });

            make_binary_op<bool, array_t, dict_t, is_compatible_op_t>([](const array_t& arg_a, const dict_t& arg_b) -> bool { return true; });
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
