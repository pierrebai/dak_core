#include <CppUnitTest.h>

#include <dak/core/all.h>
#include <dak/tests/helpers.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;

namespace tests
{		
   TEST_CLASS(any_is_compatible_op_tests)
	{
	public:
		TEST_METHOD(is_compatible)
		{
         is_compatible_op_t::register_ops();

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
   };
}
