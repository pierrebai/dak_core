// File: dak/core/var_ops.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_VAR_OPS_H
#define DAK_CORE_VAR_OPS_H

#include <dak/core/var.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Arithmetic operators.

   // This defines the operator op= for the type basic_type.
   //
   // For example, it defines += for int32.
   //
   // It does so by extracting the value basic_type from the var_type, then applying
   // the operator, then assigning the value back to the var_type.
   //
   // This means the type then becomes the one that was given.

   #define DAK_CORE_VAR_OPERATOR(op, basic_type, var_type)              \
      inline var_type& operator op=(var_type& a, const basic_type& b)   \
      { basic_type c = a.as<basic_type>(); c op= b; a = c; return a; }

   // This defines the op= operator for integer-like types.

   #define DAK_CORE_VAR_INT_OPERATORS(op, var_type)   \
      DAK_CORE_VAR_OPERATOR(op, wchar_t, var_type)    \
      DAK_CORE_VAR_OPERATOR(op, char, var_type)       \
      DAK_CORE_VAR_OPERATOR(op, int16_t, var_type)    \
      DAK_CORE_VAR_OPERATOR(op, int32_t, var_type)    \
      DAK_CORE_VAR_OPERATOR(op, int64_t, var_type)    \
      DAK_CORE_VAR_OPERATOR(op, uint16_t, var_type)   \
      DAK_CORE_VAR_OPERATOR(op, uint32_t, var_type)   \
      DAK_CORE_VAR_OPERATOR(op, uint64_t, var_type)   \

   // This defines the op= operator for floating-point-like types.

   #define DAK_CORE_VAR_REAL_OPERATORS(op, var_type)  \
      DAK_CORE_VAR_OPERATOR(op, float, var_type)      \
      DAK_CORE_VAR_OPERATOR(op, double, var_type)     \

   // This defines the op= operator for container types.

   #define DAK_CORE_VAR_CONTAINER_OPERATORS(op, var_type)   \
      DAK_CORE_VAR_OPERATOR(op, array_t, var_type)          \
      DAK_CORE_VAR_OPERATOR(op, dict_t, var_type)

   // This defines the op= operator for the text type.

   #define DAK_CORE_VAR_TEXT_OPERATORS(op, var_type)              \
         DAK_CORE_VAR_OPERATOR(op, text_t, var_type)              \
         inline var_type& operator += (var_type& a, str_ptr_t b)  \
         { if (b) { text_t c = a.as<text_t>(); c op= b; a = c; } return a; }

   // Define the desired operators for each type.

   #define DAK_CORE_VAR_ALL_OPERATORS(var_type)    \
      DAK_CORE_VAR_INT_OPERATORS(+, var_type)      \
      DAK_CORE_VAR_INT_OPERATORS(-, var_type)      \
      DAK_CORE_VAR_INT_OPERATORS(*, var_type)      \
      DAK_CORE_VAR_INT_OPERATORS(/ , var_type)     \
      DAK_CORE_VAR_INT_OPERATORS(&, var_type)      \
      DAK_CORE_VAR_INT_OPERATORS(| , var_type)     \
      DAK_CORE_VAR_INT_OPERATORS(^, var_type)      \
      DAK_CORE_VAR_INT_OPERATORS(%, var_type)      \
      DAK_CORE_VAR_INT_OPERATORS(<< , var_type)    \
      DAK_CORE_VAR_INT_OPERATORS(>> , var_type)    \
                                                   \
      DAK_CORE_VAR_REAL_OPERATORS(+, var_type)     \
      DAK_CORE_VAR_REAL_OPERATORS(-, var_type)     \
      DAK_CORE_VAR_REAL_OPERATORS(*, var_type)     \
      DAK_CORE_VAR_REAL_OPERATORS(/ , var_type)    \
                                                   \
      DAK_CORE_VAR_TEXT_OPERATORS(+, var_type)
}

#endif /* DAK_CORE_VAR_H */
