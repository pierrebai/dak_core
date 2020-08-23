// File: dak/core/array.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_ARRAY_H
#define DAK_CORE_ARRAY_H

#include <dak/core/types.h>
#include <dak/core/ref_counted.h>
#include <dak/core/any_var.h>
#include <dak/core/var_ops.h>

#include <vector>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Array. elements are indexed by an integer, beginning at zero (0).
   //
   // Indexing past the end inserts element in between.
   //
   // Indexing with negative index starts from the end of the array,
   // minus one being the last item.

   struct array_t : private ref_counted_t
   {
      // Types used by the array: data container and iterators.
      typedef std::vector<any_var_t> elements_t;
      typedef elements_t::iterator iterator;
      typedef elements_t::const_iterator const_iterator;

      // Append the given array.
      array_t& operator +=(const array_t &);

      // Make a ref-counted instance.
      static ref_t<array_t> make();
      static ref_t<array_t> make(const array_t &);

      // Empty array.
      static const array_t empty;

      // Number of elements in the array.
      index_t size() const;
      void reserve(index_t a_size);

      // Modifications to the array.
      void append(const array_t &);
      void append(const any_var_t&);
      bool erase(index_t an_index);
      any_var_t& insert(index_t an_index);
      any_var_t& grow();

      // Element retrieval.
      any_var_t & operator [](index_t an_index);
      const any_var_t & operator [](index_t an_index) const;

      // Iterations over the elements.
      iterator begin();
      iterator end();
      const_iterator begin() const;
      const_iterator end() const;

      // Comparisons.
      bool operator == (const array_t& an_other) const;
      bool operator != (const array_t& an_other) const { return !((*this) == an_other); }
      bool operator <  (const array_t& an_other) const;
      bool operator >  (const array_t& an_other) const { return an_other < *this; }

   private:
      // Make the given index positive, possibly by resizing the array.
      // Return the positive index.
      index_t make_fit(index_t an_index);

      // Make the given index positive if possible.
      // Return the positive index or negative if the normalization failed.
      index_t verify_fit(index_t an_index) const;

      elements_t my_elements;

      friend struct ref_t<array_t>;
   };

   DAK_CORE_VAR_OPERATOR(+, array_t, any_var_t);
}

#endif /* DAK_CORE_ARRAY_H */
