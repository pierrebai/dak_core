// File: dak/object.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_OBJECT_H
#define DAK_CORE_OBJECT_H

#include <dak/core/types.h>
#include <dak/core/ref_counted.h>
#include <dak/core/name.h>

#include <map>

namespace dak_ns::core_ns
{
   struct var_t;

   //////////////////////////////////////////////////////////////////////////
   //
   // Object. Contains member variables indexed by names.

   struct object_t : private ref_counted_t
   {
      // Types used by the object data container and iterators.
      typedef std::map<name_t, var_t *> variables_t;
      typedef variables_t::iterator iterator;
      typedef variables_t::const_iterator const_iterator;

      // Make a ref-counted instance.
      static ref_t<object_t> make();
      static ref_t<object_t> make(const object_t &);

      // Empty object.
      static const object_t empty;

      // Number of variables in the object.
      index_t size() const;

      // Variable access.
      bool contains(const name_t&) const;
      var_t* operator [](const name_t &);
      const var_t* operator [](const name_t &) const;

      // Iterations over the variables.
      iterator begin();
      iterator end();
      const_iterator begin() const;
      const_iterator end() const;

      // Comparisons.
      bool operator == (const object_t&) const;
      bool operator != (const object_t&) const;

   protected:
      variables_t my_vars;

      friend struct ref_t<object_t>;
   };
}

#endif /* DAK_CORE_OBJECT_H */
