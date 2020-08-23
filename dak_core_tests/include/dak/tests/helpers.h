// File: dak/tests/helpers.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_TESTS_HELPERS_H
#define DAK_CORE_TESTS_HELPERS_H

#include <CppUnitTest.h>

#include <dak/core/name.h>
#include <dak/core/array.h>
#include <dak/core/dict.h>
#include <dak/core/stream.h>
#include <dak/core/any_var.h>

namespace Microsoft::VisualStudio::CppUnitTestFramework
{
   template<> inline std::wstring ToString<dak_ns::core_ns::name_t>(const dak_ns::core_ns::name_t& a_name)
   {
      RETURN_WIDE_STRING(a_name);
   }

   template<> inline std::wstring ToString<dak_ns::core_ns::dict_t>(const dak_ns::core_ns::dict_t& a_dict)
   {
      RETURN_WIDE_STRING(a_dict);
   }

   template<> inline std::wstring ToString<dak_ns::core_ns::array_t>(const dak_ns::core_ns::array_t& an_array)
   {
      RETURN_WIDE_STRING(an_array);
   }

   template<> inline std::wstring ToString<dak_ns::core_ns::uint16_t>(const dak_ns::core_ns::uint16_t& i)
   {
      RETURN_WIDE_STRING(i);
   }

   template<> inline std::wstring ToString<dak_ns::core_ns::index_t>(const dak_ns::core_ns::index_t& i)
   {
      RETURN_WIDE_STRING(i);
   }

   template<> inline std::wstring ToString<dak_ns::core_ns::var_t>(const dak_ns::core_ns::var_t& a_var)
   {
      RETURN_WIDE_STRING(a_var);
   }

   template<> inline std::wstring ToString<std::type_info>(const std::type_info& an_info)
   {
      RETURN_WIDE_STRING(an_info.name());
   }

   template<> inline std::wstring ToString<dak_ns::core_ns::any_var_t>(const dak_ns::core_ns::any_var_t& a_var)
   {
      RETURN_WIDE_STRING(a_var);
   }

   template<> inline std::wstring ToString<std::any>(const std::any& a_var)
   {
      using namespace dak_ns::core_ns;
      RETURN_WIDE_STRING(a_var);
   }

}

#endif /* DAK_CORE_TESTS_HELPERS_H */
