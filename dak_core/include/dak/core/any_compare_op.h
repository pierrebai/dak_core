// File: dak/core/any_compare_op.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_COMPARE_OP
#define DAK_CORE_ANY_COMPARE_OP

#include <dak/core/any_binary_op.h>
#include <dak/core/types.h>

#include <any>

namespace dak_ns::core_ns
{

   //////////////////////////////////////////////////////////////////////////
   //
   // The compare operation compares two values.
   // 
   // Note: returns comparison_t::incomparable if two values cannot be compared.

   struct compare_op_t : binary_op_t<compare_op_t>
   {
      constexpr static comparison_t equal = comparison_t::equal;
      constexpr static comparison_t less = comparison_t::less;
      constexpr static comparison_t more = comparison_t::more;
      constexpr static comparison_t incomparable = comparison_t::incomparable;

      static comparison_t call(const std::any& arg_a, const std::any& arg_b)
      {
         if (!arg_a.has_value())
         {
            return !arg_b.has_value() ? equal : less;
         }
         else if (!arg_b.has_value())
         {
            return more;
         }

         const std::any result = binary_op_t<compare_op_t>::call(arg_a, arg_b);
         if (result.has_value())
            return std::any_cast<comparison_t>(result);

         return incomparable;
      }

      template<class A>
      static comparison_t call(const A& arg_a, const A& arg_b)
      {
         return compare_op_t::call(std::make_any(arg_a), std::make_any(arg_b));
      }

      // Note: pre-defined operations implementation are automatically registered,
      //       but these static variables do not get initialized by the testing framework.
      //       Tests need to explicitly call a function to trigger initialization.
      static void register_ops();
   };


   //////////////////////////////////////////////////////////////////////////
   //
   // Comparison C++ operators.

   inline bool operator==(const std::any& arg_a, const std::any& arg_b)
   {
      return compare_op_t::call(arg_a, arg_b) == compare_op_t::equal;
   }

   inline bool operator<(const std::any& arg_a, const std::any& arg_b)
   {
      return compare_op_t::call(arg_a, arg_b) == compare_op_t::less;
   }

   inline bool operator>(const std::any& arg_a, const std::any& arg_b)
   {
      return compare_op_t::call(arg_a, arg_b) == compare_op_t::more;
   }

   inline bool operator!=(const std::any& arg_a, const std::any& arg_b)
   {
      return compare_op_t::call(arg_a, arg_b) != compare_op_t::equal;
   }

   inline bool operator<=(const std::any& arg_a, const std::any& arg_b)
   {
      return is(compare_op_t::call(arg_a, arg_b), comparison_t::less_or_equal);
   }

   inline bool operator>=(const std::any& arg_a, const std::any& arg_b)
   {
      return is(compare_op_t::call(arg_a, arg_b), comparison_t::more_or_equal);
   }
}

#endif /* DAK_CORE_ANY_COMPARE_OP */
