// File: any_convert_op.cpp
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
            make_unary_op<int8_t, bool,     convert_op_t, int8_t>([](bool arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, char,     convert_op_t, int8_t>([](char arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, wchar_t,  convert_op_t, int8_t>([](wchar_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, int8_t,   convert_op_t, int8_t>([](int8_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, int16_t,  convert_op_t, int8_t>([](int16_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, int32_t,  convert_op_t, int8_t>([](int32_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, int64_t,  convert_op_t, int8_t>([](int64_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, uint8_t,  convert_op_t, int8_t>([](uint8_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, uint16_t, convert_op_t, int8_t>([](uint16_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, uint32_t, convert_op_t, int8_t>([](uint32_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, uint64_t, convert_op_t, int8_t>([](uint64_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, float,    convert_op_t, int8_t>([](float arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            make_unary_op<int8_t, double,   convert_op_t, int8_t>([](double arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });

            make_unary_op<uint8_t, bool,     convert_op_t, uint8_t>([](bool arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, char,     convert_op_t, uint8_t>([](char arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, wchar_t,  convert_op_t, uint8_t>([](wchar_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, int8_t,   convert_op_t, uint8_t>([](int8_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, int16_t,  convert_op_t, uint8_t>([](int16_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, int32_t,  convert_op_t, uint8_t>([](int32_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, int64_t,  convert_op_t, uint8_t>([](int64_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, uint8_t,  convert_op_t, uint8_t>([](uint8_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, uint16_t, convert_op_t, uint8_t>([](uint16_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, uint32_t, convert_op_t, uint8_t>([](uint32_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, uint64_t, convert_op_t, uint8_t>([](uint64_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, float,    convert_op_t, uint8_t>([](float arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            make_unary_op<uint8_t, double,   convert_op_t, uint8_t>([](double arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });

            make_unary_op<int16_t, bool,     convert_op_t, int16_t>([](bool arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, char,     convert_op_t, int16_t>([](char arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, wchar_t,  convert_op_t, int16_t>([](wchar_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, int8_t,   convert_op_t, int16_t>([](int8_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, int16_t,  convert_op_t, int16_t>([](int16_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, int32_t,  convert_op_t, int16_t>([](int32_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, int64_t,  convert_op_t, int16_t>([](int64_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, uint8_t,  convert_op_t, int16_t>([](uint8_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, uint16_t, convert_op_t, int16_t>([](uint16_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, uint32_t, convert_op_t, int16_t>([](uint32_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, uint64_t, convert_op_t, int16_t>([](uint64_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, float,    convert_op_t, int16_t>([](float arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            make_unary_op<int16_t, double,   convert_op_t, int16_t>([](double arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });

            make_unary_op<uint16_t, bool,     convert_op_t, uint16_t>([](bool arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, char,     convert_op_t, uint16_t>([](char arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, wchar_t,  convert_op_t, uint16_t>([](wchar_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, int8_t,   convert_op_t, uint16_t>([](int8_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, int16_t,  convert_op_t, uint16_t>([](int16_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, int32_t,  convert_op_t, uint16_t>([](int32_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, int64_t,  convert_op_t, uint16_t>([](int64_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, uint8_t,  convert_op_t, uint16_t>([](uint8_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, uint16_t, convert_op_t, uint16_t>([](uint16_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, uint32_t, convert_op_t, uint16_t>([](uint32_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, uint64_t, convert_op_t, uint16_t>([](uint64_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, float,    convert_op_t, uint16_t>([](float arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            make_unary_op<uint16_t, double,   convert_op_t, uint16_t>([](double arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });

            make_unary_op<int32_t, bool,     convert_op_t, int32_t>([](bool arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, char,     convert_op_t, int32_t>([](char arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, wchar_t,  convert_op_t, int32_t>([](wchar_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, int8_t,   convert_op_t, int32_t>([](int8_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, int16_t,  convert_op_t, int32_t>([](int16_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, int32_t,  convert_op_t, int32_t>([](int32_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, int64_t,  convert_op_t, int32_t>([](int64_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, uint8_t,  convert_op_t, int32_t>([](uint8_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, uint16_t, convert_op_t, int32_t>([](uint16_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, uint32_t, convert_op_t, int32_t>([](uint32_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, uint64_t, convert_op_t, int32_t>([](uint64_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, float,    convert_op_t, int32_t>([](float arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            make_unary_op<int32_t, double,   convert_op_t, int32_t>([](double arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });

            make_unary_op<uint32_t, bool,     convert_op_t, uint32_t>([](bool arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, char,     convert_op_t, uint32_t>([](char arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, wchar_t,  convert_op_t, uint32_t>([](wchar_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, int8_t,   convert_op_t, uint32_t>([](int8_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, int16_t,  convert_op_t, uint32_t>([](int16_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, int32_t,  convert_op_t, uint32_t>([](int32_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, int64_t,  convert_op_t, uint32_t>([](int64_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, uint8_t,  convert_op_t, uint32_t>([](uint8_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, uint16_t, convert_op_t, uint32_t>([](uint16_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, uint32_t, convert_op_t, uint32_t>([](uint32_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, uint64_t, convert_op_t, uint32_t>([](uint64_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, float,    convert_op_t, uint32_t>([](float arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            make_unary_op<uint32_t, double,   convert_op_t, uint32_t>([](double arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });

            make_unary_op<int64_t, bool,     convert_op_t, int64_t>([](bool arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, char,     convert_op_t, int64_t>([](char arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, wchar_t,  convert_op_t, int64_t>([](wchar_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, int8_t,   convert_op_t, int64_t>([](int8_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, int16_t,  convert_op_t, int64_t>([](int16_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, int32_t,  convert_op_t, int64_t>([](int32_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, int64_t,  convert_op_t, int64_t>([](int64_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, uint8_t,  convert_op_t, int64_t>([](uint8_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, uint16_t, convert_op_t, int64_t>([](uint16_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, uint32_t, convert_op_t, int64_t>([](uint32_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, uint64_t, convert_op_t, int64_t>([](uint64_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, float,    convert_op_t, int64_t>([](float arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            make_unary_op<int64_t, double,   convert_op_t, int64_t>([](double arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });

            make_unary_op<uint64_t, bool,     convert_op_t, uint64_t>([](bool arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, char,     convert_op_t, uint64_t>([](char arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, wchar_t,  convert_op_t, uint64_t>([](wchar_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, int8_t,   convert_op_t, uint64_t>([](int8_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, int16_t,  convert_op_t, uint64_t>([](int16_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, int32_t,  convert_op_t, uint64_t>([](int32_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, int64_t,  convert_op_t, uint64_t>([](int64_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, uint8_t,  convert_op_t, uint64_t>([](uint8_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, uint16_t, convert_op_t, uint64_t>([](uint16_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, uint32_t, convert_op_t, uint64_t>([](uint32_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, uint64_t, convert_op_t, uint64_t>([](uint64_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, float,    convert_op_t, uint64_t>([](float arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            make_unary_op<uint64_t, double,   convert_op_t, uint64_t>([](double arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });

            make_unary_op<bool, bool,     convert_op_t, bool>([](bool arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, char,     convert_op_t, bool>([](char arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, wchar_t,  convert_op_t, bool>([](wchar_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, int8_t,   convert_op_t, bool>([](int8_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, int16_t,  convert_op_t, bool>([](int16_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, int32_t,  convert_op_t, bool>([](int32_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, int64_t,  convert_op_t, bool>([](int64_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, uint8_t,  convert_op_t, bool>([](uint8_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, uint16_t, convert_op_t, bool>([](uint16_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, uint32_t, convert_op_t, bool>([](uint32_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, uint64_t, convert_op_t, bool>([](uint64_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, float,    convert_op_t, bool>([](float arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, double,   convert_op_t, bool>([](double arg_b) -> bool { return static_cast<bool>(arg_b); });
            make_unary_op<bool, name_t,   convert_op_t, bool>([](name_t arg_b) -> bool { return arg_b.is_valid(); });
            make_unary_op<bool, text_t,   convert_op_t, bool>([](text_t arg_b) -> bool { return static_cast<bool>(arg_b.size()); });
            make_unary_op<bool, array_t,  convert_op_t, bool>([](array_t arg_b) -> bool { return static_cast<bool>(arg_b.size()); });
            make_unary_op<bool, dict_t,   convert_op_t, bool>([](dict_t arg_b) -> bool { return static_cast<bool>(arg_b.size()); });

            make_unary_op<float, bool,      convert_op_t, float>([](bool arg_b) -> float { return static_cast<float>(arg_b); });
            make_unary_op<float, char,      convert_op_t, float>([](char arg_b) -> float { return static_cast<float>(arg_b); });
            make_unary_op<float, wchar_t,   convert_op_t, float>([](wchar_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_unary_op<float, int8_t,    convert_op_t, float>([](int8_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_unary_op<float, int16_t,   convert_op_t, float>([](int16_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_unary_op<float, int32_t,   convert_op_t, float>([](int32_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_unary_op<float, int64_t,   convert_op_t, float>([](int64_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_unary_op<float, uint8_t,   convert_op_t, float>([](uint8_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_unary_op<float, uint16_t,  convert_op_t, float>([](uint16_t arg_b) -> float { return static_cast<float>(arg_b); });
            make_unary_op<float, uint32_t,  convert_op_t, float>([](uint32_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a bit since float only have 23-bit mantissa...
            make_unary_op<float, uint64_t,  convert_op_t, float>([](uint64_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a lot since float only have 23-bit mantissa...
            make_unary_op<float, float,     convert_op_t, float>([](float arg_b) -> float { return static_cast<float>(arg_b); });
            make_unary_op<float, double,    convert_op_t, float>([](double arg_b) -> float { return static_cast<float>(arg_b); });

            make_unary_op<double, bool,      convert_op_t, double>([](bool arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, char,      convert_op_t, double>([](char arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, wchar_t,   convert_op_t, double>([](wchar_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, int8_t,    convert_op_t, double>([](int8_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, int16_t,   convert_op_t, double>([](int16_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, int32_t,   convert_op_t, double>([](int32_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, int64_t,   convert_op_t, double>([](int64_t arg_b) -> double { return static_cast<double>(arg_b); }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_unary_op<double, uint8_t,   convert_op_t, double>([](uint8_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, uint16_t,  convert_op_t, double>([](uint16_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, uint32_t,  convert_op_t, double>([](uint32_t arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, uint64_t,  convert_op_t, double>([](uint64_t arg_b) -> double { return static_cast<double>(arg_b); }); // Note: cheating a bit since double only have 52-bit mantissa...
            make_unary_op<double, float,     convert_op_t, double>([](float arg_b) -> double { return static_cast<double>(arg_b); });
            make_unary_op<double, double,    convert_op_t, double>([](double arg_b) -> double { return static_cast<double>(arg_b); });

            make_unary_op<text_t, text_t,    convert_op_t, text_t>([](const text_t& arg_b) -> text_t { return arg_b; });
            make_unary_op<text_t, str_ptr_t, convert_op_t, text_t>([](str_ptr_t arg_b) -> text_t { return text_t(arg_b ? arg_b : L""); });

            make_unary_op<array_t, array_t, convert_op_t, array_t>([](const array_t& arg_b) -> array_t { return arg_b; });
            make_unary_op<dict_t,  dict_t,  convert_op_t, dict_t >([](const dict_t& arg_b) -> dict_t { return arg_b; });
            make_unary_op<name_t,  name_t,  convert_op_t, name_t >([](const name_t& arg_b) -> name_t { return arg_b; });

            make_unary_op<array_t, dict_t, convert_op_t, array_t>([](const dict_t& arg_b) -> array_t
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
