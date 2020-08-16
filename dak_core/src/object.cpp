// File: object.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/object.h>
#include <dak/core/var.h>

namespace dak_ns::core_ns
{
   const object_t object_t::empty;

   ref_t<object_t> object_t::make()
   {
      return ref_t<object_t>(new object_t);
   }

   ref_t<object_t> object_t::make(const object_t & an_object)
   {
      return ref_t<object_t>(new object_t(an_object));
   }

   bool object_t::contains(const name_t& a_name) const
   {
      return 0 != my_vars.count(a_name);
   }

   index_t object_t::size() const
   {
      return my_vars.size();
   }

   var_t* object_t::operator [](const name_t& a_name)
   {
      return my_vars[a_name];
   }

   const var_t* object_t::operator [](const name_t& a_name) const
   {
      const_iterator pos = my_vars.find(a_name);
      if(my_vars.end() == pos)
         return &any_var_t::empty;
      else
         return pos->second;
   }

   object_t::iterator object_t::begin()
   {
      return my_vars.begin();
   }

   object_t::iterator object_t::end()
   {
      return my_vars.end();
   }

   object_t::const_iterator object_t::begin() const
   {
      return my_vars.begin();
   }

   object_t::const_iterator object_t::end() const
   {
      return my_vars.end();
   }

   bool object_t::operator ==(const object_t& an_object) const
   {
      if (an_object.size() != size())
         return false;

      for (const auto& [a_name, e] : an_object.my_vars)
         if (e != (*this)[a_name])
            return false;

      return true;
   }

   bool object_t::operator !=(const object_t& an_object) const
   {
      return !((*this) == an_object);
   }
}
