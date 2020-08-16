// File: name.cpp
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#include <dak/core/name.h>

#include <atomic>

namespace dak_ns::core_ns
{
   std::atomic<uint32_t> last_name = int32_t(name_t::last_well_known_name);

   name_t make_name(const text_t& name)
   {
      return name_t(last_name.fetch_add(1));
   }

}
