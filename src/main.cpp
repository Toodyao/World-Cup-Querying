#include <iostream>
#include <rapidjson/filereadstream.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "structures.h"
#include "heap.hpp"
#include "my_time.h"
using namespace std;
using namespace rapidjson;

void test(string s) {
	cout << s << endl;
}

#define DEBUG_READ_DATA_OUTPUT

int main() {
	string json_path = "../../data/output-line.json";
	ifstream json_file(json_path);

	string json;
	getline(json_file, json);

//	Match m;
//	m.read(json);
//	cout << m.home_events.size() << endl;
	Matches m;
	m.read(json);


//	string s("2018-06-14T15:00:00Z");
////	test(s);
//	MyTime t(s);
//	cout << t.get_string() << endl;
//	cout << t.seconds() << endl;
	return 0;
}