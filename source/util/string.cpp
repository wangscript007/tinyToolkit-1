/**
 *
 *  作者: hm
 *
 *  说明: 字符串处理
 *
 */


#include "string.h"

#include <cstring>
#include <cstdlib>
#include <algorithm>


namespace tinyToolkit
{
	namespace util
	{
		/**
		 *
		 * 删除
		 *
		 * @param content 内容
		 * @param key 关键字
		 * @param offset 偏移
		 *
		 */
		void String::Erase(std::string & content, char key, std::size_t offset)
		{
			if (content.empty() || offset > content.length())
			{
				return;
			}

			while ((offset = content.find(key, offset)) != std::string::npos)
			{
				content.erase(offset, 1);
			}
		}

		/**
		 *
		 * 删除
		 *
		 * @param content 内容
		 * @param key 关键字
		 * @param offset 偏移
		 *
		 */
		void String::Erase(std::string & content, const std::string & key, std::size_t offset)
		{
			if (key.empty() || content.empty() || offset > content.length())
			{
				return;
			}

			while ((offset = content.find(key, offset)) != std::string::npos)
			{
				content.erase(offset, key.length());
			}
		}

		/**
		 *
		 * 转换小写
		 *
		 * @param content 内容
		 * @param offset 偏移
		 *
		 */
		void String::Lower(std::string & content, std::size_t offset)
		{
			if (content.empty() || offset > content.length())
			{
				return;
			}

			std::transform(content.begin() + static_cast<std::string::difference_type>(offset), content.end(), content.begin() + static_cast<std::string::difference_type>(offset), ::tolower);
		}

		/**
		 *
		 * 转换大写
		 *
		 * @param content 内容
		 * @param offset 偏移
		 *
		 */
		void String::Upper(std::string & content, std::size_t offset)
		{
			if (content.empty() || offset > content.length())
			{
				return;
			}

			std::transform(content.begin() + static_cast<std::string::difference_type>(offset), content.end(), content.begin() + static_cast<std::string::difference_type>(offset), ::toupper);
		}

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
		void String::Split(const std::string & content, const std::string & key, std::vector<std::string> & result, bool isKeepEmpty)
		{
			if (key.empty() || content.empty())
			{
				if (content.empty())
				{
					if (isKeepEmpty)
					{
						result.emplace_back();
					}
				}
				else
				{
					result.push_back(content);
				}

				return;
			}

			std::string::const_iterator beg{ content.begin() };
			std::string::const_iterator end{ };

			while (true)
			{
				end = std::search(beg, content.end(), key.begin(), key.end());

				if (beg == end)
				{
					if (isKeepEmpty)
					{
						result.emplace_back();
					}
				}
				else
				{
					result.emplace_back(beg, end);
				}

				if (end == content.end())
				{
					break;
				}

				beg = end + static_cast<std::string::difference_type>(key.length());

				if (beg == content.end())
				{
					break;
				}
			}
		}

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
		void String::Replace(std::string & content, const std::string & src, const std::string & dst, std::size_t offset)
		{
			if (src.empty() || content.empty() || offset > content.length())
			{
				return;
			}

			for (std::size_t pos = offset; pos != std::string::npos; pos += dst.length())
			{
				if ((pos = content.find(src, pos)) == std::string::npos)
				{
					break;
				}

				content.replace(pos, src.length(), dst);
			}
		}

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
		bool String::EndWith(const std::string & content, const std::string & key)
		{
			return content.length() >= key.length() && std::equal(key.rbegin(), key.rend(), content.rbegin());
		}

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
		bool String::StartWith(const std::string & content, const std::string & key)
		{
			return content.length() >= key.length() && std::equal(key.begin(), key.end(), content.begin());
		}

