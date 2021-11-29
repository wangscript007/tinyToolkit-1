/**
 *
 *  作者: hm
 *
 *  说明: 文件处理
 *
 */


#include "filesystem.h"

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS
#
#  include <cstdlib>
#
#  include <io.h>
#  include <direct.h>
#  include <Windows.h>
#
#else
#
#  include <unistd.h>
#  include <dirent.h>
#
#  include <sys/stat.h>
#
#endif

#include <cstdio>
#include <memory>
#include <cstring>


namespace tinyToolkit
{
	namespace util
	{
		/**
		 *
		 * 是否为目录
		 *
		 * @param path 路径
		 *
		 * @return 是否为目录
		 *
		 */
		static bool IsDir(const std::string & path)
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			return ::GetFileAttributesA(path.c_str()) & FILE_ATTRIBUTE_DIRECTORY;

		#else

			#if TOOLKIT_PLATFORM_BYTE == 32 || TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

				struct stat st{ };

				if (::stat(path.c_str(), &st) == -1)
				{
					return false;
				}

			#else

				struct stat64 st{ };

				if (::stat64(path.c_str(), &st) == -1)
				{
					return false;
				}

			#endif

			return S_ISDIR(st.st_mode);

		#endif
		}

		/**
		 *
		 * 扫描路径
		 *
		 * @param path 路径
		 * @param separator 分隔符
		 * @param files 文件结果
		 * @param directories 目录结果
		 * @param pred 预判
		 * @param isRecursive 是否递归
		 *
		 * @return 是否扫描成功
		 *
		 */
		static bool ScanPath(const std::string & path, char separator, std::vector<std::string> * files, std::vector<std::string> * directories, const std::function<bool(const std::string &)> & pred, bool isRecursive)
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			std::string match{ };

			match.reserve(path.length() + 3);

			match.append(path);
			match.append("*.*", 3);

			WIN32_FIND_DATA finder{ };

			std::unique_ptr<typename std::remove_pointer<HANDLE>::type, std::function<void(HANDLE)>> dir
			(
				::FindFirstFile(match.c_str(), &finder),

				[](HANDLE handle)
				{
					if (handle && handle != INVALID_HANDLE_VALUE)
					{
						::FindClose(handle);
					}
				}
			);

			if (dir == nullptr || dir.get() == INVALID_HANDLE_VALUE)
			{
				return false;
			}

			bool status = true;

			do
			{
				if (::strcmp(finder.cFileName, ".") == 0 || ::strcmp(finder.cFileName, "..") == 0)
				{
					continue;
				}

				std::string value{ };

				value.reserve(path.length() + TOOLKIT_PATH_MAX + 1);

				value.append(path);
				value.append(finder.cFileName);

				if (finder.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (directories)
					{
						if (pred == nullptr || pred(value))
						{
							directories->push_back(value);
						}
					}

					if (isRecursive)
					{
						value.push_back(separator);

						if (!ScanPath(value, separator, files, directories, pred, isRecursive))
						{
							status = false;
						}
					}
				}
				else
				{
					if (files)
					{
						if (pred == nullptr || pred(value))
						{
							files->push_back(value);
						}
					}
				}
			}
			while (::FindNextFile(dir.get(), &finder));

		#else

			std::unique_ptr<DIR, std::function<void(DIR *)>> dir
			(
				::opendir(path.empty() ? "." : path.c_str()),

				[](DIR * handle)
				{
					if (handle)
					{
						::closedir(handle);
					}
				}
			);

			if (dir == nullptr)
			{
				return false;
			}

			struct dirent * finder = ::readdir(dir.get());

			if (finder == nullptr)
			{
				return false;
			}

			bool status = true;

