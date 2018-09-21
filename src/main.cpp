#include <iostream>
#include "structures.h"
#include "Heap.hpp"
#include <rapidjson/filereadstream.h>
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;
using namespace rapidjson;

int main() {

	freopen("../../data/test_data", "r", stdin);
	string json;
	getline(cin, json);

	Match m;
	m.read(json);


	return 0;
}