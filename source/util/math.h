#ifndef __UTIL__MATH__H__
#define __UTIL__MATH__H__


/**
 *
 *  作者: hm
 *
 *  说明: 数学处理
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#include <random>


namespace tinyToolkit
{
	namespace util
	{
		class TOOLKIT_API Math
		{
		public:
			/**
			 *
			 * 是否为偶数
			 *
			 * @param value 数据
			 *
			 * @return 是否为偶数
			 *
			 */
			template <typename ContentType>
			static bool IsEven(ContentType content)
			{
				static_assert(std::is_integral<ContentType>::value, "Template must be an integral type");

				return (content & 1) == 0;
			}

			/***
			 *
			 * 是否为奇数
			 *
			 * @param value 数据
			 *
			 * @return 是否为奇数
			 *
			 */
			template <typename ContentType>
			static bool IsOdd(ContentType content)
			{
				static_assert(std::is_integral<ContentType>::value, "Template must be an integral type");

				return (content & 1) != 0;
			}

			/**
			 *
			 * 均匀分布的浮点型随机数
			 *
			 * @return 均匀分布的浮点型随机数
			 *
			 */
			template <typename ContentType>
			static ContentType FloatRandomWithUniformDistribution(ContentType min, ContentType max)
			{
				static_assert(std::is_floating_point<ContentType>::value, "Template must be an integral type");

				std::random_device rd{ };

				std::mt19937 mt(rd());

				std::uniform_real_distribution<ContentType> dis(min, max);

				return dis(mt);
			}

			/**
			 *
			 * 均匀分布的整型随机数
			 *
			 * @return 均匀分布的整数随机数
			 *
			 */
			template <typename ContentType>
			static ContentType IntegralRandomWithUniformDistribution(ContentType min, ContentType max)
			{
				static_assert(std::is_integral<ContentType>::value, "Template must be an integral type");

				std::random_device rd{ };

				std::mt19937 mt(rd());

				std::uniform_int_distribution<ContentType> dis(min, max);

				return dis(mt);
			}
		};
	}
}


#endif // __UTIL__MATH__H__
