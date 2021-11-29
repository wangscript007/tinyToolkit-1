#ifndef __UTIL__TIME__H__
#define __UTIL__TIME__H__


/**
 *
 *  作者: hm
 *
 *  说明: 时间处理
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#include <string>
#include <chrono>
#include <cstdint>


namespace tinyToolkit
{
	namespace util
	{
		class TOOLKIT_API Time
		{
		public:
			/**
			 *
			 * 小时时间戳
			 *
			 * @param point 时间点
			 *
			 * @return 小时时间戳
			 *
			 */
			static int64_t Hour(const std::chrono::system_clock::time_point & point = TimePoint());

			/**
			 *
			 * 分钟时间戳
			 *
			 * @param point 时间点
			 *
			 * @return 分钟时间戳
			 *
			 */
			static int64_t Minute(const std::chrono::system_clock::time_point & point = TimePoint());

			/**
			 *
			 * 秒数时间戳
			 *
			 * @param point 时间点
			 *
			 * @return 秒数时间戳
			 *
			 */
			static int64_t Second(const std::chrono::system_clock::time_point & point = TimePoint());

			/**
			 *
			 * 时区
			 *
			 * @return 时区
			 *
			 */
			static int64_t Timezone();

			/**
			 *
			 * 到期时间戳
			 *
			 * @param day 天
			 * @param hour 时
			 * @param minute 分
			 * @param second 秒
			 *
			 * @return 到期时间戳(秒)
			 *
			 */
			static int64_t Expiration(int64_t day = 0, int32_t hour = 0, int32_t minute = 0, int32_t second = 0);

			/**
			 *
			 * 纳秒时间戳
			 *
			 * @param point 时间点
			 *
			 * @return 纳秒时间戳
			 *
			 */
			static int64_t Nanosecond(const std::chrono::system_clock::time_point & point = TimePoint());

			/**
			 *
			 * 微秒时间戳
			 *
			 * @param point 时间点
			 *
			 * @return 微秒时间戳
			 *
			 */
			static int64_t Microsecond(const std::chrono::system_clock::time_point & point = TimePoint());

			/**
			 *
			 * 毫秒时间戳
			 *
			 * @param point 时间点
			 *
			 * @return 毫秒时间戳
			 *
			 */
			static int64_t Millisecond(const std::chrono::system_clock::time_point & point = TimePoint());

			/**
			 *
			 * 转换为秒数时间戳
			 *
			 * @param date 日期
			 * @param format 格式
			 *
			 * @return 秒数时间戳
			 *
			 */
			static int64_t FromTimeString(const char * date, const char * format = "%4d-%02d-%02d %02d:%02d:%02d");

			/**
			 *
			 * 转换为日期字符串
			 *
			 * @param second 秒数时间戳
			 * @param timezone 时区
			 * @param format 格式
			 *
			 * @return 日期字符串
			 *
			 */
			static std::string ToTimeString(int64_t second, int64_t timezone, const char * format = "%4d-%02d-%02d %02d:%02d:%02d");

			/**
			 *
			 * 当前UTC时间字符串
			 *
			 * @param format 格式
			 *
			 * @return 时间字符串
			 *
			 */
			static std::string CurrentUTCTimeString(const char * format = "%4d-%02d-%02d %02d:%02d:%02d");

			/**
			 *
			 * 当前本地时间字符串
			 *
			 * @param format 格式
			 *
			 * @return 时间字符串
			 *
			 */
			static std::string CurrentLocalTimeString(const char * format = "%4d-%02d-%02d %02d:%02d:%02d");

			/**
			 *
			 * 时间点
			 *
			 * @return 时间点
			 *
			 */
			static std::chrono::system_clock::time_point TimePoint();

			/**
			 *
			 * 时间点
			 *
			 * @param seconds 秒数时间戳
			 *
			 * @return 时间点
			 *
			 */
			static std::chrono::system_clock::time_point TimePoint(int64_t time);
		};
	}
}


#endif // __UTIL__TIME__H__
