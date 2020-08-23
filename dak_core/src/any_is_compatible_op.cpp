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
            make_nullary_op<is_compatible_op_t, bool, int8_t, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, int64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, uint64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int8_t, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, uint8_t, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, int64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, uint64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint8_t, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, int16_t, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, int64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, uint64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int16_t, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, uint16_t, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, int64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, uint64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint16_t, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, int32_t, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, int64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, uint64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int32_t, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, uint32_t, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, int64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, uint64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint32_t, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, int64_t, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, int64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, uint64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, int64_t, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, uint64_t, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, int64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, uint64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, uint64_t, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, bool, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, int64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, uint64_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, name_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, double>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, text_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, array_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, bool, dict_t>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, float, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, float, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, float, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, float, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, float, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, float, int32_t>([]() -> bool { return true; }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_nullary_op<is_compatible_op_t, bool, float, int64_t>([]() -> bool { return true; }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_nullary_op<is_compatible_op_t, bool, float, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, float, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, float, uint32_t>([]() -> bool { return true; }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_nullary_op<is_compatible_op_t, bool, float, uint64_t>([]() -> bool { return true; }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_nullary_op<is_compatible_op_t, bool, float, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, float, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, double, bool>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, char>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, wchar_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, int8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, int16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, int32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, int64_t>([]() -> bool { return true; }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_nullary_op<is_compatible_op_t, bool, double, uint8_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, uint16_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, uint32_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, uint64_t>([]() -> bool { return true; }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_nullary_op<is_compatible_op_t, bool, double, float>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, double, double>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, text_t, text_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, text_t, str_ptr_t>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, array_t, array_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, dict_t, dict_t>([]() -> bool { return true; });
            make_nullary_op<is_compatible_op_t, bool, name_t, name_t>([]() -> bool { return true; });

            make_nullary_op<is_compatible_op_t, bool, array_t, dict_t>([]() -> bool { return true; });
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
