#include <gtest/gtest.h>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <iostream>
#include <fstream>
#include <string>
#include "structures.h"
using namespace std;

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

TEST(tool_test, json_read_data_old_way) {
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
	EXPECT_EQ(m.time.get_string(), "2018-06-14T15:00:00Z");
	EXPECT_EQ(m.time.seconds(), 0);

	FILE* fp = fopen("../../data/output.json", "r");
	Matches mm;
	mm.read(fp);
	EXPECT_EQ(mm.size(), 64);
}

TEST(tool_test, json_read_all) {
	using namespace rapidjson;
	using std::string;
	FILE* fp = fopen("../../data/output.json", "r");
	Matches m;
	m.read(fp);
	EXPECT_EQ(m.size(), 64);
}