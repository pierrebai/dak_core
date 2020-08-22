// File: dak/core/util.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#pragma once

#ifndef DAK_CORE_UTIL_H
#define DAK_CORE_UTIL_H

namespace dak_ns::core_ns
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Prevent copy construction and assignments when used as a base class.

   struct no_copy_t
   {
   protected:
      no_copy_t() = default;

   private:
      no_copy_t(const no_copy_t&) = delete;
      no_copy_t& operator =(const no_copy_t&) = delete;
   };

   //////////////////////////////////////////////////////////////////////////
   //
   // Prevent move construction and assignments when used as a base class.

   struct no_move_t
   {
   protected:
      no_move_t() = default;

   private:
      no_move_t(const no_move_t&&) = delete;
      no_move_t& operator =(const no_move_t&&) = delete;
   };
}

#endif /* DAK_CORE_UTIL_H */

