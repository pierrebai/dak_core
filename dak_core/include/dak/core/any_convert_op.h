// File: dak/core/any_convert_op.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_CONVERT_OP
#define DAK_CORE_ANY_CONVERT_OP

#include <dak/core/any_unary_op.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // The convert operation converts a a type to another.

   struct convert_op_t : unary_op_t<convert_op_t>
   {

      template<class TO>
      static TO call(const std::any& arg_a)
      {
         const std::any result = call_op<TO>(arg_a);
         if (result.has_value())
            return std::any_cast<TO>(result);
         else
            return TO {};
      }
      template<class TO, class FROM>
      static TO call(const FROM& arg_a)
      {
         const std::any result = call_op<TO>(arg_a);
         if (result.has_value())
            return std::any_cast<TO>(result);
         else
            return TO {};
      }

      // Note: pre-defined operations implementation are automatically registered,
      //       but these static variables do not get initialized by the testing framework.
      //       Tests need to explicitly call a function to trigger initialization.
      static void register_ops();
   };
}

#endif /* DAK_CORE_ANY_CONVERT_OP */
