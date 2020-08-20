// File: dict.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/dict.h>

namespace dak_ns::core_ns
{
   const dict_t dict_t::empty;

   ref_t<dict_t> dict_t::make()
   {
      return ref_t<dict_t>(new dict_t);
   }

   ref_t<dict_t> dict_t::make(const dict_t& an_other)
   {
      return ref_t<dict_t>(new dict_t(an_other));
   }

   dict_t& dict_t::operator +=(const dict_t& an_other)
   {
      append(an_other);
      return *this;
   }

   void dict_t::append(const dict_t& an_other)
   {
      for (const auto& [a_name, e] : an_other.my_elements)
         (*this)[a_name] = e;
   }

   bool dict_t::erase(const name_t& a_name)
   {
      return my_elements.erase(a_name) > 0;
   }

   bool dict_t::contains(const name_t& a_name) const
   {
      return 0 != my_elements.count(a_name);
   }

   index_t dict_t::size() const
   {
      return index_t(my_elements.size());
   }

   any_var_t& dict_t::operator [](const name_t& a_name)
   {
      return my_elements[a_name];
   }

   const any_var_t& dict_t::operator [](const name_t& a_name) const
   {
      const_iterator pos = my_elements.find(a_name);
      if (my_elements.end() == pos)
         return any_var_t::empty;
      else
         return pos->second;
   }

   dict_t::iterator dict_t::begin()
   {
      return my_elements.begin();
   }

   dict_t::iterator dict_t::end()
   {
      return my_elements.end();
   }

   dict_t::const_iterator dict_t::begin() const
   {
      return my_elements.begin();
   }

   dict_t::const_iterator dict_t::end() const
   {
      return my_elements.end();
   }

   bool dict_t::operator == (const dict_t& an_other) const
   {
      if (an_other.size() != size())
         return false;

      for (const auto& [a_name, e] : an_other.my_elements)
         if (e != (*this)[a_name])
            return false;

      return true;
   }

   bool dict_t::operator < (const dict_t& an_other) const
   {
      const auto my_end = end();
      const auto other_end = an_other.end();

      for (auto my_pos = begin(), other_pos = an_other.begin(); my_pos != my_end && other_pos != other_end; ++my_pos, ++other_pos)
      {
         if (my_pos->first < other_pos->first)
            return true;
         if (other_pos->first < my_pos->first)
            return false;

         if (my_pos->second < other_pos->second)
            return true;
         if (other_pos->second < my_pos->second)
            return false;
      }

      if (size() >= an_other.size())
         return false;

      return true;
   }

}
