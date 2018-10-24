#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "structures.h"
#include "timeline.h"
using namespace std;

TEST(tool_test, Matches_oprator) {
	using namespace rapidjson;
	using std::string;
	FILE* fp = fopen("../../data/output.json", "r");
	Matches m;
	m.read(fp);

	EXPECT_EQ(m[63].winner, "France");
}

TEST(tool_test, Player_oprator) {
	Player a, b;
	a.goal = 3;
	b.goal = 2;
	EXPECT_EQ(a > b, true);
	EXPECT_EQ(a < b, false);
	a.name = "a";
	b.name = "b";
	EXPECT_EQ(a == b, false);
	a.name = "b";
	EXPECT_EQ(a == b, true);
}

TEST(tool_test, Match_valid_test) {
	Match m;
	EXPECT_EQ(m.valid, false);

	string json_path = "../../data/test_data";
	ifstream json_file(json_path);
	string json;
	getline(json_file, json);

	Match m2;
	m2.read(json);
	EXPECT_EQ(m2.valid, true);
	m = m2;
	EXPECT_EQ(m.valid, true);
}

TEST(tool_test, get_match_index_test) {
	FILE* fp = fopen("../../data/output.json", "r");
	Matches m;
	m.read(fp);

	Timeline timeline;
	Match match;
	int index;

	timeline.set_curr("2018-06-14T22:00:00Z");
	index = m.get_current_match_info(timeline);
	EXPECT_EQ(index, -1);

	timeline.set_curr("2018-06-14T16:00:00Z");
	index = m.get_current_match_info(timeline);
	EXPECT_EQ(index, 0);

	timeline.set_curr("2018-07-15T15:01:00Z");
	index = m.get_current_match_info(timeline);
	EXPECT_EQ(index, 63);

	timeline.set_curr("2018-06-14T22:00:00Z");
	index = m.get_match_index_till(timeline);
	EXPECT_EQ(index, 0);
}

TEST(tool_test, team_hash_table_test) {
	Teams t;
	ASSERT_EQ(t.find("RUS").country, "Russia");
	ASSERT_EQ(t.find("JPN").country, "Japan");

	ASSERT_EQ(t.find("RUS").code, "RUS");
	ASSERT_EQ(t.find("JPN").code, "JPN");
}