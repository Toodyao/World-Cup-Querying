#include "gtest/gtest.h"
#include "rapidjson.h"

TEST(test, successed_test) {
	EXPECT_EQ(1, 1);
}

TEST(test, failed_test) {
	EXPECT_EQ(1, 1);
}

GTEST_API_ int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}