/**
 *
 *  作者: hm
 *
 *  说明: 描述信息
 *
 */


#include "description.h"


TOOLKIT_TEST_CASE(Description, DefaultEmpty)
{
	tinyToolkit::options::Description description("fuck", "f", "fuck description", tinyToolkit::options::Value<std::string>());

	TOOLKIT_EXPECT_TRUE(description.Value() != nullptr);
	TOOLKIT_EXPECT_TRUE(description.Value()->Type() == tinyToolkit::options::VALUE_TYPE::STRING);
	TOOLKIT_EXPECT_FALSE(description.Value()->HasValue());
	TOOLKIT_EXPECT_FALSE(description.Value()->HasDefault());
	TOOLKIT_EXPECT_FALSE(description.IsValid());
	TOOLKIT_EXPECT_TRUE(description.IsRequired());

	TOOLKIT_EXPECT_STR_EQ(description.Value()->Default(), "");
	TOOLKIT_EXPECT_STR_EQ(description.Info(), "fuck description");
	TOOLKIT_EXPECT_STR_EQ(description.LongName(), "fuck");
	TOOLKIT_EXPECT_STR_EQ(description.ShortName(), "f");
	TOOLKIT_EXPECT_STR_EQ(description.OptionName(), "-f, --fuck");

	description.Update();

	TOOLKIT_EXPECT_TRUE(description.Value() != nullptr);
	TOOLKIT_EXPECT_TRUE(description.Value()->Type() == tinyToolkit::options::VALUE_TYPE::STRING);
	TOOLKIT_EXPECT_FALSE(description.Value()->HasValue());
	TOOLKIT_EXPECT_FALSE(description.Value()->HasDefault());
	TOOLKIT_EXPECT_TRUE(description.IsValid());
	TOOLKIT_EXPECT_TRUE(description.IsRequired());

	TOOLKIT_EXPECT_STR_EQ(description.Value()->Default(), "");
	TOOLKIT_EXPECT_STR_EQ(description.Info(), "fuck description");
	TOOLKIT_EXPECT_STR_EQ(description.LongName(), "fuck");
	TOOLKIT_EXPECT_STR_EQ(description.ShortName(), "f");
	TOOLKIT_EXPECT_STR_EQ(description.OptionName(), "-f, --fuck");

	description.Update("123");

	TOOLKIT_EXPECT_TRUE(description.Value() != nullptr);
	TOOLKIT_EXPECT_TRUE(description.Value()->Type() == tinyToolkit::options::VALUE_TYPE::STRING);
	TOOLKIT_EXPECT_TRUE(description.Value()->HasValue());
	TOOLKIT_EXPECT_FALSE(description.Value()->HasDefault());
	TOOLKIT_EXPECT_TRUE(description.IsValid());
	TOOLKIT_EXPECT_TRUE(description.IsRequired());

	TOOLKIT_EXPECT_STR_EQ(description.Value()->Default(), "");
	TOOLKIT_EXPECT_STR_EQ(description.Info(), "fuck description");
	TOOLKIT_EXPECT_STR_EQ(description.LongName(), "fuck");
	TOOLKIT_EXPECT_STR_EQ(description.ShortName(), "f");
	TOOLKIT_EXPECT_STR_EQ(description.OptionName(), "-f, --fuck");
}


