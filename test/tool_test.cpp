#include <gtest/gtest.h>
#include <string>
#include <fstream>
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

	t3.set_time("2018-06-14T15:00:01Z");
	EXPECT_EQ("Thu Jun 14 15:00:01 2018\n", t3.get_string());
	EXPECT_EQ(1, t3.seconds());
}

TEST(tool_test, json_parse_test) {
	using namespace rapidjson;
	Document d;
	d.Parse("{}");
}

TEST(tool_test, read_file_test) {
	string json_path = "../../data/test_data";

	ifstream json_file(json_path);

	string json;
	getline(json_file, json);
	EXPECT_EQ(json.size(), 2172);
}

TEST(tool_test, json_read_data) {
	using namespace rapidjson;
	using std::string;
	string json_path = "../../data/test_data";
	ifstream json_file(json_path);

	string json;
	getline(json_file, json);

	Document d;
	d.Parse(json.c_str());

	Match m;
	m.read(json);
	EXPECT_EQ(m.home_team.country, "Russia");
	EXPECT_EQ(m.away_team.country, "Saudi Arabia");
	EXPECT_EQ(m.home_events.at(1).type, "substitution-in");
	EXPECT_EQ(m.away_events.at(1).type, "substitution-out");
	EXPECT_EQ(m.home_events.at(1).time, 24);
	EXPECT_EQ(m.away_events.at(1).time, 64);
	EXPECT_EQ((int)m.home_events.size(), 12);
	EXPECT_EQ((int)m.away_events.size(), 8);
	EXPECT_EQ(m.winner, "Russia");
//	EXPECT_EQ(m.time, "2018-06-14T15:00:00Z");
	EXPECT_EQ(m.time.get_string(), "Thu Jun 14 15:00:00 2018\n");
	EXPECT_EQ(m.time.seconds(), 0);
}

TEST(tool_test, json_read_all) {
	using namespace rapidjson;
	using std::string;
	string json_path = "../../data/output-line.json";
	ifstream json_file(json_path);

	string json;
	getline(json_file, json);

	Document d;
	d.Parse(json.c_str());

	Matches m;
	m.read(json);

	EXPECT_EQ(m.size(), 64);
}

TEST(tool_test, Matches_oprator) {
	using namespace rapidjson;
	using std::string;
	string json_path = "../../data/output-line.json";
	ifstream json_file(json_path);

	string json;
	getline(json_file, json);

	Document d;
	d.Parse(json.c_str());

	Matches m;
	m.read(json);

	EXPECT_EQ(m[63].winner, "France");
}


TEST(tool_test, Player_oprator) {
	Player a, b;
	a.goal = 3;
	b.goal = 2;
	EXPECT_EQ(a > b, true);
	EXPECT_EQ(a < b, false);
	EXPECT_EQ(a == b, false);
	a.goal = 2;
	EXPECT_EQ(a == b, true);
}