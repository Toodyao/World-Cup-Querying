#include "structures.h"

void Matches::read(const string& json) {
	rapidjson::Document d;
	d.Parse(json.c_str());
//	cout << d.GetType() << endl;
	assert(d.IsArray());
	int debug_count = 0;
	for (auto& i : d.GetArray()) {
		Match temp;
		temp.read(i);
		v.push_back(temp);
		debug_count++;
	}
}

void Matches::read(FILE* fp) {
	char readBuffer[65536];
	rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	rapidjson::Document d;
	d.ParseStream(is);
	fclose(fp);

	assert(d.IsArray());
	int debug_count = 0;
	for (auto& i : d.GetArray()) {
		Match temp;
		temp.read(i);
		v.push_back(temp);
		debug_count++;
	}
}

size_t Matches::size() {
	return v.size();
}

Match& Matches::operator[](int i) {
	return v[i];
}

int Matches::get_match_index_till(Timeline timeline) {
	// Find match index according to the timeline.
	int ret = -1;
	for (int i = 0; i < v.size(); i++) {
		if (timeline.curr() >= v[i].time.seconds())
//				&& timeline.curr() - v[i].time.seconds() < 130*60)
			ret = i;
	}
	return ret;
}

int Matches::get_current_match_index(Timeline timeline) {
	// If no match at that timeline, return -1.
	int ret = -1;
	for (int i = 0; i < v.size(); i++) {
		if (timeline.curr() >= v[i].time.seconds()
				&& timeline.curr() - v[i].time.seconds() < 130*60)
			ret = i;
	}
	return ret;
}

Match Matches::get_current_match_info(Timeline timeline) {
	Match ret, temp;
	int index = get_current_match_index(timeline);

	if (get_current_match_index(timeline) == -1) // If no match at current time.
		index++;                                 // Move index to the next.

	ret = temp = this->operator[](index);
	auto home_event = temp.get_curr_event(0, timeline);
	auto away_event = temp.get_curr_event(1, timeline);
	ret.home_events = home_event;
	ret.away_events = away_event;
	ret.home_team.goals = 0;
	ret.home_team.goal_own = 0;
	ret.home_team.goal_opposite = 0;
	ret.home_team.goal_penalties = 0;
	ret.away_team.goals = 0;
	ret.away_team.goal_own = 0;
	ret.away_team.goal_opposite = 0;
	ret.away_team.goal_penalties = 0;
	count_goal(home_event, ret.home_team, ret.away_team);
	count_goal(away_event, ret.away_team, ret.home_team);

	return ret;
}

void Matches::count_goal(vector<TeamEvent>& event, Team& home_team, Team& away_team) {
	for (auto& e : event) {
		if(e.type == "goal") {
			home_team.goals += 1;
			home_team.goal_diff += 1;
			away_team.goal_diff -= 1;
		}
		if (e.type == "goal-penalty") {
			home_team.goal_penalties += 1;
			home_team.goal_diff += 1;
			away_team.goal_diff -= 1;
		}
		if (e.type == "goal-own") {
			home_team.goal_own += 1;
			away_team.goal_opposite += 1;
		}
	}
}
