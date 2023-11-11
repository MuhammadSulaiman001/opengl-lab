#include "pch.h"

import SharedModule;

using namespace std;

extern const int const_int;

namespace cpp_tests
{
	TEST(CppTests, pointer_and_ref_variables_demo)
	{
		int a = 3;
		int& b = a;
		int* c = &a;
		EXPECT_EQ(a, b);
		EXPECT_EQ(a, *c);
		EXPECT_EQ(&a, c);
		EXPECT_EQ(&b, c);
		a = 4; // change value to 4, so, b and c will get it, same checks hold
		EXPECT_EQ(a, b);
		EXPECT_EQ(a, *c);
		EXPECT_EQ(&a, c);
		EXPECT_EQ(&b, c);
		b = 5; // using b, change value to 5, same checks hold
		EXPECT_EQ(a, b);
		EXPECT_EQ(a, *c);
		EXPECT_EQ(&a, c);
		EXPECT_EQ(&b, c);
		*c = 6; // using c, change value to 6, same checks hold
		EXPECT_EQ(a, b);
		EXPECT_EQ(a, *c);
		EXPECT_EQ(&a, c);
		EXPECT_EQ(&b, c);
		int d = a; // d is a new variable with the same value as a
		EXPECT_EQ(d, a);
		d = 7; // changing the value of d does not affect a,b or c, so, same checks hold
		EXPECT_EQ(a, b);
		EXPECT_EQ(a, *c);
		EXPECT_EQ(&a, c);
		EXPECT_EQ(&b, c);
		// let's compare C++ with C#
		/* C#
		 * int a = 3; int b = a; b = 4; // result: a == 3, b == 4
		 * C++ (same as C#)
		 * int a = 3; int b = a; b = 4; // result: a == 3, b == 4
		 * C++ (differs from C#)
		 * int a = 3; int& b = a; b = 4; // result: a == 4, b == 4
		 */
	}

	void try_increment_input(int i)
	{
		// ReSharper disable once CppAssignedValueIsNeverUsed
		i++;
	}

	void increment_input(int& i)
	{
		i++;
	}

	TEST(CppTests, input_should_be_incremented_only_when_passed_as_reference)
	{
		int a = 3;
		try_increment_input(a); // won't increment a, because value passed by value
		EXPECT_EQ(a, 3);
		increment_input(a); // will increment a, because value passed by reference
		EXPECT_EQ(a, 4);
	}

	TEST(CppTests, prefer_vector_over_array)
	{
		auto a = std::vector{1, 2, 3};
		auto b = new int[]{1, 2, 3};
		EXPECT_EQ(a[1], b[1]);
	}

	TEST(CppTests, prefer_nullptr_over_NULL)
	{
		int *p1, *p2;
		p1 = nullptr;
		p2 = NULL; // not preferred
		EXPECT_TRUE(p1 == p2);
	}

	TEST(CppTests, prefer_constexpr_over_macro)
	{
#ifndef SOME_INT
#define SOME_INT 10
#endif
		constexpr int someInt = 10;
		EXPECT_EQ(SOME_INT, someInt);
	}

	TEST(CppTests, prefer_delete_or_nullptr)
	{
		int *p1, *p2;
		p1 = p2 = new int(1);
		p1 = nullptr; // p1 still exist in memory
		delete p2; // this will remove p2 from memory
	}

	TEST(CppTests, const_pointer_vs_const_value)
	{
		int a = 3;
		int* const p_const = &a;
		// p_const = &a; // not allowed, due to const
		const int* p2 = &a;
		// *p2 = 3;  // not allowed, due to const
		const int* const p3 = &a;
		// p3 = &a // not allowed, due to second const
		// *p3 = 3 // not allowed, due to first const
	}

	TEST(CppTests, pointer_can_be_incremented_by_1)
	{
		int a[3] = {10, 20};
		int* p = &a[0]; // points to first cell
		EXPECT_EQ(*p, 10);
		p = p + 1; // moves the pointer one step forward
		EXPECT_EQ(*p, 20);
		p = p - 1; // moves the pointer one step forward
		EXPECT_EQ(*p, 10);
	}

	class pack
	{
	public:
		int a = 10;
	};

	TEST(CppTests, create_instance)
	{
		pack instance1;
		EXPECT_EQ(instance1.a, 10);
		auto instance2 = pack();
		EXPECT_EQ(instance2.a, 10);
		auto instance3 = pack{};
		EXPECT_EQ(instance3.a, 10);
	}

	TEST(CppTests, access_class_member)
	{
		auto instance = pack();
		auto pointer = new pack();
		EXPECT_EQ(instance.a, pointer->a);
	}

	TEST(CppTests, weird_cpp)
	{
		int* p = new int(3);
		p[3] = 1; // what is this? Dynamic_Memory_Allocation
	}

	TEST(CppTests, typeid_demo)
	{
		EXPECT_TRUE(typeid(5) == typeid(int));
		EXPECT_TRUE(typeid("5") == typeid(char const [2])); // 5, \0
		std::string str{"Hi there"};
		std::string str2{"Bey"};
		std::wstring str3{L"very long string!"};
		EXPECT_EQ(typeid(str), typeid(str2));
		EXPECT_NE(typeid(str), typeid(str3));
	}

	TEST(CppTests, decltype_demo)
	{
		pack var1{1};
		pack var2{2};
		bool isSameType = is_same_v<decltype(var1), decltype(var2)>;
		EXPECT_TRUE(isSameType);
		int var3{3};
		isSameType = is_same_v<decltype(var1), decltype(var3)>;
		EXPECT_FALSE(isSameType);
	}

