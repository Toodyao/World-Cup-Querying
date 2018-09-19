#include "structures.h"
#include "rapidjson/document.h"
using namespace rapidjson;

#include <iostream> // test used

void Match::read(const std::string& json) {
	Document d;
	d.Parse(json.c_str());
	winner = d["winner"].GetString();
	std::cout << winner << std::endl;
}
