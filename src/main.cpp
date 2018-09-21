#include <iostream>
#include "structures.h"
#include "Heap.hpp"
#include "my_time.h"
#include <rapidjson/filereadstream.h>
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;
using namespace rapidjson;

typedef vector<Match> Matches;

void test(string s) {
	cout << s << endl;
}

void read_match(Matches m, string json) {
	Document d;
	d.Parse(json.c_str());
	cout << d.GetType() << endl;
	assert(d.IsArray());
	for (auto& i : d.GetArray()) {
		Match temp;
		temp.read(i);
		m.push_back(temp);
	}
}

#define DEBUG_READ_DATA_OUTPUT

int main() {
	freopen("../../data/output-line.json", "r", stdin);
	string json;
	getline(cin, json);

//	Match m;
//	m.read(json);
//	cout << m.home_events.size() << endl;

	Matches m;
	read_match(m, json);


//	string s("2018-06-14T15:00:00Z");
////	test(s);
//	MyTime t(s);
//	cout << t.get_string() << endl;
//	cout << t.seconds() << endl;
	return 0;
}