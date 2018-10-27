#include <gtest/gtest.h>
#include <string>
#include "my_time.h"
#include "structures.h"
using namespace std;

TEST(tool_test, time_test) {
	string s("2018-06-14T15:00:00Z");
	MyTime t(s);
	EXPECT_EQ("2018-06-14T15:00:00Z", t.get_string());
	EXPECT_EQ(0, t.seconds());

	string s2("2018-06-14T15:00:01Z");
	MyTime t2(s2);
	EXPECT_EQ("2018-06-14T15:00:01Z", t2.get_string());
	EXPECT_EQ(1, t2.seconds());

	string s3("2018-06-14T16:00:00Z");
	MyTime t3(s3);
	EXPECT_EQ("2018-06-14T16:00:00Z", t3.get_string());
	EXPECT_EQ(60*60, t3.seconds());

	t3.set_time("2018-06-14T15:00:01Z");
	EXPECT_EQ("2018-06-14T15:00:01Z", t3.get_string());
	EXPECT_EQ(1, t3.seconds());

	MyTime t4("2018-06-14T16:00:00Z");
	EXPECT_EQ("2018-06-14T16:00:00Z", t4.get_string());
}

TEST(tool_test, prase_time_test) {
	TeamEvent tv;
	EXPECT_EQ(tv.parse_time("1'"), 1);
	EXPECT_EQ(tv.parse_time("10'"), 10);
	EXPECT_EQ(tv.parse_time("90'"), 90);
	EXPECT_EQ(tv.parse_time("90'+7'"), 97);
	EXPECT_EQ(tv.parse_time("104'"), 104);
}

TEST(tool_test, timeline_test) {
	Timeline t;
	string time_test = "2018-06-14T15:00:00Z";
	t.set_curr(time_test);
	EXPECT_EQ(t.curr(), 0);
	time_test = "2018-06-14T16:00:00Z";
	t.set_curr(time_test);
	EXPECT_EQ(t.curr(), 60*60);
	EXPECT_EQ(t.prev(), 0);
}
