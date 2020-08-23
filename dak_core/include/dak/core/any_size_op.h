// File: dak/core/any_size.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_SIZE_OP
#define DAK_CORE_ANY_SIZE_OP

#include <dak/core/any_unary_op.h>
#include <dak/core/TYPES.h>

namespace dak_ns::core_ns
{

   //////////////////////////////////////////////////////////////////////////
   //
   // The size operation returns the size of a container type.
   //
   // That is, the number of elements it contains.

   struct size_op_t : unary_op_t<size_op_t>
   {
      static index_t call(const std::any& arg_a)
      {
         const std::any result = call_op(arg_a);
         if (result.has_value())
            return std::any_cast<index_t>(result);
         else
            return 0;
      }

      template<class A>
      static index_t call(const A& arg_a)
      {
         return call(std::make_any<A>());
      }

      // Note: pre-defined operations implementation are automatically registered,
      //       but these static variables do not get initialized by the testing framework.
      //       Tests need to explicitly call a function to trigger initialization.
      static void register_ops();
   };
}

#endif /* DAK_CORE_ANY_SIZE_OP */
