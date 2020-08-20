// File: dak/any_ops.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/any_convert_op.h>
#include <dak/core/name.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Conversion from a type to another.

   namespace
   {
      struct convert_op_init_t
      {
         convert_op_init_t()
         {
            make_binary_op<int8_t, int8_t, bool, convert_op_t>([](int8_t arg_a, bool arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, char, convert_op_t>([](int8_t arg_a, char arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, wchar_t, convert_op_t>([](int8_t arg_a, wchar_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, int8_t, convert_op_t>([](int8_t arg_a, int8_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, int16_t, convert_op_t>([](int8_t arg_a, int16_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, int32_t, convert_op_t>([](int8_t arg_a, int32_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, int64_t, convert_op_t>([](int8_t arg_a, int64_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, uint8_t, convert_op_t>([](int8_t arg_a, uint8_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, uint16_t, convert_op_t>([](int8_t arg_a, uint16_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, uint32_t, convert_op_t>([](int8_t arg_a, uint32_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, uint64_t, convert_op_t>([](int8_t arg_a, uint64_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, float, convert_op_t>([](int8_t arg_a, float arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_binary_op<int8_t, int8_t, double, convert_op_t>([](int8_t arg_a, double arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });

            make_binary_op<uint8_t, uint8_t, bool, convert_op_t>([](uint8_t arg_a, bool arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, char, convert_op_t>([](uint8_t arg_a, char arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, wchar_t, convert_op_t>([](uint8_t arg_a, wchar_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, int8_t, convert_op_t>([](uint8_t arg_a, int8_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, int16_t, convert_op_t>([](uint8_t arg_a, int16_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, int32_t, convert_op_t>([](uint8_t arg_a, int32_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, int64_t, convert_op_t>([](uint8_t arg_a, int64_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, uint8_t, convert_op_t>([](uint8_t arg_a, uint8_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, uint16_t, convert_op_t>([](uint8_t arg_a, uint16_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, uint32_t, convert_op_t>([](uint8_t arg_a, uint32_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, uint64_t, convert_op_t>([](uint8_t arg_a, uint64_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, float, convert_op_t>([](uint8_t arg_a, float arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_binary_op<uint8_t, uint8_t, double, convert_op_t>([](uint8_t arg_a, double arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });

            make_binary_op<int16_t, int16_t, bool, convert_op_t>([](int16_t arg_a, bool arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, char, convert_op_t>([](int16_t arg_a, char arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, wchar_t, convert_op_t>([](int16_t arg_a, wchar_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, int8_t, convert_op_t>([](int16_t arg_a, int8_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, int16_t, convert_op_t>([](int16_t arg_a, int16_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, int32_t, convert_op_t>([](int16_t arg_a, int32_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, int64_t, convert_op_t>([](int16_t arg_a, int64_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, uint8_t, convert_op_t>([](int16_t arg_a, uint8_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, uint16_t, convert_op_t>([](int16_t arg_a, uint16_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, uint32_t, convert_op_t>([](int16_t arg_a, uint32_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, uint64_t, convert_op_t>([](int16_t arg_a, uint64_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, float, convert_op_t>([](int16_t arg_a, float arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_binary_op<int16_t, int16_t, double, convert_op_t>([](int16_t arg_a, double arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });

            make_binary_op<uint16_t, uint16_t, bool, convert_op_t>([](uint16_t arg_a, bool arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, char, convert_op_t>([](uint16_t arg_a, char arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, wchar_t, convert_op_t>([](uint16_t arg_a, wchar_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, int8_t, convert_op_t>([](uint16_t arg_a, int8_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, int16_t, convert_op_t>([](uint16_t arg_a, int16_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, int32_t, convert_op_t>([](uint16_t arg_a, int32_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, int64_t, convert_op_t>([](uint16_t arg_a, int64_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, uint8_t, convert_op_t>([](uint16_t arg_a, uint8_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, uint16_t, convert_op_t>([](uint16_t arg_a, uint16_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, uint32_t, convert_op_t>([](uint16_t arg_a, uint32_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, uint64_t, convert_op_t>([](uint16_t arg_a, uint64_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, float, convert_op_t>([](uint16_t arg_a, float arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_binary_op<uint16_t, uint16_t, double, convert_op_t>([](uint16_t arg_a, double arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });

            make_binary_op<int32_t, int32_t, bool, convert_op_t>([](int32_t arg_a, bool arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, char, convert_op_t>([](int32_t arg_a, char arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, wchar_t, convert_op_t>([](int32_t arg_a, wchar_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, int8_t, convert_op_t>([](int32_t arg_a, int8_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, int16_t, convert_op_t>([](int32_t arg_a, int16_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, int32_t, convert_op_t>([](int32_t arg_a, int32_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, int64_t, convert_op_t>([](int32_t arg_a, int64_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, uint8_t, convert_op_t>([](int32_t arg_a, uint8_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, uint16_t, convert_op_t>([](int32_t arg_a, uint16_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, uint32_t, convert_op_t>([](int32_t arg_a, uint32_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, uint64_t, convert_op_t>([](int32_t arg_a, uint64_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, float, convert_op_t>([](int32_t arg_a, float arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_binary_op<int32_t, int32_t, double, convert_op_t>([](int32_t arg_a, double arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });

            make_binary_op<uint32_t, uint32_t, bool, convert_op_t>([](uint32_t arg_a, bool arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, char, convert_op_t>([](uint32_t arg_a, char arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, wchar_t, convert_op_t>([](uint32_t arg_a, wchar_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, int8_t, convert_op_t>([](uint32_t arg_a, int8_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, int16_t, convert_op_t>([](uint32_t arg_a, int16_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, int32_t, convert_op_t>([](uint32_t arg_a, int32_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, int64_t, convert_op_t>([](uint32_t arg_a, int64_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, uint8_t, convert_op_t>([](uint32_t arg_a, uint8_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, uint16_t, convert_op_t>([](uint32_t arg_a, uint16_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, uint32_t, convert_op_t>([](uint32_t arg_a, uint32_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, uint64_t, convert_op_t>([](uint32_t arg_a, uint64_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, float, convert_op_t>([](uint32_t arg_a, float arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_binary_op<uint32_t, uint32_t, double, convert_op_t>([](uint32_t arg_a, double arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });

            make_binary_op<int64_t, int64_t, bool, convert_op_t>([](int64_t arg_a, bool arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, char, convert_op_t>([](int64_t arg_a, char arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, wchar_t, convert_op_t>([](int64_t arg_a, wchar_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, int8_t, convert_op_t>([](int64_t arg_a, int8_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, int16_t, convert_op_t>([](int64_t arg_a, int16_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, int32_t, convert_op_t>([](int64_t arg_a, int32_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, int64_t, convert_op_t>([](int64_t arg_a, int64_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, uint8_t, convert_op_t>([](int64_t arg_a, uint8_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, uint16_t, convert_op_t>([](int64_t arg_a, uint16_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, uint32_t, convert_op_t>([](int64_t arg_a, uint32_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, uint64_t, convert_op_t>([](int64_t arg_a, uint64_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, float, convert_op_t>([](int64_t arg_a, float arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_binary_op<int64_t, int64_t, double, convert_op_t>([](int64_t arg_a, double arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });

            make_binary_op<uint64_t, uint64_t, bool, convert_op_t>([](uint64_t arg_a, bool arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, char, convert_op_t>([](uint64_t arg_a, char arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, wchar_t, convert_op_t>([](uint64_t arg_a, wchar_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, int8_t, convert_op_t>([](uint64_t arg_a, int8_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, int16_t, convert_op_t>([](uint64_t arg_a, int16_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, int32_t, convert_op_t>([](uint64_t arg_a, int32_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, int64_t, convert_op_t>([](uint64_t arg_a, int64_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, uint8_t, convert_op_t>([](uint64_t arg_a, uint8_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, uint16_t, convert_op_t>([](uint64_t arg_a, uint16_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, uint32_t, convert_op_t>([](uint64_t arg_a, uint32_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, uint64_t, convert_op_t>([](uint64_t arg_a, uint64_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, float, convert_op_t>([](uint64_t arg_a, float arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_binary_op<uint64_t, uint64_t, double, convert_op_t>([](uint64_t arg_a, double arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });

            make_binary_op<bool, bool, bool, convert_op_t>([](bool arg_a, bool arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, char, convert_op_t>([](bool arg_a, char arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, wchar_t, convert_op_t>([](bool arg_a, wchar_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, int8_t, convert_op_t>([](bool arg_a, int8_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, int16_t, convert_op_t>([](bool arg_a, int16_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, int32_t, convert_op_t>([](bool arg_a, int32_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, int64_t, convert_op_t>([](bool arg_a, int64_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, uint8_t, convert_op_t>([](bool arg_a, uint8_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, uint16_t, convert_op_t>([](bool arg_a, uint16_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, uint32_t, convert_op_t>([](bool arg_a, uint32_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, uint64_t, convert_op_t>([](bool arg_a, uint64_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, name_t, convert_op_t>([](bool arg_a, name_t arg_b) -> bool { return arg_b.is_valid(); });
            make_binary_op<bool, bool, float, convert_op_t>([](bool arg_a, float arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, double, convert_op_t>([](bool arg_a, double arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_binary_op<bool, bool, text_t, convert_op_t>([](bool arg_a, text_t arg_b) -> bool { return static_cast<bool>(arg_b.size()); });
            make_binary_op<bool, bool, array_t, convert_op_t>([](bool arg_a, array_t arg_b) -> bool { return static_cast<bool>(arg_b.size()); });
            make_binary_op<bool, bool, dict_t, convert_op_t>([](bool arg_a, dict_t arg_b) -> bool { return static_cast<bool>(arg_b.size()); });

            make_binary_op<float, float, bool, convert_op_t>([](float arg_a, bool arg_b) -> float { return static_cast<float>(arg_b); });
            make_binary_op<float, float, char, convert_op_t>([](float arg_a, char arg_b) -> float { return static_cast<float>(arg_b); });
            make_binary_op<float, float, wchar_t, convert_op_t>([](float arg_a, wchar_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_binary_op<float, float, int8_t, convert_op_t>([](float arg_a, int8_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_binary_op<float, float, int16_t, convert_op_t>([](float arg_a, int16_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_binary_op<float, float, int32_t, convert_op_t>([](float arg_a, int32_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_binary_op<float, float, int64_t, convert_op_t>([](float arg_a, int64_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_binary_op<float, float, uint8_t, convert_op_t>([](float arg_a, uint8_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_binary_op<float, float, uint16_t, convert_op_t>([](float arg_a, uint16_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_binary_op<float, float, uint32_t, convert_op_t>([](float arg_a, uint32_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_binary_op<float, float, uint64_t, convert_op_t>([](float arg_a, uint64_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_binary_op<float, float, float, convert_op_t>([](float arg_a, float arg_b) -> float { return static_cast<float>(arg_b); });
            make_binary_op<float, float, double, convert_op_t>([](float arg_a, double arg_b) -> float { return static_cast<float>(arg_b); });

            make_binary_op<double, double, bool, convert_op_t>([](double arg_a, bool arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, char, convert_op_t>([](double arg_a, char arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, wchar_t, convert_op_t>([](double arg_a, wchar_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, int8_t, convert_op_t>([](double arg_a, int8_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, int16_t, convert_op_t>([](double arg_a, int16_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, int32_t, convert_op_t>([](double arg_a, int32_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, int64_t, convert_op_t>([](double arg_a, int64_t arg_b) -> double { return static_cast<double>(arg_b); }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_binary_op<double, double, uint8_t, convert_op_t>([](double arg_a, uint8_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, uint16_t, convert_op_t>([](double arg_a, uint16_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, uint32_t, convert_op_t>([](double arg_a, uint32_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, uint64_t, convert_op_t>([](double arg_a, uint64_t arg_b) -> double { return static_cast<double>(arg_b); }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_binary_op<double, double, float, convert_op_t>([](double arg_a, float arg_b) -> double { return static_cast<double>(arg_b); });
            make_binary_op<double, double, double, convert_op_t>([](double arg_a, double arg_b) -> double { return static_cast<double>(arg_b); });

            make_binary_op<text_t, text_t, text_t, convert_op_t>([](const text_t& arg_a, const text_t& arg_b) -> text_t { return arg_b; });
            make_binary_op<text_t, text_t, str_ptr_t, convert_op_t>([](const text_t& arg_a, str_ptr_t arg_b) -> text_t { return text_t(arg_b ? arg_b : L""); });

            make_binary_op<array_t, array_t, array_t, convert_op_t>([](const array_t& arg_a, const array_t& arg_b) -> array_t { return arg_b; });
            make_binary_op<dict_t, dict_t, dict_t, convert_op_t>([](const dict_t& arg_a, const dict_t& arg_b) -> dict_t { return arg_b; });
            make_binary_op<name_t, name_t, name_t, convert_op_t>([](const name_t& arg_a, const name_t& arg_b) -> name_t { return arg_b; });

            make_binary_op<array_t, array_t, dict_t, convert_op_t>([](const array_t& arg_a, const dict_t& arg_b) -> array_t
            {
               array_t result;
               result.reserve(arg_b.size());
               for (const auto& key_value : arg_b)
                  result.grow() = key_value;
               return result;
            });
         }
      };

      convert_op_init_t convert_op_init;
   }

   void convert_op_t::register_ops()
   {
      // Needed so that the global operations are initialized in the tests.
      // All that is needed is to enter this file to create the globals.
   }
}
