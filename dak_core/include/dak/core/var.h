// File: dak/core/var.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_VAR_H
#define DAK_CORE_VAR_H

#include <dak/core/types.h>
#include <dak/core/name.h>

#include <any>
#include <typeinfo>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Variable abstract base class.
   // TODO: propagate change.

   struct var_t
   {
      // Access.
      virtual bool set_any(std::any& a_value) = 0;
      virtual const std::any& get_any() const = 0;

      // Type.
      virtual const std::type_info& get_type() const = 0;

      // Comparisons.
      comparison_t compare(const var_t& an_other) const;

      bool operator == (const var_t& an_other) const { return compare(an_other) == comparison_t::equal; }
      bool operator != (const var_t& an_other) const { return compare(an_other) != comparison_t::equal; }
      bool operator < (const var_t& an_other) const { return compare(an_other) == comparison_t::less; }
      bool operator > (const var_t& an_other) const { return compare(an_other) == comparison_t::more; }
      bool operator <= (const var_t& an_other) const { return is(compare(an_other), comparison_t::less_or_equal); }
      bool operator >= (const var_t& an_other) const { return is(compare(an_other), comparison_t::more_or_equal); }

   private:
      // Comparisons.
      virtual comparison_t compare_same_type(const var_t& an_other) const = 0;
   };

}

#endif /* DAK_CORE_VAR_H */
