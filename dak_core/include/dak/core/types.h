// File: dak/types.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_TYPES_H
#define DAK_CORE_TYPES_H

#include <cstdint>
#include <string>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Basic types.
   //
   // Because we favor using signed types due to the C/C++ integer promotion
   // rules, we give unsigned types memory-related names, underlining their
   // raw-memory usage instead of numerical nature.

   typedef int8_t          int8_t;
   typedef int16_t         int16_t;
   typedef int32_t         int32_t;
   typedef int64_t         int64;
   typedef uint8_t         byte_t;
   typedef uint16_t        uint16_t;
   typedef uint32_t        uint32_t;
   typedef uint64_t        uint64_t;
   typedef std::wstring    text_t;
   typedef const wchar_t*  str_ptr_t;

   // Type used as index in array.
   typedef intptr_t        index_t;


   //////////////////////////////////////////////////////////////////////////
   //
   // Comparison possible results.
   //
   // Note: incomparable should result in operator== returning false,
   //       operator!= returning true, and all relative operators
   //       (<, >, <=, >=) returning false.

   enum class comparison_t : int8_t
   {
      incomparable = 0,
      equal = 1,
      less = 2,
      more = 4,
      less_or_equal = less | equal,
      more_or_equal = more | equal,
   };

   inline bool is(const comparison_t result, const comparison_t desired)
   {
      return 0 != (uint8_t(result) & uint8_t(desired));
   }

   //////////////////////////////////////////////////////////////////////////
   //
   // Forward declare some types defined elesewhere.

   struct array_t;
   struct object_t;
   struct dict_t;
   struct ref_counted_t;
   struct var_t;
   struct no_copy_t;
   struct ref_base_t;
   template<class T> struct ref_t;
}

#endif /* DAK_CORE_TYPES_H */
