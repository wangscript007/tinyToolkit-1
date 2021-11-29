#ifndef __CONVERT__URL__H__
#define __CONVERT__URL__H__


/**
 *
 *  作者: hm
 *
 *  说明: url
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#include <string>
#include <cstdint>


namespace tinyToolkit
{
	namespace convert
	{
		class TOOLKIT_API Url
		{
		public:
			/**
			 *
			 * 编码
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string Encode(const char * content);

			/**
			 *
			 * 编码
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string Encode(const uint8_t * content);

			/**
			 *
			 * 编码
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string Encode(const std::string & content);

			/**
			 *
			 * 编码
			 *
			 * @param content 内容
			 * @param length 长度
			 *
			 * @return 结果
			 *
			 */
			static std::string Encode(const char * content, std::size_t length);

			/**
			 *
			 * 编码
			 *
			 * @param content 内容
			 * @param length 长度
			 *
			 * @return 结果
			 *
			 */
			static std::string Encode(const uint8_t * content, std::size_t length);

			/**
			 *
			 * 编码
			 *
			 * @param content 内容
			 * @param length 长度
			 *
			 * @return 结果
			 *
			 */
			static std::string Encode(const std::string & content, std::size_t length);

			/**
			 *
			 * 解码
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string Decode(const char * content);

			/**
			 *
			 * 解码
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string Decode(const uint8_t * content);

			/**
			 *
			 * 解码
			 *
			 * @param content 内容
			 *
			 * @return 结果
			 *
			 */
			static std::string Decode(const std::string & content);

			/**
			 *
			 * 解码
			 *
			 * @param content 内容
			 * @param length 长度
			 *
			 * @return 结果
			 *
			 */
			static std::string Decode(const char * content, std::size_t length);

			/**
			 *
			 * 解码
			 *
			 * @param content 内容
			 * @param length 长度
			 *
			 * @return 结果
			 *
			 */
			static std::string Decode(const uint8_t * content, std::size_t length);

			/**
			 *
			 * 解码
			 *
			 * @param content 内容
			 * @param length 长度
			 *
			 * @return 结果
			 *
			 */
			static std::string Decode(const std::string & content, std::size_t length);
		};
	}
}


#endif // __CONVERT__URL__H__
