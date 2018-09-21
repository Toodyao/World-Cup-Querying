#include <gtest/gtest.h>
#include <string>
#include "my_time.h"
#include "rapidjson/document.h"
#include "structures.h"
using namespace std;

TEST(tool_test, time_test) {
	string s("2018-06-14T15:00:00Z");
	MyTime t(s);
	EXPECT_EQ("Thu Jun 14 15:00:00 2018\n", t.get_string());
	EXPECT_EQ(0, t.seconds());

	string s2("2018-06-14T15:00:01Z");
	MyTime t2(s2);
	EXPECT_EQ("Thu Jun 14 15:00:01 2018\n", t2.get_string());
	EXPECT_EQ(1, t2.seconds());

	string s3("2018-06-14T16:00:00Z");
	MyTime t3(s3);
	EXPECT_EQ("Thu Jun 14 16:00:00 2018\n", t3.get_string());
	EXPECT_EQ(60*60, t3.seconds());
}

TEST(tool_test, json_read_test) {
	using namespace rapidjson;
	Document d;
	d.Parse("{}");
}

TEST(tool_test, json_read_data) {
	using namespace rapidjson;
	using std::string;
	freopen("../../data/test_data", "r", stdin);

	string json;
	getline(cin, json);

	Document d;
	d.Parse(json.c_str());

	Match m;
	m.read(json);
	EXPECT_EQ(m.home_team.country, "Russia");
	EXPECT_EQ(m.away_team.country, "Saudi Arabia");
	EXPECT_EQ(m.home_events.at(1).type, "substitution-in");
	EXPECT_EQ(m.away_events.at(1).type, "substitution-out");
	EXPECT_EQ((int)m.home_events.size(), 12);
	EXPECT_EQ((int)m.away_events.size(), 8);
	EXPECT_EQ(m.winner, "Russia");
	EXPECT_EQ(m.time, "2018-06-14T15:00:00Z");
}
