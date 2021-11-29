#ifndef __OPTIONS__DESCRIPTION__H__
#define __OPTIONS__DESCRIPTION__H__


/**
 *
 *  作者: hm
 *
 *  说明: 描述信息
 *
 */


#include "value.h"


namespace tinyToolkit
{
	namespace options
	{
		class TOOLKIT_API Description
		{
		public:
			/**
			 *
			 * 构造函数
			 *
			 * @param longName 全长名称
			 * @param shortName 缩略名称
			 * @param info 信息
			 *
			 */
			Description(const char * longName, const char * shortName, const char * info);

			/**
			 *
			 * 构造函数
			 *
			 * @param longName 全长名称
			 * @param shortName 缩略名称
			 * @param info 信息
			 * @param value 数据
			 *
			 */
			Description(const char * longName, const char * shortName, const char * info, std::shared_ptr<BasicValue> value);

		public:
			/**
			 *
			 * 更新
			 *
			 */
			void Update();

			/**
			 *
			 * 更新
			 *
			 * @param content 内容
			 *
			 */
			void Update(const std::string & content);

			/**
			 *
			 * 是否有效
			 *
			 * @return 是否有效
			 *
			 */
			bool IsValid() const;

			/**
			 *
			 * 是否需要数据
			 *
			 * @return 是否需要数据
			 *
			 */
			bool IsRequired() const;

			/**
			 *
			 * 信息
			 *
			 * @return 信息
			 *
			 */
			const std::string & Info() const;

			/**
			 *
			 * 名称
			 *
			 * @return 名称
			 *
			 */
			const std::string & LongName() const;

			/**
			 *
			 * 名称
			 *
			 * @return 名称
			 *
			 */
			const std::string & ShortName() const;

			/**
			 *
			 * 名称
			 *
			 * @return 名称
			 *
			 */
			const std::string & OptionName() const;

			/**
			 *
			 * 数据
			 *
			 * @return 数据
			 *
			 */
			const std::shared_ptr<BasicValue> & Value() const;

		private:
			/**
			 *
			 * 设置名称
			 *
			 * @param longName 全长名称
			 * @param shortName 缩略名称
			 *
			 */
			void SetName(const char * longName, const char * shortName);

		private:
			bool _isValid{ false };

			std::string _info{ };
			std::string _longName{ };
			std::string _shortName{ };
			std::string _optionName{ };

			std::shared_ptr<BasicValue> _value{ };
		};
	}
}


#endif // __OPTIONS__DESCRIPTION__H__