			do
			{
				if (::strcmp(finder->d_name, ".") == 0 || ::strcmp(finder->d_name, "..") == 0)
				{
					continue;
				}

				std::string value{ };

				value.reserve(path.length() + TOOLKIT_NAME_MAX + 1);

				value.append(path);
				value.append(finder->d_name);

				if (IsDir(value))
				{
					if (directories)
					{
						if (pred == nullptr || pred(value))
						{
							directories->push_back(value);
						}
					}

					if (isRecursive)
					{
						value.push_back(separator);

						if (!ScanPath(value, separator, files, directories, pred, isRecursive))
						{
							status = false;
						}
					}
				}
				else
				{
					if (files)
					{
						if (pred == nullptr || pred(value))
						{
							files->push_back(value);
						}
					}
				}
			}
			while ((finder = ::readdir(dir.get())));

		#endif

			return status;
		}

		/**
		 *
		 * 创建目录
		 *
		 * @param path 路径
		 *
		 * @return 是否创建成功
		 *
		 */
		static bool CreateDir(const std::string & path)
		{
			if (path.empty())
			{
				return false;
			}

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			if (::_access(path.c_str(), S_OK) == 0)
			{
				return true;
			}

			return ::_mkdir(path.c_str()) == 0;

		#else

			if (::access(path.c_str(), F_OK) == 0)
			{
				return true;
			}

			return ::mkdir(path.c_str(), 0777) == 0;

		#endif
		}

		/**
		 *
		 * 删除资源
		 *
		 * @param path 路径
		 *
		 * @return 是否删除成功
		 *
		 */
		static bool RemoveResource(const std::string & path, char separator)
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			if (!IsDir(path))
			{
				return ::DeleteFile(path.c_str()) == TRUE;
			}

			std::string match{ };

			match.reserve(path.length() + 3);

			match.append(path);
			match.append("*.*", 3);

			WIN32_FIND_DATA finder{ };

			std::unique_ptr<typename std::remove_pointer<HANDLE>::type, std::function<void(HANDLE)>> dir
			(
				::FindFirstFile(match.c_str(), &finder),

				[](HANDLE handle)
				{
					if (handle && handle != INVALID_HANDLE_VALUE)
					{
						::FindClose(handle);
					}
				}
			);

			if (dir == nullptr || dir.get() == INVALID_HANDLE_VALUE)
			{
				return false;
			}

			bool status = true;

			do
			{
				if (::strcmp(finder.cFileName, ".") == 0 || ::strcmp(finder.cFileName, "..") == 0)
				{
					continue;
				}

				std::string value{ };

				value.reserve(path.length() + TOOLKIT_PATH_MAX + 1);

				value.append(path);
				value.append(finder.cFileName);

				if (finder.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					value.push_back(separator);

					if (!RemoveResource(value, separator))
					{
						status = false;
					}
				}
				else
				{
					if (::DeleteFile(value.c_str()) == FALSE)
					{
						status = false;
					}
				}
			}
			while (::FindNextFile(dir.get(), &finder));

			if (::RemoveDirectory(path.c_str()) == FALSE)
			{
				status = false;
			}

		#else

			if (!IsDir(path))
			{
				return std::remove(path.c_str()) == 0;
			}

			std::unique_ptr<DIR, std::function<void(DIR *)>> dir
			(
				::opendir(path.empty() ? "." : path.c_str()),

				[](DIR * handle)
				{
					if (handle)
					{
						::closedir(handle);
					}
				}
			);

			if (dir == nullptr)
			{
				return false;
			}

			struct dirent * finder = ::readdir(dir.get());

			if (finder == nullptr)
			{
				return false;
			}

			bool status = true;

			do
			{
				if (::strcmp(finder->d_name, ".") == 0 || ::strcmp(finder->d_name, "..") == 0)
				{
					continue;
				}

				std::string value{ };

				value.reserve(path.length() + TOOLKIT_NAME_MAX + 1);

				value.append(path);
				value.append(finder->d_name);

				if (IsDir(value))
				{
					value.push_back(separator);

					if (!RemoveResource(value, separator))
					{
						status = false;
					}
				}
				else
				{
					if (std::remove(value.c_str()) == -1)
					{
						status = false;
					}
				}
			}
			while ((finder = ::readdir(dir.get())));

			if (::rmdir(path.c_str()) == -1)
			{
				status = false;
			}

		#endif

			return status;
		}

		/**
		 *
		 * 分隔符
		 *
		 * @param path 路径
		 *
		 * @return 分隔符
		 *
		 */
		static char Separator(const std::string & path)
		{
			auto find = path.find_last_of("\\/");

			return find == std::string::npos ? TOOLKIT_PATH_SEP : path[find];
		}

		/**
		 *
		 * 标准化路径
		 *
		 * @param path 路径
		 *
		 * @return 标准化路径
		 *
		 */
		static std::string NormalizePath(const std::string & path)
		{
			if (path.length() == 1)
			{
				if (path[0] == '.')
				{
					return std::string{ };
				}
				else if (path[0] == '/')
				{
					return path;
				}
			}

			auto find = path.find_last_of("\\/");

			if (find == std::string::npos)
			{
				return path + TOOLKIT_PATH_SEP;
			}

			return find == (path.length() - 1) ? path : path + path[find];
		}


		////////////////////////////////////////////////////////////////////////////////////////////////////


		/**
		 *
		 * 更改工作目录
		 *
		 * @param path 路径
		 *
		 * @return 是否更改成功
		 *
		 */
		bool Filesystem::Chdir(const std::string & path)
		{
			if (!IsDirectory(path))
			{
				return false;
			}

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			return ::_chdir(path.c_str()) == 0;

		#else

			return ::chdir(path.c_str()) == 0;

		#endif
		}

		/**
		 *
		 * 是否存在
		 *
		 * @param path 路径
		 *
		 * @return 是否存在
		 *
		 */
		bool Filesystem::Exists(const std::string & path)
		{
			if (path.empty())
			{
				return false;
			}

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			return ::_access(path.c_str(), S_OK) == 0;

		#else

			return ::access(path.c_str(), F_OK) == 0;

		#endif
		}

		/**
		 *
		 * 删除
		 *
		 * @param path 路径
		 *
		 * @return 是否删除成功
		 *
		 */
		bool Filesystem::Remove(const std::string & path)
		{
			if (!Exists(path))
			{
				return true;
			}

			return RemoveResource(IsDir(path) ? NormalizePath(path) : path, Separator(path));
		}

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
		bool Filesystem::Rename(const std::string & src, const std::string & dst)
		{
			if (!Exists(src))
			{
				return false;
			}

			if (dst.empty() || Exists(dst))
			{
				return false;
			}

			return std::rename(src.c_str(), dst.c_str()) == 0;
		}

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
		bool Filesystem::ReadFile(const std::string & path, std::vector<std::string> & result, bool isKeepEmpty)
		{
			if (!Exists(path))
			{
				return false;
			}

			if (IsDir(path))
			{
				return false;
			}

			std::ifstream ifs(path, std::ios::binary);

			if (!ifs.is_open())
			{
				return false;
			}

			std::string content{ };

			while (!ifs.eof())
			{
				std::getline(ifs, content);

				if (content.empty() || content[0] == '\r' || content[0] == '\n')
				{
					if (isKeepEmpty)
					{
						result.emplace_back();
					}
				}
				else
				{
					std::size_t length = content.length();

					while (length > 0)
					{
						if (content[length - 1] != '\r' && content[length - 1] != '\n')
						{
							break;
						}

						--length;
					}

					result.emplace_back(content.c_str(), length);
				}
			}

			ifs.close();

			return true;
		}

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
		bool Filesystem::Traverse(const std::string & path, std::vector<std::string> & result, bool isRecursive)
		{
			if (!IsDirectory(path))
			{
				return false;
			}

			return ScanPath(NormalizePath(path), Separator(path), &result, &result, nullptr, isRecursive);
		}

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
		bool Filesystem::Traverse(const std::string & path, std::vector<std::string> & result, const std::function<bool(const std::string &)> & pred, bool isRecursive)
		{
			if (!IsDirectory(path))
			{
				return false;
			}

			return ScanPath(NormalizePath(path), Separator(path), &result, &result, pred, isRecursive);
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
		bool Filesystem::CreateFiles(const std::string & path)
		{
			if (path.empty())
			{
				return false;
			}

			if (Exists(path))
			{
				return !IsDir(path);
			}

			CreateDirectories(Dirname(path));

			std::ofstream ofs(path, std::ios::binary);

			if (!ofs.is_open())
			{
				return false;
			}

			ofs.close();

			return true;
		}

		/**
		 *
		 * 是否为目录
		 *
		 * @param path 路径
		 *
		 * @return 是否为目录
		 *
		 */
		bool Filesystem::IsDirectory(const std::string & path)
		{
			return Exists(path) && IsDir(path);
		}

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
		bool Filesystem::TraverseFile(const std::string & path, std::vector<std::string> & result, bool isRecursive)
		{
			if (!IsDirectory(path))
			{
				return false;
			}

			return ScanPath(NormalizePath(path), Separator(path), &result, nullptr, nullptr, isRecursive);
		}

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
		bool Filesystem::TraverseFile(const std::string & path, std::vector<std::string> & result, const std::function<bool(const std::string &)> & pred, bool isRecursive)
		{
			if (!IsDirectory(path))
			{
				return false;
			}

			return ScanPath(NormalizePath(path), Separator(path), &result, nullptr, pred, isRecursive);
		}

		/**
		 *
		 * 创建目录
		 *
		 * @param path 路径
		 *
		 * @return 是否创建成功
		 *
		 */
		bool Filesystem::CreateDirectories(const std::string & path)
		{
			if (path.empty())
			{
				return false;
			}

			if (Exists(path))
			{
				return IsDir(path);
			}

			std::size_t offset = 0;

			do
			{
				auto pos = path.find_first_of("\\/", offset);

				if (pos == std::string::npos)
				{
					pos = path.length();
				}

				if (pos == 0)
				{
					pos = 1;
				}

				if (!CreateDir(path.substr(0, pos)))
				{
					return false;
				}

				offset = pos + 1;
			}
			while (offset < path.length());

			return true;
		}

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
		bool Filesystem::TraverseDirectory(const std::string & path, std::vector<std::string> & result, bool isRecursive)
		{
			if (!IsDirectory(path))
			{
				return false;
			}

			return ScanPath(NormalizePath(path), Separator(path), nullptr, &result, nullptr, isRecursive);
		}

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
		bool Filesystem::TraverseDirectory(const std::string & path, std::vector<std::string> & result, const std::function<bool(const std::string &)> & pred, bool isRecursive)
		{
			if (!IsDirectory(path))
			{
				return false;
			}

			return ScanPath(NormalizePath(path), Separator(path), nullptr, &result, pred, isRecursive);
		}

		/**
		 *
		 * 文件大小
		 *
		 * @param path 路径
		 *
		 * @return 文件大小
		 *
		 */
		std::size_t Filesystem::FileSize(const std::string & path)
		{
			if (!Exists(path))
			{
				return 0;
			}

			if (IsDir(path))
			{
				return 0;
			}

			std::ifstream ifs(path, std::ifstream::binary | std::ifstream::ate);

			if (!ifs.is_open())
			{
				return 0;
			}

			auto size = static_cast<std::size_t>(ifs.tellg());

			ifs.close();

			return size;
		}

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
		std::string Filesystem::Dirname(const std::string & path, bool isResolver)
		{
			if (path.empty())
			{
				return std::string{ };
			}

			std::size_t pos = path.find_last_of("\\/");

			if (pos == std::string::npos)
			{
				return isResolver ? CurrentDirectory() : ".";
			}

			if (pos == 0)
			{
				pos = 1;
			}

			return [&](const std::string & dir)
			{
				return isResolver ? Canonical(dir) : dir;
			}(path.substr(0, pos));
		}

		/**
		 *
		 * 文件名称
		 *
		 * @param path 路径
		 *
		 * @return 文件名称
		 *
		 */
		std::string Filesystem::Basename(const std::string & path)
		{
			if (path.empty())
			{
				return std::string{ };
			}

			std::size_t pos = path.find_last_of("\\/");

			if (pos == std::string::npos)
			{
				return path;
			}

			return path.substr(pos + 1);
		}

		/**
		 *
		 * 绝对路径
		 *
		 * @param path 路径
		 *
		 * @return 绝对路径
		 *
		 */
		std::string Filesystem::Canonical(const std::string & path)
		{
			if (!Exists(path))
			{
				return std::string{ };
			}

			char content[TOOLKIT_PATH_MAX + 1]{ 0 };

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			if (::_fullpath(content, path.c_str(), TOOLKIT_PATH_MAX) == nullptr)
			{
				return std::string{ };
			}

			char * tail = ::strrchr(content, TOOLKIT_PATH_SEP);

			if (*(tail + 1) == '\0' && tail != ::strchr(content, TOOLKIT_PATH_SEP))
			{
				*tail = '\0';
			}

		#else

			if (::realpath(path.c_str(), content) == nullptr)
			{
				return std::string{ };
			}

		#endif

			return content;
		}

		/**
		 *
		 * 文件内容
		 *
		 * @param path 路径
		 *
		 * @return 文件内容
		 *
		 */
		std::string Filesystem::FileContent(const std::string & path)
		{
			if (!Exists(path))
			{
				return std::string{ };
			}

			if (IsDir(path))
			{
				return std::string{ };
			}

			std::ifstream ifs(path, std::ios::binary);

			if (!ifs.is_open())
			{
				return std::string{ };
			}

			std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

			ifs.close();

			return content;
		}

		/**
		 *
		 * 父级目录
		 *
		 * @param path 路径
		 *
		 * @return 父级目录
		 *
		 */
		std::string Filesystem::ParentDirectory(const std::string & path)
		{
			if (!Exists(path))
			{
				return std::string{ };
			}

			auto dir = Canonical(path);

			if (dir.length() == 1)
			{
				return dir;
			}

			std::size_t head = dir.find(TOOLKIT_PATH_SEP);
			std::size_t tail = dir.rfind(TOOLKIT_PATH_SEP);

			return dir.substr(0, head == tail ? tail + 1 : tail);
		}

		/**
		 *
		 * 当前目录
		 *
		 * @return 当前目录
		 *
		 */
		std::string Filesystem::CurrentDirectory()
		{
			char content[TOOLKIT_PATH_MAX + 1]{ 0 };

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			if (::_getcwd(content, TOOLKIT_PATH_MAX) == nullptr)
			{
				return std::string{ };
			}

		#else

			if (::getcwd(content, TOOLKIT_PATH_MAX) == nullptr)
			{
				return std::string{ };
			}

		#endif

			return content;
		}

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
		std::vector<std::string> Filesystem::ReadFile(const std::string & path, bool isKeepEmpty)
		{
			std::vector<std::string> result{ };

			ReadFile(path, result, isKeepEmpty);

			return result;
		}

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
		std::vector<std::string> Filesystem::Traverse(const std::string & path, bool isRecursive)
		{
			std::vector<std::string> result{ };

			Traverse(path, result, isRecursive);

			return result;
		}

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
		std::vector<std::string> Filesystem::Traverse(const std::string & path, const std::function<bool(const std::string &)> & pred, bool isRecursive)
		{
			std::vector<std::string> result{ };

			Traverse(path, result, pred, isRecursive);

			return result;
		}

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
		std::vector<std::string> Filesystem::TraverseFile(const std::string & path, bool isRecursive)
		{
			std::vector<std::string> result{ };

			TraverseFile(path, result, isRecursive);

			return result;
		}

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
		std::vector<std::string> Filesystem::TraverseFile(const std::string & path, const std::function<bool(const std::string &)> & pred, bool isRecursive)
		{
			std::vector<std::string> result{ };

			TraverseFile(path, result, pred, isRecursive);

			return result;
		}

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
		std::vector<std::string> Filesystem::TraverseDirectory(const std::string & path, bool isRecursive)
		{
			std::vector<std::string> result{ };

			TraverseDirectory(path, result, isRecursive);

			return result;
		}

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
		std::vector<std::string> Filesystem::TraverseDirectory(const std::string & path, const std::function<bool(const std::string &)> & pred, bool isRecursive)
		{
			std::vector<std::string> result{ };

			TraverseDirectory(path, result, pred, isRecursive);

			return result;
		}
	}
}
