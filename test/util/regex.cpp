/**
 *
 *  作者: hm
 *
 *  说明: 正则处理
 *
 */


#include "regex.h"


TOOLKIT_TEST_CASE(Regex, Match)
{
	std::regex rule(R"(^((https|http|ftp|rtsp|mms)?:\/\/)[^\s]+)");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::Match("ftp://192.168.2.1", rule));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::Match("rtsp://192.168.2.1/h264_3", rule));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::Match("https://www.baidu.com", rule));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::Match("thunder://abc123", rule));
}


TOOLKIT_TEST_CASE(Regex, IsIP)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIP("192.168.2.0"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIP("192.168.2.255"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIP("192.168.2.256"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIP("2001::1319:8a2h:37"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIP("f1ec:a63b:1db9::828"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIP("fe80::8c3d:dee5:19b:22b7%4"));
}


TOOLKIT_TEST_CASE(Regex, IsMAC)
{
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsMAC("aa:bb:cc:dd:ee"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsMAC("aa-bb-cc-dd-ee"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsMAC("aa:bb:cc:dd:ee:"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsMAC("aa-bb-cc-dd-ee-"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsMAC("aa:bb:cc:dd:ee:ff"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsMAC("aa-bb-cc-dd-ee-ff"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsMAC("aa:bb:cc:dd:ee:ff:"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsMAC("aa-bb-cc-dd-ee-ff-"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsMAC("aa:bb:cc:dd:ee:ff:gg"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsMAC("aa-bb-cc-dd-ee-ff-gg"));
}


TOOLKIT_TEST_CASE(Regex, IsIPv4)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIPv4("192.168.2.0"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIPv4("192.168.2.255"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIPv4("255.168.2.1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIPv4("192.255.2.1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIPv4("192.168.255.1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIPv4("192.168.2.255"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv4("256.168.2.1"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv4("192.256.2.1"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv4("192.168.256.1"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv4("192.168.2.256"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv4("2001::1319:8a2h:37"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv4("f1ec:a63b:1db9::828"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv4("fe80::8c3d:dee5:19b:22b7%4"));
}


TOOLKIT_TEST_CASE(Regex, IsIPv6)
{
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv6("192.168.2.0"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv6("192.168.2.255"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv6("192.168.2.256"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsIPv6("2001::1319:8a2h:37"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIPv6("f1ec:a63b:1db9::828"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsIPv6("fe80::8c3d:dee5:19b:22b7%4"));
}


TOOLKIT_TEST_CASE(Regex, IsMail)
{
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsMail("abc@xyz"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsMail("abc@xyz.com"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsMail("abc@xyz.com.cn"));
}


TOOLKIT_TEST_CASE(Regex, IsDate)
{
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019-2-1"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019-2-01"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019-02-1"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019-2-2"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019-2-02"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019-02-2"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020-2-3"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020-2-03"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020-02-3"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020-2-4"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020-2-04"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020-02-4"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019-2-28"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019-2-29"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020-2-28"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020-2-29"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2019-02-01"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2019-02-02"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2020-02-03"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2020-02-04"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2019-02-28"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019-02-29"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2020-02-28"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2020-02-29"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019/2/28"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019/2/29"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020/2/28"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2020/2/29"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2019/02/28"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDate("2019/02/29"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2020/02/28"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDate("2020/02/29"));
}


TOOLKIT_TEST_CASE(Regex, IsTime)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsTime("00:00:00"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsTime("23:59:59"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsTime("23:59:60"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsTime("23:60:00"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsTime("24:00:00"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsTime("00:00:00.000"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsTime("23:59:59.000"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsTime("23:59:60.000"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsTime("23:60:00.000"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsTime("24:00:00.000"));
}


TOOLKIT_TEST_CASE(Regex, IsDateTime)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2019-02-28 00:00:00"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2019-02-28 23:59:59"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDateTime("2019-02-29 00:00:00"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDateTime("2019-02-29 23:59:59"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2020-02-28 00:00:00"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2020-02-28 23:59:59"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2020-02-29 00:00:00"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2020-02-29 23:59:59"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2019/02/28 00:00:00"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2019/02/28 23:59:59"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDateTime("2019/02/29 00:00:00"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Regex::IsDateTime("2019/02/29 23:59:59"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2020/02/28 00:00:00"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2020/02/28 23:59:59"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2020/02/29 00:00:00"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Regex::IsDateTime("2020/02/29 23:59:59"));
}
