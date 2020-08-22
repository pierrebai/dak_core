#include "CppUnitTest.h"

#include "dak/core/stream.h"
#include "dak/tests/helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;
using namespace std;

namespace tests
{		
   TEST_CLASS(stream_tests)
	{
	public:
		TEST_METHOD(stream_base)
		{
         initialize_names();

         wstringstream ss;

         ss.clear();
         ss.str(L"");
         ss << ns::point;
         Assert::AreEqual(text_t(L"point"), ss.str());

         ss.clear();
         ss.str(L"");
         dict_t d1;
         ss << d1;
         Assert::AreEqual(text_t(L"{ }"), ss.str());

         ss.clear();
         ss.str(L"");
         dict_t d2;
         d2[ns::point] = 3;
         ss << d2;
         Assert::AreEqual(text_t(L"{ point : 3 , }"), ss.str());

         ss.clear();
         ss.str(L"");
         array_t a1;
         ss << a1;
         Assert::AreEqual(text_t(L"[ ]"), ss.str());

         ss.clear();
         ss.str(L"");
         array_t a2;
         a2.grow() = 3;
         a2.grow() = 5;
         a2.grow() = 7;
         ss << a2;
         Assert::AreEqual(text_t(L"[ 3 , 5 , 7 , ]"), ss.str());

      }
   };
}