TOOLKIT_TEST_CASE(Description, DefaultDefine)
{
	tinyToolkit::options::Description description("fuck", "f", "fuck description", tinyToolkit::options::Value<std::string>("666"));

	TOOLKIT_EXPECT_TRUE(description.Value() != nullptr);
	TOOLKIT_EXPECT_TRUE(description.Value()->Type() == tinyToolkit::options::VALUE_TYPE::STRING);
	TOOLKIT_EXPECT_TRUE(description.Value()->HasValue());
	TOOLKIT_EXPECT_TRUE(description.Value()->HasDefault());
	TOOLKIT_EXPECT_TRUE(description.IsValid());
	TOOLKIT_EXPECT_TRUE(description.IsRequired());

	TOOLKIT_EXPECT_STR_EQ(description.Value()->Default(), "666");
	TOOLKIT_EXPECT_STR_EQ(description.Info(), "fuck description");
	TOOLKIT_EXPECT_STR_EQ(description.LongName(), "fuck");
	TOOLKIT_EXPECT_STR_EQ(description.ShortName(), "f");
	TOOLKIT_EXPECT_STR_EQ(description.OptionName(), "-f, --fuck");

	description.Update();

	TOOLKIT_EXPECT_TRUE(description.Value() != nullptr);
	TOOLKIT_EXPECT_TRUE(description.Value()->Type() == tinyToolkit::options::VALUE_TYPE::STRING);
	TOOLKIT_EXPECT_TRUE(description.Value()->HasValue());
	TOOLKIT_EXPECT_TRUE(description.Value()->HasDefault());
	TOOLKIT_EXPECT_TRUE(description.IsValid());
	TOOLKIT_EXPECT_TRUE(description.IsRequired());

	TOOLKIT_EXPECT_STR_EQ(description.Value()->Default(), "666");
	TOOLKIT_EXPECT_STR_EQ(description.Info(), "fuck description");
	TOOLKIT_EXPECT_STR_EQ(description.LongName(), "fuck");
	TOOLKIT_EXPECT_STR_EQ(description.ShortName(), "f");
	TOOLKIT_EXPECT_STR_EQ(description.OptionName(), "-f, --fuck");

	description.Update("123");

	TOOLKIT_EXPECT_TRUE(description.Value() != nullptr);
	TOOLKIT_EXPECT_TRUE(description.Value()->Type() == tinyToolkit::options::VALUE_TYPE::STRING);
	TOOLKIT_EXPECT_TRUE(description.Value()->HasValue());
	TOOLKIT_EXPECT_TRUE(description.Value()->HasDefault());
	TOOLKIT_EXPECT_TRUE(description.IsValid());
	TOOLKIT_EXPECT_TRUE(description.IsRequired());

	TOOLKIT_EXPECT_STR_EQ(description.Value()->Default(), "666");
	TOOLKIT_EXPECT_STR_EQ(description.Info(), "fuck description");
	TOOLKIT_EXPECT_STR_EQ(description.LongName(), "fuck");
	TOOLKIT_EXPECT_STR_EQ(description.ShortName(), "f");
	TOOLKIT_EXPECT_STR_EQ(description.OptionName(), "-f, --fuck");
}


TOOLKIT_TEST_CASE(Description, NotDefault)
{
	tinyToolkit::options::Description description("test", "t", "test description");

	TOOLKIT_EXPECT_TRUE(description.Value() == nullptr);
	TOOLKIT_EXPECT_FALSE(description.IsValid());
	TOOLKIT_EXPECT_FALSE(description.IsRequired());

	TOOLKIT_EXPECT_STR_EQ(description.Info(), "test description");
	TOOLKIT_EXPECT_STR_EQ(description.LongName(), "test");
	TOOLKIT_EXPECT_STR_EQ(description.ShortName(), "t");
	TOOLKIT_EXPECT_STR_EQ(description.OptionName(), "-t, --test");

	try
	{
		description.Update("123");

		TOOLKIT_EXPECT_TRUE(false);
		TOOLKIT_EXPECT_FALSE(true);
	}
	catch (...)
	{
		TOOLKIT_EXPECT_TRUE(description.Value() == nullptr);
		TOOLKIT_EXPECT_FALSE(description.IsValid());
		TOOLKIT_EXPECT_FALSE(description.IsRequired());

		TOOLKIT_EXPECT_STR_EQ(description.Info(), "test description");
		TOOLKIT_EXPECT_STR_EQ(description.LongName(), "test");
		TOOLKIT_EXPECT_STR_EQ(description.ShortName(), "t");
		TOOLKIT_EXPECT_STR_EQ(description.OptionName(), "-t, --test");
	}

	description.Update();

	TOOLKIT_EXPECT_TRUE(description.Value() == nullptr);
	TOOLKIT_EXPECT_TRUE(description.IsValid());
	TOOLKIT_EXPECT_FALSE(description.IsRequired());

	TOOLKIT_EXPECT_STR_EQ(description.Info(), "test description");
	TOOLKIT_EXPECT_STR_EQ(description.LongName(), "test");
	TOOLKIT_EXPECT_STR_EQ(description.ShortName(), "t");
	TOOLKIT_EXPECT_STR_EQ(description.OptionName(), "-t, --test");
}
