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
	time.set_time_init(d["datetime"].GetString());

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
		if (((*a).type == "goal" || (*a).type == "goal-penalty" || (*a).type == "goal-own")
			&& ((*a).type == (*b).type) && ((*a).player == (*b).player) && ((*b).time - (*a).time) < 4) {
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

void Match::count_goal_own() {
	for (auto& i : home_events) {

	}
}

vector<TeamEvent> Match::get_curr_event(int home_or_away, Timeline timeline) {
	int begin_time = this->time.seconds();
	int curr_time = timeline.curr();
	double time_diff = (curr_time - begin_time) / 60.0; // Convert to minutes.
	//assert(time_diff >= 0); // Match not start.

	vector<TeamEvent> v;
	vector<TeamEvent> ret;
	if (home_or_away == 0)
		v = home_events;
	else
		v = away_events;

	for (auto& i : v) {
		if (i.time <= time_diff) {
			ret.push_back(i);
		}
	}
	return ret;
}

vector<TeamEvent> Match::get_curr_event_union(Timeline timeline) {
	auto home = get_curr_event(0, timeline);
	auto away = get_curr_event(1, timeline);
	vector<TeamEvent> ret;

	for (auto& i : home) {
		i.id += 10000; // id > 10000 means home team.
	}

	ret.reserve(home.size()+away.size());
	ret.insert(ret.end(), home.begin(), home.end());
	ret.insert(ret.end(), away.begin(), away.end());

	std::stable_sort(ret.begin(), ret.end());

	//int n = (int)std::max(home.size(), away.size());
	////int i = (int)home.size(), j = (int)away.size();
	//int i = 0, j = 0;
	//while (i < (int)home.size() && j < (int)away.size()) {
	//	if (home[i].time <= away[j].time && i < (int)home.size()) {
	//		ret.push_back(home[i]);
	//		i++;
	//	} else if (j < (int)away.size()){
	//		ret.push_back(away[j]);
	//		j++;
	//	}
	//	//if (i < (int)home.size()) {
	//	//	i++;
	//	//}
	//	//if (j < (int)away.size()) {
	//	//	j++;
	//	//}
	//}

	return ret;
}
