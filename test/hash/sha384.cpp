/**
 *
 *  作者: hm
 *
 *  说明: sha384
 *
 */


#include "sha384.h"


TOOLKIT_TEST_CASE(SHA384, Char)
{
	std::vector<std::string> src{ "123", "abc", ";'.", "#$%" };
	std::vector<std::string> dst
	{
		"9A0A82F0C0CF31470D7AFFEDE3406CC9AA8410671520B727044EDA15B4C25532A9B5CD8AAF9CEC4919D76255B6BFB00F",
		"40889BD7AEE5BE35F9D713C4F51FF00FE2099FD901D094284D6EDC9AA39EC096CEBE9547D3CBAF1F35101A6489F033C3",
		"4A9A4CB6D188D679B1C194F6FD86A90339F44222FC43DB4A97CA2761773139B6CB7E5DA45B44D4F28E48378C03F0F577",
		"F4EFBEDB2D0C87D1E8840C335676C7F7A1F6C2AC974873C8DB3343ED598287286C0EF2F3CB3CDE2CC8A2FF01AE0BC13C"
	};

	tinyToolkit::hash::SHA384 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(src[i].c_str());

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA384, UChar)
{
	std::vector<std::string> src{ "123", "abc", ";'.", "#$%" };
	std::vector<std::string> dst
	{
		"9A0A82F0C0CF31470D7AFFEDE3406CC9AA8410671520B727044EDA15B4C25532A9B5CD8AAF9CEC4919D76255B6BFB00F",
		"40889BD7AEE5BE35F9D713C4F51FF00FE2099FD901D094284D6EDC9AA39EC096CEBE9547D3CBAF1F35101A6489F033C3",
		"4A9A4CB6D188D679B1C194F6FD86A90339F44222FC43DB4A97CA2761773139B6CB7E5DA45B44D4F28E48378C03F0F577",
		"F4EFBEDB2D0C87D1E8840C335676C7F7A1F6C2AC974873C8DB3343ED598287286C0EF2F3CB3CDE2CC8A2FF01AE0BC13C"
	};

	tinyToolkit::hash::SHA384 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(reinterpret_cast<const uint8_t *>(src[i].c_str()));

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA384, String)
{
	std::vector<std::string> src{ "123", "abc", ";'.", "#$%" };
	std::vector<std::string> dst
	{
		"9A0A82F0C0CF31470D7AFFEDE3406CC9AA8410671520B727044EDA15B4C25532A9B5CD8AAF9CEC4919D76255B6BFB00F",
		"40889BD7AEE5BE35F9D713C4F51FF00FE2099FD901D094284D6EDC9AA39EC096CEBE9547D3CBAF1F35101A6489F033C3",
		"4A9A4CB6D188D679B1C194F6FD86A90339F44222FC43DB4A97CA2761773139B6CB7E5DA45B44D4F28E48378C03F0F577",
		"F4EFBEDB2D0C87D1E8840C335676C7F7A1F6C2AC974873C8DB3343ED598287286C0EF2F3CB3CDE2CC8A2FF01AE0BC13C"
	};

	tinyToolkit::hash::SHA384 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(src[i]);

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA384, Char_Length)
{
	std::vector<std::string> src{ "123456", "abcdef", ";'.,/]", "#$%^&*" };
	std::vector<std::string> dst
	{
		"9A0A82F0C0CF31470D7AFFEDE3406CC9AA8410671520B727044EDA15B4C25532A9B5CD8AAF9CEC4919D76255B6BFB00F",
		"40889BD7AEE5BE35F9D713C4F51FF00FE2099FD901D094284D6EDC9AA39EC096CEBE9547D3CBAF1F35101A6489F033C3",
		"4A9A4CB6D188D679B1C194F6FD86A90339F44222FC43DB4A97CA2761773139B6CB7E5DA45B44D4F28E48378C03F0F577",
		"F4EFBEDB2D0C87D1E8840C335676C7F7A1F6C2AC974873C8DB3343ED598287286C0EF2F3CB3CDE2CC8A2FF01AE0BC13C"
	};

	tinyToolkit::hash::SHA384 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(src[i].c_str(), 3);

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA384, UChar_Length)
{
	std::vector<std::string> src{ "123456", "abcdef", ";'.,/]", "#$%^&*" };
	std::vector<std::string> dst
	{
		"9A0A82F0C0CF31470D7AFFEDE3406CC9AA8410671520B727044EDA15B4C25532A9B5CD8AAF9CEC4919D76255B6BFB00F",
		"40889BD7AEE5BE35F9D713C4F51FF00FE2099FD901D094284D6EDC9AA39EC096CEBE9547D3CBAF1F35101A6489F033C3",
		"4A9A4CB6D188D679B1C194F6FD86A90339F44222FC43DB4A97CA2761773139B6CB7E5DA45B44D4F28E48378C03F0F577",
		"F4EFBEDB2D0C87D1E8840C335676C7F7A1F6C2AC974873C8DB3343ED598287286C0EF2F3CB3CDE2CC8A2FF01AE0BC13C"
	};

	tinyToolkit::hash::SHA384 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(reinterpret_cast<const uint8_t *>(src[i].c_str()), 3);

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA384, String_Length)
{
	std::vector<std::string> src{ "123456", "abcdef", ";'.,/]", "#$%^&*" };
	std::vector<std::string> dst
	{
		"9A0A82F0C0CF31470D7AFFEDE3406CC9AA8410671520B727044EDA15B4C25532A9B5CD8AAF9CEC4919D76255B6BFB00F",
		"40889BD7AEE5BE35F9D713C4F51FF00FE2099FD901D094284D6EDC9AA39EC096CEBE9547D3CBAF1F35101A6489F033C3",
		"4A9A4CB6D188D679B1C194F6FD86A90339F44222FC43DB4A97CA2761773139B6CB7E5DA45B44D4F28E48378C03F0F577",
		"F4EFBEDB2D0C87D1E8840C335676C7F7A1F6C2AC974873C8DB3343ED598287286C0EF2F3CB3CDE2CC8A2FF01AE0BC13C"
	};

	tinyToolkit::hash::SHA384 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(src[i], 3);

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}