		/**
		 *
		 * 按行拆分
		 *
		 * @param content 内容
		 * @param result 结果
		 * @param isKeepEmpty 是否保留空行
		 *
		 */
		void String::SplitLine(const std::string & content, std::vector<std::string> & result, bool isKeepEmpty)
		{
			if (content.empty())
			{
				if (isKeepEmpty)
				{
					result.emplace_back();
				}

				return;
			}

			std::size_t i = 0;
			std::size_t j = 0;

			while (i < content.length())
			{
				while (i < content.length() && content[i] != '\r' && content[i] != '\n' && content[i] != '\0')
				{
					++i;
				}

				if (i == j)
				{
					if (isKeepEmpty)
					{
						result.emplace_back();
					}
				}
				else
				{
					result.emplace_back(content.c_str() + j, content.c_str() + i);
				}

				if (i < content.length())
				{
					i += (content[i] == '\r' && (i + 1) < content.length() && content[i + 1] == '\n') ? 2 : 1;
				}

				j = i;
			}
		}

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
		void String::ReplaceLoop(std::string & content, const std::string & src, const std::string & dst, std::size_t offset)
		{
			if (src.empty() || content.empty() || offset > content.length())
			{
				return;
			}

			std::size_t pos;

			while (true)
			{
				if ((pos = content.find(src, offset)) == std::string::npos)
				{
					break;
				}

				content.replace(pos, src.length(), dst);
			}
		}

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
		bool String::EqualIgnoreCase(const std::string & src, const std::string & dst)
		{
			if (src.length() != dst.length())
			{
				return false;
			}

			return std::equal(src.begin(), src.end(), dst.begin(), [](char s, char d) -> bool
			{
				return ::tolower(s) == ::tolower(d);
			});
		}

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
		std::string String::Trim(const std::string & content, const char * pattern)
		{
			if (content.empty() || pattern == nullptr)
			{
				return content;
			}

			auto head = content.find_first_not_of(pattern);

			if (head == std::string::npos)
			{
				return std::string{ };
			}

			auto tail = content.find_last_not_of(pattern);

			return content.substr(head, 1 + tail - head);
		}

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
		std::string String::Erase(const std::string & content, char key, std::size_t offset)
		{
			std::string result = content;

			Erase(result, key, offset);

			return result;
		}

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
		std::string String::Erase(const std::string & content, const std::string & key, std::size_t offset)
		{
			std::string result = content;

			Erase(result, key, offset);

			return result;
		}

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
		std::string String::Lower(const std::string & content, std::size_t offset)
		{
			std::string result = content;

			Lower(result, offset);

			return result;
		}

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
		std::string String::Upper(const std::string & content, std::size_t offset)
		{
			std::string result = content;

			Upper(result, offset);

			return result;
		}

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
		std::string String::Replace(const std::string & content, const std::string & src, const std::string & dst, std::size_t offset)
		{
			std::string result = content;

			Replace(result, src, dst, offset);

			return result;
		}

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
		std::string String::TrimLeft(const std::string & content, const char * pattern)
		{
			if (content.empty() || pattern == nullptr)
			{
				return content;
			}

			auto head = content.find_first_not_of(pattern);

			if (head == std::string::npos)
			{
				return std::string{ };
			}

			return content.substr(head);
		}

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
		std::string String::TrimRight(const std::string & content, const char * pattern)
		{
			if (content.empty() || pattern == nullptr)
			{
				return content;
			}

			auto tail = content.find_last_not_of(pattern);

			if (tail == std::string::npos)
			{
				return std::string{ };
			}

			return content.substr(0, tail + 1);
		}

