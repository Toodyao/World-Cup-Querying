#include "structures.h"

void Match::read(const std::string& json) {
	rapidjson::Document d;
	d.Parse(json.c_str());

//	d.HasMember("home_team");
	home_team.read(d["home_team"]);
	away_team.read(d["away_team"]);
	winner = d["winner"].GetString();
	time.set_time(d["datetime"].GetString());

#ifdef DEBUG_READ_DATA_OUTPUT
	cout << winner << endl;
	cout << time.get_string() << endl;
#endif

	read_events(home_events, d["home_team_events"]);
	read_events(away_events, d["away_team_events"]);

	clean_events(home_events);
	clean_events(away_events);

	valid = true;
}

void Match::read(const rapidjson::Value& d) {
	home_team.read(d["home_team"]);
	away_team.read(d["away_team"]);
	winner = d["winner"].GetString();
	time.set_time(d["datetime"].GetString());

#ifdef DEBUG_READ_DATA_OUTPUT
	cout << winner << endl;
	cout << time.get_string() << endl;
#endif
	read_events(home_events, d["home_team_events"]);
	read_events(away_events, d["away_team_events"]);

	clean_events(home_events);
	clean_events(away_events);

	valid = true;
}

void Match::read_events(vector<TeamEvent>& events, const rapidjson::Value& v) {
	for (auto& i : v.GetArray()) {
		TeamEvent temp;
		temp.read(i);
		events.push_back(temp);
	}
}

void Match::clean_events(vector<TeamEvent>& events) { // TODO: Need test and need refactor(extract)
	vector<TeamEvent>::iterator a, b; // a: front, b: back
	a = events.begin();
	b = events.begin(); ++b;
	while (b != events.end()) {
		if (((*a).type == "goal" || (*a).type == "goal-penalty") && ((*a).type == (*b).type) && ((*a).player == (*b).player) && ((*b).time - (*a).time) < 4) {
			auto tmp = a;
			events.erase(tmp);
			if (b == events.end()) {
				break;
			}
			a++; b++;
		} else {
			a++; b++;
		}
	}
}