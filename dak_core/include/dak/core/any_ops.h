// File: dak/core/any_ops.h
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
   //////////////////////////////////////////////////////////////////////////
   //
   // Selectors for the operation.

   // This template converts any type into the type std::type_index.
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

   // Needed so that the global operations are initialized in the tests.
   void initialize_ops();
}

#endif /* DAK_CORE_ANY_OPS_H */
