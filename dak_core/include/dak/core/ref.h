// File: dak/ref.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_REF_H
#define DAK_CORE_REF_H

#include <dak/core/types.h>
#include <dak/core/ref_counted.h>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Base class for the smart reference-counted templated pointer.
   // Holds references to ref_counted objects.
   //
   // Holds the common code.

   struct ref_base_t
   {
      void clear();
      bool is_valid() const;
      bool is_null() const;

   protected:
      // Constructors.
      ref_base_t() = default;

      // Copy.
      ref_base_t(ref_counted_t*);
      ref_base_t(const ref_base_t&);
      ref_base_t(const ref_base_t&&);
      ref_base_t& operator =(ref_counted_t*);
      ref_base_t& operator =(const ref_base_t&);
      ref_base_t& operator =(const ref_base_t&&);

      // Destructor.
      ~ref_base_t();

   protected:
      ref_counted_t* my_object = nullptr;
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // A smart reference-counted pointer to a ref_counted object.
   //
   // You cannot create an initialized instance of a smart pointer directly.
   // To create one, call the make() function on the type T.
   // See for example: array::make() in array.h.

   template<class T> struct ref_t : ref_base_t
   {
      // Constructors.
      ref_t() = default;

      // Access to the referenced object.
      operator T*() { return static_cast<T*>(my_object); }
      operator const T*() const { return static_cast<const T*>(my_object); }

      T* operator ->() { return static_cast<T*>(my_object); }
      const T* operator ->() const { return static_cast<const T*>(my_object); }

      T& operator *() { return static_cast<T&>(*my_object); }
      const T& operator *() const { return static_cast<const T&>(*my_object); }

   private:
      ref_t(T* t) : ref_base_t(t) {}
      ref_t<T>& operator =(T* t) { ref_base_t::operator =(t); return *this; }

      friend ref_t<T> T::make();
      friend ref_t<T> T::make(const T&);
   };
}

#endif /* DAK_CORE_REF_H */
