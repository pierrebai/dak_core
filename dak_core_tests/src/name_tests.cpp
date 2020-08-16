#include <CppUnitTest.h>

#include <dak/core/name.h>
#include <helpers.h>

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
         name_t n = name_t::key;

         // Root is valid.
         Assert::IsTrue(n != name_t::invalid);

         // Note: two roots are not equal.
         Assert::AreNotEqual(n, name_t());
         Assert::AreNotEqual(n, (const name_t&)name_t::rect);

         // Note: two roots are not equal.
         Assert::IsFalse(n == name_t());
         Assert::IsTrue( n != name_t());

         // We cannot predict the address the sub-names will be.
         //Assert::IsFalse(n <  name_t());
         //Assert::IsTrue( n <= name_t());
         //Assert::IsFalse(n >  name_t());
         //Assert::IsTrue( n >= name_t());

         Assert::IsFalse(n == name_t::rect);
         Assert::IsTrue( n != name_t::rect);
      }

      TEST_METHOD(name_derived)
      {
         name_t r(name_t::rect);

         Assert::IsTrue(r != name_t::invalid);

         Assert::AreNotEqual((const name_t&)r, name_t());
         Assert::AreEqual(r, name_t::rect);

         Assert::IsTrue( r == name_t::rect);
         Assert::IsFalse(r != name_t::rect);

         // We cannot predict the address the sub-names will be.
         //Assert::IsFalse(r < name_t::rect);
         //Assert::IsTrue( r <= name_t::rect);
         //Assert::IsFalse(r > name_t::rect);
         //Assert::IsTrue( r >= name_t::rect);

         Assert::IsFalse(r == name_t());
         Assert::IsTrue(r != name_t());
      }

   };
}