	class base_pack
	{
		virtual int get_result() = 0;
	};

	class stupid_pack : base_pack
	{
		int* i_;
	public:
		stupid_pack(int i)
		{
			i_ = new int(i);
		}

		~stupid_pack() // this must be called, to free the memory
		{
			delete i_;
		}

		int get_result() override
		{
			return *i_;
		}
	};

	class smart_pack : base_pack
	{
		unique_ptr<int> i_;
	public:
		smart_pack(int i)
		{
			i_ = std::make_unique<int>(i);
		}

		int get_result() override
		{
			return *i_;
		}
	};

	TEST(CppTests, stupid_vs_smart_pointer)
	{
		// todo, Test Explorer failure
		// stupid_pack stupid(3);
		// smart_pack smart(3);
		// EXPECT_EQ(smart.get_result(), stupid.get_result());
	}

	TEST(CppTests, delete_pointer_demo)
	{
		int array[2] = {0, 1};
		auto pointer = new int[2]{0, 1};
		EXPECT_EQ(array[0], pointer[0]);
		EXPECT_EQ(array[1], pointer[1]);
		delete[] pointer;
	}

	class pack2
	{
		int a;
	public:
		int get_result() const { return a; }
		int get_result2() { return a; }
	};

	TEST(CppTests, const_instance_can_only_call_const_methods)
	{
		pack2 instance1;
		instance1.get_result();
		instance1.get_result2();

		const pack2 instance2{};
		instance2.get_result();
		// instance2.get_result2(); // not allowed
	}

#pragma region friend class

	class pack3
	{
	private:
		int i = 3;
	public:
		friend class pack4;
	};

	class pack4
	{
	public:
		int expose_my_secret(pack3 p)
		{
			return p.i;
		}
	};

	TEST(CppTests, friend_function_demo)
	{
		pack3 me{};
		pack4 my_friend{};
		EXPECT_EQ(my_friend.expose_my_secret(me), 3);
	}

#pragma endregion

	class pack5
	{
	public:
		int a = 3;
	};

	TEST(CppTests, default_copy_ctor_demo)
	{
		pack5 instance1{};
		pack5 instance2(instance1);
		EXPECT_TRUE(instance1.a == instance2.a); // values are the same
		EXPECT_TRUE(&instance1.a != &instance2.a); // but references are not
	}

	/**
	 * \brief 
	 * \return returns a reference to a static variable! so any change to the variable by the caller will affect the behaviour of this function in the next time it is called!
	 * todo doc: This is weird (i.e. static variable for a function)! as friend class/function, as multiple inheritance!
	 */
	int& get_reference_to_static_var()
	{
		static int a = 0; // defined only once
		return a;
	}

	TEST(CppTests, static_var_inside_function_can_be_changed_outside_the_function)
	{
		EXPECT_EQ(get_reference_to_static_var()++, 0);
		EXPECT_EQ(get_reference_to_static_var(), 1);
	}

	TEST(CppTests, extern_demo)
	{
		EXPECT_EQ(const_int, 32);
	}

	union union1
	{
		int i;
		char c;
	};

	TEST(CppTests, union_demo)
	{
		union1 instance;
		instance.i = 10;
		EXPECT_EQ(instance.i, 10);
		instance.c = 'm';
		EXPECT_NE(instance.i, 10); // notice that 10 is lost
		EXPECT_EQ(instance.c, 'm');

		instance.i = 44;
		EXPECT_NE(instance.c, 'm'); // notice that 'm' is lost
		EXPECT_EQ(instance.i, 44);
	}

	// Define the enum
	enum class Quantifier
	{
		None = 0,
		// First == 1
		First,
		Some = 5,
		Many = 10,
		Default = None
	};

	TEST(CppTests, enum_class_demo)
	{
		Quantifier q = Quantifier::Default;
		EXPECT_EQ(q, Quantifier::None);
		q = Quantifier::Some;
		EXPECT_EQ((int)q, 5);
	}

	template <typename T>
	T minimum(const T& lhs, const T& rhs)
	{
		return lhs < rhs ? lhs : rhs;
	}

	TEST(CppTests, template_function_demo)
	{
		EXPECT_EQ(minimum(10, 20), 10);
	}

	template <typename T, typename U>
	class Foo
	{
		T t_;
		U u_;
	public:
		Foo(T t, U u)
		{
			t_ = t;
			u_ = u;
		}

		void clear_values()
		{
			t_ = 0;
			u_ = 0;
		}

		T get_t()
		{
			return t_;
		}
	};

	TEST(CppTests, template_class_demo)
	{
		auto instance1 = Foo(10, 'm');
		EXPECT_EQ(instance1.get_t(), 10);
		instance1.clear_values();
		EXPECT_NE(instance1.get_t(), 10);
	}

	TEST(CppTests, throw_exception_demo)
	{
		// Expected exception
		EXPECT_THROW({ throw exception("I want extra marks");}, exception);
		EXPECT_NO_THROW({
			try
			{
			throw exception("You just sleep and ask for extra marks!");
			}
			catch (exception& e)
			{
			cout << "The issue is that, " << e.what() << endl;
			}
			});
	}

	TEST(CppTests, lambda_demo)
	{
		auto sum = [](float x, float y)
		{
			return y + x;
		};
		EXPECT_EQ(sum(3, 10), 13);
	}

	TEST(CppTests, notImplementedException_should_be_thrown)
	{
		EXPECT_THROW({ throw NotImplementedException(); }, logic_error);
	}
}
