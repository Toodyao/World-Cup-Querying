#include "gtest/gtest.h"
#include "rapidjson/document.h"

TEST(test, successed_test) {
	EXPECT_EQ(1, 1);
}

TEST(test, failed_test) {
	EXPECT_EQ(1, 1);
}

TEST(test, json_read_test) {
	using namespace rapidjson;
	Document d;
	d.Parse("{}");
}

GTEST_API_ int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}