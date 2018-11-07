#include "backend.h"
#include <iostream>

using std::cout;
using std::endl;

void BackEnd::init() {
	// Get data ready
	FILE* fp = fopen("../../data/output.json", "r");
	assert(fp);
	matches.read(fp);

	// Default timeline
	timeline.set_curr("2018-06-14T15:00:00Z");

	players.set_matches(&matches);

	teams.set_timeline(&timeline);
	teams.set_match(&matches);

	groups.set_team(&teams);
	groups.make_group();

	knockout.set_matches(&matches);
	knockout.set_timeline(&timeline);
	knockout.set_groups(&groups);

	has_match_bool = false;
}

void BackEnd::init(string data_path) {
	// Get data ready
	FILE* fp = fopen(data_path.c_str(), "r");
	matches.read(fp);

	// Default timeline
	timeline.set_curr("2018-06-14T15:00:00Z");

	players.set_matches(&matches);

	teams.set_timeline(&timeline);
	teams.set_match(&matches);

	groups.set_team(&teams);
	groups.make_group();

	knockout.set_matches(&matches);
	knockout.set_timeline(&timeline);
	knockout.set_groups(&groups);

	has_match_bool = false;
}

void BackEnd::update() {
	players.update(timeline);
	update_goal_rank();

	teams.update();
	groups.update();

	has_match_bool = (matches.get_current_match_index(timeline) != -1);
	curr_match = matches.get_current_match_info(timeline);


	if (timeline.curr() >= knockout_time.seconds()) {
		knockout.update();
	}
}

void BackEnd::update_goal_rank() {
	int index = matches.get_match_index_till(timeline);
	goal_rank.clear();
	auto& hash_table = players.hash_raw().v;
	for (size_t i = 0; i < hash_table.size(); i++) {
		auto& list = hash_table[i];
		for (size_t j = 0; j < list.size(); j++) {
			goal_rank.add(list[j].value);
		}
	}
	goal_rank.update();
}

void BackEnd::set_time(const string& s) {
	timeline.set_curr(s);
}

int BackEnd::get_curr_match_index(Timeline timeline) {
	return matches.get_match_index_till(timeline);
}

string BackEnd::get_time_string() {
	return timeline.get_time_string();
}

bool BackEnd::has_match() {
	return has_match_bool;
}

string BackEnd::get_home_name() {
	return curr_match.home_team.country;
}

string BackEnd::get_away_name() {
	return curr_match.away_team.country;
}

int BackEnd::get_home_goal() {
	return curr_match.home_team.goals;
}

int BackEnd::get_away_goal() {
	return curr_match.away_team.goals;
}

vector<string> BackEnd::get_goal_rank_player_name() {
	vector<string> ret;
	for (auto& i : goal_rank.v) {
		ret.push_back(i.name);
	}
	return ret;
}

vector<Player> BackEnd::get_goal_rank() {
	return goal_rank.v;
}
