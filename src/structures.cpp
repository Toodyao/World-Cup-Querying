#include "structures.h"
using namespace rapidjson;

#include <iostream> // test used
using std::cout;
using std::endl;

//#define DEBUG_READ_DATA_OUTPUT

void TeamEvent::read(const Value& v) {
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

void Team::read(const Value& v) {
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

void Match::read(const std::string& json) {
	Document d;
	d.Parse(json.c_str());

//	d.HasMember("home_team");
	home_team.read(d["home_team"]);
	away_team.read(d["away_team"]);
	winner = d["winner"].GetString();
	time.set_time(d["datetime"].GetString());

#ifdef DEBUG_READ_DATA_OUTPUT
	cout << winner << endl;
	cout << time << endl;
#endif

	read_events(home_events, d["home_team_events"]);
	read_events(away_events, d["away_team_events"]);

}

void Match::read(const rapidjson::Value& d) {
	home_team.read(d["home_team"]);
	away_team.read(d["away_team"]);
	winner = d["winner"].GetString();
	time.set_time(d["datetime"].GetString());

#ifdef DEBUG_READ_DATA_OUTPUT
	cout << winner << endl;
	cout << time << endl;
#endif
	read_events(home_events, d["home_team_events"]);
	read_events(away_events, d["away_team_events"]);
}

void Match::read_events(vector<TeamEvent>& events, const rapidjson::Value& v) {
	for (auto& i : v.GetArray()) {
		TeamEvent temp;
		temp.read(i);
		events.push_back(temp);
	}
}

void Matches::read(const string& json) {
	rapidjson::Document d;
	d.Parse(json.c_str());
	cout << d.GetType() << endl;
	assert(d.IsArray());
	for (auto& i : d.GetArray()) {
		Match temp;
		temp.read(i);
		v.push_back(temp);
	}
}

size_t Matches::size() {
	return v.size();
}

Match& Matches::operator[](int i) {
	return v[i];
}

Player::Player() {
	name = "";
	country = "";
	goal = 0;
	substitution_in = 0;
	substitution_out = 0;
	yellow_card = 0;
	red_card = 0;
	goal_penalty = 0;
	goal_own = 0;
}
