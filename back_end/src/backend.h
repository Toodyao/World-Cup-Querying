#ifndef WORLD_CUP_QUERYING_BACK_END_H
#define WORLD_CUP_QUERYING_BACK_END_H

#include <string>
#include "structures.h"
#include "rank.hpp"
#include "hash.hpp"
#include "knockout.h"

using std::string;
using std::vector;

class BackEnd {
public:
	Matches matches;
	Timeline timeline;
	Rank<Player> goal_rank;
	Players players;
	Teams teams;
	Groups groups;
	Knockout knockout;

	Match curr_match;
	bool has_match_bool;

	BackEnd() {
		//init();
	}

	void init();
	void init(string data_path);
	void update();
	void update_goal_rank();
	void set_time(const string& s);
	string get_time_string();
	int get_curr_match_index(Timeline timeline);
    bool has_match();
    string get_home_name();
    string get_away_name();
    int get_home_goal();
    int get_away_goal();
    vector<string> get_goal_rank_player_name();
    vector<Player> get_goal_rank();
};


#endif //WORLD_CUP_QUERYING_BACK_END_H
