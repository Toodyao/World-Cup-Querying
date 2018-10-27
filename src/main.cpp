#include <iostream>
#include <rapidjson/filereadstream.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <set>
#include <unordered_map>
#include "structures.h"
#include "my_time.h"
#include "heap.hpp"
#include "timeline.h"
#include "demo.h"
#include "hash.hpp"

using namespace std;
using namespace rapidjson;

#define DEBUG_READ_DATA_OUTPUT


int main() {

	demo d;
	d.init();
	d.set_time("2018-06-14T15:13:00Z");
	d.set_time("2018-06-19T18:13:00Z");
	d.update();
	d.set_time("2018-06-20T18:13:00Z");
	d.update();
	d.set_time("2018-06-21T18:13:00Z");
	d.update();
	d.set_time("2018-08-07T15:00:00Z");
	d.update();

	int index = d.matches.get_match_index_till(d.timeline);
	auto v = d.matches[index];

	return 0;
}

