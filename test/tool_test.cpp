#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include "my_time.h"
#include "rapidjson/document.h"
#include "structures.h"
#include "heap.hpp"
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

TEST(tool_test, prase_time_test) {
	TeamEvent tv;
	EXPECT_EQ(tv.parse_time("1'"), 1);
	EXPECT_EQ(tv.parse_time("10'"), 10);
	EXPECT_EQ(tv.parse_time("90'"), 90);
	EXPECT_EQ(tv.parse_time("90'+7'"), 97);
	EXPECT_EQ(tv.parse_time("104'"), 104);
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

	FILE* fp = fopen("../../data/output.json", "r");
	Matches mm;
	mm.read(fp);
	EXPECT_EQ(mm.size(), 64);
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
	a.name = "a";
	b.name = "b";
	EXPECT_EQ(a == b, false);
	a.name = "b";
	EXPECT_EQ(a == b, true);
}

TEST(tool_test, heap_test) {
	srand(0);
	Heap<Player> h(new MyGreater<Player>);
	int n = 10;
	for (int i = 0; i < n; i++) {
		Player a;
		a.goal = rand() % 100;
		a.name = to_string(rand()%1000000);
		h.push(a);
	}
	Player a;
	a.goal = 5;
	h.push(a);
//	n = h.size();
//	for (int i = n - 1; i >= 0; i--) {
//		Player tmp = h.top();
//		EXPECT_EQ(i, tmp.goal);
//		h.pop();
//	}
	n = h.size();
	for (int i = n - 1; i >= 0; i--) {
		Player tmp = h.top();
		cout << tmp.goal << endl;
		h.pop();
	}
}