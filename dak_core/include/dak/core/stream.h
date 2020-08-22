// File: dak/core/stream.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_STREAM_H
#define DAK_CORE_STREAM_H

#include <dak/core/name.h>
#include <dak/core/types.h>

#include <iostream>
#include <any>

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Stream operations on known data types.
   //
   // By default, uses the standard output stream. Specialized for our own types.

   std::wostream& operator <<(std::wostream& o, const name_t& a_name);
   std::wostream& operator <<(std::wostream& o, const var_t& a_var);
   std::wostream& operator <<(std::wostream& o, const array_t& an_array);
   std::wostream& operator <<(std::wostream& o, const dict_t& a_dict);
   std::wostream& operator <<(std::wostream& o, const std::any& a_var);
}

#endif /* DAK_CORE_STREAM_H */
