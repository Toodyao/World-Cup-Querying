#include "structures.h"

void TeamEvent::read(const rapidjson::Value& v) {
	id     = v["id"].GetInt();
	type   = v["type_of_event"].GetString();
	player = v["player"].GetString();
	time   = parse_time(v["time"].GetString());

#ifdef DEBUG_READ_DATA_OUTPUT
	cout << "{" << endl;
	cout << id << endl;
	cout << type << endl;
	cout << player << endl;
	cout << time << endl;
	cout << "}" << endl;
#endif
}

int TeamEvent::parse_time(string s) {
	int time = 0;
	if (s.size() <= 4 && s[s.size()-1] == '\'') { // If time <= 90
		s.erase(s.size()-1);
		time = std::stoi(s);
	} else {
		time = 90;
		time += std::stoi(s.substr(4, 1));
	}
	return time;
}