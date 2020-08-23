// File: dak/core/any_stream_op.h
//
// Dak Copyright © 2012-2020. All Rights Reserved.

#ifndef DAK_CORE_ANY_STREAM_OP
#define DAK_CORE_ANY_STREAM_OP

#include <dak/core/any_binary_ops.h>

#include <ostream>

namespace dak_ns::core_ns
{

   //////////////////////////////////////////////////////////////////////////
   //
   // The stream operation writes the value to an output stream.
   //
   // Note: the stream is received by pointer to travel in a std::any.

   struct stream_op_t : binary_op_t<stream_op_t>
   {
      static std::wostream& call(std::wostream& a_stream, const std::any& arg_b)
      {
         binary_ops_t<stream_op_t>::call(std::any(&a_stream), arg_b);
         return a_stream;
      }

      template<class A>
      static std::wostream& call(std::wostream& a_stream, const A& arg_b)
      {
         return stream_op_t::call(a_stream, std::make_any<A>());
      }

      // Note: pre-defined operations implementation are automatically registered,
      //       but these static variables do not get initialized by the testing framework.
      //       Tests need to explicitly call a function to trigger initialization.
      static void register_ops();
   };

   std::wostream& operator<<(std::wostream& a_stream, const std::any& a_value);
}

#endif /* DAK_CORE_ANY_STREAM_OP */
