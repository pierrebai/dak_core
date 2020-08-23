// File: dak/core/any_op_selector.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_OP_SELECTOR
#define DAK_CORE_ANY_OP_SELECTOR

#include <any>
#include <typeinfo>
#include <typeindex>
#include <utility>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Selectors for the operations.
   //
   // These templates convert any type into the type std::type_index.
   // It is used so that we can build a tuple containing a type index
   // for each selection type.

   template <class A>
   struct op_selector_converter_t
   {
      using selector_t = std::type_index;
   };

   template <class... SELECTORS>
   struct op_selector_t
   {
      using selector_t = std::tuple<typename op_selector_converter_t<SELECTORS>::selector_t...>;
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Selectors for the nullary operations.

   template <class... EXTRA_SELECTORS>
   struct nullary_op_selector_t : op_selector_t<EXTRA_SELECTORS...>
   {
      using selector_t = typename op_selector_t<EXTRA_SELECTORS...>::selector_t;

      static selector_t make()
      {
         return selector_t(std::type_index(typeid(EXTRA_SELECTORS))...);
      }

      static selector_t make_any(EXTRA_SELECTORS... selectors)
      {
         return selector_t(selectors...);
      }
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Selectors for the unary operations.

   template <class... EXTRA_SELECTORS>
   struct unary_op_selector_t : op_selector_t<std::any, EXTRA_SELECTORS...>
   {
      using selector_t = typename op_selector_t<std::any, EXTRA_SELECTORS...>::selector_t;

      template <class A>
      static selector_t make()
      {
         return selector_t(std::type_index(typeid(A)), std::type_index(typeid(EXTRA_SELECTORS))...);
      }

      static selector_t make(const std::any& arg_a)
      {
         return selector_t(std::type_index(arg_a.type()), std::type_index(typeid(EXTRA_SELECTORS))...);
      }

      static selector_t make_any(const std::any& arg_a, EXTRA_SELECTORS... selectors)
      {
         return selector_t(std::type_index(arg_a.type()), selectors...);
      }
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Selectors for the binary operations.

   template <class... EXTRA_SELECTORS>
   struct binary_op_selector_t : op_selector_t<std::any, std::any, EXTRA_SELECTORS...>
   {
      using selector_t = typename op_selector_t<std::any, std::any, EXTRA_SELECTORS...>::selector_t;

      template <class A, class B>
      static selector_t make()
      {
         return selector_t(std::type_index(typeid(A)), std::type_index(typeid(B)), std::type_index(typeid(EXTRA_SELECTORS))...);
      }

      static selector_t make(const std::any& arg_a, const std::any& arg_b)
      {
         return selector_t(std::type_index(arg_a.type()), std::type_index(arg_b.type()), std::type_index(typeid(EXTRA_SELECTORS))...);
      }

      static selector_t make_any(const std::any& arg_a, const std::any& arg_b, EXTRA_SELECTORS... selectors)
      {
         return selector_t(std::type_index(arg_a.type()), std::type_index(arg_b.type()), selectors...);
      }
   };

   // Needed so that the global operations are initialized in the tests. TODO: move elsewhere?
   void register_ops();
}

#endif /* DAK_CORE_ANY_OP_SELECTOR */
