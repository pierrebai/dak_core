// File: dak/any_compare_op.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_COMPARE_OP
#define DAK_CORE_ANY_COMPARE_OP

#include <dak/core/any_ops.h>

namespace dak_ns::core_ns
{

   //////////////////////////////////////////////////////////////////////////
   //
   // The compare operation writes the value to an output compare.
   //
   // Note: the compare is received by pointer to travel in a std::any.

   struct compare_op_t : binary_op_t<compare_op_t>
   {
      static int32_t call(const std::any& arg_a, const std::any& arg_b)
      {
         if (!arg_a.has_value())
         {
            return !arg_b.has_value() ? 0 : -1;
         }
         else if (!arg_b.has_value())
         {
            return 1;
         }

         const std::any result = binary_ops_t<compare_op_t>::call(arg_a, arg_b);
         if (result.has_value())
            return std::any_cast<int32_t>(result);
         else
            return 1; // TODO: maybe should throw?
      }

      template<class A>
      static int32_t call(const A& arg_a, const A& arg_b)
      {
         return compare_op_t::call(std::make_any(arg_a), std::make_any(arg_b));
      }

      // Note: pre-defined operations implementation are automatically registered,
      //       but these static variables do not get initialized by the testing framework.
      //       Tests need to explicitly call a function to trigger initialization.
      static void register_ops();
   };

   
}

#endif /* DAK_CORE_ANY_COMPARE_OP */
