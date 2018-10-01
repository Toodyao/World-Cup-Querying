#include "demo.h"
#include "structures.h"
#include "rank.hpp"
#include <iostream>
using namespace std;

void demo::init() {
	FILE* fp = fopen("../../data/output.json", "r");
//	FILE* fp = fopen("../../data/test_data_group.json", "r");
	matches.read(fp);

	timeline.set_curr("2018-06-14T15:00:00Z");
}

void demo::update_goal_rank() {
	int index = matches.get_match_index_till(timeline);
	goal_rank.clear();
	auto& hash_table = players.v;
	for (int i = 0; i < hash_table.size(); i++) {
		auto& list = hash_table[i];
		for (int j = 0; j < list.size(); j++) {
			goal_rank.add(list[j].value);
		}
	}
//	for (auto it = players.begin(); it != players.end(); ++it) {
//		goal_rank.add(it->second);
//	}
	goal_rank.update();
}

void demo::update_player() {
	players.clear();
	int index = matches.get_match_index_till(timeline);
	for (int i = 0; i < index; i++) {
		count_goal(i, matches[i].home_events, matches[i].home_team); // Home team goal till timeline.
		count_goal(i, matches[i].away_events, matches[i].away_team); // Away team goal till timeline.
	}

	int end_time_point = timeline.curr() - matches[index].time.seconds();
	assert(end_time_point > 0);

	count_goal(index, matches[index].home_events, matches[index].home_team); // Home team goal (on-going).
	count_goal(index, matches[index].away_events, matches[index].away_team); // Away team goal (on-going).
}

void demo::set_time(const string& s) {
	timeline.set_curr(s);
}

void demo::print_player() {
//	for (Hash::iterator it = players.begin(); it != players.end(); ++it) {
//		std::cout << it->first;
//		std::cout << ": ";
//		std::cout << it->second.goal << std::endl;
//	}
}

void demo::print_goal_rank() {
	for (int i = 0; i < goal_rank.size(); i++) {
		std::cout << goal_rank[i].name;
		std::cout << ": ";
		std::cout << goal_rank[i].goal << std::endl;
	}
}

void demo::count_goal(int i, vector<TeamEvent> tv, Team team) {
	for (int j = 0; j < tv.size(); j++) {
		if (tv[j].type == "goal" || tv[j].type == "goal-penalty") {
			if (players.find_ptr(tv[j].player) == nullptr) { // If not exits, add new.
				Player tmp;
				tmp.country = team.country;
				tmp.name = tv[j].player;
				tmp.goal = 1;
//				std::pair<string, Player> p(tv[j].player, tmp);
				players.insert(tv[j].player, tmp);
			} else {
				auto& it = players.find(tv[j].player);
				it.goal++;
			}
		}
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
