// File: dak/core/var.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_VAR_H
#define DAK_CORE_VAR_H

#include <dak/core/types.h>
#include <dak/core/name.h>
#include <dak/core/any_ops.h>
#include <dak/core/any_convert_op.h>
#include <dak/core/any_is_compatible_op.h>
#include <dak/core/var_ops.h>

#include <any>
#include <typeinfo>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Variable abstract base class. TODO: propagate change.

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

   //////////////////////////////////////////////////////////////////////////
   //
   // Conversion of a variable to a particular type.

   template <class T>
   const T& as(const var_t& a_var);

   template <class T>
   T& as(var_t& a_var);

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

   //////////////////////////////////////////////////////////////////////////
   //
   // Variable in dict and array.

   struct any_var_t : var_t
   {
      // Empty variable.
      static const any_var_t empty;

      // Construction.
      any_var_t() = default;

      template <class T>
      any_var_t(const T& a_value) : my_value(a_value) {}

      any_var_t(str_ptr_t a_value) : my_value(text_t(a_value ? a_value : L"")) {}

      // Type.
      const std::type_info& get_type() const override { return my_value.type(); }

      // Access.
      bool set_any(std::any& a_value) override { my_value = a_value; return true; }
      const std::any& get_any() const override { return my_value; }

      std::any& as_any() { return my_value; }
      const std::any& as_any() const { return my_value; }

      operator std::any& () { return my_value; }
      operator const std::any& () const { return my_value; }

      template <class T>
      T& as() { ensure<T>(); return std::any_cast<T&>(my_value); }

      // Note: will throw if the wrong type is requested!
      template <class T>
      const T& as() const { verify<T>(); return std::any_cast<const T&>(my_value); }

      template <class T>
      operator T&() { return as<T>(); }

      template <class T>
      operator const T&() const { return as<T>(); }

      // Modify.
      any_var_t& operator=(const any_var_t& an_other) = default;

      template <class T>
      any_var_t& operator=(const T& a_value)
      { reset<T>(a_value); return *this; }

      any_var_t& operator=(str_ptr_t a_value)
      { reset<text_t>(a_value ? a_value : L""); return (*this); }

      // All integer-like types are equivalent, so you can read a boolean
      // from an integer. Same for double-like types, float and double.
      template <class T>
      bool compatible() const { return is_compatible_op_t::call<T>(my_value); }

      // Clear the old data and set the type. Clear even if same type.
      // Returns true if the type was successfully set.
      template <class T>
      any_var_t& reset(const T& a_value) { my_value = a_value; return *this; }

      any_var_t& reset(str_ptr_t a_value) { my_value = text_t(a_value ? a_value : L""); return *this; }

      template <class T>
      any_var_t& reset() { my_value = T{}; return *this; }

      any_var_t& reset() { my_value.reset(); return *this; }

      // Reset if currently not the requested type.
      // Tries to preserve as much of the old value as possible.
      // Returns true if the type was successfully set.
      template <class T>
      any_var_t& ensure()
      {
         if (my_value.type() == typeid(T))
            return *this;

         const T new_value(convert_op_t::call<T>(my_value));
         return reset<T>(new_value);
      }

      // Verify if it has the requested type or unknown, in which case set the type.
      // Returns true if the type was already correct or successfully set.
      // Returns false if the type was different.
      template <class T>
      bool verify() const
      {
         if (my_value.type() == typeid(T))
            return true;

         if (!my_value.has_value())
         {
            const_cast<any_var_t&>(*this).reset<T>();
            return true;
         }

         return false;
      }

      // Array conversion + immediate array operation.
      any_var_t& operator [](index_t anIndex);
      const any_var_t& operator [](index_t anIndex) const;
      bool erase(index_t anIndex);
      void append(const array_t&);
      void append(const any_var_t&);
      any_var_t& insert(index_t anIndex);
      any_var_t& grow();

      // Dict conversion + immediate dict operation.
      void append(const dict_t&);
      bool erase(const name_t&);
      bool contains(const name_t&) const;
      any_var_t& operator [](const name_t&);
      const any_var_t& operator [](const name_t&) const;

      // Array, dict and text return the length, others return zero.
      index_t size() const;

   private:
      // Comparisons.
      comparison_t compare_same_type(const var_t& an_other) const override;

   private:
      std::any my_value;
   };

   DAK_CORE_VAR_ALL_OPERATORS(any_var_t)

}

#endif /* DAK_CORE_VAR_H */
