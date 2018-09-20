#include <iostream>
#include "structures.h"
#include <rapidjson/filereadstream.h>
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;
using namespace rapidjson;

int main() {

	freopen("../../data/test_data", "r", stdin);
	Match m;
	string json;
	getline(cin, json);
	m.read(json);
//	m.read(R"({"winner":"success", "home_team":{"country":"Russia"} })");
	return 0;
}