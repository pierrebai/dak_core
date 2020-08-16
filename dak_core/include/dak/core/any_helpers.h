// File: dak/any_helpers.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_HELPERS_H
#define DAK_CORE_ANY_HELPERS_H

#include <dak/core/types.h>

#include <any>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Template that returns true if the types are compatible.

   template <class TO, class FROM>
   struct is_compatible { constexpr bool operator()() const { return false; } };

   template<class T> struct is_compatible<T,T> { constexpr bool operator()() const { return true; } };

   //////////////////////////////////////////////////////////////////////////
   //
   // Define our specialization for types we consider compatible.

   #define DAK_CORE_ANY_IS_COMPATIBLE(to, from) template <> struct is_compatible<to, from> { constexpr bool operator()() const { return true; } }

   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, char);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, int32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, int64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, uint32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, uint64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, float);
   DAK_CORE_ANY_IS_COMPATIBLE(int8_t, double);

   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, char);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, int32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, int64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, uint32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, uint64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, float);
   DAK_CORE_ANY_IS_COMPATIBLE(uint8_t, double);

   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, char);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, int32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, int64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, uint32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, uint64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, float);
   DAK_CORE_ANY_IS_COMPATIBLE(int16_t, double);

   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, char);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, int32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, int64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, uint32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, uint64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, float);
   DAK_CORE_ANY_IS_COMPATIBLE(uint16_t, double);

   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, char);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, int64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, uint32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, uint64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, float);
   DAK_CORE_ANY_IS_COMPATIBLE(int32_t, double);

   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, char);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, int32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, int64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, uint64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, float);
   DAK_CORE_ANY_IS_COMPATIBLE(uint32_t, double);

   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, char);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, int32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, uint32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, uint64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, float);
   DAK_CORE_ANY_IS_COMPATIBLE(int64_t, double);

   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, char);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, int32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, int64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, uint32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, float);
   DAK_CORE_ANY_IS_COMPATIBLE(uint64_t, double);

   DAK_CORE_ANY_IS_COMPATIBLE(bool, char);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, int32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, int64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, uint32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, uint64_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, name_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, float);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, double);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, text_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, array_t);
   DAK_CORE_ANY_IS_COMPATIBLE(bool, dict_t);

   DAK_CORE_ANY_IS_COMPATIBLE(float, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(float, char);
   DAK_CORE_ANY_IS_COMPATIBLE(float, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(float, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(float, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(float, int32_t); // Note: cheating a bit since float only have 23-bit mantissa...
   DAK_CORE_ANY_IS_COMPATIBLE(float, int64_t); // Note: cheating a lot since float only have 23-bit mantissa...
   DAK_CORE_ANY_IS_COMPATIBLE(float, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(float, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(float, uint32_t); // Note: cheating a bit since float only have 23-bit mantissa...
   DAK_CORE_ANY_IS_COMPATIBLE(float, uint64_t); // Note: cheating a lot since float only have 23-bit mantissa...

   DAK_CORE_ANY_IS_COMPATIBLE(double, bool);
   DAK_CORE_ANY_IS_COMPATIBLE(double, char);
   DAK_CORE_ANY_IS_COMPATIBLE(double, wchar_t);
   DAK_CORE_ANY_IS_COMPATIBLE(double, int8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(double, int16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(double, int32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(double, int64_t); // Note: cheating a bit since double only have 52-bit mantissa...
   DAK_CORE_ANY_IS_COMPATIBLE(double, uint8_t);
   DAK_CORE_ANY_IS_COMPATIBLE(double, uint16_t);
   DAK_CORE_ANY_IS_COMPATIBLE(double, uint32_t);
   DAK_CORE_ANY_IS_COMPATIBLE(double, uint64_t); // Note: cheating a bit since double only have 52-bit mantissa...
   DAK_CORE_ANY_IS_COMPATIBLE(double, float);
   DAK_CORE_ANY_IS_COMPATIBLE(double, double);

   //////////////////////////////////////////////////////////////////////////
   //
   // Template to apply a templated operation if the types are compatible.
   //
   // Thanks to constexpr, invalid combinations are rejected at compile time.

   #define DAK_CORE_APPLY_OP_IF_COMPATIBLE(to, from, op) \
      if constexpr (is_compatible<to, from>()()) \
      { \
         if (const from* f = std::any_cast<from>(&an_any)) \
         { \
            return op<to, from>()(*f); \
         } \
      }

   template <class RET, class TO, template<class TO, class FROM> class OP>
   struct apply_compatible_op
   {
      using clean_TO = std::remove_cv_t<std::remove_reference_t<TO>>;

      RET operator()(const std::any& an_any) const
      {
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, clean_TO, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, int32_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, int64_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, float, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, double, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, text_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, array_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, dict_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, name_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, uint32_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, uint64_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, bool, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, char, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, wchar_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, int8_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, uint8_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, int16_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, uint16_t, OP)
         return RET {};
      }

      RET operator()(std::any& an_any) const
      {
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, clean_TO, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, int32_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, int64_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, float, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, double, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, text_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, array_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, dict_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, name_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, bool, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, char, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, wchar_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, int8_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, uint8_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, int16_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, uint16_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, uint32_t, OP)
         DAK_CORE_APPLY_OP_IF_COMPATIBLE(clean_TO, uint64_t, OP)
         return RET {};
      }
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Template that applies a templated operation if the types match exactly.
   //
   // Thanks to constexpr, invalid combinations are rejected at compile time.

   #define DAK_CORE_APPLY_OP_IF_EXACT(from, op) \
      if (const from* f = std::any_cast<from>(&an_any)) \
      { \
         return op<from>()(*f); \
      }

   template <class RET, template<class FROM> class OP>
   struct apply_exact_op
   {
      RET operator()(const std::any& an_any)
      {
         DAK_CORE_APPLY_OP_IF_EXACT(int32_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(uint32_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(int64_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(uint64_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(float, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(double, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(text_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(array_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(dict_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(bool, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(char, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(wchar_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(int8_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(uint8_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(int16_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(uint16_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(name_t, OP)
         return RET {};
      }

      template <class RET, template<class FROM> class OP>
      RET operator()(std::any& an_any)
      {
         DAK_CORE_APPLY_OP_IF_EXACT(int32_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(uint32_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(int64_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(uint64_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(float, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(double, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(text_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(array_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(dict_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(bool, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(char, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(wchar_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(int8_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(uint8_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(int16_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(uint16_t, OP)
         DAK_CORE_APPLY_OP_IF_EXACT(name_t, OP)
         return RET {};
      }
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Template to convert a std::any to a target type if compatible.

   template <class TO, class FROM>
   struct convert_any_op
   {
      TO operator()(const FROM& from) const
      {
         return static_cast<TO>(from);
      }
   };

   template <>
   struct convert_any_op<bool, text_t>
   {
      bool operator()(const text_t& from) const
      {
         return from.size() > 0;
      }
   };

   template <class TO>
   TO convert_any(const std::any& an_any)
   {
      return apply_compatible_op<TO, TO, convert_any_op>()(an_any);
   }

   //////////////////////////////////////////////////////////////////////////
   //
   // Template to verify that a std::any is compatible with a type.

   template <class TO, class FROM>
   struct compatible_any_op
   {
      bool constexpr operator()(const FROM&) const
      {
         return true;
      }
   };

   template <class TO>
   bool compatible_any(const std::any& an_any)
   {
      return apply_compatible_op<bool, TO, compatible_any_op>()(an_any);
   }
}

#endif /* DAK_CORE_ANY_HELPERS_H */
