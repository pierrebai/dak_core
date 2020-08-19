#include <CppUnitTest.h>

#include <dak/core/any_ops.h>
#include <helpers.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;

namespace tests
{		
   TEST_CLASS(any_ops_tests)
	{
	public:
		TEST_METHOD(is_compatible)
		{
         initialize_ops();

         Assert::IsTrue(is_compatible_op_t::call<int32_t, bool>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, char>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, wchar_t>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, int8_t>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, int16_t>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, int32_t>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, int64_t>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, uint8_t>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, uint16_t>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, uint32_t>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, uint64_t>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, float>());
         Assert::IsTrue(is_compatible_op_t::call<int32_t, double>());

         Assert::IsTrue(is_compatible_op_t::call<int64_t, bool>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, char>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, wchar_t>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, int8_t>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, int16_t>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, int32_t>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, int64_t>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, uint8_t>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, uint16_t>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, uint32_t>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, uint64_t>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, float>());
         Assert::IsTrue(is_compatible_op_t::call<int64_t, double>());

         Assert::IsTrue(is_compatible_op_t::call<double, bool>());
         Assert::IsTrue(is_compatible_op_t::call<double, char>());
         Assert::IsTrue(is_compatible_op_t::call<double, wchar_t>());
         Assert::IsTrue(is_compatible_op_t::call<double, int8_t>());
         Assert::IsTrue(is_compatible_op_t::call<double, int16_t>());
         Assert::IsTrue(is_compatible_op_t::call<double, int32_t>());
         Assert::IsTrue(is_compatible_op_t::call<double, int64_t>());
         Assert::IsTrue(is_compatible_op_t::call<double, uint8_t>());
         Assert::IsTrue(is_compatible_op_t::call<double, uint16_t>());
         Assert::IsTrue(is_compatible_op_t::call<double, uint32_t>());
         Assert::IsTrue(is_compatible_op_t::call<double, uint64_t>());
         Assert::IsTrue(is_compatible_op_t::call<double, float>());
         Assert::IsTrue(is_compatible_op_t::call<double, double>());

         Assert::IsTrue(is_compatible_op_t::call<bool, bool>());
         Assert::IsTrue(is_compatible_op_t::call<bool, char>());
         Assert::IsTrue(is_compatible_op_t::call<bool, wchar_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, int8_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, int16_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, int32_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, int64_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, uint8_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, uint16_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, uint32_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, uint64_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, float>());
         Assert::IsTrue(is_compatible_op_t::call<bool, double>());
         Assert::IsTrue(is_compatible_op_t::call<bool, name_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, array_t>());
         Assert::IsTrue(is_compatible_op_t::call<bool, dict_t>());

         Assert::IsTrue(is_compatible_op_t::call<array_t, dict_t>());
         Assert::IsFalse(is_compatible_op_t::call<array_t, name_t>());

         Assert::IsFalse(is_compatible_op_t::call<dict_t, array_t>());
         Assert::IsFalse(is_compatible_op_t::call<dict_t, name_t>());

         Assert::IsFalse(is_compatible_op_t::call<name_t, array_t>());
         Assert::IsFalse(is_compatible_op_t::call<name_t, dict_t>());
      }

      TEST_METHOD(convert)
      {
         initialize_ops();

         Assert::AreEqual<int32_t>(1,  convert_op_t::call<int32_t, bool>(true));
         Assert::AreEqual<int32_t>(97, convert_op_t::call<int32_t, char>('a'));
         Assert::AreEqual<int32_t>(98, convert_op_t::call<int32_t, wchar_t>(L'b'));
         Assert::AreEqual<int32_t>(2,  convert_op_t::call<int32_t, int8_t>(2));
         Assert::AreEqual<int32_t>(3,  convert_op_t::call<int32_t, int16_t>(3));
         Assert::AreEqual<int32_t>(4,  convert_op_t::call<int32_t, int32_t>(4));
         Assert::AreEqual<int32_t>(5,  convert_op_t::call<int32_t, int64_t>(5));
         Assert::AreEqual<int32_t>(6,  convert_op_t::call<int32_t, uint8_t>(6));
         Assert::AreEqual<int32_t>(7,  convert_op_t::call<int32_t, uint16_t>(7));
         Assert::AreEqual<int32_t>(8,  convert_op_t::call<int32_t, uint32_t>(8));
         Assert::AreEqual<int32_t>(9,  convert_op_t::call<int32_t, uint64_t>(9));
         Assert::AreEqual<int32_t>(10, convert_op_t::call<int32_t, float>(10.f));
         Assert::AreEqual<int32_t>(11, convert_op_t::call<int32_t, double>(11.));

         Assert::AreEqual<int64_t>(1,  convert_op_t::call<int64_t, bool>(true));
         Assert::AreEqual<int64_t>(65, convert_op_t::call<int64_t, char>('A'));
         Assert::AreEqual<int64_t>(66, convert_op_t::call<int64_t, wchar_t>(L'B'));
         Assert::AreEqual<int64_t>(2,  convert_op_t::call<int64_t, int8_t>(2));
         Assert::AreEqual<int64_t>(3,  convert_op_t::call<int64_t, int16_t>(3));
         Assert::AreEqual<int64_t>(4,  convert_op_t::call<int64_t, int32_t>(4));
         Assert::AreEqual<int64_t>(5,  convert_op_t::call<int64_t, int64_t>(5));
         Assert::AreEqual<int64_t>(6,  convert_op_t::call<int64_t, uint8_t>(6));
         Assert::AreEqual<int64_t>(7,  convert_op_t::call<int64_t, uint16_t>(7));
         Assert::AreEqual<int64_t>(8,  convert_op_t::call<int64_t, uint32_t>(8));
         Assert::AreEqual<int64_t>(9,  convert_op_t::call<int64_t, uint64_t>(9));
         Assert::AreEqual<int64_t>(10, convert_op_t::call<int64_t, float>(10.f));
         Assert::AreEqual<int64_t>(11, convert_op_t::call<int64_t, double>(11.));

         Assert::AreEqual<double>(1.,  convert_op_t::call<double, bool>(true));
         Assert::AreEqual<double>(65., convert_op_t::call<double, char>('A'));
         Assert::AreEqual<double>(66., convert_op_t::call<double, wchar_t>(L'B'));
         Assert::AreEqual<double>(2.,  convert_op_t::call<double, int8_t>(2));
         Assert::AreEqual<double>(3.,  convert_op_t::call<double, int16_t>(3));
         Assert::AreEqual<double>(4.,  convert_op_t::call<double, int32_t>(4));
         Assert::AreEqual<double>(5.,  convert_op_t::call<double, int64_t>(5));
         Assert::AreEqual<double>(6.,  convert_op_t::call<double, uint8_t>(6));
         Assert::AreEqual<double>(7.,  convert_op_t::call<double, uint16_t>(7));
         Assert::AreEqual<double>(8.,  convert_op_t::call<double, uint32_t>(8));
         Assert::AreEqual<double>(9.,  convert_op_t::call<double, uint64_t>(9));
         Assert::AreEqual<double>(10., convert_op_t::call<double, float>(10.f));
         Assert::AreEqual<double>(11., convert_op_t::call<double, double>(11.));

         array_t a1; a1.grow() = 2;

         dict_t d1; d1[ns::angle] = 45.;

         Assert::AreEqual<bool>(true, convert_op_t::call<bool, bool>(true));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, char>('A'));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, wchar_t>(L'B'));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, int8_t>(2));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, int16_t>(3));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, int32_t>(4));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, int64_t>(5));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, uint8_t>(6));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, uint16_t>(7));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, uint32_t>(8));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, uint64_t>(9));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, float>(10.f));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, double>(11.));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, name_t>(ns::above));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, array_t>(a1));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, dict_t>(d1));
         Assert::AreEqual<bool>(true, convert_op_t::call<bool, text_t>(L"hello"));

         Assert::AreEqual<bool>(false, convert_op_t::call<bool, bool>(false));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, char>('\0'));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, wchar_t>(L'\0'));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, int8_t>(0));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, int16_t>(0));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, int32_t>(0));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, int64_t>(0));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, uint8_t>(0));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, uint16_t>(0));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, uint32_t>(0));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, uint64_t>(0));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, float>(0.f));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, double>(0.));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, name_t>(name_t()));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, array_t>(array_t::empty));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, dict_t>(dict_t::empty));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, text_t>(text_t()));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, str_ptr_t>(nullptr));
         Assert::AreEqual<bool>(false, convert_op_t::call<bool, str_ptr_t>(L""));

         //Assert::AreEqual<array_t>(convert_op_t::call<array_t, dict_t>());
      }
   };
}
