#ifndef __UTIL__FILESYSTEM__H__
#define __UTIL__FILESYSTEM__H__


/**
 *
 *  作者: hm
 *
 *  说明: 文件处理
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#include <string>
#include <vector>
#include <fstream>
#include <functional>


namespace tinyToolkit
{
	namespace util
	{
		class TOOLKIT_API Filesystem
		{
		public:
			/**
			 *
			 * 更改工作目录
			 *
			 * @param path 路径
			 *
			 * @return 是否更改成功
			 *
			 */
			static bool Chdir(const std::string & path);

			/**
			 *
			 * 是否存在
			 *
			 * @param path 路径
			 *
			 * @return 是否存在
			 *
			 */
			static bool Exists(const std::string & path);

			/**
			 *
			 * 删除
			 *
			 * @param path 路径
			 *
			 * @return 是否删除成功
			 *
			 */
			static bool Remove(const std::string & path);

			/**
			 *
			 * 更改
			 *
			 * @param src 原始路径
			 * @param dst 目的路径
			 *
			 * @return 是否更改成功
			 *
			 */
			static bool Rename(const std::string & src, const std::string & dst);

			/**
			 *
			 * 读取文件
			 *
			 * @param path 路径
			 * @param result 结果
			 * @param isKeepEmpty 是否保留空行
			 *
			 * @return 是否读取成功
			 *
			 */
			static bool ReadFile(const std::string & path, std::vector<std::string> & result, bool isKeepEmpty = true);

			/**
			 *
			 * 遍历
			 *
			 * @param path 路径
			 * @param result 结果
			 * @param isRecursive 是否递归
			 *
			 * @return 是否遍历成功
			 *
			 */
			static bool Traverse(const std::string & path, std::vector<std::string> & result, bool isRecursive = false);

			/**
			 *
			 * 遍历
			 *
			 * @param path 路径
			 * @param result 结果
			 * @param pred 预判
			 * @param isRecursive 是否递归
			 *
			 * @return 是否遍历成功
			 *
			 */
			static bool Traverse(const std::string & path, std::vector<std::string> & result, const std::function<bool(const std::string &)> & pred, bool isRecursive = false);

			/**
			 *
			 * 写入文件
			 *
			 * @param path 路径
			 * @param content 内容
			 * @param isTruncate 是否截断
			 *
			 * @return 是否写入成功
			 *
			 */
			template <typename ContentType>
			static bool WriteFile(const std::string & path, ContentType && content, bool isTruncate = false)
			{
				if (path.empty())
				{
					return false;
				}

				std::ofstream ofs(path, std::ios::binary | (isTruncate ? std::ios::trunc : std::ios::app));

				if (!ofs.is_open())
				{
					return false;
				}

				ofs << std::forward<ContentType>(content);

				ofs.close();

				return true;
			}

			/**
			 *
			 * 写入文件
			 *
			 * @param path 路径
			 * @param content 内容
			 * @param isTruncate 是否截断
			 *
			 * @return 是否写入成功
			 *
			 */
			template <typename IteratorType>
			static bool WriteFile(const std::string & path, const IteratorType & begin, const IteratorType & end, bool isTruncate = false)
			{
				if (path.empty())
				{
					return false;
				}

				std::ofstream ofs(path, std::ios::binary | (isTruncate ? std::ios::trunc : std::ios::app));

				if (!ofs.is_open())
				{
					return false;
				}

				for (auto iter = begin; iter != end; ++iter)
				{
					ofs << *iter;
				}

				ofs.close();

				return true;
			}

			/**
			 *
			 * 创建文件
			 *
			 * @param path 路径
			 *
			 * @return 是否创建成功
			 *
			 */
			static bool CreateFiles(const std::string & path);

			/**
			 *
			 * 是否为目录
			 *
			 * @param path 路径
			 *
			 * @return 是否为目录
			 *
			 */
			static bool IsDirectory(const std::string & path);

			/**
			 *
			 * 遍历文件
			 *
			 * @param path 路径
			 * @param result 结果
			 * @param isRecursive 是否递归
			 *
			 * @return 是否遍历成功
			 *
			 */
			static bool TraverseFile(const std::string & path, std::vector<std::string> & result, bool isRecursive = false);

			/**
			 *
			 * 遍历文件
			 *
			 * @param path 路径
			 * @param result 结果
			 * @param pred 预判
			 * @param isRecursive 是否递归
			 *
			 * @return 是否遍历成功
			 *
			 */
			static bool TraverseFile(const std::string & path, std::vector<std::string> & result, const std::function<bool(const std::string &)> & pred, bool isRecursive = false);

			/**
			 *
			 * 创建目录
			 *
			 * @param path 路径
			 *
			 * @return 是否创建成功
			 *
			 */
			static bool CreateDirectories(const std::string & path);

			/**
			 *
			 * 遍历目录
			 *
			 * @param path 路径
			 * @param result 结果
			 * @param isRecursive 是否递归
			 *
			 * @return 是否遍历成功
			 *
			 */
			static bool TraverseDirectory(const std::string & path, std::vector<std::string> & result, bool isRecursive = false);

			/**
			 *
			 * 遍历目录
			 *
			 * @param path 路径
			 * @param result 结果
			 * @param pred 预判
			 * @param isRecursive 是否递归
			 *
			 * @return 是否遍历成功
			 *
			 */
			static bool TraverseDirectory(const std::string & path, std::vector<std::string> & result, const std::function<bool(const std::string &)> & pred, bool isRecursive = false);

			/**
			 *
			 * 文件大小
			 *
			 * @param path 路径
			 *
			 * @return 文件大小
			 *
			 */
			static std::size_t FileSize(const std::string & path);

			/**
			 *
			 * 目录名称
			 *
			 * @param path 路径
			 * @param isResolver 是否解析路径
			 *
			 * @return 目录名称
			 *
			 */
			static std::string Dirname(const std::string & path, bool isResolver = false);

			/**
			 *
			 * 文件名称
			 *
			 * @param path 路径
			 *
			 * @return 文件名称
			 *
			 */
			static std::string Basename(const std::string & path);

			/**
			 *
			 * 绝对路径
			 *
			 * @param path 路径
			 *
			 * @return 绝对路径
			 *
			 */
			static std::string Canonical(const std::string & path);

			/**
			 *
			 * 文件内容
			 *
			 * @param path 路径
			 *
			 * @return 文件内容
			 *
			 */
			static std::string FileContent(const std::string & path);

			/**
			 *
			 * 父级目录
			 *
			 * @param path 路径
			 *
			 * @return 父级目录
			 *
			 */
			static std::string ParentDirectory(const std::string & path);

			/**
			 *
			 * 当前目录
			 *
			 * @return 当前目录
			 *
			 */
			static std::string CurrentDirectory();

			/**
			 *
			 * 读取文件
			 *
			 * @param path 路径
			 * @param isKeepEmpty 是否保留空行
			 *
			 * @return 结果
			 *
			 */
			static std::vector<std::string> ReadFile(const std::string & path, bool isKeepEmpty = true);

			/**
			 *
			 * 遍历
			 *
			 * @param path 路径
			 * @param isRecursive 是否递归
			 *
			 * @return 结果
			 *
			 */
			static std::vector<std::string> Traverse(const std::string & path, bool isRecursive = false);

			/**
			 *
			 * 遍历
			 *
			 * @param path 路径
			 * @param pred 预判
			 * @param isRecursive 是否递归
			 *
			 * @return 结果
			 *
			 */
			static std::vector<std::string> Traverse(const std::string & path, const std::function<bool(const std::string &)> & pred, bool isRecursive = false);

			/**
			 *
			 * 遍历文件
			 *
			 * @param path 路径
			 * @param isRecursive 是否递归
			 *
			 * @return 结果
			 *
			 */
			static std::vector<std::string> TraverseFile(const std::string & path, bool isRecursive = false);

			/**
			 *
			 * 遍历文件
			 *
			 * @param path 路径
			 * @param pred 预判
			 * @param isRecursive 是否递归
			 *
			 * @return 结果
			 *
			 */
			static std::vector<std::string> TraverseFile(const std::string & path, const std::function<bool(const std::string &)> & pred, bool isRecursive = false);

			/**
			 *
			 * 遍历目录
			 *
			 * @param path 路径
			 * @param isRecursive 是否递归
			 *
			 * @return 结果
			 *
			 */
			static std::vector<std::string> TraverseDirectory(const std::string & path, bool isRecursive = false);

			/**
			 *
			 * 遍历目录
			 *
			 * @param path 路径
			 * @param pred 预判
			 * @param isRecursive 是否递归
			 *
			 * @return 结果
			 *
			 */
			static std::vector<std::string> TraverseDirectory(const std::string & path, const std::function<bool(const std::string &)> & pred, bool isRecursive = false);
		};
	}
}


#endif // __UTIL__FILESYSTEM__H__
