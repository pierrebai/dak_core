// File: array.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/array.h>

#include <algorithm>

namespace dak_ns::core_ns
{
   const array_t array_t::empty;

   ref_t<array_t> array_t::make()
   {
      return ref_t<array_t>(new array_t);
   }

   ref_t<array_t> array_t::make(const array_t & an_array)
   {
      return ref_t<array_t>(new array_t(an_array));
   }

   array_t& array_t::operator +=(const array_t & an_array)
   {
      append(an_array);
      return *this;
   }

   index_t array_t::size() const
   {
      return my_elements.size();
   }

   void array_t::reserve(index_t a_size)
   {
      my_elements.reserve(a_size);
   }

   void array_t::append(const array_t & an_array)
   {
      for (const any_var_t& e : an_array)
      {
         grow() = e;
      }
   }

   index_t array_t::make_fit(index_t index_t)
   {
      if (index_t < 0)
      {
         index_t = size() + index_t;
         if (index_t < 0)
         {
            // Note: index_t is negative, so subtracting adds.
            my_elements.resize(size() - index_t);
            index_t = 0;
         }
      }
      else if (index_t >= size())
      {
         my_elements.resize(index_t + 1);
      }

      return index_t;
   }

   index_t array_t::verify_fit(index_t an_index) const
   {
      if (an_index < 0)
      {
         return size() + an_index;
      }
      else if (an_index >= size())
      {
         return -1;
      }
      else
      {
         return an_index;
      }
   }

   bool array_t::erase(index_t an_index)
   {
      an_index = verify_fit(an_index);
      if (an_index < 0)
         return false;

      my_elements.erase(my_elements.begin() + an_index);
      return true;
   }

   any_var_t & array_t::insert(index_t an_index)
   {
      an_index = make_fit(an_index);
      return *my_elements.insert(my_elements.begin() + an_index, any_var_t::empty);
   }

   any_var_t & array_t::operator [](index_t an_index)
   {
      an_index = make_fit(an_index);
      return my_elements [an_index];
   }

   const any_var_t & array_t::operator [](index_t an_index) const
   {
      an_index = verify_fit(an_index);

      if (an_index < 0)
         return any_var_t::empty;

      return my_elements [an_index];
   }

   any_var_t & array_t::grow()
   {
      return (*this) [ size() ];
   }

   array_t::iterator array_t::begin()
   {
      return my_elements.begin();
   }

   array_t::iterator array_t::end()
   {
      return my_elements.end();
   }

   array_t::const_iterator array_t::begin() const
   {
      return my_elements.begin();
   }

   array_t::const_iterator array_t::end() const
   {
      return my_elements.end();
   }

   bool array_t::operator == (const array_t& an_array) const
   {
      if (an_array.size() != size())
         return false;

      for (index_t i = 0; i < size(); ++i)
         if (an_array.my_elements[i] != my_elements[i])
            return false;

      return true;
   }

   bool array_t::operator < (const array_t& an_array) const
   {
      const index_t min_size = std::min(size(), an_array.size());
      for (index_t i = 0; i < min_size; ++i)
      {
         if (my_elements[i] < an_array.my_elements[i])
            return true;
         if (an_array.my_elements[i] < my_elements[i])
            return false;
      }

      if (size() >= an_array.size())
         return false;

      return true;
   }

}
