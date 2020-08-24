// File: dak/core/any_dominant_op.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_DOMINANT_OP
#define DAK_CORE_ANY_DOMINANT_OP

#include <dak/core/any_unary_op.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // The dominant operation convert a value to the most doiminant type
   // between two type. For an easy example, between int8_t and int32_t
   // int32_t is the dominant type.
   //
   // It is basically the automatic conversion rules of C++.
   //
   // We will define only those case where the value is converted.
   // If the value would be the same, the operation will not be defined
   // and this absence will mean the leave the value as-is.

   struct dominant_op_t : unary_op_t<dominant_op_t>
   {

      template<class OTHER>
      static std::any call(const std::any& arg_a)
      {
         const std::any result = call_op<OTHER>(arg_a);
         if (result.has_value())
            return result;
         else
            return arg_a;
      }

      template<class OTHER, class FROM>
      static std::any call(const FROM& arg_a)
      {
         return call<OTHER>(std::any(arg_a));
      }

      // Note: pre-defined operations implementation are automatically registered,
      //       but these static variables do not get initialized by the testing framework.
      //       Tests need to explicitly call a function to trigger initialization.
      static void register_ops();
   };
}

#endif /* DAK_CORE_ANY_DOMINANT_OP */
