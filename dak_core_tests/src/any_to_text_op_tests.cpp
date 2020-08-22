#include <CppUnitTest.h>

#include <dak/core/all.h>
#include <dak/tests/helpers.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;

namespace tests
{		
   TEST_CLASS(any_to_text_op_tests)
	{
	public:
		TEST_METHOD(to_text)
		{
         to_text_op_t::register_ops();

         std::wostringstream stream;

         std::any e_t1(text_t(L"text_t"));
         std::any e_t2(L"strptr");
         std::any e_c1('c');
         std::any e_c2(L'w');
         std::any e_b (true);
         std::any e_i2((int16_t)2);
         std::any e_i1((int32_t)1);
         std::any e_i3((int64_t)3);
         std::any e_u1((uint16_t)4u);
         std::any e_u2((uint32_t)5u);
         std::any e_u3((uint64_t)6u);
         std::any e_r1(7.0f);
         std::any e_r2(8.0);
         std::any e_a ((array_t()));
         std::any e_d ((dict_t()));
         std::any e_n (ns::view);

         Assert::AreEqual<text_t>(L"text_t",   to_text_op_t::call(e_t1));
         Assert::AreEqual<text_t>(L"strptr",   to_text_op_t::call(e_t2));
         Assert::AreEqual<text_t>(L"c",        to_text_op_t::call(e_c1));
         Assert::AreEqual<text_t>(L"w",        to_text_op_t::call(e_c2));
         Assert::AreEqual<text_t>(L"true",     to_text_op_t::call(e_b ));
         Assert::AreEqual<text_t>(L"2",        to_text_op_t::call(e_i2));
         Assert::AreEqual<text_t>(L"1",        to_text_op_t::call(e_i1));
         Assert::AreEqual<text_t>(L"3",        to_text_op_t::call(e_i3));
         Assert::AreEqual<text_t>(L"4",        to_text_op_t::call(e_u1));
         Assert::AreEqual<text_t>(L"5",        to_text_op_t::call(e_u2));
         Assert::AreEqual<text_t>(L"6",        to_text_op_t::call(e_u3));
         Assert::AreEqual<text_t>(L"7",        to_text_op_t::call(e_r1));
         Assert::AreEqual<text_t>(L"8",        to_text_op_t::call(e_r2));
         Assert::AreEqual<text_t>(L"[ ]",      to_text_op_t::call(e_a ));
         Assert::AreEqual<text_t>(L"{ }",      to_text_op_t::call(e_d ));
         Assert::AreEqual<text_t>(L"view",     to_text_op_t::call(e_n ));
      }
   };
}
