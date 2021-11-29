/**
 *
 *  作者: hm
 *
 *  说明: 数学处理
 *
 */


#include "math.h"


TOOLKIT_TEST_CASE(Math, IsEven)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Math::IsEven(456));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Math::IsEven(123));
}


TOOLKIT_TEST_CASE(Math, IsOdd)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Math::IsOdd(123));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Math::IsOdd(456));
}


TOOLKIT_TEST_CASE(Math, FloatRandomWithUniformDistribution)
{
	for (std::size_t i = 0; i < 10; ++i)
	{
		auto rand = tinyToolkit::util::Math::FloatRandomWithUniformDistribution(1.0, 10.0);

		TOOLKIT_EXPECT_TRUE(1.0 <= rand && rand <= 10.0);
		TOOLKIT_EXPECT_FALSE(1.0 > rand || rand > 10.0);
	}
}


TOOLKIT_TEST_CASE(Math, IntegralRandomWithUniformDistribution)
{
	for (std::size_t i = 0; i < 10; ++i)
	{
		auto rand = tinyToolkit::util::Math::IntegralRandomWithUniformDistribution(100, 1000);

		TOOLKIT_EXPECT_TRUE(100 <= rand && rand <= 1000);
		TOOLKIT_EXPECT_FALSE(100 > rand || rand > 1000);
	}
}
