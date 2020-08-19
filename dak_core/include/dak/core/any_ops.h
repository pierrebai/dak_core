// File: dak/any_ops.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_OPS_H
#define DAK_CORE_ANY_OPS_H

#include <dak/core/types.h>

#include <any>
#include <functional>
#include <map>
#include <typeinfo>
#include <typeindex>
#include <utility>

namespace dak_ns::core_ns
{
   // TODO: allow additional arguments to the operators.
   //       In fact, separating selection types from arguments types would be best.

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

   template <class OP>
   struct unary_ops_t;

   template <class OP>
   struct unary_op_t
   {
      using op_t = std::function<std::any(const std::any& arg_a)>;

      unary_op_t() = default;
      unary_op_t(const op_t& an_op) : my_op(an_op) {}

   private:
      static std::any no_op(const std::any&) { return {}; }

      op_t my_op = no_op;

      friend struct unary_ops_t<OP>;
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Container of single-argument operation implementations for various types.

   template <class OP>
   struct unary_ops_t
   {
      using args_t = std::type_index;
      using op_t = unary_op_t<OP>;

      static std::any call(const std::any& arg_a)
      {
         const auto& ops = get_ops();
         const auto pos = ops.find(args_t(std::type_index(arg_a.type())));
         if (pos == ops.end())
            return std::any();
         return pos->second.my_op(arg_a);
      }

      template <class A>
      static void register_op(const op_t& an_op)
      {
         auto& ops = get_ops();
         ops[args_t(std::type_index(typeid(A)))] = an_op;
      }

   private:
      static std::map<args_t, op_t>& get_ops()
      {
         static std::map<args_t, op_t> ops;
         return ops;
      }
   };

   template <class RET, class A, class OP>
   void make_unary_op(std::function<RET(const A& arg_a)> a_func)
   {
      unary_op_t<OP> op([a_func](const std::any& arg_a) -> std::any
      {
         return std::any(a_func(std::any_cast<A>(arg_a)));
      });

      unary_ops_t<OP>::register_op<A>(op);
   }

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

   template <class OP>
   struct binary_ops_t;

   template <class OP>
   struct binary_op_t
   {
      using op_t = std::function<std::any(const std::any& arg_a, const std::any& arg_b)>;

      binary_op_t() = default;
      binary_op_t(const op_t& an_op) : my_op(an_op) {}

   private:
      static std::any no_op(const std::any&, const std::any&) { return {}; }

      op_t my_op = no_op;

      friend struct binary_ops_t<OP>;
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Container of single-argument operation implementations for various types.

   template <class OP>
   struct binary_ops_t
   {
      using args_t = std::pair<std::type_index, std::type_index>;
      using op_t = binary_op_t<OP>;

      static std::any call(const std::any& arg_a, const std::any& arg_b)
      {
         const auto& ops = get_ops();
         const auto pos = ops.find(args_t(std::type_index(arg_a.type()), std::type_index(arg_b.type())));
         if (pos == ops.end())
            return std::any();
         return pos->second.my_op(arg_a, arg_b);
      }

      template<class A, class B>
      static std::any call(const A& arg_a, const B& arg_b)
      {
         return call(std::any(arg_a), std::any(arg_b));
      }

      template <class A, class B>
      static void register_op(const op_t& an_op)
      {
         auto& ops = get_ops();
         ops[args_t(std::type_index(typeid(A)), std::type_index(typeid(B)))] = an_op;
      }

   private:
      static std::map<args_t, op_t>& get_ops()
      {
         static std::map<args_t, op_t> ops;
         return ops;
      }
   };

   template <class RET, class A, class B, class OP>
   void make_binary_op(std::function<RET(const A& arg_a, const B& arg_b)> a_func)
   {
      binary_op_t<OP> op([a_func](const std::any& arg_a, const std::any& arg_b) -> std::any
      {
         return std::any(a_func(std::any_cast<A>(arg_a), std::any_cast<B>(arg_b)));
      });

      binary_ops_t<OP>::register_op<A, B>(op);
   }

   // Needed so that the global operations are initialized in the tests.
   void initialize_ops();
}

#endif /* DAK_CORE_ANY_OPS_H */
