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
         Assert::IsTrue(is_compatible_op_t::call<int32_t, double>());
      }
   };
}
