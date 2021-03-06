// File: dak/core/any_to_text.h
//
// Dak Copyright � 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_TO_TEXT_OP
#define DAK_CORE_ANY_TO_TEXT_OP

#include <dak/core/any_unary_op.h>
#include <dak/core/types.h>

namespace dak_ns::core_ns
{

   //////////////////////////////////////////////////////////////////////////
   //
   // The to-text operation returns a textual representation of the type.

   struct to_text_op_t : unary_op_t<to_text_op_t>
   {
      static text_t call(const std::any& arg_a)
      {
         const std::any result = call_op(arg_a);
         if (result.has_value())
            return *std::any_cast<text_t>(&result);
         else
            return {};
      }

      template<class A>
      static text_t call(const A& arg_a)
      {
         return call(std::make_any<A>());
      }

      // Note: pre-defined operations implementation are automatically registered,
      //       but these static variables do not get initialized by the testing framework.
      //       Tests need to explicitly call a function to trigger initialization.
      static void register_ops();
   };
}

#endif /* DAK_CORE_ANY_TO_TEXT_OP */