		/**
		 *
		 * 收缩json
		 *
		 * @param content 内容
		 *
		 * @return 结果
		 *
		 */
		std::string String::ReduceJson(const std::string & content)
		{
			if (content.empty())
			{
				return std::string{ };
			}

			std::size_t tag = 0;
			std::size_t length = content.length();

			std::string str{ };

			for (std::size_t i = 0; i < length; ++i)
			{
				auto & key = content[i];

				if ((tag & 1) == 0)
				{
					if (key == ' ' || key == '\t' || key == '\r' || key == '\n')
					{
						continue;
					}

					if (key == ',' || key == '[' || key == ']' || key == '{' || key == '}')
					{
						str += key;

						continue;
					}
				}

				if (key == '\"')
				{
					++tag;
				}

				str += key;
			}

			return str;
		}

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
		std::string String::ReplaceLoop(const std::string & content, const std::string & src, const std::string & dst, std::size_t offset)
		{
			std::string result = content;

			ReplaceLoop(result, src, dst, offset);

			return result;
		}

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
		std::string String::ToHexString(const char * content, bool isReverse)
		{
			if (content == nullptr)
			{
				return std::string{ };
			}

			return ToHexString(content, ::strlen(content), isReverse);
		}

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
		std::string String::ToHexString(const uint8_t * content, bool isReverse)
		{
			if (content == nullptr)
			{
				return std::string{ };
			}

			return ToHexString(content, ::strlen(reinterpret_cast<const char *>(content)), isReverse);
		}

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
		std::string String::ToHexString(const std::string & content, bool isReverse)
		{
			if (content.empty())
			{
				return std::string{ };
			}

			return ToHexString(content, content.length(), isReverse);
		}

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
		std::string String::ToHexString(const char * content, std::size_t length, bool isReverse)
		{
			if (content == nullptr || length == 0)
			{
				return std::string{ };
			}

			return ToHexString(reinterpret_cast<const uint8_t *>(content), length, isReverse);
		}

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
		std::string String::ToHexString(const uint8_t * content, std::size_t length, bool isReverse)
		{
			if (content == nullptr || length == 0)
			{
				return std::string{ };
			}

			static char Hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

			int64_t op = isReverse ? -1 : 1;
			int64_t end = isReverse ? -1 : static_cast<int64_t>(length);
			int64_t init = isReverse ? static_cast<int64_t>(length) - 1 : 0;

			std::string str{ };

			str.reserve(length * 2);

			for (int64_t i = init; i != end; i += op)
			{
				str += Hex[(content[i] >> 4) & 0x0F];
				str += Hex[(content[i] >> 0) & 0x0F];
			}

			return str;
		}

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
		std::string String::ToHexString(const std::string & content, std::size_t length, bool isReverse)
		{
			if (content.empty() || length == 0)
			{
				return std::string{ };
			}

			return ToHexString(content.c_str(), length, isReverse);
		}

