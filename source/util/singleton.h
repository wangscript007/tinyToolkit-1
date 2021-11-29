#ifndef __UTIL__SINGLETON__H__
#define __UTIL__SINGLETON__H__


/**
 *
 *  作者: hm
 *
 *  说明: 单例对象
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#include <mutex>
#include <memory>


namespace tinyToolkit
{
	namespace util
	{
		template <typename ObjectType>
		class Singleton
		{
		public:
			/**
			 *
			 * 获取单例
			 *
			 * @param args 参数
			 *
			 * @return 单例对象
			 *
			 */
			template <typename ... Args>
			static ObjectType & Instance(Args &&... args)
			{
				std::call_once(_flag, [](Args &&... args_)
				{
					_instance = std::unique_ptr<ObjectType>(new ObjectType(std::forward<Args>(args_)...));
				}, std::forward<Args>(args)...);

				return *_instance;
			}

		private:
			/**
			 *
			 * 构造函数
			 *
			 */
			Singleton() = default;

			/**
			 *
			 * 析构函数
			 *
			 */
			~Singleton() = default;

		private:
			static std::once_flag _flag;

			static std::unique_ptr<ObjectType> _instance;
		};

		template <typename ObjectType>
		std::once_flag Singleton<ObjectType>::_flag;

		template <typename ObjectType>
		std::unique_ptr<ObjectType> Singleton<ObjectType>::_instance = nullptr;
	}
}


#endif // __UTIL__SINGLETON__H__
