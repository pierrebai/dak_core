#include <CppUnitTest.h>

#include <dak/core/all.h>
#include <tests_helpers.h>

#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;

namespace tests
{		
   TEST_CLASS(any_stream_op_tests)
	{
	public:
		TEST_METHOD(stream)
		{
         stream_op_t::register_ops();

         std::wostringstream stream;

         std::any e_t1(text_t(L"text_t"));
         std::any e_t2(L"strptr");
         std::any e_c1('c');
         std::any e_c2(L'w');
         std::any e_b(true);
         std::any e_i2((int16_t)2);
         std::any e_i1((int32_t)1);
         std::any e_i3((int64_t)3);
         std::any e_u1((uint16_t)4u);
         std::any e_u2((uint32_t)5u);
         std::any e_u3((uint64_t)6u);
         std::any e_r1(7.0f);
         std::any e_r2(8.0);
         std::any e_a((array_t()));
         std::any e_d((dict_t()));
         std::any e_n(ns::view);

         stream
            << e_t1 << L" -- "
            << e_t2 << L" -- "
            << e_c1 << L" -- "
            << e_c2 << L" -- "
            << e_b  << L" -- "
            << e_i2 << L" -- "
            << e_i1 << L" -- "
            << e_i3 << L" -- "
            << e_u1 << L" -- "
            << e_u2 << L" -- "
            << e_u3 << L" -- "
            << e_r1 << L" -- "
            << e_r2 << L" -- "
            << e_a  << L" -- "
            << e_d  << L" -- "
            << e_n  << L" -- ";

         Assert::AreEqual(
            L"text_t -- "
            L"strptr -- "
            L"c -- "
            L"w -- "
            L"1 -- "
            L"2 -- "
            L"1 -- "
            L"3 -- "
            L"4 -- "
            L"5 -- "
            L"6 -- "
            L"7 -- "
            L"8 -- "
            L"[ ] -- "
            L"{ } -- "
            L"view -- ",
            stream.str().c_str());
      }
   };
}
