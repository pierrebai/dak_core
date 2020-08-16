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
