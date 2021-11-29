/**
 *
 *  作者: hm
 *
 *  说明: 正则处理
 *
 */


#include "regex.h"


namespace tinyToolkit
{
	namespace util
	{
		/**
		 *
		 * 正则匹配
		 *
		 * @param content 内容
		 * @param rule 规则
		 *
		 * @return 是否匹配成功
		 *
		 */
		bool Regex::Match(const std::string & content, const std::regex & rule)
		{
			if (content.empty())
			{
				return false;
			}

			std::cmatch result{ };

			/**
			 *
			 * gcc4.8 对 c++11 的 regex 不支持, 使用的时候会抛 std::regex_error 异常
			 *
			 */
			return std::regex_search(content.c_str(), result, rule);
		}

		/**
		 *
		 * 是否为IP地址
		 *
		 * @param content 内容
		 *
		 * @return 是否为IP地址
		 *
		 */
		bool Regex::IsIP(const std::string & content)
		{
			return IsIPv4(content) || IsIPv6(content);
		}

		/**
		 *
		 * 是否为MAC地址
		 *
		 * @param content 内容
		 *
		 * @return 是否为MAC地址
		 *
		 */
		bool Regex::IsMAC(const std::string & content)
		{
			static std::regex rule(R"(^(?:(?:(?:[A-Fa-f\d]{2}:){5})|(?:(?:[A-Fa-f\d]{2}-){5}))[A-Fa-f\d]{2}$)");

			return Match(content, rule);
		}

		/**
		 *
		 * 是否为IPv4地址
		 *
		 * @param content 内容
		 *
		 * @return 是否为IPv4地址
		 *
		 */
		bool Regex::IsIPv4(const std::string & content)
		{
			static std::regex rule(R"(^(?:[1-9]?\d|1\d{2}|2[0-4]\d|25[0-5])(?:\.(?:[1-9]?\d|1\d{2}|2[0-4]\d|25[0-5])){3}$)");

			return Match(content, rule);
		}

		/**
		 *
		 * 是否为IPv6地址
		 *
		 * @param content 内容
		 *
		 * @return 是否为IPv6地址
		 *
		 */
		bool Regex::IsIPv6(const std::string & content)
		{
			static std::regex rule(R"(^\s*(?:(?:(?:[A-Fa-f\d]{1,4}:){7}(?:[A-Fa-f\d]{1,4}|:))|(?:(?:[A-Fa-f\d]{1,4}:){6}(?::[A-Fa-f\d]{1,4}|(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3})|:))|(?:(?:[A-Fa-f\d]{1,4}:){5}(?:(?:(?::[A-Fa-f\d]{1,4}){1,2})|:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3})|:))|(?:(?:[A-Fa-f\d]{1,4}:){4}(?:(?:(?::[A-Fa-f\d]{1,4}){1,3})|(?:(?::[A-Fa-f\d]{1,4})?:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:))|(?:(?:[A-Fa-f\d]{1,4}:){3}(?:(?:(?::[A-Fa-f\d]{1,4}){1,4})|(?:(?::[A-Fa-f\d]{1,4}){0,2}:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:))|(?:(?:[A-Fa-f\d]{1,4}:){2}(?:(?:(?::[A-Fa-f\d]{1,4}){1,5})|(?:(?::[A-Fa-f\d]{1,4}){0,3}:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:))|(?:(?:[A-Fa-f\d]{1,4}:){1}(?:(?:(?::[A-Fa-f\d]{1,4}){1,6})|(?:(?::[A-Fa-f\d]{1,4}){0,4}:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:))|(?::(?:(?:(?::[A-Fa-f\d]{1,4}){1,7})|(?:(?::[A-Fa-f\d]{1,4}){0,5}:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:)))(?:%.+)?\s*$)");

			return Match(content, rule);
		}

		/**
		 *
		 * 是否为邮箱地址
		 *
		 * @param content 内容
		 *
		 * @return 是否为邮箱地址
		 *
		 */
		bool Regex::IsMail(const std::string & content)
		{
			static std::regex rule(R"(^\w[-\w.+]*@(?:[A-Za-z\d][-A-Za-z\d]+\.)+[A-Za-z]{2,14}$)");

			return Match(content, rule);
		}

		/**
		 *
		 * 是否为日期
		 *
		 * @param content 内容
		 *
		 * @return 是否为日期
		 *
		 */
		bool Regex::IsDate(const std::string & content)
		{
			static std::regex rule(R"(^(?:(?!0000)\d{4}([-/.])(?:(?:0[1-9]|1[0-2])\1(?:0[1-9]|1\d|2[0-8])|(?:0[13-9]|1[0-2])\1(?:29|30)|(?:0[13578]|1[02])\1(?:31))|(?:\d{2}(?:0[48]|[2468][048]|[13579][26])|(?:0[48]|[2468][048]|[13579][26])00)([-/.])(?:02)\2(?:29))$)");

			return Match(content, rule);
		}

		/**
		 *
		 * 是否为时间
		 *
		 * @param content 内容
		 *
		 * @return 是否为时间
		 *
		 */
		bool Regex::IsTime(const std::string & content)
		{
			static std::regex rule(R"(^(?:[0-1]\d|2[0-3])(?::[0-5]\d){2}(?:.\d{1,9})?$)");

			return Match(content, rule);
		}

		/**
		 *
		 * 是否为日期与时间
		 *
		 * @param content 内容
		 *
		 * @return 是否为日期与时间
		 *
		 */
		bool Regex::IsDateTime(const std::string & content)
		{
			static std::regex rule(R"(^(?:(?!0000)\d{4}([-/.])(?:(?:0[1-9]|1[0-2])\1(?:0[1-9]|1\d|2[0-8])|(?:0[13-9]|1[0-2])\1(?:29|30)|(?:0[13578]|1[02])\1(?:31))|(?:\d{2}(?:0[48]|[2468][048]|[13579][26])|(?:0[48]|[2468][048]|[13579][26])00)([-/.])(?:02)\2(?:29))[ ]{1,}(?:[0-1]\d|2[0-3])(?::[0-5]\d){2}(?:.\d{1,9})?$)");

			return Match(content, rule);
		}
	}
}
