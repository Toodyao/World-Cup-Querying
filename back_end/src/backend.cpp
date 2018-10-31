#include "backend.h"
#include <iostream>

using std::cout;
using std::endl;

void BackEnd::init() {
	// Get data ready
	FILE* fp = fopen("../../data/output.json", "r");
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

	has_match_bool = (matches.get_current_match_info(timeline) != -1);
	curr_match = matches[matches.get_match_index_till(timeline)];

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
