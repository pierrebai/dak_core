#include <CppUnitTest.h>

#include <dak/core/var.h>
#include <tests_helpers.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak_ns::core_ns;

namespace tests
{		
   TEST_CLASS(var_tests)
	{
	public:
		TEST_METHOD(element_base)
		{
         any_var_t e;

         Assert::AreEqual(e, any_var_t());
         Assert::AreEqual(e, any_var_t::empty);
         Assert::AreNotEqual(e, any_var_t(1));

         Assert::IsTrue( e == any_var_t());
         Assert::IsTrue(e == any_var_t::empty);
         Assert::IsFalse(e != any_var_t());

         Assert::IsFalse(e == any_var_t(1));
         Assert::IsFalse(any_var_t::empty == any_var_t(1));
         Assert::IsTrue(e != any_var_t(1));
      }

      TEST_METHOD(element_constructors)
      {
         any_var_t e_u;
         any_var_t e_t1(text_t(L"text_t"));
         any_var_t e_t2(L"strptr");
         any_var_t e_c1('c');
         any_var_t e_c2(L'w');
         any_var_t e_b(true);
         any_var_t e_i2((int16_t)2);
         any_var_t e_i1((int32_t)1);
         any_var_t e_i3((int64_t)3);
         any_var_t e_u1((uint16_t)4u);
         any_var_t e_u2((uint32_t)5u);
         any_var_t e_u3((uint64_t)6u);
         any_var_t e_r1(7.0f);
         any_var_t e_r2(8.0);
         any_var_t e_a((array_t()));
         any_var_t e_d((dict_t()));
         any_var_t e_n(ns::view);

         Assert::AreEqual(typeid(void), e_u.get_type());
         Assert::AreEqual(typeid(text_t), e_t1.get_type());
         Assert::AreEqual(typeid(text_t), e_t2.get_type());
         Assert::AreEqual(typeid(char), e_c1.get_type());
         Assert::AreEqual(typeid(wchar_t), e_c2.get_type());
         Assert::AreEqual(typeid(bool), e_b.get_type());
         Assert::AreEqual(typeid(int16_t), e_i2.get_type());
         Assert::AreEqual(typeid(int32_t), e_i1.get_type());
         Assert::AreEqual(typeid(int64_t), e_i3.get_type());
         Assert::AreEqual(typeid(uint16_t), e_u1.get_type());
         Assert::AreEqual(typeid(uint32_t), e_u2.get_type());
         Assert::AreEqual(typeid(uint64_t), e_u3.get_type());
         Assert::AreEqual(typeid(float), e_r1.get_type());
         Assert::AreEqual(typeid(double), e_r2.get_type());
         Assert::AreEqual(typeid(array_t), e_a.get_type());
         Assert::AreEqual(typeid(dict_t), e_d.get_type());
         Assert::AreEqual(typeid(name_t), e_n.get_type());
      }

      TEST_METHOD(element_assignments)
      {
         any_var_t e_u;
         any_var_t e_t1;
         any_var_t e_t2;
         any_var_t e_c1;
         any_var_t e_c2;
         any_var_t e_b;
         any_var_t e_i2;
         any_var_t e_i1;
         any_var_t e_i3;
         any_var_t e_u1;
         any_var_t e_u2;
         any_var_t e_u3;
         any_var_t e_r1;
         any_var_t e_r2;
         any_var_t e_a;
         any_var_t e_d;
         any_var_t e_n;

         e_u  = any_var_t();
         e_t1 = text_t(L"text_t");
         e_t2 = L"strptr";
         e_c1 = 'c';
         e_c2 = L'w';
         e_b  = true;
         e_i2 = (int16_t)2;
         e_i1 = (int32_t)1;
         e_i3 = (int64_t)3;
         e_u1 = (uint16_t)4u;
         e_u2 = (uint32_t)5u;
         e_u3 = (uint64_t)6u;
         e_r1 = 7.0f;
         e_r2 = 8.0;
         e_a  = array_t();
         e_d  = dict_t();
         e_n  = ns::view;

         Assert::AreEqual(typeid(void), e_u.get_type());
         Assert::AreEqual(typeid(text_t), e_t1.get_type());
         Assert::AreEqual(typeid(text_t), e_t2.get_type());
         Assert::AreEqual(typeid(char), e_c1.get_type());
         Assert::AreEqual(typeid(wchar_t), e_c2.get_type());
         Assert::AreEqual(typeid(bool), e_b.get_type());
         Assert::AreEqual(typeid(int16_t), e_i2.get_type());
         Assert::AreEqual(typeid(int32_t), e_i1.get_type());
         Assert::AreEqual(typeid(int64_t), e_i3.get_type());
         Assert::AreEqual(typeid(uint16_t), e_u1.get_type());
         Assert::AreEqual(typeid(uint32_t), e_u2.get_type());
         Assert::AreEqual(typeid(uint64_t), e_u3.get_type());
         Assert::AreEqual(typeid(float), e_r1.get_type());
         Assert::AreEqual(typeid(double), e_r2.get_type());
         Assert::AreEqual(typeid(array_t), e_a.get_type());
         Assert::AreEqual(typeid(dict_t), e_d.get_type());
         Assert::AreEqual(typeid(name_t), e_n.get_type());
      }

      TEST_METHOD(var_text_assignments)
      {
         any_var_t e1;

         e1 = L"hello";
         Assert::AreEqual<text_t>(text_t(L"hello"), e1);

         e1 = (str_ptr_t)nullptr;
         Assert::AreEqual<text_t>(text_t(L""), e1);

         e1 = L"bye";
         Assert::AreEqual<text_t>(text_t(L"bye"), e1);
      }

      TEST_METHOD(element_conversion)
      {
         any_var_t e_u;
         any_var_t e_t1(text_t(L"text_t"));
         any_var_t e_t2(L"strptr");
         any_var_t e_c1('c');
         any_var_t e_c2(L'w');
         any_var_t e_b(true);
         any_var_t e_i2((int16_t)2);
         any_var_t e_i1((int32_t)1);
         any_var_t e_i3((int64_t)3);
         any_var_t e_u1((uint16_t)4u);
         any_var_t e_u2((uint32_t)5u);
         any_var_t e_u3((uint64_t)6u);
         any_var_t e_r1(7.0f);
         any_var_t e_r2(8.0);
         any_var_t e_a((array_t()));
         any_var_t e_d((dict_t()));
         any_var_t e_n(ns::view);

         Assert::AreEqual<int32_t>(0, e_u);
         Assert::AreEqual<text_t>(text_t(L"text_t"), e_t1);
         Assert::AreEqual<text_t>(L"strptr", e_t2);
         Assert::AreEqual<char>('c', e_c1);
         Assert::AreEqual<wchar_t>(L'w', e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<int16_t>((int16_t)2, e_i2);
         Assert::AreEqual<int32_t>((int32_t)1, e_i1);
         Assert::AreEqual<int64_t>((int64_t)3, e_i3);
         Assert::AreEqual<uint16_t>((uint16_t)4u, e_u1);
         Assert::AreEqual<uint32_t>((uint32_t)5u, e_u2);
         Assert::AreEqual<uint64_t>((uint64_t)6u, e_u3);
         Assert::AreEqual<float>(7.0f, e_r1);
         Assert::AreEqual<double>(8.0, e_r2);
         Assert::AreEqual<array_t>((array_t()), e_a);
         Assert::AreEqual<dict_t>((dict_t()), e_d);
         Assert::AreEqual<name_t>(ns::view, e_n);
      }

      TEST_METHOD(element_const_conversion)
      {
         const any_var_t e_u;
         const any_var_t e_t1(text_t(L"text_t"));
         const any_var_t e_t2(L"strptr");
         const any_var_t e_c1('c');
         const any_var_t e_c2(L'w');
         const any_var_t e_b(true);
         const any_var_t e_i2((int16_t)2);
         const any_var_t e_i1((int32_t)1);
         const any_var_t e_i3((int64_t)3);
         const any_var_t e_u1((uint16_t)4u);
         const any_var_t e_u2((uint32_t)5u);
         const any_var_t e_u3((uint64_t)6u);
         const any_var_t e_r1(7.0f);
         const any_var_t e_r2(8.0);
         const any_var_t e_a((array_t()));
         const any_var_t e_d((dict_t()));
         const any_var_t e_n(ns::view);

         Assert::AreEqual<int32_t>(0, e_u);
         Assert::AreEqual<text_t>(text_t(L"text_t"), e_t1);
         Assert::AreEqual<text_t>(L"strptr", e_t2);
         Assert::AreEqual<char>('c', e_c1);
         Assert::AreEqual<wchar_t>(L'w', e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<int16_t>((int16_t)2, e_i2);
         Assert::AreEqual<int32_t>((int32_t)1, e_i1);
         Assert::AreEqual<int64_t>((int64_t)3, e_i3);
         Assert::AreEqual<uint16_t>((uint16_t)4u, e_u1);
         Assert::AreEqual<uint32_t>((uint32_t)5u, e_u2);
         Assert::AreEqual<uint64_t>((uint64_t)6u, e_u3);
         Assert::AreEqual<float>(7.0f, e_r1);
         Assert::AreEqual<double>(8.0, e_r2);
         Assert::AreEqual<array_t>((array_t()), e_a);
         Assert::AreEqual<dict_t>((dict_t()), e_d);
         Assert::AreEqual<name_t>(ns::view, e_n);
      }

      TEST_METHOD(element_unknown_assignments)
      {
         any_var_t e_u;
         any_var_t e_t1(text_t(L"text_t"));
         any_var_t e_t2(L"strptr");
         any_var_t e_c1('c');
         any_var_t e_c2(L'w');
         any_var_t e_b(true);
         any_var_t e_i2((int16_t)2);
         any_var_t e_i1((int32_t)1);
         any_var_t e_i3((int64_t)3);
         any_var_t e_u1((uint16_t)4u);
         any_var_t e_u2((uint32_t)5u);
         any_var_t e_u3((uint64_t)6u);
         any_var_t e_r1(7.0f);
         any_var_t e_r2(8.0);
         any_var_t e_a((array_t()));
         any_var_t e_d((dict_t()));
         any_var_t e_n(ns::view);

         // Assigning an empty any_var_t of get_type void
         // should set the get_type to void and reset the value.
         e_u = any_var_t();
         e_t1 = any_var_t();
         e_t2 = any_var_t();
         e_c1 = any_var_t();
         e_c2 = any_var_t();
         e_b = any_var_t();
         e_i2 = any_var_t();
         e_i1 = any_var_t();
         e_i3 = any_var_t();
         e_u1 = any_var_t();
         e_u2 = any_var_t();
         e_u3 = any_var_t();
         e_r1 = any_var_t();
         e_r2 = any_var_t();
         e_a = any_var_t();
         e_d = any_var_t();
         e_n = any_var_t();

         Assert::AreEqual(typeid(void), e_u.get_type());
         Assert::AreEqual(typeid(void), e_t1.get_type());
         Assert::AreEqual(typeid(void), e_t2.get_type());
         Assert::AreEqual(typeid(void), e_c1.get_type());
         Assert::AreEqual(typeid(void), e_c2.get_type());
         Assert::AreEqual(typeid(void), e_b.get_type());
         Assert::AreEqual(typeid(void), e_i2.get_type());
         Assert::AreEqual(typeid(void), e_i1.get_type());
         Assert::AreEqual(typeid(void), e_i3.get_type());
         Assert::AreEqual(typeid(void), e_u1.get_type());
         Assert::AreEqual(typeid(void), e_u2.get_type());
         Assert::AreEqual(typeid(void), e_u3.get_type());
         Assert::AreEqual(typeid(void), e_r1.get_type());
         Assert::AreEqual(typeid(void), e_r2.get_type());
         Assert::AreEqual(typeid(void), e_a.get_type());
         Assert::AreEqual(typeid(void), e_d.get_type());
         Assert::AreEqual(typeid(void), e_n.get_type());

         Assert::AreEqual<int32_t>(0, e_u);
         Assert::AreEqual<text_t>(text_t(L""), e_t1);
         Assert::AreEqual<text_t>(L"", e_t2);
         Assert::AreEqual<char>('\0', e_c1);
         Assert::AreEqual<wchar_t>(L'\0', e_c2);
         Assert::AreEqual<bool>(false, e_b);
         Assert::AreEqual<int16_t>((int16_t)0, e_i2);
         Assert::AreEqual<int32_t>((int32_t)0, e_i1);
         Assert::AreEqual<int64_t>((int64_t)0, e_i3);
         Assert::AreEqual<uint16_t>((uint16_t)0u, e_u1);
         Assert::AreEqual<uint32_t>((uint32_t)0u, e_u2);
         Assert::AreEqual<uint64_t>((uint64_t)0u, e_u3);
         Assert::AreEqual<float>(0.0f, e_r1);
         Assert::AreEqual<double>(0.0, e_r2);
         Assert::AreEqual<array_t>((array_t()), e_a);
         Assert::AreEqual<dict_t>((dict_t()), e_d);
         Assert::AreEqual<name_t>(name_t(), e_n);
      }

      TEST_METHOD(element_size)
      {
         dict_t d;
         d[ns::view] = 33;
         d[ns::vector] = 4;
         d[ns::matrix] = 5;

         array_t a;
         a.grow() = 55;
         a.grow() = 66;
         a.grow() = 77;

         const any_var_t e_u;
         const any_var_t e_t1(text_t(L"text_t"));
         const any_var_t e_t2(L"strptr");
         const any_var_t e_c1('c');
         const any_var_t e_c2(L'w');
         const any_var_t e_b(true);
         const any_var_t e_i2((int16_t)2);
         const any_var_t e_i1((int32_t)1);
         const any_var_t e_i3((int64_t)3);
         const any_var_t e_u1((uint16_t)4u);
         const any_var_t e_u2((uint32_t)5u);
         const any_var_t e_u3((uint64_t)6u);
         const any_var_t e_r1(7.0f);
         const any_var_t e_r2(8.0);
         const any_var_t e_a(a);
         const any_var_t e_d(d);
         const any_var_t e_n(ns::view);

         //Assert::AreEqual<index_t>(0, e_u.size());
         //Assert::AreEqual<index_t>(4, e_t1.size());
         //Assert::AreEqual<index_t>(6, e_t2.size());
         //Assert::AreEqual<index_t>(0, e_c1.size());
         //Assert::AreEqual<index_t>(0, e_c2.size());
         //Assert::AreEqual<index_t>(0, e_b.size());
         //Assert::AreEqual<index_t>(0, e_i2.size());
         //Assert::AreEqual<index_t>(0, e_i1.size());
         //Assert::AreEqual<index_t>(0, e_i3.size());
         //Assert::AreEqual<index_t>(0, e_u1.size());
         //Assert::AreEqual<index_t>(0, e_u2.size());
         //Assert::AreEqual<index_t>(0, e_u3.size());
         //Assert::AreEqual<index_t>(0, e_r1.size());
         //Assert::AreEqual<index_t>(0, e_r2.size());
         //Assert::AreEqual<index_t>(3, e_a.size());
         //Assert::AreEqual<index_t>(3, e_d.size());
         //Assert::AreEqual<index_t>(0, e_n.size());
      }

      TEST_METHOD(element_compatible)
      {
         dict_t d;
         d[ns::view] = 33;
         d[ns::vector] = 4;
         d[ns::matrix] = 5;

         array_t a;
         a.grow() = 55;
         a.grow() = 66;
         a.grow() = 77;

         const any_var_t e_u;
         const any_var_t e_t1(text_t(L"text_t"));
         const any_var_t e_t2(L"strptr");
         const any_var_t e_c1('c');
         const any_var_t e_c2(L'w');
         const any_var_t e_b(true);
         const any_var_t e_i2((int16_t)2);
         const any_var_t e_i1((int32_t)1);
         const any_var_t e_i3((int64_t)3);
         const any_var_t e_u1((uint16_t)4u);
         const any_var_t e_u2((uint32_t)5u);
         const any_var_t e_u3((uint64_t)6u);
         const any_var_t e_r1(7.0f);
         const any_var_t e_r2(8.0);
         const any_var_t e_a(a);
         const any_var_t e_d(d);
         const any_var_t e_n(ns::view);

         Assert::IsTrue(e_t1.compatible<text_t>());
         Assert::IsTrue(e_t2.compatible<text_t>());
         Assert::IsTrue(e_c1.compatible<int64_t>());
         Assert::IsTrue(e_c2.compatible<int64_t>());
         Assert::IsTrue(e_b.compatible<bool>());
         Assert::IsTrue(e_i2.compatible<int64_t>());
         Assert::IsTrue(e_i1.compatible<int64_t>());
         Assert::IsTrue(e_i3.compatible<int64_t>());
         Assert::IsTrue(e_u1.compatible<int64_t>());
         Assert::IsTrue(e_u2.compatible<int64_t>());
         Assert::IsTrue(e_u3.compatible<int64_t>());
         Assert::IsTrue(e_r1.compatible<double>());
         Assert::IsTrue(e_r2.compatible<double>());
         Assert::IsTrue(e_a.compatible<array_t>());
         Assert::IsTrue(e_d.compatible<dict_t>());
         Assert::IsTrue(e_n.compatible<name_t>());

         Assert::IsTrue(e_b.compatible<int64_t>());
         Assert::IsTrue(e_i2.compatible<bool>());
         Assert::IsTrue(e_i1.compatible<bool>());
         Assert::IsTrue(e_i3.compatible<bool>());
         Assert::IsTrue(e_u1.compatible<bool>());
         Assert::IsTrue(e_u2.compatible<bool>());
         Assert::IsTrue(e_u3.compatible<bool>());

         Assert::IsFalse(e_u.compatible<text_t>());
         Assert::IsFalse(e_t1.compatible<int64_t>());
         Assert::IsFalse(e_t2.compatible<int64_t>());
         Assert::IsTrue(e_c1.compatible<double>());
         Assert::IsTrue(e_b.compatible<double>());
         Assert::IsFalse(e_i2.compatible<text_t>());
         Assert::IsFalse(e_i1.compatible<array_t>());
         Assert::IsFalse(e_i3.compatible<dict_t>());
         Assert::IsFalse(e_u1.compatible<name_t>());
         Assert::IsTrue(e_u3.compatible<double>());
         Assert::IsTrue(e_r1.compatible<int64_t>());
         Assert::IsFalse(e_r2.compatible<name_t>());
         Assert::IsFalse(e_a.compatible<dict_t>());
         Assert::IsTrue(e_d.compatible<array_t>());
         Assert::IsFalse(e_n.compatible<int64_t>());
      }

      TEST_METHOD(element_reset)
      {
         dict_t d;
         d[ns::view] = 33;
         d[ns::vector] = 4;
         d[ns::matrix] = 5;

         array_t a;
         a.grow() = 55;
         a.grow() = 66;
         a.grow() = 77;

         any_var_t e_u;
         any_var_t e_t1(text_t(L"text_t"));
         any_var_t e_t2(L"strptr");
         any_var_t e_c1('c');
         any_var_t e_c2(L'w');
         any_var_t e_b(true);
         any_var_t e_i2((int16_t)2);
         any_var_t e_i1((int32_t)1);
         any_var_t e_i3((int64_t)3);
         any_var_t e_u1((uint16_t)4u);
         any_var_t e_u2((uint32_t)5u);
         any_var_t e_u3((uint64_t)6u);
         any_var_t e_r1(7.0f);
         any_var_t e_r2(8.0);
         any_var_t e_a(a);
         any_var_t e_d(d);
         any_var_t e_n(ns::view);

         e_u.reset();
         e_t1.reset();
         e_t2.reset();
         e_c1.reset();
         e_c2.reset();
         e_b.reset();
         e_i2.reset();
         e_i1.reset();
         e_i3.reset();
         e_u1.reset();
         e_u2.reset();
         e_u3.reset();
         e_r1.reset();
         e_r2.reset();
         e_a.reset();
         e_d.reset();
         e_n.reset();

         Assert::AreEqual(typeid(void), e_u.get_type());
         Assert::AreEqual(typeid(void), e_t1.get_type());
         Assert::AreEqual(typeid(void), e_t2.get_type());
         Assert::AreEqual(typeid(void), e_c1.get_type());
         Assert::AreEqual(typeid(void), e_c2.get_type());
         Assert::AreEqual(typeid(void), e_b.get_type());
         Assert::AreEqual(typeid(void), e_i2.get_type());
         Assert::AreEqual(typeid(void), e_i1.get_type());
         Assert::AreEqual(typeid(void), e_i3.get_type());
         Assert::AreEqual(typeid(void), e_u1.get_type());
         Assert::AreEqual(typeid(void), e_u2.get_type());
         Assert::AreEqual(typeid(void), e_u3.get_type());
         Assert::AreEqual(typeid(void), e_r1.get_type());
         Assert::AreEqual(typeid(void), e_r2.get_type());
         Assert::AreEqual(typeid(void), e_a.get_type());
         Assert::AreEqual(typeid(void), e_d.get_type());
         Assert::AreEqual(typeid(void), e_n.get_type());
      }

      TEST_METHOD(element_ensure)
      {
         any_var_t e_u;
         any_var_t e_t1;
         any_var_t e_t2;
         any_var_t e_c1;
         any_var_t e_c2;
         any_var_t e_b;
         any_var_t e_i2;
         any_var_t e_i1;
         any_var_t e_i3;
         any_var_t e_u1;
         any_var_t e_u2;
         any_var_t e_u3;
         any_var_t e_r1;
         any_var_t e_r2;
         any_var_t e_a;
         any_var_t e_d;
         any_var_t e_n;

         e_u.reset();
         e_t1.ensure<text_t>();
         e_t2.ensure<text_t>();
         e_c1.ensure<char>();
         e_c2.ensure<wchar_t>();
         e_b.ensure<bool>();
         e_i2.ensure<int16_t>();
         e_i1.ensure<int32_t>();
         e_i3.ensure<int64_t>();
         e_u1.ensure<uint16_t>();
         e_u2.ensure<uint32_t>();
         e_u3.ensure<uint64_t>();
         e_r1.ensure<float>();
         e_r2.ensure<double>();
         e_a.ensure<array_t>();
         e_d.ensure<dict_t>();
         e_n.ensure<name_t>();

         Assert::AreEqual(typeid(void), e_u.get_type());
         Assert::AreEqual(typeid(text_t), e_t1.get_type());
         Assert::AreEqual(typeid(text_t), e_t2.get_type());
         Assert::AreEqual(typeid(char), e_c1.get_type());
         Assert::AreEqual(typeid(wchar_t), e_c2.get_type());
         Assert::AreEqual(typeid(bool), e_b.get_type());
         Assert::AreEqual(typeid(int16_t), e_i2.get_type());
         Assert::AreEqual(typeid(int32_t), e_i1.get_type());
         Assert::AreEqual(typeid(int64_t), e_i3.get_type());
         Assert::AreEqual(typeid(uint16_t), e_u1.get_type());
         Assert::AreEqual(typeid(uint32_t), e_u2.get_type());
         Assert::AreEqual(typeid(uint64_t), e_u3.get_type());
         Assert::AreEqual(typeid(float), e_r1.get_type());
         Assert::AreEqual(typeid(double), e_r2.get_type());
         Assert::AreEqual(typeid(array_t), e_a.get_type());
         Assert::AreEqual(typeid(dict_t), e_d.get_type());
         Assert::AreEqual(typeid(name_t), e_n.get_type());
      }

      TEST_METHOD(element_ensure_preserve_value)
      {
         dict_t d;
         d[ns::view] = 33;
         d[ns::vector] = 4;
         d[ns::matrix] = 5;

         array_t a;
         a.grow() = 55;
         a.grow() = 66;
         a.grow() = 77;

         any_var_t e_u;
         any_var_t e_t1(text_t(L"text_t"));
         any_var_t e_t2(L"strptr");
         any_var_t e_c1('c');
         any_var_t e_c2(L'w');
         any_var_t e_b(true);
         any_var_t e_i2((int16_t)2);
         any_var_t e_i1((int32_t)1);
         any_var_t e_i3((int64_t)3);
         any_var_t e_u1((uint16_t)4u);
         any_var_t e_u2((uint32_t)5u);
         any_var_t e_u3((uint64_t)6u);
         any_var_t e_r1(7.0f);
         any_var_t e_r2(8.0);
         any_var_t e_a(a);
         any_var_t e_d(d);
         any_var_t e_n(ns::view);

         // Ensuring the same get_type should not reset the value.
         e_u.reset();
         e_t1.ensure<text_t>();
         e_t2.ensure<text_t>();
         e_c1.ensure<char>();
         e_c2.ensure<wchar_t>();
         e_b.ensure<bool>();
         e_i2.ensure<int16_t>();
         e_i1.ensure<int32_t>();
         e_i3.ensure<int64_t>();
         e_u1.ensure<uint16_t>();
         e_u2.ensure<uint32_t>();
         e_u3.ensure<uint64_t>();
         e_r1.ensure<float>();
         e_r2.ensure<double>();
         e_a.ensure<array_t>();
         e_d.ensure<dict_t>();
         e_n.ensure<name_t>();

         Assert::AreEqual(typeid(void), e_u.get_type());
         Assert::AreEqual(typeid(text_t), e_t1.get_type());
         Assert::AreEqual(typeid(text_t), e_t2.get_type());
         Assert::AreEqual(typeid(char), e_c1.get_type());
         Assert::AreEqual(typeid(wchar_t), e_c2.get_type());
         Assert::AreEqual(typeid(bool), e_b.get_type());
         Assert::AreEqual(typeid(int16_t), e_i2.get_type());
         Assert::AreEqual(typeid(int32_t), e_i1.get_type());
         Assert::AreEqual(typeid(int64_t), e_i3.get_type());
         Assert::AreEqual(typeid(uint16_t), e_u1.get_type());
         Assert::AreEqual(typeid(uint32_t), e_u2.get_type());
         Assert::AreEqual(typeid(uint64_t), e_u3.get_type());
         Assert::AreEqual(typeid(float), e_r1.get_type());
         Assert::AreEqual(typeid(double), e_r2.get_type());
         Assert::AreEqual(typeid(array_t), e_a.get_type());
         Assert::AreEqual(typeid(dict_t), e_d.get_type());
         Assert::AreEqual(typeid(name_t), e_n.get_type());

         Assert::AreEqual<int32_t>(0, e_u);
         Assert::AreEqual<text_t>(text_t(L"text_t"), e_t1);
         Assert::AreEqual<text_t>(L"strptr", e_t2);
         Assert::AreEqual<char>('c', e_c1);
         Assert::AreEqual<wchar_t>(L'w', e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<int16_t>((int16_t)2, e_i2);
         Assert::AreEqual<int32_t>((int32_t)1, e_i1);
         Assert::AreEqual<int64_t>((int64_t)3, e_i3);
         Assert::AreEqual<uint16_t>((uint16_t)4u, e_u1);
         Assert::AreEqual<uint32_t>((uint32_t)5u, e_u2);
         Assert::AreEqual<uint64_t>((uint64_t)6u, e_u3);
         Assert::AreEqual<float>(7.0f, e_r1);
         Assert::AreEqual<double>(8.0, e_r2);
         Assert::AreEqual<array_t>(a, e_a);
         Assert::AreEqual<dict_t>(d, e_d);
         Assert::AreEqual<name_t>(ns::view, e_n);

         // Ensuring a similar get_type should preserve most of the value.
         e_u.ensure<int64_t>();
         e_t1.ensure<bool>();
         e_t2.ensure<bool>();
         e_c1.ensure<double>();
         e_c2.ensure<double>();
         e_b.ensure<float>();
         e_i2.ensure<double>();
         e_i1.ensure<double>();
         e_i3.ensure<double>();
         e_u1.ensure<double>();
         e_u2.ensure<bool>();
         e_u3.ensure<bool>();
         e_r1.ensure<int32_t>();
         e_r2.ensure<bool>();
         e_a.ensure<bool>();
         e_d.ensure<bool>();
         e_n.ensure<bool>();

         Assert::AreEqual<int64_t>(0, e_u);
         Assert::AreEqual<bool>(true, e_t1);
         Assert::AreEqual<bool>(true, e_t2);
         Assert::AreEqual<double>(99., e_c1);
         Assert::AreEqual<double>(119., e_c2);
         Assert::AreEqual<bool>(1., e_b);
         Assert::AreEqual<double>(2., e_i2);
         Assert::AreEqual<double>(1., e_i1);
         Assert::AreEqual<double>(3., e_i3);
         Assert::AreEqual<double>(4., e_u1);
         Assert::AreEqual<bool>(true, e_u2);
         Assert::AreEqual<bool>(true, e_u3);
         Assert::AreEqual<int64_t>(7, e_r1);
         Assert::AreEqual<bool>(true, e_r2);
         Assert::AreEqual<bool>(true, e_a);
         Assert::AreEqual<bool>(true, e_d);
         Assert::AreEqual<bool>(true, e_n);

      }

      TEST_METHOD(element_verify)
      {
         dict_t d;
         d[ns::view] = 33;
         d[ns::vector] = 4;
         d[ns::matrix] = 5;

         array_t a;
         a.grow() = 55;
         a.grow() = 66;
         a.grow() = 77;

         any_var_t e_u;
         any_var_t e_t1(text_t(L"text_t"));
         any_var_t e_t2(L"strptr");
         any_var_t e_c1('c');
         any_var_t e_c2(L'w');
         any_var_t e_b(true);
         any_var_t e_i2((int16_t)2);
         any_var_t e_i1((int32_t)1);
         any_var_t e_i3((int64_t)3);
         any_var_t e_u1((uint16_t)4u);
         any_var_t e_u2((uint32_t)5u);
         any_var_t e_u3((uint64_t)6u);
         any_var_t e_r1(7.0f);
         any_var_t e_r2(8.0);
         any_var_t e_a(a);
         any_var_t e_d(d);
         any_var_t e_n(ns::view);

         // Verifying the same get_type should not reset the value.
         e_u.reset();
         e_t1.verify<text_t>();
         e_t2.verify<text_t>();
         e_c1.verify<char>();
         e_c2.verify<wchar_t>();
         e_b.verify<bool>();
         e_i2.verify<int16_t>();
         e_i1.verify<int32_t>();
         e_i3.verify<int64_t>();
         e_u1.verify<uint16_t>();
         e_u2.verify<uint32_t>();
         e_u3.verify<uint64_t>();
         e_r1.verify<float>();
         e_r2.verify<double>();
         e_a.verify<array_t>();
         e_d.verify<dict_t>();
         e_n.verify<name_t>();

         Assert::AreEqual(typeid(void), e_u.get_type());
         Assert::AreEqual(typeid(text_t), e_t1.get_type());
         Assert::AreEqual(typeid(text_t), e_t2.get_type());
         Assert::AreEqual(typeid(char), e_c1.get_type());
         Assert::AreEqual(typeid(wchar_t), e_c2.get_type());
         Assert::AreEqual(typeid(bool), e_b.get_type());
         Assert::AreEqual(typeid(int16_t), e_i2.get_type());
         Assert::AreEqual(typeid(int32_t), e_i1.get_type());
         Assert::AreEqual(typeid(int64_t), e_i3.get_type());
         Assert::AreEqual(typeid(uint16_t), e_u1.get_type());
         Assert::AreEqual(typeid(uint32_t), e_u2.get_type());
         Assert::AreEqual(typeid(uint64_t), e_u3.get_type());
         Assert::AreEqual(typeid(float), e_r1.get_type());
         Assert::AreEqual(typeid(double), e_r2.get_type());
         Assert::AreEqual(typeid(array_t), e_a.get_type());
         Assert::AreEqual(typeid(dict_t), e_d.get_type());
         Assert::AreEqual(typeid(name_t), e_n.get_type());

         Assert::AreEqual<int32_t>(0, e_u);
         Assert::AreEqual<text_t>(text_t(L"text_t"), e_t1);
         Assert::AreEqual<text_t>(L"strptr", e_t2);
         Assert::AreEqual<char>('c', e_c1);
         Assert::AreEqual<wchar_t>(L'w', e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<int16_t>((int16_t)2, e_i2);
         Assert::AreEqual<int32_t>((int32_t)1, e_i1);
         Assert::AreEqual<int64_t>((int64_t)3, e_i3);
         Assert::AreEqual<uint16_t>((uint16_t)4u, e_u1);
         Assert::AreEqual<uint32_t>((uint32_t)5u, e_u2);
         Assert::AreEqual<uint64_t>((uint64_t)6u, e_u3);
         Assert::AreEqual<float>(7.0f, e_r1);
         Assert::AreEqual<double>(8.0, e_r2);
         Assert::AreEqual<array_t>(a, e_a);
         Assert::AreEqual<dict_t>(d, e_d);
         Assert::AreEqual<name_t>(ns::view, e_n);
      }

      TEST_METHOD(element_int64_operators)
      {
         any_var_t e;

         Assert::AreEqual<int64_t>(0, e);

         e += 2;
         Assert::AreEqual<int64_t>(2, e);

         e -= 7;
         Assert::AreEqual<int64_t>(-5, e);

         e *= 3;
         Assert::AreEqual<int64_t>(-15, e);

         e /= -5;
         Assert::AreEqual<int64_t>(3, e);

         e &= 1;
         Assert::AreEqual<int64_t>(1, e);

         e |= 10;
         Assert::AreEqual<int64_t>(11, e);

         e ^= 8;
         Assert::AreEqual<int64_t>(3, e);

         e <<= 2;
         Assert::AreEqual<int64_t>(12, e);

         e >>= 1;
         Assert::AreEqual<int64_t>(6, e);

         e += 2.5;
         Assert::AreEqual<double>(8.5, e);

         e -= 0.99;
         Assert::AreEqual<double>(7.51, e);

         e *= 0.5;
         Assert::AreEqual<double>(3.755, e);

         e /= 2.1;
         Assert::AreEqual<double>(3.755 / 2.1, e);

         e = text_t(L"hello");
         Assert::AreEqual<text_t>(L"hello", e);

         //e += L", world!";
         //Assert::AreEqual<text_t>(L"hello, world!", e);

         e = L"bye";
         Assert::AreEqual<text_t>(L"bye", e);
      }

      TEST_METHOD(element_double_operators)
      {
         any_var_t e;

         e = 0.0;

         Assert::AreEqual<double>(0, e);

         e += 2;
         Assert::AreEqual<double>(2, e);

         e -= 7;
         Assert::AreEqual<double>(-5, e);

         e *= 3;
         Assert::AreEqual<double>(-15, e);

         e /= -5;
         Assert::AreEqual<double>(3, e);

         e &= 1;
         Assert::AreEqual<double>(1, e);

         e |= 10;
         Assert::AreEqual<double>(11, e);

         e ^= 8;
         Assert::AreEqual<double>(3, e);

         e <<= 2;
         Assert::AreEqual<double>(12, e);

         e >>= 1;
         Assert::AreEqual<double>(6, e);

         e += 2.5;
         Assert::AreEqual<double>(8.5, e);

         e -= 0.99;
         Assert::AreEqual<double>(7.51, e);

         e *= 0.5;
         Assert::AreEqual<double>(3.755, e);

         e /= 2.1;
         Assert::AreEqual<double>(3.755 / 2.1, e);

         e = text_t(L"hello");
         Assert::AreEqual<text_t>(L"hello", e);

         e += L", world!";
         Assert::AreEqual<text_t>(L"hello, world!", e);

         e = L"bye";
         Assert::AreEqual<text_t>(L"bye", e);
      }

      TEST_METHOD(element_bool_operator)
      {
         any_var_t e_u;
         any_var_t e_t1(L"");
         any_var_t e_t2(text_t(L""));
         any_var_t e_c1('\0');
         any_var_t e_c2(L'\0');
         any_var_t e_b(false);
         any_var_t e_i2((int16_t)0);
         any_var_t e_i1((int32_t)0);
         any_var_t e_i3((int64_t)0);
         any_var_t e_u1((uint16_t)0);
         any_var_t e_u2((uint32_t)0);
         any_var_t e_u3((uint64_t)0);
         any_var_t e_r1(0.f);
         any_var_t e_r2(0.);
         any_var_t e_a(array_t::empty);
         any_var_t e_d(dict_t::empty);
         any_var_t e_n((name_t()));

         Assert::AreEqual<bool>(false, e_u);
         Assert::AreEqual<bool>(false, e_t1);
         Assert::AreEqual<bool>(false, e_t2);
         Assert::AreEqual<bool>(false, e_c1);
         Assert::AreEqual<bool>(false, e_c2);
         Assert::AreEqual<bool>(false, e_b);
         Assert::AreEqual<bool>(false, e_i2);
         Assert::AreEqual<bool>(false, e_i1);
         Assert::AreEqual<bool>(false, e_i3);
         Assert::AreEqual<bool>(false, e_u1);
         Assert::AreEqual<bool>(false, e_u2);
         Assert::AreEqual<bool>(false, e_u3);
         Assert::AreEqual<bool>(false, e_r1);
         Assert::AreEqual<bool>(false, e_r2);
         Assert::AreEqual<bool>(false, e_a);
         Assert::AreEqual<bool>(false, e_d);
         Assert::AreEqual<bool>(false, e_n);

         dict_t d;
         d[ns::view] = 33;
         d[ns::vector] = 4;
         d[ns::matrix] = 5;

         array_t a;
         a.grow() = 55;
         a.grow() = 66;
         a.grow() = 77;

         e_u = any_var_t();
         e_t1 = text_t(L"text_t");
         e_t2 = L"strptr";
         e_c1 = 'c';
         e_c2 = L'w';
         e_b = true;
         e_i2 = (int16_t)2;
         e_i1 = (int32_t)1;
         e_i3 = (int64_t)3;
         e_u1 = (uint16_t)4u;
         e_u2 = (uint32_t)5u;
         e_u3 = (uint64_t)6u;
         e_r1 = 7.0f;
         e_r2 = 8.0;
         e_a = a;
         e_d = d;
         e_n = ns::view;

         Assert::AreEqual<bool>(false, e_u);
         Assert::AreEqual<bool>(true, e_t1);
         Assert::AreEqual<bool>(true, e_t2);
         Assert::AreEqual<bool>(true, e_c1);
         Assert::AreEqual<bool>(true, e_c2);
         Assert::AreEqual<bool>(true, e_b);
         Assert::AreEqual<bool>(true, e_i2);
         Assert::AreEqual<bool>(true, e_i1);
         Assert::AreEqual<bool>(true, e_i3);
         Assert::AreEqual<bool>(true, e_u1);
         Assert::AreEqual<bool>(true, e_u2);
         Assert::AreEqual<bool>(true, e_u3);
         Assert::AreEqual<bool>(true, e_r1);
         Assert::AreEqual<bool>(true, e_r2);
         Assert::AreEqual<bool>(true, e_a);
         Assert::AreEqual<bool>(true, e_d);
         Assert::AreEqual<bool>(true, e_n);
      }

      TEST_METHOD(element_array)
      {
         array_t a;
         a.grow() = 55;
         a.grow() = 66.;
         a.grow() = 77.f;

         any_var_t e;

         //e.grow() = 11;
         //e.grow() = 22;

         //e.insert(0) = 33;

         //e.erase(1);

         //e.append(a);

         //Assert::AreEqual<index_t>(5, e.size());
         //Assert::AreEqual<int32_t>(33, e[0]);
         //Assert::AreEqual<int32_t>(22, e[1]);
         //Assert::AreEqual<int32_t>(55, e[2]);
         //Assert::AreEqual<double>(66., e[3]);
         //Assert::AreEqual<float>(77.f, e[4]);
      }

      TEST_METHOD(element_dict)
      {
         dict_t d;
         d[ns::view] = 33.;
         d[ns::vector] = 4;
         d[ns::matrix] = 5.f;

         any_var_t e;

         //e[voc::age] = 55.;
         //e.append(d);
         //e.erase(ns::view);
         //e.erase(ns::vector);

         //Assert::IsFalse(e.contains(ns::vector));
         //Assert::IsTrue(e.contains(ns::matrix));
         //Assert::IsTrue(e.contains(voc::age));
         //Assert::IsFalse(e.contains(ns::view));

         //Assert::AreEqual<index_t>(2, e.size());
         //Assert::AreEqual<float>(5.f, e[ns::matrix]);
         //Assert::AreEqual<double>(55., e[voc::age]);
      }
   };
}
