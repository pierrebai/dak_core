// File: dak/core/any_binary_op.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_BINARY_OP_H
#define DAK_CORE_ANY_BINARY_OP_H

#include <dak/core/any_op_selector.h>

#include <any>
#include <functional>
#include <map>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Familiy of binary operations.
   //
   // To create a new binary operation family called foo:
   //
   //    Declare a class named foo deriving from binary_op_t. This class
   //    can be empty. It is only needed to identity the operation via
   //    its type. For our example:
   //
   //            struct foo : binary_op_t<foo> {};
   //
   // To implement the operation foo for type A returning RET:
   //
   //    Create an instance by calling make_binary_op<RET, A, B, foo>
   //    passing a function taking an A and a B and returning a RET.
   //
   // The class hierarchy will be:
   //
   //                     binary_opt_t<foo>
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
   //       specific types then registers the implementation.
   //       It is also a convenience to automatically extract
   //       the correct types from std::any and write code without
   //       std::any.
   //
   // The family of foo operations will be registered in the binary_ops_t<foo>
   // class. (Note the plural.)
   //
   // To call an implementation corresponding to the value kept in a std::any,
   // call:
   //
   //        std::any arg_a = 2152671; // any value type!
   //        std::any arg_b = "hello"; // any value type!
   //        std::any result = bianry_ops_t<foo>::call(arg_a, arg_b);
   //

   template <class OP, class... EXTRA_ARGS>
   struct binary_op_t
   {
      using op_func_t = std::function<std::any(EXTRA_ARGS ..., const std::any& arg_a, const std::any& arg_b)>;
      using op_base_t = binary_op_t<OP, EXTRA_ARGS...>;

      binary_op_t() = default;
      binary_op_t(const op_func_t& an_op) : my_op_func(an_op) {}

      op_func_t my_op_func = no_op;

      static std::any no_op(EXTRA_ARGS..., const std::any&, const std::any&) { return {}; }

      // Creator of binary operation implementations.
      template <class RET, class A, class B, class... EXTRA_SELECTORS>
      static void make_op(std::function<RET(EXTRA_ARGS... args, const A& arg_a, const B& arg_b)> a_func)
      {
         op_base_t op([a_func](EXTRA_ARGS... args, const std::any& arg_a, const std::any& arg_b) -> std::any
         {
            return std::any(a_func(args..., *std::any_cast<A>(&arg_a), *std::any_cast<B>(&arg_b)));
         });

         register_op<A, B, EXTRA_SELECTORS...>(op);
      }

      template <class... EXTRA_SELECTORS>
      static std::any call_op(EXTRA_ARGS... args, const std::any& arg_a, const std::any& arg_b)
      {
         using selector_t = typename op_selector_t<std::any, std::any, EXTRA_SELECTORS...>::selector_t;
         const auto& ops = get_ops<selector_t>();
         const auto pos = ops.find(selector_t(std::type_index(arg_a.type()), std::type_index(arg_b.type()), std::type_index(typeid(EXTRA_SELECTORS))...));
         if (pos == ops.end())
            return std::any();
         return pos->second.my_op_func(args..., arg_a, arg_b);
      }

      template <class A, class B, class... EXTRA_SELECTORS>
      static void register_op(const op_base_t& an_op)
      {
         using selector_t = typename op_selector_t<std::any, std::any, EXTRA_SELECTORS...>::selector_t;
         auto& ops = get_ops<selector_t>();
         ops[selector_t(std::type_index(typeid(A)), std::type_index(typeid(B)), std::type_index(typeid(EXTRA_SELECTORS))...)] = an_op;
      }

      template <class SELECTOR>
      static std::map<SELECTOR, op_base_t>& get_ops()
      {
         static std::map<SELECTOR, op_base_t> ops;
         return ops;
      }
   };
}

#endif /* DAK_CORE_ANY_BINARY_OP_H */
