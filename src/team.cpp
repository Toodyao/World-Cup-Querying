#include "structures.h"

void Team::read(const rapidjson::Value& v) {
	country   = v["country"].GetString();
	code      = v["code"].GetString();
	goals     = v["goals"].GetInt();
	penalties = v["penalties"].GetInt();

#ifdef DEBUG_READ_DATA_OUTPUT
	//	cout << "{" << endl;
	cout << country << endl;
	cout << code << endl;
	cout << goals << endl;
	cout << penalties << endl;
//	cout << "}" << endl;
#endif
}