		/**
		 *
		 * 美化json
		 *
		 * @param content 内容
		 *
		 * @return 结果
		 *
		 */
		std::string String::BeautifyJson(const std::string & content)
		{
			if (content.empty())
			{
				return std::string{ };
			}

			std::size_t tmp;
			std::size_t tag = 0;
			std::size_t count = 0;
			std::size_t length = content.length();

			std::string str{ };

			static auto append_indent = [](std::string & value, std::size_t indent_count)
			{
				for (std::size_t i = 0; i < indent_count; ++i)
				{
					value += '\t';
				}
			};

			for (std::size_t i = 0; i < length; ++i)
			{
				auto & key = content[i];

				if ((tag & 1) == 0)
				{
					if (key == ' ' || key == '\t' || key == '\r' || key == '\n')
					{
						continue;
					}

					if (key == ',')
					{
						str += key;
						str += TOOLKIT_LINE_EOL;

						append_indent(str, count);

						continue;
					}

					if (key == '[' || key == '{')
					{
						tmp = i;

						while (tmp >= 1)
						{
							--tmp;

							if (content[tmp] == ' ')
							{
								continue;
							}

							if (content[tmp] == ':')
							{
								str += TOOLKIT_LINE_EOL;

								append_indent(str, count);
							}

							break;
						}

						str += key;
						str += TOOLKIT_LINE_EOL;

						++count;

						append_indent(str, count);

						continue;
					}

					if (key == ']' || key == '}')
					{
						tmp = i;

						while (tmp >= 1)
						{
							--tmp;

							if (content[tmp] == ' ')
							{
								continue;
							}

							if (content[tmp] != ']' && content[tmp] != '}')
							{
								str += TOOLKIT_LINE_EOL;
							}

							break;
						}

						--count;

						append_indent(str, count);

						str += key;

						while ((i + 1) < length)
						{
							if (content[i + 1] == ' ')
							{
								++i;

								continue;
							}

							if (content[i + 1] != ',')
							{
								str += TOOLKIT_LINE_EOL;
							}

							break;
						}

						continue;
					}
				}

				if (key == '\"')
				{
					if (i > 1)
					{
						if (content[i - 1] != '\\')
						{
							++tag;
						}
					}
					else
					{
						++tag;
					}
				}

				str += key;
			}

			return str;
		}

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
		std::string String::FromHexString(const char * content, bool isReverse)
		{
			if (content == nullptr)
			{
				return std::string{ };
			}

			return FromHexString(content, ::strlen(content), isReverse);
		}

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
		std::string String::FromHexString(const uint8_t * content, bool isReverse)
		{
			if (content == nullptr)
			{
				return std::string{ };
			}

			return FromHexString(content, ::strlen(reinterpret_cast<const char *>(content)), isReverse);
		}

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
		std::string String::FromHexString(const std::string & content, bool isReverse)
		{
			if (content.empty())
			{
				return std::string{ };
			}

			return FromHexString(content, content.length(), isReverse);
		}

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
		std::string String::FromHexString(const char * content, std::size_t length, bool isReverse)
		{
			if (content == nullptr || length == 0)
			{
				return std::string{ };
			}

			int64_t op = isReverse ? -2 : 2;
			int64_t end = isReverse ? -2 : static_cast<int64_t>(length);
			int64_t init = isReverse ? static_cast<int64_t>(length) - 2 : 0;

			std::string str{ };

			str.reserve(length / 2);

			for (int64_t i = init; i != end; i += op)
			{
				char buffer[3] = { content[i], content[i + 1], '\0' };

				str.push_back(static_cast<char>(::strtol(buffer, nullptr, 16)));
			}

			return str;
		}

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
		std::string String::FromHexString(const uint8_t * content, std::size_t length, bool isReverse)
		{
			if (content == nullptr || length == 0)
			{
				return std::string{ };
			}

			return FromHexString(reinterpret_cast<const char *>(content), length, isReverse);
		}

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
		std::string String::FromHexString(const std::string & content, std::size_t length, bool isReverse)
		{
			if (content.empty() || length == 0)
			{
				return std::string{ };
			}

			return FromHexString(content.c_str(), length, isReverse);
		}

