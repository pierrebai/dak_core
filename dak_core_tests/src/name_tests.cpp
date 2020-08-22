#include <CppUnitTest.h>

#include <dak/core/name.h>
#include <dak/tests/helpers.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;
using namespace std;

namespace tests
{		
   TEST_CLASS(name_tests)
	{
	public:
		TEST_METHOD(name_base)
		{
         initialize_names();

         name_t n = ns::key;

         // Root is valid.
         Assert::IsTrue(n != name_t());

         // Note: two roots are not equal.
         Assert::AreNotEqual(n, name_t());
         Assert::AreNotEqual(n, (const name_t&)ns::rect);

         // Note: two roots are not equal.
         Assert::IsFalse(n == name_t());
         Assert::IsTrue( n != name_t());

         // We cannot predict the address the sub-names will be.
         //Assert::IsFalse(n <  name_t());
         //Assert::IsTrue( n <= name_t());
         //Assert::IsFalse(n >  name_t());
         //Assert::IsTrue( n >= name_t());

         Assert::IsFalse(n == ns::rect);
         Assert::IsTrue( n != ns::rect);
      }

      TEST_METHOD(name_derived)
      {
         initialize_names();

         name_t r(ns::rect);

         Assert::IsTrue(r != name_t());

         Assert::AreNotEqual((const name_t&)r, name_t());
         Assert::AreEqual(r, ns::rect);

         Assert::IsTrue( r == ns::rect);
         Assert::IsFalse(r != ns::rect);

         // We cannot predict the address the sub-names will be.
         //Assert::IsFalse(r < ns::rect);
         //Assert::IsTrue( r <= ns::rect);
         //Assert::IsFalse(r > ns::rect);
         //Assert::IsTrue( r >= ns::rect);

         Assert::IsFalse(r == name_t());
         Assert::IsTrue(r != name_t());
      }

   };
}
