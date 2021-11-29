/**
 *
 *  作者: hm
 *
 *  说明: 单例对象
 *
 */


#include "singleton.h"


TOOLKIT_TEST_CASE(Singleton, Class)
{
	class Referent
	{
	public:
		explicit Referent(int32_t number) : _number(number)
		{
			TOOLKIT_UNUSED(_number);
		}

	private:
		int32_t _number{ 0 };
	};

	Referent & ref = tinyToolkit::util::Singleton<Referent>::Instance(1);

	std::thread t1([&]()
	{
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(1)));
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(2)));
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(3)));
	});

	std::thread t2([&]()
	{
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(1)));
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(2)));
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(3)));
	});

	t1.join();
	t2.join();
}


TOOLKIT_TEST_CASE(Singleton, Struct)
{
	struct Referent
	{
		explicit Referent(int32_t number) : _number(number)
		{
			TOOLKIT_UNUSED(_number);
		}

		int32_t _number{ 0 };
	};

	Referent & ref = tinyToolkit::util::Singleton<Referent>::Instance(1);

	std::thread t1([&]()
	{
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(1)));
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(2)));
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(3)));
	});

	std::thread t2([&]()
	{
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(1)));
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(2)));
		TOOLKIT_EXPECT_TRUE(std::addressof(ref) == std::addressof(tinyToolkit::util::Singleton<Referent>::Instance(3)));
	});

	t1.join();
	t2.join();
}


