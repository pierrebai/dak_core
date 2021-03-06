#include "CppUnitTest.h"

#include <dak/core/array.h>
#include <dak/core/any_compare_op.h>
#include <dak/tests/helpers.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;

namespace tests
{		
   TEST_CLASS(array_tests)
	{
	public:
		TEST_METHOD(array_base)
		{
         array_t a;

         Assert::AreEqual<index_t>(0, a.size());

         a.grow() = 3;
         a.grow() = 4;
         a.grow() = 5.0;
         a.grow() = L"6";

         Assert::AreEqual<index_t>(4, a.size());

         Assert::AreEqual<int32_t>(3, a[0]);
         Assert::AreEqual<int64_t>(4, a[1]);
         Assert::AreEqual<double>(5.0, a[2]);
         Assert::AreEqual<text_t>(L"6", a[3]);

         Assert::IsFalse(a.erase(5));
         Assert::IsFalse(a.erase(4));
         Assert::IsTrue(a.erase(3));
         Assert::IsTrue(a.erase(2));
         Assert::IsTrue(a.erase(1));
         Assert::IsTrue(a.erase(0));

         Assert::AreEqual<index_t>(0, a.size());
      }

      TEST_METHOD(array_append)
      {
         array_t a1;

         a1.grow() = 3;
         a1.grow() = int64_t(4);
         a1.grow() = 5.0;
         a1.grow() = L"6";

         array_t a2;

         a2 += a1;

         Assert::AreEqual<index_t>(4, a1.size());
         Assert::AreEqual<index_t>(4, a2.size());

         Assert::AreEqual<int32_t>(3, a2[0]);
         Assert::AreEqual<int64_t>(4, a2[1]);
         Assert::AreEqual<double>(5.0, a2[2]);
         Assert::AreEqual<text_t>(L"6", a2[3]);

         Assert::AreEqual(a1, a2);
      }

      TEST_METHOD(array_insert)
      {
         array_t a1;

         a1.grow() = 3;
         a1.grow() = 4;
         a1.grow() = 5.0;
         a1.grow() = L"6";

         a1.insert(1) = 33;

         Assert::AreEqual<index_t>(5, a1.size());

         Assert::AreEqual<int32_t>(3, a1[0]);
         Assert::AreEqual<int32_t>(33, a1[1]);
         Assert::AreEqual<int64_t>(4, a1[2]);
         Assert::AreEqual<double>(5.0, a1[3]);
         Assert::AreEqual<text_t>(L"6", a1[4]);
      }

      TEST_METHOD(array_iterator)
      {
         array_t a1;

         a1.grow() = 3;
         a1.grow() = 4ll;
         a1.grow() = 5.0;
         a1.grow() = L"6";

         int32_t count = 0;
         for (const any_var_t& e : a1)
         {
            count += 1;
            switch (count)
            {
               case 1:
                  Assert::AreEqual<int32_t>(3, e);
                  break;
               case 2:
                  Assert::AreEqual<int64_t>(4, e);
                  break;
               case 3:
                  Assert::AreEqual<double>(5.0, e);
                  break;
               case 4:
                  Assert::AreEqual<text_t>(L"6", e);
                  break;
            }
         }

         Assert::AreEqual(4, count);
      }
      TEST_METHOD(array_negative_index)
      {
         array_t a1;

         a1[-1] = 3.;

         Assert::AreEqual<index_t>(1, a1.size());
         Assert::AreEqual<double>(3., a1[0]);

         a1[-7] = L"first";

         Assert::AreEqual<index_t>(7, a1.size());
         Assert::AreEqual<text_t>(text_t(L"first"), a1[0]);
         Assert::AreEqual(any_var_t::empty, a1[1]);
         Assert::AreEqual(any_var_t::empty, a1[2]);
         Assert::AreEqual(any_var_t::empty, a1[3]);
         Assert::AreEqual(any_var_t::empty, a1[4]);
         Assert::AreEqual(any_var_t::empty, a1[5]);
         Assert::AreEqual(any_var_t::empty, a1[6]);

         // Note: insert inserts before the index_t given, so -1 inserts before the last any_var_t.
         a1.insert(-1) = 8;
         Assert::AreEqual<index_t>(8, a1.size());
         Assert::AreEqual<int64_t>(8, a1[6]);
         Assert::AreEqual<int64_t>(0, a1[7]);

         Assert::IsFalse(a1.erase(-9));
         Assert::AreEqual<index_t>(8, a1.size());
         Assert::AreEqual<text_t>(text_t(L"first"), a1[0]);

         Assert::IsTrue(a1.erase(-8));
         Assert::AreEqual<index_t>(7, a1.size());
         Assert::AreEqual(any_var_t::empty, a1[0]);

         Assert::IsTrue(a1.erase(-1));
         Assert::AreEqual<index_t>(6, a1.size());
         Assert::AreEqual<int64_t>(8, a1[5]);
      }

      TEST_METHOD(array_compare)
      {
         compare_op_t::register_ops();

         array_t a_empty;
         array_t a_small1;
         array_t a_small2;
         array_t a_big1;
         array_t a_big2;

         a_small1.grow() = 2;

         a_small2.grow() = 3;

         a_big1.grow() = 3;
         a_big1.grow() = 4;

         a_big2.grow() = 4;

         Assert::IsFalse(a_empty < a_empty);
         Assert::IsTrue(a_empty < a_small1);
         Assert::IsTrue(a_empty < a_small2);
         Assert::IsTrue(a_empty < a_big1);
         Assert::IsTrue(a_empty < a_big2);

         Assert::IsFalse(a_small1 < a_empty);
         Assert::IsFalse(a_small1 < a_small1);
         Assert::IsTrue(a_small1 < a_small2);
         Assert::IsTrue(a_small1 < a_big1);
         Assert::IsTrue(a_small1 < a_big2);

         Assert::IsFalse(a_small2 < a_empty);
         Assert::IsFalse(a_small2 < a_small1);
         Assert::IsFalse(a_small2 < a_small2);
         Assert::IsTrue(a_small2 < a_big1);
         Assert::IsTrue(a_small2 < a_big2);

         Assert::IsFalse(a_big1 < a_empty);
         Assert::IsFalse(a_big1 < a_small1);
         Assert::IsFalse(a_big1 < a_small2);
         Assert::IsFalse(a_big1 < a_big1);
         Assert::IsTrue(a_big1 < a_big2);

         Assert::IsFalse(a_big2 < a_empty);
         Assert::IsFalse(a_big2 < a_small1);
         Assert::IsFalse(a_big2 < a_small2);
         Assert::IsFalse(a_big2 < a_big1);
         Assert::IsFalse(a_big2 < a_big2);
      }

   };
}
