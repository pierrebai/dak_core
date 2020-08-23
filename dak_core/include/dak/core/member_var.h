// File: dak/core/member_var.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_MEMBER_VAR_H
#define DAK_CORE_MEMBER_VAR_H

#include <dak/core/var.h>

namespace dak_ns::core_ns
{

   //////////////////////////////////////////////////////////////////////////
   //
   // Variable in objects.

   template <class C, class T>
   struct member_var_t : var_t
   {
      // Construction.
      // TODO: pass in object.
      member_var_t() = default;
      member_var_t(const T& a_value) : my_value(a_value) {}

      // Type.
      const std::type_info& get_type() const override { return typeid(T); }

      // Name.
      name_t get_name() const { return N; }

      // Access.
      bool set_any(std::any& a_value) override
      {
         std::any t_value = convert_op_t::call<T>(a_value);
         if (!t_value.has_value())
            return false;
         my_value = *std::any_cast<T>(&t_value);
         return true;
      }

      const std::any& get_any() const override { return my_any = my_value; return my_any; }

      operator T& () { return my_value; }
      operator const T& () const { return my_value; }

      T& as() { return my_value; }
      const T& as() const { return my_value; }

   private:
      // Comparisons.
      comparison_t compare_same_type(const var_t& an_other) const override
      {
         const T other_value& as<T>(an_other);
         if (my_value < other_value)
            return comparison_t::less;
         if (my_value > other_value)
            return comparison_t::more;
         if (my_value == other.value)
            return comparison_t::equal;
         return comparison_t::incomparable;
      }

   private:
      std::any my_any;
      T my_value;
   };

}

#endif /* DAK_CORE_MEMBER_VAR_H */
