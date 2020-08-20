// File: dak/any_convert_op.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_CONVERT_OP
#define DAK_CORE_ANY_CONVERT_OP

#include <dak/core/any_ops.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // The convert operation converts a a type to another.

   struct convert_op_t : binary_op_t<convert_op_t>
   {

      template<class A>
      static A call(const std::any& arg_b)
      {
         std::any result = binary_ops_t<convert_op_t>::call(std::make_any<A>(), arg_b);
         if (result.has_value())
            return std::any_cast<A>(result);
         else
            return A {};
      }
      template<class A, class B>
      static A call(const B& arg_b)
      {
         std::any result = binary_ops_t<convert_op_t>::call(A {}, arg_b);
         if (result.has_value())
            return std::any_cast<A>(result);
         else
            return A {};
      }

      // Note: pre-defined operations implementation are automatically registered,
      //       but these static variables do not get initialized by the testing framework.
      //       Tests need to explicitly call a function to trigger initialization.
      static void register_ops();
   };
}

#endif /* DAK_CORE_ANY_CONVERT_OP */
