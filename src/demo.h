#ifndef WORLD_CUP_QUERYING_DEMO_H
#define WORLD_CUP_QUERYING_DEMO_H

#include <string>
#include <unordered_map>
#include <map>
#include "structures.h"
#include "rank.hpp"
#include "hash.hpp"

using std::string;

class demo {
public:
	Matches matches;
	Timeline timeline;
	Rank<Player> goal_rank;
	//typedef std::unordered_map<string, Player> Hash;
	//Hash<string, Player> players;
	Players players;
	Teams teams;
	vector<Group> groups = vector<Group>(8);

	void init();
	void update();
	void update_goal_rank();
	//void update_player();
	void set_time(const string& s);
	//void print_player();
	void print_goal_rank();
	//void count_goal(int i, vector<TeamEvent> tv, Team team);
	void goal_rank_test();

};


#endif //WORLD_CUP_QUERYING_DEMO_H
