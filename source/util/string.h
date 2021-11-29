#ifndef __UTIL__STRING__H__
#define __UTIL__STRING__H__


/**
 *
 *  作者: hm
 *
 *  说明: 字符串处理
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#ifdef TOOLKIT_WITH_FMT
#
#  include <fmt/format.h>
#
#endif

#include <string>
#include <vector>
#include <cstdint>
#include <sstream>


namespace tinyToolkit
{
	namespace util
	{
		class TOOLKIT_API String
		{
		public:
			/**
			 *
			 * 流对象填充
			 *
			 * @param stream 流对象
			 * @param content 内容
			 *
			 */
			template <typename ContentType>
			static void JoinStream(std::stringstream & stream, ContentType && content)
			{
				stream << std::forward<ContentType>(content);
			}

			/**
			 *
			 * 流对象填充
			 *
			 * @param stream 流对象
			 * @param content 内容
			 * @param args 内容
			 *
			 */
			template <typename ContentType, typename... Args>
			static void JoinStream(std::stringstream & stream, ContentType && content, Args && ... args)
			{
				JoinStream(stream, std::forward<ContentType>(content));
				JoinStream(stream, std::forward<Args>(args)...);
			}

			/**
			 *
			 * 填充
			 *
			 * @param content 内容
			 * @param args 内容
			 *
			 * @return 结果
			 *
			 */
			template <typename... Args>
			static std::string Join(Args && ... args)
			{
				std::stringstream stream{ };

				JoinStream(stream, std::forward<Args>(args)...);

				return stream.str();
			}

		#ifdef TOOLKIT_WITH_FMT

			/**
			 *
			 * 格式化内容
			 *
			 * @param format 格式化
			 * @param args 内容
			 *
			 * @return 内容
			 *
			 */
			template <typename... Args>
			static std::string Format(const char * format, Args &&... args)
			{
				return fmt::format(format, std::forward<Args>(args)...);
			}

			/**
			 *
			 * 格式化内容
			 *
			 * @param format 格式化
			 * @param args 内容
			 *
			 * @return 内容
			 *
			 */
			template <typename... Args>
			static std::string Format(const std::string & format, Args &&... args)
			{
				return fmt::format(format, std::forward<Args>(args)...);
			}

		#endif

		public:
			/**
			 *
			 * 删除
			 *
			 * @param content 内容
			 * @param key 关键字
			 * @param offset 偏移
			 *
			 */
			static void Erase(std::string & content, char key, std::size_t offset = 0);

			/**
			 *
			 * 删除
			 *
			 * @param content 内容
			 * @param key 关键字
			 * @param offset 偏移
			 *
			 */
			static void Erase(std::string & content, const std::string & key, std::size_t offset = 0);

			/**
			 *
			 * 转换小写
			 *
			 * @param content 内容
			 * @param offset 偏移
			 *
			 */
			static void Lower(std::string & content, std::size_t offset = 0);

			/**
			 *
			 * 转换大写
			 *
			 * @param content 内容
			 * @param offset 偏移
			 *
			 */
			static void Upper(std::string & content, std::size_t offset = 0);

			/**
			 *
			 * 按值拆分
			 *
			 * @param content 内容
			 * @param key 关键字
			 * @param result 结果
			 * @param isKeepEmpty 是否保留空串
			 *
			 */
			static void Split(const std::string & content, const std::string & key, std::vector<std::string> & result, bool isKeepEmpty = false);

			/**
			 *
			 * 替换
			 *
			 * @param content 内容
			 * @param src 原始值
			 * @param dst 目的值
			 * @param offset 偏移
			 *
			 */
			static void Replace(std::string & content, const std::string & src, const std::string & dst, std::size_t offset = 0);

			/**
			 *
			 * 尾部匹配
			 *
			 * @param content 内容
			 * @param key 关键字
			 *
			 * @return 是否匹配
			 *
			 */
			static bool EndWith(const std::string & content, const std::string & key);

			/**
			 *
			 * 首部匹配
			 *
			 * @param content 内容
			 * @param key 关键字
			 *
			 * @return 是否匹配
			 *
			 */
			static bool StartWith(const std::string & content, const std::string & key);

			/**
			 *
			 * 按行拆分
			 *
			 * @param content 内容
			 * @param result 结果
			 * @param isKeepEmpty 是否保留空行
			 *
			 */
			static void SplitLine(const std::string & content, std::vector<std::string> & result, bool isKeepEmpty = false);

			/**
			 *
			 * 循环替换
			 *
			 * @param content 内容
			 * @param src 原始值
			 * @param dst 目的值
			 * @param offset 偏移
			 *
			 */
			static void ReplaceLoop(std::string & content, const std::string & src, const std::string & dst, std::size_t offset = 0);

			/**
			 *
			 * 不区分大小写比较
			 *
			 * @param src 原始值
			 * @param dst 目的值
			 *
			 * @return 是否相等
			 *
			 */
			static bool EqualIgnoreCase(const std::string & src, const std::string & dst);

			/**
			 *
			 * 清除
			 *
			 * @param content 内容
			 * @param pattern 规则
			 *
			 * @return 结果
			 *
			 */
			static std::string Trim(const std::string & content, const char * pattern = "\r\n\t ");

			/**
			 *
			 * 删除
			 *
			 * @param content 内容
			 * @param key 关键字
			 * @param offset 偏移
			 *
			 * @return 结果
			 *
			 */
			static std::string Erase(const std::string & content, char key, std::size_t offset = 0);

			/**
			 *
			 * 删除
			 *
			 * @param content 内容
			 * @param key 关键字
			 * @param offset 偏移
			 *
			 * @return 结果
			 *
			 */
			static std::string Erase(const std::string & content, const std::string & key, std::size_t offset = 0);

			/**
			 *
			 * 转换小写
			 *
			 * @param content 内容
			 * @param offset 偏移
			 *
			 * @return 结果
			 *
			 */
			static std::string Lower(const std::string & content, std::size_t offset = 0);

			/**
			 *
			 * 转换大写
			 *
			 * @param content 内容
			 * @param offset 偏移
			 *
			 * @return 结果
			 *
			 */
			static std::string Upper(const std::string & content, std::size_t offset = 0);

			/**
			 *
			 * 替换
			 *
			 * @param content 内容
			 * @param src 原始值
			 * @param dst 目的值
			 * @param offset 偏移
			 *
			 * @return 结果
			 *
			 */
			static std::string Replace(const std::string & content, const std::string & src, const std::string & dst, std::size_t offset = 0);

			/**
			 *
			 * 清除左侧
			 *
			 * @param content 内容
			 * @param pattern 规则
			 *
			 * @return 结果
			 *
			 */
			static std::string TrimLeft(const std::string & content, const char * pattern = "\r\n\t ");

			/**
			 *
			 * 清除右侧
			 *
			 * @param content 内容
			 * @param pattern 规则
			 *
			 * @return 结果
			 *
			 */
			static std::string TrimRight(const std::string & content, const char * pattern = "\r\n\t ");

			/**
			 *
			 * 收缩json
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string ReduceJson(const std::string & content);

			/**
			 *
			 * 循环替换
			 *
			 * @param content 内容
			 * @param src 原始值
			 * @param dst 目的值
			 * @param offset 偏移
			 *
			 * @return 结果
			 *
			 */
			static std::string ReplaceLoop(const std::string & content, const std::string & src, const std::string & dst, std::size_t offset = 0);

			/**
			 *
			 * 转换为16进制内容
			 *
			 * @param content 内容
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string ToHexString(const char * content, bool isReverse = false);

			/**
			 *
			 * 转换为16进制内容
			 *
			 * @param content 内容
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string ToHexString(const uint8_t * content, bool isReverse = false);

			/**
			 *
			 * 转换为16进制内容
			 *
			 * @param content 内容
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string ToHexString(const std::string & content, bool isReverse = false);

			/**
			 *
			 * 转换为16进制内容
			 *
			 * @param content 内容
			 * @param length 长度
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string ToHexString(const char * content, std::size_t length, bool isReverse = false);

			/**
			 *
			 * 转换为16进制内容
			 *
			 * @param content 内容
			 * @param length 长度
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string ToHexString(const uint8_t * content, std::size_t length, bool isReverse = false);

			/**
			 *
			 * 转换为16进制内容
			 *
			 * @param content 内容
			 * @param length 长度
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string ToHexString(const std::string & content, std::size_t length, bool isReverse = false);

			/**
			 *
			 * 美化json
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string BeautifyJson(const std::string & content);

			/**
			 *
			 * 转换为10进制内容
			 *
			 * @param content 内容
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string FromHexString(const char * content, bool isReverse = false);

			/**
			 *
			 * 转换为10进制内容
			 *
			 * @param content 内容
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string FromHexString(const uint8_t * content, bool isReverse = false);

			/**
			 *
			 * 转换为10进制内容
			 *
			 * @param content 内容
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string FromHexString(const std::string & content, bool isReverse = false);

			/**
			 *
			 * 转换为10进制内容
			 *
			 * @param content 内容
			 * @param length 长度
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string FromHexString(const char * content, std::size_t length, bool isReverse = false);

			/**
			 *
			 * 转换为10进制内容
			 *
			 * @param content 内容
			 * @param length 长度
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string FromHexString(const uint8_t * content, std::size_t length, bool isReverse = false);

			/**
			 *
			 * 转换为10进制内容
			 *
			 * @param content 内容
			 * @param length 长度
			 * @param isReverse 是否反向转换
			 *
			 * @return 结果
			 *
			 */
			static std::string FromHexString(const std::string & content, std::size_t length, bool isReverse = false);

			/**
			 *
			 * 过滤注释
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string FilterComments(const std::string & content);

			/**
			 *
			 * 千分位格式化
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string ThousandsFormat(const std::string & content);

			/**
			 *
			 * 按值拆分
			 *
			 * @param content 内容
			 * @param key 关键字
			 * @param isKeepEmpty 是否保留空串
			 *
			 * @return 结果
			 *
			 */
			static std::vector<std::string> Split(const std::string & content, const std::string & key, bool isKeepEmpty = false);

			/**
			 *
			 * 按行拆分
			 *
			 * @param content 内容
			 * @param isKeepEmpty 是否保留空行
			 *
			 * @return 结果
			 *
			 */
			static std::vector<std::string> SplitLine(const std::string & content, bool isKeepEmpty = false);
		};
	}
}


#endif // __UTIL__STRING__H__
