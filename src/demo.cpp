#include "demo.h"
#include "structures.h"
#include "rank.hpp"
#include <iostream>

void demo::init() {
	FILE* fp = fopen("../../data/output.json", "r");
//	FILE* fp = fopen("../../data/test_data_group", "r");
	matches.read(fp);

	timeline.set_curr("2018-06-14T15:00:00Z");
}

void demo::update_goal_rank() {
	int index = matches.get_match_index_till(timeline);
	goal_rank.clear();
	for (auto it = players.begin(); it != players.end(); ++it) {
		goal_rank.add(it->second);
	}
	goal_rank.update();
}

void demo::update_player() {
	int index = matches.get_match_index_till(timeline);
	for (int i = 0; i < index; i++) {
		vector<TeamEvent> tv = matches[i].home_events;
		for (int j = 0; j < tv.size(); j++) {
			if (tv[j].type == "goal" || tv[j].type == "goal-penalty") {
				if (players.count(tv[j].player) == 0) { // If not exits, add new.
					Player tmp;
					tmp.country = matches[i].home_team.country;
					tmp.name = tv[j].player;
					tmp.goal = 1;
					std::pair<string, Player> p(tv[j].player, tmp);
					players.insert(p);
				} else {
					auto& it = players[tv[j].player];
					it.goal++;
				}
			}
		}
		tv = matches[i].away_events;
		for (int j = 0; j < tv.size(); j++) {
			if (tv[j].type == "goal" || tv[j].type == "goal-penalty") {
				if (players.count(tv[j].player) == 0) { // If not exits, add new.
					Player tmp;
					tmp.country = matches[i].away_team.country;
					tmp.name = tv[j].player;
					tmp.goal = 1;
					std::pair<string, Player> p(tv[j].player, tmp);
					players.insert(p);
				} else {
					auto& it = players[tv[j].player];
					it.goal++;
				}
			}
		}
	}
	int end_time_point = timeline.curr() - matches[index].time.seconds();
	assert(end_time_point > 0);
	vector<TeamEvent> tv = matches[index].home_events;
	for (int i = 0; i < tv.size() && tv[i].time < end_time_point; i++) {
		if (tv[i].type == "goal" || tv[i].type == "goal-penalty") {
			if (players.count(tv[i].player) == 0) { // If not exits, add new.
				Player tmp;
				tmp.country = matches[index].home_team.country;
				tmp.name = tv[i].player;
				tmp.goal = 1;
				std::pair<string, Player> p(tv[i].player, tmp);
				players.insert(p);
			} else {
				auto& it = players[tv[i].player];
				it.goal++;
			}
		}
	}
	tv = matches[index].away_events;
	for (int i = 0; i < tv.size() && tv[i].time < end_time_point; i++) {
		if (tv[i].type == "goal" || tv[i].type == "goal-penalty") {
			if (players.count(tv[i].player) == 0) { // If not exits, add new.
				Player tmp;
				tmp.country = matches[index].away_team.country;
				tmp.name = tv[i].player;
				tmp.goal = 1;
				std::pair<string, Player> p(tv[i].player, tmp);
				players.insert(p);
			} else {
				auto& it = players[tv[i].player];
				it.goal++;
			}
		}
	}
}

void demo::set_time(const string& s) {
	timeline.set_curr(s);
}

void demo::print_player() {
	for (Hash::iterator it = players.begin(); it != players.end(); ++it) {
		std::cout << it->first;
		std::cout << ": ";
		std::cout << it->second.goal << std::endl;
	}
}

void demo::print_goal_rank() {
	for (int i = 0; i < goal_rank.size(); i++) {
		std::cout << goal_rank[i].name;
		std::cout << ": ";
		std::cout << goal_rank[i].goal << std::endl;
	}
}
