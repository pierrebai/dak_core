// File: dak/core/dict.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_DICT_H
#define DAK_CORE_DICT_H

#include <dak/core/object.h>
#include <dak/core/any_var.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Dictionary. Lookup data when given a name_t.
   //
   // Automatically adds elements when referenced via the [] operator.

   struct dict_t : private ref_counted_t
   {
      // Types used by the dictionary: data container and iterators.
      typedef std::map<name_t, any_var_t> elements_t;
      typedef elements_t::iterator iterator;
      typedef elements_t::const_iterator const_iterator;

      // Append the given dictionary.
      dict_t& operator +=(const dict_t& an_other);

      // Make a ref-counted instance.
      static ref_t<dict_t> make();
      static ref_t<dict_t> make(const dict_t& an_other);

      // Empty dictionary.
      static const dict_t empty;

      // Number of elements in the dictionary.
      index_t size() const;

      // Modifications to the dictionary.
      void append(const dict_t& an_other);
      bool erase(const name_t& a_name);
      bool contains(const name_t& a_name) const;

      // Element retrieval.
      any_var_t& operator [](const name_t& a_name);
      const any_var_t& operator [](const name_t& a_name) const;

      // Iterations over the elements.
      iterator begin();
      iterator end();
      const_iterator begin() const;
      const_iterator end() const;

      // Comparisons.
      bool operator == (const dict_t& an_other) const;
      bool operator != (const dict_t& an_other) const { return !((*this) == an_other); }
      bool operator <  (const dict_t& an_other) const;
      bool operator >  (const dict_t& an_other) const { return an_other < *this; }

   protected:
      elements_t my_elements;

      friend struct ref_t<dict_t>;
   };


   DAK_CORE_VAR_OPERATOR(+, dict_t, any_var_t);
}

#endif /* DAK_CORE_DICT_H */
