/**
 *
 *  作者: hm
 *
 *  说明: sha512
 *
 */


#include "sha512.h"


TOOLKIT_TEST_CASE(SHA512, Char)
{
	std::vector<std::string> src{ "123", "abc", ";'.", "#$%" };
	std::vector<std::string> dst
	{
		"3C9909AFEC25354D551DAE21590BB26E38D53F2173B8D3DC3EEE4C047E7AB1C1EB8B85103E3BE7BA613B31BB5C9C36214DC9F14A42FD7A2FDB84856BCA5C44C2",
		"7B6AD79B346FB6951275343948E13C1B4EBCA82A5452A6C5D15684377F096CA927506A23A847E6E046061399631B16FC2820C8B0E02D0EA87AA5A203A77C2A7E",
		"8706E52A28544B2519338B0C345B67E9C2BF66F262B803348A65AD393FE481287C5B8F6030EF952F9F7633FB04D36896D41779C161E213AD46D92DB3DF651DCB",
		"5D0F6F817E99798F7DCD15617A3D027750A1AC2F448271CC6FD76DDBE73CE2042311BF2CE0E223357E3D6F1CA795B0E0D5217AA3C7D07F8900E0636B35CF77DE"
	};

	tinyToolkit::hash::SHA512 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(src[i].c_str());

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA512, UChar)
{
	std::vector<std::string> src{ "123", "abc", ";'.", "#$%" };
	std::vector<std::string> dst
	{
		"3C9909AFEC25354D551DAE21590BB26E38D53F2173B8D3DC3EEE4C047E7AB1C1EB8B85103E3BE7BA613B31BB5C9C36214DC9F14A42FD7A2FDB84856BCA5C44C2",
		"7B6AD79B346FB6951275343948E13C1B4EBCA82A5452A6C5D15684377F096CA927506A23A847E6E046061399631B16FC2820C8B0E02D0EA87AA5A203A77C2A7E",
		"8706E52A28544B2519338B0C345B67E9C2BF66F262B803348A65AD393FE481287C5B8F6030EF952F9F7633FB04D36896D41779C161E213AD46D92DB3DF651DCB",
		"5D0F6F817E99798F7DCD15617A3D027750A1AC2F448271CC6FD76DDBE73CE2042311BF2CE0E223357E3D6F1CA795B0E0D5217AA3C7D07F8900E0636B35CF77DE"
	};

	tinyToolkit::hash::SHA512 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(reinterpret_cast<const uint8_t *>(src[i].c_str()));

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA512, String)
{
	std::vector<std::string> src{ "123", "abc", ";'.", "#$%" };
	std::vector<std::string> dst
	{
		"3C9909AFEC25354D551DAE21590BB26E38D53F2173B8D3DC3EEE4C047E7AB1C1EB8B85103E3BE7BA613B31BB5C9C36214DC9F14A42FD7A2FDB84856BCA5C44C2",
		"7B6AD79B346FB6951275343948E13C1B4EBCA82A5452A6C5D15684377F096CA927506A23A847E6E046061399631B16FC2820C8B0E02D0EA87AA5A203A77C2A7E",
		"8706E52A28544B2519338B0C345B67E9C2BF66F262B803348A65AD393FE481287C5B8F6030EF952F9F7633FB04D36896D41779C161E213AD46D92DB3DF651DCB",
		"5D0F6F817E99798F7DCD15617A3D027750A1AC2F448271CC6FD76DDBE73CE2042311BF2CE0E223357E3D6F1CA795B0E0D5217AA3C7D07F8900E0636B35CF77DE"
	};

	tinyToolkit::hash::SHA512 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(src[i]);

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA512, Char_Length)
{
	std::vector<std::string> src{ "123456", "abcdef", ";'.,/]", "#$%^&*" };
	std::vector<std::string> dst
	{
		"3C9909AFEC25354D551DAE21590BB26E38D53F2173B8D3DC3EEE4C047E7AB1C1EB8B85103E3BE7BA613B31BB5C9C36214DC9F14A42FD7A2FDB84856BCA5C44C2",
		"7B6AD79B346FB6951275343948E13C1B4EBCA82A5452A6C5D15684377F096CA927506A23A847E6E046061399631B16FC2820C8B0E02D0EA87AA5A203A77C2A7E",
		"8706E52A28544B2519338B0C345B67E9C2BF66F262B803348A65AD393FE481287C5B8F6030EF952F9F7633FB04D36896D41779C161E213AD46D92DB3DF651DCB",
		"5D0F6F817E99798F7DCD15617A3D027750A1AC2F448271CC6FD76DDBE73CE2042311BF2CE0E223357E3D6F1CA795B0E0D5217AA3C7D07F8900E0636B35CF77DE"
	};

	tinyToolkit::hash::SHA512 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(src[i].c_str(), 3);

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA512, UChar_Length)
{
	std::vector<std::string> src{ "123456", "abcdef", ";'.,/]", "#$%^&*" };
	std::vector<std::string> dst
	{
		"3C9909AFEC25354D551DAE21590BB26E38D53F2173B8D3DC3EEE4C047E7AB1C1EB8B85103E3BE7BA613B31BB5C9C36214DC9F14A42FD7A2FDB84856BCA5C44C2",
		"7B6AD79B346FB6951275343948E13C1B4EBCA82A5452A6C5D15684377F096CA927506A23A847E6E046061399631B16FC2820C8B0E02D0EA87AA5A203A77C2A7E",
		"8706E52A28544B2519338B0C345B67E9C2BF66F262B803348A65AD393FE481287C5B8F6030EF952F9F7633FB04D36896D41779C161E213AD46D92DB3DF651DCB",
		"5D0F6F817E99798F7DCD15617A3D027750A1AC2F448271CC6FD76DDBE73CE2042311BF2CE0E223357E3D6F1CA795B0E0D5217AA3C7D07F8900E0636B35CF77DE"
	};

	tinyToolkit::hash::SHA512 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(reinterpret_cast<const uint8_t *>(src[i].c_str()), 3);

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}


TOOLKIT_TEST_CASE(SHA512, String_Length)
{
	std::vector<std::string> src{ "123456", "abcdef", ";'.,/]", "#$%^&*" };
	std::vector<std::string> dst
	{
		"3C9909AFEC25354D551DAE21590BB26E38D53F2173B8D3DC3EEE4C047E7AB1C1EB8B85103E3BE7BA613B31BB5C9C36214DC9F14A42FD7A2FDB84856BCA5C44C2",
		"7B6AD79B346FB6951275343948E13C1B4EBCA82A5452A6C5D15684377F096CA927506A23A847E6E046061399631B16FC2820C8B0E02D0EA87AA5A203A77C2A7E",
		"8706E52A28544B2519338B0C345B67E9C2BF66F262B803348A65AD393FE481287C5B8F6030EF952F9F7633FB04D36896D41779C161E213AD46D92DB3DF651DCB",
		"5D0F6F817E99798F7DCD15617A3D027750A1AC2F448271CC6FD76DDBE73CE2042311BF2CE0E223357E3D6F1CA795B0E0D5217AA3C7D07F8900E0636B35CF77DE"
	};

	tinyToolkit::hash::SHA512 handle{ };

	for (std::size_t i = 0; i < 4; ++i)
	{
		handle.Append(src[i], 3);

		TOOLKIT_EXPECT_STR_EQ(handle.Result(), dst[i]);
	}
}
