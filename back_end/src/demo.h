#ifndef WORLD_CUP_QUERYING_DEMO_H
#define WORLD_CUP_QUERYING_DEMO_H

//#include <string>
#include <unordered_map>
#include <map>
#include "structures.h"
#include "rank.hpp"
#include "hash.hpp"
#include "knockout.h"

using std::string;

class demo {
public:
	Matches matches;
	Timeline timeline;
	Rank<Player> goal_rank;
	Players players;
	Teams teams;
	Groups groups;
	Knockout knockout;

	demo() {
		init();
	}
	
	void init();
	void update();
	void update_goal_rank();
	void set_time(const string& s);
	void print_goal_rank();
	void goal_rank_test();

};


#endif //WORLD_CUP_QUERYING_DEMO_H
