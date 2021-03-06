// File: any_convert_op.cpp
//
// Dak Copyright � 2012-2020. All Rights Reserved.

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
            unary_op_t<convert_op_t>::make_op<int8_t, bool,     int8_t>([](bool arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, char,     int8_t>([](char arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, wchar_t,  int8_t>([](wchar_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, int8_t,   int8_t>([](int8_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, int16_t,  int8_t>([](int16_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, int32_t,  int8_t>([](int32_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, int64_t,  int8_t>([](int64_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, uint8_t,  int8_t>([](uint8_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, uint16_t, int8_t>([](uint16_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, uint32_t, int8_t>([](uint32_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, uint64_t, int8_t>([](uint64_t arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, float,    int8_t>([](float arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int8_t, double,   int8_t>([](double arg_b) -> int8_t { return static_cast<int8_t>(arg_b); });

            unary_op_t<convert_op_t>::make_op<uint8_t, bool,     uint8_t>([](bool arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, char,     uint8_t>([](char arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, wchar_t,  uint8_t>([](wchar_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, int8_t,   uint8_t>([](int8_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, int16_t,  uint8_t>([](int16_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, int32_t,  uint8_t>([](int32_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, int64_t,  uint8_t>([](int64_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, uint8_t,  uint8_t>([](uint8_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, uint16_t, uint8_t>([](uint16_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, uint32_t, uint8_t>([](uint32_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, uint64_t, uint8_t>([](uint64_t arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, float,    uint8_t>([](float arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint8_t, double,   uint8_t>([](double arg_b) -> uint8_t { return static_cast<uint8_t>(arg_b); });

            unary_op_t<convert_op_t>::make_op<int16_t, bool,     int16_t>([](bool arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, char,     int16_t>([](char arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, wchar_t,  int16_t>([](wchar_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, int8_t,   int16_t>([](int8_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, int16_t,  int16_t>([](int16_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, int32_t,  int16_t>([](int32_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, int64_t,  int16_t>([](int64_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, uint8_t,  int16_t>([](uint8_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, uint16_t, int16_t>([](uint16_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, uint32_t, int16_t>([](uint32_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, uint64_t, int16_t>([](uint64_t arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, float,    int16_t>([](float arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int16_t, double,   int16_t>([](double arg_b) -> int16_t { return static_cast<int16_t>(arg_b); });

            unary_op_t<convert_op_t>::make_op<uint16_t, bool,     uint16_t>([](bool arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, char,     uint16_t>([](char arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, wchar_t,  uint16_t>([](wchar_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, int8_t,   uint16_t>([](int8_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, int16_t,  uint16_t>([](int16_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, int32_t,  uint16_t>([](int32_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, int64_t,  uint16_t>([](int64_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, uint8_t,  uint16_t>([](uint8_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, uint16_t, uint16_t>([](uint16_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, uint32_t, uint16_t>([](uint32_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, uint64_t, uint16_t>([](uint64_t arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, float,    uint16_t>([](float arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint16_t, double,   uint16_t>([](double arg_b) -> uint16_t { return static_cast<uint16_t>(arg_b); });

            unary_op_t<convert_op_t>::make_op<int32_t, bool,     int32_t>([](bool arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, char,     int32_t>([](char arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, wchar_t,  int32_t>([](wchar_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, int8_t,   int32_t>([](int8_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, int16_t,  int32_t>([](int16_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, int32_t,  int32_t>([](int32_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, int64_t,  int32_t>([](int64_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, uint8_t,  int32_t>([](uint8_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, uint16_t, int32_t>([](uint16_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, uint32_t, int32_t>([](uint32_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, uint64_t, int32_t>([](uint64_t arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, float,    int32_t>([](float arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int32_t, double,   int32_t>([](double arg_b) -> int32_t { return static_cast<int32_t>(arg_b); });

            unary_op_t<convert_op_t>::make_op<uint32_t, bool,     uint32_t>([](bool arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, char,     uint32_t>([](char arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, wchar_t,  uint32_t>([](wchar_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, int8_t,   uint32_t>([](int8_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, int16_t,  uint32_t>([](int16_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, int32_t,  uint32_t>([](int32_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, int64_t,  uint32_t>([](int64_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, uint8_t,  uint32_t>([](uint8_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, uint16_t, uint32_t>([](uint16_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, uint32_t, uint32_t>([](uint32_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, uint64_t, uint32_t>([](uint64_t arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, float,    uint32_t>([](float arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint32_t, double,   uint32_t>([](double arg_b) -> uint32_t { return static_cast<uint32_t>(arg_b); });

            unary_op_t<convert_op_t>::make_op<int64_t, bool,     int64_t>([](bool arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, char,     int64_t>([](char arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, wchar_t,  int64_t>([](wchar_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, int8_t,   int64_t>([](int8_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, int16_t,  int64_t>([](int16_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, int32_t,  int64_t>([](int32_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, int64_t,  int64_t>([](int64_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, uint8_t,  int64_t>([](uint8_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, uint16_t, int64_t>([](uint16_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, uint32_t, int64_t>([](uint32_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, uint64_t, int64_t>([](uint64_t arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, float,    int64_t>([](float arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<int64_t, double,   int64_t>([](double arg_b) -> int64_t { return static_cast<int64_t>(arg_b); });

            unary_op_t<convert_op_t>::make_op<uint64_t, bool,     uint64_t>([](bool arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, char,     uint64_t>([](char arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, wchar_t,  uint64_t>([](wchar_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, int8_t,   uint64_t>([](int8_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, int16_t,  uint64_t>([](int16_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, int32_t,  uint64_t>([](int32_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, int64_t,  uint64_t>([](int64_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, uint8_t,  uint64_t>([](uint8_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, uint16_t, uint64_t>([](uint16_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, uint32_t, uint64_t>([](uint32_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, uint64_t, uint64_t>([](uint64_t arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, float,    uint64_t>([](float arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });
            unary_op_t<convert_op_t>::make_op<uint64_t, double,   uint64_t>([](double arg_b) -> uint64_t { return static_cast<uint64_t>(arg_b); });

            unary_op_t<convert_op_t>::make_op<bool, bool,     bool>([](bool arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, char,     bool>([](char arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, wchar_t,  bool>([](wchar_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, int8_t,   bool>([](int8_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, int16_t,  bool>([](int16_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, int32_t,  bool>([](int32_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, int64_t,  bool>([](int64_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, uint8_t,  bool>([](uint8_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, uint16_t, bool>([](uint16_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, uint32_t, bool>([](uint32_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, uint64_t, bool>([](uint64_t arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, float,    bool>([](float arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, double,   bool>([](double arg_b) -> bool { return static_cast<bool>(arg_b); });
            unary_op_t<convert_op_t>::make_op<bool, name_t,   bool>([](name_t arg_b) -> bool { return arg_b.is_valid(); });
            unary_op_t<convert_op_t>::make_op<bool, text_t,   bool>([](const text_t& arg_b) -> bool { return static_cast<bool>(arg_b.size()); });
            unary_op_t<convert_op_t>::make_op<bool, array_t,  bool>([](const array_t& arg_b) -> bool { return static_cast<bool>(arg_b.size()); });
            unary_op_t<convert_op_t>::make_op<bool, dict_t,   bool>([](const dict_t& arg_b) -> bool { return static_cast<bool>(arg_b.size()); });

            unary_op_t<convert_op_t>::make_op<float, bool,      float>([](bool arg_b) -> float { return static_cast<float>(arg_b); });
            unary_op_t<convert_op_t>::make_op<float, char,      float>([](char arg_b) -> float { return static_cast<float>(arg_b); });
            unary_op_t<convert_op_t>::make_op<float, wchar_t,   float>([](wchar_t arg_b) -> float { return static_cast<float>(arg_b); });
            unary_op_t<convert_op_t>::make_op<float, int8_t,    float>([](int8_t arg_b) -> float { return static_cast<float>(arg_b); });
            unary_op_t<convert_op_t>::make_op<float, int16_t,   float>([](int16_t arg_b) -> float { return static_cast<float>(arg_b); });
            unary_op_t<convert_op_t>::make_op<float, int32_t,   float>([](int32_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a bit since float only have 23-bit mantissa...
            unary_op_t<convert_op_t>::make_op<float, int64_t,   float>([](int64_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a lot since float only have 23-bit mantissa...
            unary_op_t<convert_op_t>::make_op<float, uint8_t,   float>([](uint8_t arg_b) -> float { return static_cast<float>(arg_b); });
            unary_op_t<convert_op_t>::make_op<float, uint16_t,  float>([](uint16_t arg_b) -> float { return static_cast<float>(arg_b); });
            unary_op_t<convert_op_t>::make_op<float, uint32_t,  float>([](uint32_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a bit since float only have 23-bit mantissa...
            unary_op_t<convert_op_t>::make_op<float, uint64_t,  float>([](uint64_t arg_b) -> float { return static_cast<float>(arg_b); }); // Note: cheating a lot since float only have 23-bit mantissa...
            unary_op_t<convert_op_t>::make_op<float, float,     float>([](float arg_b) -> float { return static_cast<float>(arg_b); });
            unary_op_t<convert_op_t>::make_op<float, double,    float>([](double arg_b) -> float { return static_cast<float>(arg_b); });

            unary_op_t<convert_op_t>::make_op<double, bool,      double>([](bool arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, char,      double>([](char arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, wchar_t,   double>([](wchar_t arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, int8_t,    double>([](int8_t arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, int16_t,   double>([](int16_t arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, int32_t,   double>([](int32_t arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, int64_t,   double>([](int64_t arg_b) -> double { return static_cast<double>(arg_b); }); // Note: cheating a bit since double only have 52-bit mantissa...
            unary_op_t<convert_op_t>::make_op<double, uint8_t,   double>([](uint8_t arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, uint16_t,  double>([](uint16_t arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, uint32_t,  double>([](uint32_t arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, uint64_t,  double>([](uint64_t arg_b) -> double { return static_cast<double>(arg_b); }); // Note: cheating a bit since double only have 52-bit mantissa...
            unary_op_t<convert_op_t>::make_op<double, float,     double>([](float arg_b) -> double { return static_cast<double>(arg_b); });
            unary_op_t<convert_op_t>::make_op<double, double,    double>([](double arg_b) -> double { return static_cast<double>(arg_b); });

            unary_op_t<convert_op_t>::make_op<text_t, text_t,    text_t>([](const text_t& arg_b) -> text_t { return arg_b; });
            unary_op_t<convert_op_t>::make_op<text_t, str_ptr_t, text_t>([](str_ptr_t arg_b) -> text_t { return text_t(arg_b ? arg_b : L""); });

            unary_op_t<convert_op_t>::make_op<array_t, array_t, array_t>([](const array_t& arg_b) -> array_t { return arg_b; });
            unary_op_t<convert_op_t>::make_op<dict_t,  dict_t,  dict_t >([](const dict_t& arg_b) -> dict_t { return arg_b; });
            unary_op_t<convert_op_t>::make_op<name_t,  name_t,  name_t >([](const name_t& arg_b) -> name_t { return arg_b; });

            unary_op_t<convert_op_t>::make_op<array_t, dict_t, array_t>([](const dict_t& arg_b) -> array_t
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
