// File: dak/core/any_unary_ops.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_UNARY_OPS_H
#define DAK_CORE_ANY_UNARY_OPS_H

#include <dak/core/any_ops.h>

namespace dak_ns::core_ns
{
   // TODO: allow additional arguments to the operators.

   //////////////////////////////////////////////////////////////////////////
   //
   // Familiy of unary operations.
   //
   // To create a new unary operation family called foo:
   //
   //    Declare a class named foo deriving from unary_op_t. This class
   //    can be empty. It is only needed to identity the operation via
   //    its type. For our example:
   //
   //            struct foo : unary_op_t<foo> {};
   //
   // To implement the operation foo for type A returning RET:
   //
   //    Create an instance by calling make_unary_op<RET, A, foo>
   //    passing a function taking an A and returning a RET.
   //
   // The class hierarchy will be:
   //
   //                     unary_opt_t<foo>
   //                            |
   //                           foo
   //
   // The reasons there are two classes and a make function are:
   //
   //    1. The base class necessary to have a common type for all
   //       implementations and also to register_op and unregister_op.
   //
   //    2. The sub class is necessary as it is what identifies your
   //       unique operation. It's your operation!
   //
   //    3. The make function wraps the specific implementation for
   //       specific types and registers the implementation.
   //       It is also a convenience to automatically extract
   //       the correct types from std::any and write code without
   //       std::any.
   //
   // The family of foo operations will be registered in the unary_ops_t<foo>
   // class. (Note the plural.)
   //
   // To call an implementation corresponding to the value kept in a std::any,
   // call:
   //
   //        std::any arg = 2152671; // any value type!
   //        std::any result = ops<foo>::call(arg);
   //

   template <class OP, class... EXTRA_SELECTORS>
   struct unary_op_t
   {
      using op_func_t = std::function<std::any(const std::any& arg_a)>;
      using selector_t = typename op_selector_t<std::any, EXTRA_SELECTORS...>::selector_t;

      unary_op_t() = default;
      unary_op_t(const op_func_t& an_op) : my_op_func(an_op) {}

      op_func_t my_op_func = no_op;

      static std::any no_op(const std::any&) { return {}; }
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Container of single-argument operation implementations for various types.

   template <class OP>
   struct unary_ops_t
   {
      using selector_t = typename OP::selector_t;
      using op_t = unary_op_t<OP>;

      template <class A, class... EXTRA_SELECTORS>
      static void register_op(const op_t& an_op)
      {
         auto& ops = get_ops();
         ops[selector_t(std::type_index(typeid(A)), std::type_index(typeid(EXTRA_SELECTORS))...)] = an_op;
      }

   private:
      template <class... EXTRA_SELECTORS>
      static std::any call(const std::any& arg_a)
      {
         const auto& ops = get_ops();
         const auto pos = ops.find(selector_t(std::type_index(arg_a.type()), std::type_index(typeid(EXTRA_SELECTORS))...));
         if (pos == ops.end())
            return std::any();
         return pos->second.my_op_func(arg_a);
      }

      static std::map<selector_t, op_t>& get_ops()
      {
         static std::map<selector_t, op_t> ops;
         return ops;
      }

      friend OP;
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Creator of unary operation implementations.

   template <class OP, class RET, class A, class... EXTRA_SELECTORS>
   void make_unary_op(std::function<RET(const A& arg_a)> a_func)
   {
      unary_op_t<OP> op([a_func](const std::any& arg_a) -> std::any
      {
         return std::any(a_func(*std::any_cast<A>(&arg_a)));
      });

      unary_ops_t<OP>::register_op<A, EXTRA_SELECTORS...>(op);
   }
}

#endif /* DAK_CORE_ANY_UNARY_OPS_H */
