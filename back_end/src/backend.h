#ifndef WORLD_CUP_QUERYING_BACK_END_H
#define WORLD_CUP_QUERYING_BACK_END_H

#include <string>
#include "structures.h"
#include "rank.hpp"
#include "hash.hpp"
#include "knockout.h"

using std::string;

class BackEnd {
public:
	Matches matches;
	Timeline timeline;
	Rank<Player> goal_rank;
	Players players;
	Teams teams;
	Groups groups;
	Knockout knockout;

	BackEnd() {
		init();
	}

	void init();
	void update();
	void update_goal_rank();
	void set_time(const string& s);
	int get_curr_match_index(Timeline timeline);
};


#endif //WORLD_CUP_QUERYING_BACK_END_H
