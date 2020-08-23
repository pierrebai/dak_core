// File: dak/core/any_is_compatible_op.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_IS_COMPATIBLE_OP_H
#define DAK_CORE_ANY_IS_COMPATIBLE_OP_H

#include <dak/core/any_nullary_ops.h>

namespace dak_ns::core_ns
{

   //////////////////////////////////////////////////////////////////////////
   //
   // The is-compatible operation returns true if a the types are compatible.
   // That is, the first can be converted to the second.

   struct is_compatible_op_t : nullary_op_t<is_compatible_op_t, std::any, std::any>
   {
      template<class TO>
      static bool call(const std::any& arg_b)
      {
         const auto& ops = nullary_ops_t<is_compatible_op_t>::get_ops();
         const auto pos = ops.find(selector_t(std::type_index(typeid(TO)), std::type_index(arg_b.type())));
         if (pos == ops.end())
            return false;

         const std::any result = pos->second.my_op_func();
         if (result.has_value())
            return std::any_cast<bool>(result);
         else
            return false;
      }

      template<class TO, class FROM>
      static bool call()
      {
         const std::any result = nullary_ops_t<is_compatible_op_t>::call<TO, FROM>();
         if (result.has_value())
            return std::any_cast<bool>(result);
         else
            return false;
      }

      // Note: pre-defined operations implementation are automatically registered,
      //       but these static variables do not get initialized by the testing framework.
      //       Tests need to explicitly call a function to trigger initialization.
      static void register_ops();
   };

}

#endif /* DAK_CORE_ANY_IS_COMPATIBLE_OP_H */
