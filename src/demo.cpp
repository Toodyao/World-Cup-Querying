#include "demo.h"
#include "structures.h"
#include "rank.hpp"
#include <iostream>
#include <set>

using namespace std;

void demo::init() {
	// Get data ready
	FILE* fp = fopen("../../data/output.json", "r");
	//FILE* fp = fopen("../../data/test_data_group.json", "r");
	matches.read(fp);

	// Default timeline
	timeline.set_curr("2018-06-14T15:00:00Z");
	//knockout_time.set_time("2018-06-30T14:00:00Z");

	players.set_matches(&matches);
	//teams.set_player(&players);
	teams.set_timeline(&timeline);
	teams.set_match(&matches);
	groups.set_team(&teams);
	groups.make_group();

	knockout.set_matches(&matches);
	knockout.set_timeline(&timeline);
	knockout.set_groups(&groups);

}

void demo::update() {
	players.update(timeline);
	update_goal_rank();

	teams.update();
	groups.update();

	if (timeline.curr() >= knockout_time.seconds()) {
		knockout.update();
	}
}

void demo::update_goal_rank() {
	int index = matches.get_match_index_till(timeline);
	goal_rank.clear();
	auto& hash_table = players.hash_raw().v;
	for (int i = 0; i < hash_table.size(); i++) {
		auto& list = hash_table[i];
		for (int j = 0; j < list.size(); j++) {
			goal_rank.add(list[j].value);
		}
	}
	//for (auto it = players.begin(); it != players.end(); ++it) {
	//	goal_rank.add(it->second);
	//}
	goal_rank.update();
}

void demo::set_time(const string& s) {
	timeline.set_curr(s);
}

void demo::print_goal_rank() {
	for (int i = 0; i < goal_rank.size(); i++) {
		std::cout << goal_rank[i].name;
		std::cout << ": ";
		std::cout << goal_rank[i].goal << std::endl;
	}
}

void demo::goal_rank_test() {
	int goal_count[7] = {0};
	for (int i = 0; i < goal_rank.size(); i++) {
		goal_count[goal_rank[i].goal]++;
	}

	assert(goal_count[2] == 13);
	assert(goal_count[3] == 7);
	assert(goal_count[4] == 5);
	assert(goal_count[5] == 0);
	assert(goal_count[6] == 1);

	cout << "goal rank correct" << endl;
}

