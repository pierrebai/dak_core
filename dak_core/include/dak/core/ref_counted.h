// File: dak/core/ref_counted.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_REF_COUNTED_H
#define DAK_CORE_REF_COUNTED_H

#include <dak/core/types.h>
#include <dak/core/ref.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Reference-counted objects. Support reference counting, but can also
   // be declared on the stack or embedded in another object.
   //
   // Sub-classes of ref_counted *must* inherit from it privately to support the
   // restriction on reference-counting vs. stack or embedded instances.

   struct ref_counted_t
   {
   protected:
      ref_counted_t() = default;
      ref_counted_t(const ref_counted_t &);
      ref_counted_t& operator =(const ref_counted_t &);
      virtual ~ref_counted_t() = default;

   private:
      void add_ref() const;
      void remove_ref() const;

      mutable int64_t my_ref_count = 0;

      friend struct ref_base_t;
   };
}

#endif /* DAK_CORE_REF_COUNTED_H */
