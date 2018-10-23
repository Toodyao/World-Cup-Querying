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
	Hash<string, Player> players;
	Hash<string, Team>   teams;
	vector<Group> groups = vector<Group>(8);
	std::map<CountyType, string> team_code_country_map;
	std::map<string, CountyType> team_code_code_map;
	std::map<string, GroupType> team_group_map;

	void init();
	void update();
	void update_goal_rank();
	void update_player();
	void set_time(const string& s);
	void print_player();
	void print_goal_rank();
	void count_goal(int i, vector<TeamEvent> tv, Team team);
	void goal_rank_test();

	void build_team_hash();
	void build_team_code_map();
	void update_team();
	vector<Team> get_all_team_vector();
	GroupType get_team_group(string code);
	CountyType get_team_code(string code);
};


#endif //WORLD_CUP_QUERYING_DEMO_H