TOOLKIT_TEST_CASE(Singleton, Integer)
{
	auto & i08 = tinyToolkit::util::Singleton<int8_t>::Instance(static_cast<int8_t>(1));
	auto & u08 = tinyToolkit::util::Singleton<uint8_t>::Instance(static_cast<uint8_t>(1));
	auto & i16 = tinyToolkit::util::Singleton<int16_t>::Instance(static_cast<int16_t>(1));
	auto & u16 = tinyToolkit::util::Singleton<uint16_t>::Instance(static_cast<uint16_t>(1));
	auto & i32 = tinyToolkit::util::Singleton<int32_t>::Instance(static_cast<int32_t>(1));
	auto & u32 = tinyToolkit::util::Singleton<uint32_t>::Instance(static_cast<uint32_t>(1));
	auto & i64 = tinyToolkit::util::Singleton<int64_t>::Instance(static_cast<int64_t>(1));
	auto & u64 = tinyToolkit::util::Singleton<uint64_t>::Instance(static_cast<uint64_t>(1));

	std::thread t1([&]()
	{
		TOOLKIT_EXPECT_TRUE(std::addressof(i08) == std::addressof(tinyToolkit::util::Singleton<int8_t>::Instance(static_cast<int8_t>(1))));
		TOOLKIT_EXPECT_TRUE(std::addressof(i08) == std::addressof(tinyToolkit::util::Singleton<int8_t>::Instance(static_cast<int8_t>(2))));

		TOOLKIT_EXPECT_TRUE(std::addressof(u08) == std::addressof(tinyToolkit::util::Singleton<uint8_t>::Instance(static_cast<uint8_t>(1))));
		TOOLKIT_EXPECT_TRUE(std::addressof(u08) == std::addressof(tinyToolkit::util::Singleton<uint8_t>::Instance(static_cast<uint8_t>(2))));

		TOOLKIT_EXPECT_TRUE(std::addressof(i16) == std::addressof(tinyToolkit::util::Singleton<int16_t>::Instance(static_cast<int16_t>(1))));
		TOOLKIT_EXPECT_TRUE(std::addressof(i16) == std::addressof(tinyToolkit::util::Singleton<int16_t>::Instance(static_cast<int16_t>(2))));

		TOOLKIT_EXPECT_TRUE(std::addressof(u16) == std::addressof(tinyToolkit::util::Singleton<uint16_t>::Instance(static_cast<uint16_t>(1))));
		TOOLKIT_EXPECT_TRUE(std::addressof(u16) == std::addressof(tinyToolkit::util::Singleton<uint16_t>::Instance(static_cast<uint16_t>(2))));

		TOOLKIT_EXPECT_TRUE(std::addressof(i32) == std::addressof(tinyToolkit::util::Singleton<int32_t>::Instance(static_cast<int32_t>(1))));
		TOOLKIT_EXPECT_TRUE(std::addressof(i32) == std::addressof(tinyToolkit::util::Singleton<int32_t>::Instance(static_cast<int32_t>(2))));

		TOOLKIT_EXPECT_TRUE(std::addressof(u32) == std::addressof(tinyToolkit::util::Singleton<uint32_t>::Instance(static_cast<uint32_t>(1))));
		TOOLKIT_EXPECT_TRUE(std::addressof(u32) == std::addressof(tinyToolkit::util::Singleton<uint32_t>::Instance(static_cast<uint32_t>(2))));

		TOOLKIT_EXPECT_TRUE(std::addressof(i64) == std::addressof(tinyToolkit::util::Singleton<int64_t>::Instance(static_cast<int64_t>(1))));
		TOOLKIT_EXPECT_TRUE(std::addressof(i64) == std::addressof(tinyToolkit::util::Singleton<int64_t>::Instance(static_cast<int64_t>(2))));

		TOOLKIT_EXPECT_TRUE(std::addressof(u64) == std::addressof(tinyToolkit::util::Singleton<uint64_t>::Instance(static_cast<uint64_t>(1))));
		TOOLKIT_EXPECT_TRUE(std::addressof(u64) == std::addressof(tinyToolkit::util::Singleton<uint64_t>::Instance(static_cast<uint64_t>(2))));
	});

	std::thread t2([&]()
	{
		TOOLKIT_EXPECT_TRUE(std::addressof(i08) == std::addressof(tinyToolkit::util::Singleton<int8_t>::Instance(static_cast<int8_t>(-3))));
		TOOLKIT_EXPECT_TRUE(std::addressof(i08) == std::addressof(tinyToolkit::util::Singleton<int8_t>::Instance(static_cast<int8_t>(-4))));

		TOOLKIT_EXPECT_TRUE(std::addressof(u08) == std::addressof(tinyToolkit::util::Singleton<uint8_t>::Instance(static_cast<uint8_t>(-3))));
		TOOLKIT_EXPECT_TRUE(std::addressof(u08) == std::addressof(tinyToolkit::util::Singleton<uint8_t>::Instance(static_cast<uint8_t>(-4))));

		TOOLKIT_EXPECT_TRUE(std::addressof(i16) == std::addressof(tinyToolkit::util::Singleton<int16_t>::Instance(static_cast<int16_t>(-3))));
		TOOLKIT_EXPECT_TRUE(std::addressof(i16) == std::addressof(tinyToolkit::util::Singleton<int16_t>::Instance(static_cast<int16_t>(-4))));

		TOOLKIT_EXPECT_TRUE(std::addressof(u16) == std::addressof(tinyToolkit::util::Singleton<uint16_t>::Instance(static_cast<uint16_t>(-3))));
		TOOLKIT_EXPECT_TRUE(std::addressof(u16) == std::addressof(tinyToolkit::util::Singleton<uint16_t>::Instance(static_cast<uint16_t>(-4))));

		TOOLKIT_EXPECT_TRUE(std::addressof(i32) == std::addressof(tinyToolkit::util::Singleton<int32_t>::Instance(static_cast<int32_t>(-3))));
		TOOLKIT_EXPECT_TRUE(std::addressof(i32) == std::addressof(tinyToolkit::util::Singleton<int32_t>::Instance(static_cast<int32_t>(-4))));

		TOOLKIT_EXPECT_TRUE(std::addressof(u32) == std::addressof(tinyToolkit::util::Singleton<uint32_t>::Instance(static_cast<uint32_t>(-3))));
		TOOLKIT_EXPECT_TRUE(std::addressof(u32) == std::addressof(tinyToolkit::util::Singleton<uint32_t>::Instance(static_cast<uint32_t>(-4))));

		TOOLKIT_EXPECT_TRUE(std::addressof(i64) == std::addressof(tinyToolkit::util::Singleton<int64_t>::Instance(static_cast<int64_t>(-3))));
		TOOLKIT_EXPECT_TRUE(std::addressof(i64) == std::addressof(tinyToolkit::util::Singleton<int64_t>::Instance(static_cast<int64_t>(-4))));

		TOOLKIT_EXPECT_TRUE(std::addressof(u64) == std::addressof(tinyToolkit::util::Singleton<uint64_t>::Instance(static_cast<uint64_t>(-3))));
		TOOLKIT_EXPECT_TRUE(std::addressof(u64) == std::addressof(tinyToolkit::util::Singleton<uint64_t>::Instance(static_cast<uint64_t>(-4))));
	});

	t1.join();
	t2.join();
}
