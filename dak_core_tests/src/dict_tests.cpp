#include <CppUnitTest.h>

#include <dak/core/dict.h>
#include <helpers.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;

namespace tests
{
   TEST_CLASS(dict_tests)
	{
	public:
		TEST_METHOD(dict_base)
		{
         dict_t d1;

         Assert::AreEqual<index_t>(0, d1.size());

         d1[name_t::window] = 3;
         d1[name_t::canvas] = 4;
         d1[name_t::point] = 5.0;
         d1[name_t::width] = L"6";
         d1[name_t::border] = name_t::window;

         Assert::AreEqual<index_t>(5, d1.size());

         Assert::AreEqual<int32_t>(3, d1[name_t::window]);
         Assert::AreEqual<int64_t>(4, d1[name_t::canvas]);
         Assert::AreEqual<double>(5.0, d1[name_t::point]);
         Assert::AreEqual<text_t>(L"6", d1[name_t::width]);
         Assert::AreEqual<name_t>(name_t::window, d1[name_t::border]);

         Assert::IsTrue(d1.erase(name_t::window));
         Assert::IsTrue(d1.erase(name_t::canvas));
         Assert::IsTrue(d1.erase(name_t::border));
         Assert::IsTrue(d1.erase(name_t::width));
         Assert::IsTrue(d1.erase(name_t::point));
         Assert::IsFalse(d1.erase(name_t::window));

         Assert::AreEqual<index_t>(0, d1.size());
      }

      TEST_METHOD(dict_append)
      {
         dict_t d1;

         d1[name_t::window] = 3;
         d1[name_t::canvas] = 4;
         d1[name_t::point] = 5.0;
         d1[name_t::width].as<dict_t>()[name_t::border] = name_t::window;

         dict_t d2;

         d2 += d1;

         Assert::AreEqual<index_t>(4, d1.size());
         Assert::AreEqual<index_t>(4, d2.size());

         Assert::AreEqual<int32_t>(3, d2[name_t::window]);
         Assert::AreEqual<int64>(4, d2[name_t::canvas]);
         Assert::AreEqual<double>(5.0, d2[name_t::point]);
         Assert::AreEqual<name_t>(name_t::window, d2[name_t::width].as<dict_t>()[name_t::border]);

         Assert::IsTrue(d2.contains(name_t::window));
         Assert::IsTrue(d2.contains(name_t::canvas));
         Assert::IsTrue(d2.contains(name_t::point));
         Assert::IsTrue(d2.contains(name_t::width));
         Assert::IsTrue(d2.contains(name_t::width));
         Assert::IsTrue(d2[name_t::width].as<dict_t>().contains(name_t::border));

         Assert::AreEqual(d1, d2);
      }

      TEST_METHOD(dict_iterator)
      {
         dict_t d1;

         d1[name_t::window] = 3;
         d1[name_t::canvas] = 4;
         d1[name_t::point] = 5.0;
         d1[name_t::width] = L"6";

         int32_t count = 0;
         for (const auto& i : d1)
         {
            count += 1;
            if (i.first == name_t::window)
               Assert::AreEqual<int32_t>(3, i.second);
            if (i.first == name_t::canvas)
               Assert::AreEqual<int64>(4, i.second);
            if (i.first == name_t::point)
               Assert::AreEqual<double>(5.0, i.second);
            if (i.first == name_t::width)
               Assert::AreEqual<text_t>(L"6", i.second);
         }

         Assert::AreEqual(4, count);
      }
   };
}
