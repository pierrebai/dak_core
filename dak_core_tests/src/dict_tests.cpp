#include <CppUnitTest.h>

#include <dak/core/dict.h>
#include <dak/core/any_compare_op.h>
#include <dak/tests/helpers.h>

#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;

namespace tests
{
   TEST_CLASS(dict_tests)
	{
	public:
		TEST_METHOD(dict_base)
		{
         initialize_names();

         dict_t d1;

         Assert::AreEqual<index_t>(0, d1.size());

         d1[ns::window] = 3;
         d1[ns::canvas] = 4;
         d1[ns::point] = 5.0;
         d1[ns::width] = L"6";
         d1[ns::border] = ns::window;

         Assert::AreEqual<index_t>(5, d1.size());

         Assert::AreEqual<int32_t>(3, d1[ns::window]);
         Assert::AreEqual<int64_t>(4, d1[ns::canvas]);
         Assert::AreEqual<double>(5.0, d1[ns::point]);
         Assert::AreEqual<text_t>(L"6", d1[ns::width]);
         Assert::AreEqual<name_t>(ns::window, d1[ns::border]);

         Assert::IsTrue(d1.erase(ns::window));
         Assert::IsTrue(d1.erase(ns::canvas));
         Assert::IsTrue(d1.erase(ns::border));
         Assert::IsTrue(d1.erase(ns::width));
         Assert::IsTrue(d1.erase(ns::point));
         Assert::IsFalse(d1.erase(ns::window));

         Assert::AreEqual<index_t>(0, d1.size());
      }

      TEST_METHOD(dict_append)
      {
         initialize_names();

         dict_t d1;

         d1[ns::window] = 3;
         d1[ns::canvas] = int64_t(4);
         d1[ns::point] = 5.0;
         d1[ns::width].as<dict_t>()[ns::border] = ns::window;

         dict_t d2;

         d2 += d1;

         Assert::AreEqual<index_t>(4, d1.size());
         Assert::AreEqual<index_t>(4, d2.size());

         Assert::AreEqual<int32_t>(3, d2[ns::window]);
         Assert::AreEqual<int64_t>(4, d2[ns::canvas]);
         Assert::AreEqual<double>(5.0, d2[ns::point]);
         Assert::AreEqual<name_t>(ns::window, d2[ns::width].as<dict_t>()[ns::border]);

         Assert::IsTrue(d2.contains(ns::window));
         Assert::IsTrue(d2.contains(ns::canvas));
         Assert::IsTrue(d2.contains(ns::point));
         Assert::IsTrue(d2.contains(ns::width));
         Assert::IsTrue(d2.contains(ns::width));
         Assert::IsTrue(d2[ns::width].as<dict_t>().contains(ns::border));

         Assert::AreEqual(d1, d2);
      }

      TEST_METHOD(dict_iterator)
      {
         initialize_names();

         dict_t d1;

         d1[ns::window] = 3;
         d1[ns::canvas] = int64_t(4);
         d1[ns::point] = 5.0;
         d1[ns::width] = L"6";

         int32_t count = 0;
         for (const auto& i : d1)
         {
            count += 1;
            if (i.first == ns::window)
               Assert::AreEqual<int32_t>(3, i.second);
            if (i.first == ns::canvas)
               Assert::AreEqual<int64>(4, i.second);
            if (i.first == ns::point)
               Assert::AreEqual<double>(5.0, i.second);
            if (i.first == ns::width)
               Assert::AreEqual<text_t>(L"6", i.second);
         }

         Assert::AreEqual(4, count);
      }

      TEST_METHOD(dict_compare)
      {
         compare_op_t::register_ops();

         dict_t d_empty;
         dict_t d_small1;
         dict_t d_small2;
         dict_t d_big1;
         dict_t d_big2;

         // Note: name_t is not sorted alphabetically.
         name_t names[] = { ns::a, ns::b, ns::c };
         std::sort(names, names + 3);

         d_small1[names[0]] = 2;

         d_small2[names[1]] = 3;

         d_big1[names[1]] = 4;

         d_big2[names[1]] = 4;
         d_big2[names[2]] = 4;

         Assert::IsFalse(d_empty < d_empty);
         Assert::IsTrue(d_empty < d_small1);
         Assert::IsTrue(d_empty < d_small2);
         Assert::IsTrue(d_empty < d_big1);
         Assert::IsTrue(d_empty < d_big2);

         Assert::IsFalse(d_small1 < d_empty);
         Assert::IsFalse(d_small1 < d_small1);
         Assert::IsTrue(d_small1 < d_small2);
         Assert::IsTrue(d_small1 < d_big1);
         Assert::IsTrue(d_small1 < d_big2);

         Assert::IsFalse(d_small2 < d_empty);
         Assert::IsFalse(d_small2 < d_small1);
         Assert::IsFalse(d_small2 < d_small2);
         Assert::IsTrue(d_small2 < d_big1);
         Assert::IsTrue(d_small2 < d_big2);

         Assert::IsFalse(d_big1 < d_empty);
         Assert::IsFalse(d_big1 < d_small1);
         Assert::IsFalse(d_big1 < d_small2);
         Assert::IsFalse(d_big1 < d_big1);
         Assert::IsTrue(d_big1 < d_big2);

         Assert::IsFalse(d_big2 < d_empty);
         Assert::IsFalse(d_big2 < d_small1);
         Assert::IsFalse(d_big2 < d_small2);
         Assert::IsFalse(d_big2 < d_big1);
         Assert::IsFalse(d_big2 < d_big2);
      }

   };
}
