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

void test(string s) {
	cout << s << endl;
}

int main() {
//	freopen("../../data/test_data", "r", stdin);
//	string json;
//	getline(cin, json);
//
//	Match m;
//	m.read(json);
	string s("2018-06-14T15:00:00Z");
//	test(s);
	MyTime t(s);
	cout << t.get_string() << endl;
	cout << t.seconds() << endl;
	return 0;
}