// File: dak/core/any_nullary_op.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_NULLARY_OP_H
#define DAK_CORE_ANY_NULLARY_OP_H

#include <dak/core/any_op_selector.h>

#include <any>
#include <functional>
#include <map>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Familiy of nullary operations.
   //
   // To create a new nullary operation family called foo:
   //
   //    Declare a class named foo deriving from nullary_op_t. This class
   //    can be empty. It is only needed to identity the operation via
   //    its type. For our example:
   //
   //            struct foo : nullary_op_t<foo> {};
   //
   // To implement the operation foo for type A returning RET:
   //
   //    Create an instance by calling make_nullary_op<RET, A, foo>
   //    passing a function taking an A and returning a RET.
   //
   // The class hierarchy will be:
   //
   //                     nullary_op_t<foo>
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
   // The family of foo operations will be registered in the nullary_op_t<foo>
   // class.
   //
   // To call an implementation corresponding to the value kept in a std::any,
   // call:
   //
   //        std::any arg = 2152671; // any value type!
   //        std::any result = nullary_op_t<foo>::call(arg);
   //

   template <class OP, class... EXTRA_ARGS>
   struct nullary_op_t
   {
      using op_func_t = std::function<std::any(EXTRA_ARGS ...)>;
      using op_base_t = nullary_op_t<OP, EXTRA_ARGS...>;

      nullary_op_t() = default;
      nullary_op_t(const op_func_t& an_op) : my_op_func(an_op) {}

      op_func_t my_op_func = no_op;

      static std::any no_op(EXTRA_ARGS...) { return {}; }

      // Creator of nullary operation implementations.

      template <class RET, class... EXTRA_SELECTORS>
      static void make_op(std::function<RET(EXTRA_ARGS... args)> a_func)
      {
         op_base_t op([a_func](EXTRA_ARGS... args) -> std::any
         {
            return std::any(a_func(args...));
         });

         register_op<EXTRA_SELECTORS...>(op);
      }

      template <class... EXTRA_SELECTORS>
      static std::any call_op(EXTRA_ARGS... args)
      {
         using selector_t = typename nullary_op_selector_t<EXTRA_SELECTORS...>::selector_t;
         const auto& ops = get_ops<selector_t>();
         const auto pos = ops.find(nullary_op_selector_t<EXTRA_SELECTORS...>::make());
         if (pos == ops.end())
            return std::any();
         return pos->second.my_op_func(args...);
      }

      template <class... EXTRA_SELECTORS>
      static std::any call_any_op(EXTRA_ARGS... args, EXTRA_SELECTORS... selectors)
      {
         using selector_t = typename nullary_op_selector_t<EXTRA_SELECTORS...>::selector_t;
         const auto& ops = get_ops<selector_t>();
         const auto pos = ops.find(nullary_op_selector_t<EXTRA_SELECTORS...>::make_any(selectors...));
         if (pos == ops.end())
            return std::any();
         return pos->second.my_op_func(args...);
      }

   private:
      template <class... EXTRA_SELECTORS>
      static void register_op(const op_base_t& an_op)
      {
         using selector_t = typename nullary_op_selector_t<EXTRA_SELECTORS...>::selector_t;
         auto& ops = get_ops<selector_t>();
         ops[nullary_op_selector_t<EXTRA_SELECTORS...>::make()] = an_op;
      }

      template <class SELECTOR>
      static std::map<SELECTOR, op_base_t>& get_ops()
      {
         static std::map<SELECTOR, op_base_t> ops;
         return ops;
      }
   };

}

#endif /* DAK_CORE_ANY_NULLARY_OP_H */