		/**
		 *
		 * 过滤注释
		 *
		 * @param content 内容
		 *
		 * @return 结果
		 *
		 */
		std::string String::FilterComments(const std::string & content)
		{
			if (content.empty())
			{
				return std::string{ };
			}

			enum class State : uint8_t
			{
				NORMAL,					/// 正常代码
				SLASH,					/// 斜杠
				NOTE_MULTI_LINE,		/// 多行注释
				NOTE_MULTI_LINE_STAR,	/// 多行注释遇到*
				NOTE_SINGLE_LINE,		/// 单行注释
				BACKSLASH,				/// 折行注释反斜线
				CHARACTER,				/// 字符
				ESCAPE_CHARACTER,		/// 字符中的转义字符
				STRING,					/// 字符串
				ESCAPE_STRING			/// 字符串中的转义字符
			};

			std::string str{ };

			State state = State::NORMAL;

			for (const char c : content)
			{
				switch (state)
				{
					case State::NORMAL: /// 正常代码
					{
						if (c == '/')
						{
							state = State::SLASH;
						}
						else
						{
							str.push_back(c);

							if (c == '\'')
							{
								state = State::CHARACTER;
							}
							else if (c == '\"')
							{
								state = State::STRING;
							}
							else
							{
								state = State::NORMAL; /// 保持当前状态
							}
						}

						break;
					}

					case State::SLASH: /// 斜杠
					{
						if (c == '*')
						{
							state = State::NOTE_MULTI_LINE;
						}
						else if (c == '/')
						{
							state = State::NOTE_SINGLE_LINE;
						}
						else
						{
							str.push_back('/');
							str.push_back(c);

							state = State::NORMAL;
						}

						break;
					}

					case State::NOTE_MULTI_LINE: /// 多行注释
					{
						if (c == '*')
						{
							state = State::NOTE_MULTI_LINE_STAR;
						}
						else
						{
							state = State::NOTE_MULTI_LINE; /// 保持当前状态
						}

						break;
					}

					case State::NOTE_MULTI_LINE_STAR: /// 多行注释遇到*
					{
						if (c == '/')
						{
							state = State::NORMAL; /// 注释结束
						}
						else if (c == '*')
						{
							state = State::NOTE_MULTI_LINE_STAR; /// 保持当前状态
						}
						else
						{
							state = State::NOTE_MULTI_LINE;
						}

						break;
					}

					case State::NOTE_SINGLE_LINE: /// 单行注释
					{
						if (c == '\\')
						{
							state = State::BACKSLASH;
						}
						else if (c == '\r' || c == '\n')
						{
							str.push_back(c);

							state = State::NORMAL; /// 注释结束
						}
						else
						{
							state = State::NOTE_SINGLE_LINE; /// 保持当前状态
						}

						break;
					}

					case State::BACKSLASH: /// 折行注释反斜线
					{
						if (c == '\\' || c == '\r' || c == '\n')
						{
							state = State::BACKSLASH; /// 保持当前状态
						}
						else
						{
							state = State::NOTE_SINGLE_LINE;
						}

						break;
					}

					case State::CHARACTER: /// 字符
					{
						str.push_back(c);

						if (c == '\\')
						{
							state = State::ESCAPE_CHARACTER;
						}
						else if (c == '\'')
						{
							state = State::NORMAL;
						}
						else
						{
							state = State::CHARACTER; /// 保持当前状态
						}

						break;
					}

					case State::ESCAPE_CHARACTER: /// 字符中的转义字符
					{
						str.push_back(c);

						state = State::CHARACTER;

						break;
					}

					case State::STRING: /// 字符串
					{
						str.push_back(c);

						if (c == '\\')
						{
							state = State::ESCAPE_STRING;
						}
						else if (c == '\"')
						{
							state = State::NORMAL;
						}
						else
						{
							state = State::STRING; /// 保持当前状态
						}

						break;
					}

					case State::ESCAPE_STRING: /// 字符串中的转义字符
					{
						str.push_back(c);

						state = State::STRING;

						break;
					}

					default:
					{
						break;
					}
				}
			}

			return str;
		}

		/**
		 *
		 * 千分位格式化
		 *
		 * @param content 内容
		 *
		 * @return 结果
		 *
		 */
		std::string String::ThousandsFormat(const std::string & content)
		{
			if (content.empty())
			{
				return std::string{ };
			}

			std::size_t sepCount{ 0 };
			std::size_t preCount{ 0 };
			std::size_t subCount{ 0 };
			std::size_t tagCount{ 0 };

			for (auto & c : content)
			{
				if (!::isdigit(c))
				{
					if (c == '.')
					{
						if (++sepCount == 1)
						{
							continue;
						}
					}

					return content;
				}

				if (sepCount)
				{
					++subCount;
				}
				else
				{
					if (++preCount == 4)
					{
						preCount = 1;

						++tagCount;
					}
				}
			}

			if (tagCount == 0)
			{
				return content;
			}

			std::string value{ };

			value.reserve(preCount + tagCount * 4 + sepCount + subCount);

			if (preCount)
			{
				value.append(content.c_str(), preCount);
			}

			for (std::size_t i = 0; i < tagCount; ++i)
			{
				value.append(1, ',');
				value.append(content.c_str() + preCount + (i * 3), 3);
			}

			value.append(content.c_str() + preCount + (tagCount * 3), content.length() - preCount - (tagCount * 3));

			return value;
		}

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
		std::vector<std::string> String::Split(const std::string & content, const std::string & key, bool isKeepEmpty)
		{
			std::vector<std::string> result{ };

			Split(content, key, result, isKeepEmpty);

			return result;
		}

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
		std::vector<std::string> String::SplitLine(const std::string & content, bool isKeepEmpty)
		{
			std::vector<std::string> result{ };

			SplitLine(content, result, isKeepEmpty);

			return result;
		}
	}
}
