#include <gtest/gtest.h>
#include "my_time.h"
#include <string>
using namespace std;

TEST(tool_test, time_test) {
	string s("2018-06-14T15:00:00Z");
	MyTime t(s);
	cout << t.get_string();
	EXPECT_EQ("Thu Jun 14 15:00:00 2018\n", t.get_string());
	EXPECT_EQ(0, t.seconds());
}
