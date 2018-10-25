// This file stores necessary structures used in this World Cup Querying System

#ifndef WORLD_CUP_QUERYING_STRUCTURES_H
#define WORLD_CUP_QUERYING_STRUCTURES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include "my_time.h"
#include "timeline.h"
#include "rank.hpp"
#include "hash.hpp"

//#define DEBUG_READ_DATA_OUTPUT

#ifdef DEBUG_READ_DATA_OUTPUT
using std::cout;
using std::endl;
#endif

using std::string;
using std::vector;

typedef enum {RUS, KSA, URU, EGY, MAR, IRN, POR, ESP,
			  FRA, AUS, ARG, ISL, PER, DEN, CRO, NGA,
			  CRC, SRB, GER, MEX, BRA, SUI, SWE, KOR,
			  BEL, PAN, TUN, ENG, COL, JPN, POL, SEN}
			  CountyType;
typedef enum {A = 0, B, C, D, E, F, G, H} GroupType;

class Player {
public:
	string name;
	string country;
	int goal;
	int substitution_in;
	int substitution_out;
	int yellow_card;
	int red_card;
	int goal_penalty;
	int goal_own;
	Player ();
	bool operator > (const Player& a) const {
		if (this->goal == a.goal)
			return this->name < a.name; // Notice: name is different order
		else
			return this->goal > a.goal;
	}
	bool operator < (const Player& a) const {
		if (this->goal == a.goal)
			return this->name > a.name; // Notice: name is different order
		else
			return this->goal < a.goal;
	}
	bool operator == (const Player& a) const {
		return this->name == a.name;
	}
};

class Team {
public:
	//int id; // Don't know what is it
	string country;
	string code_str;
	CountyType code;
	int goals = 0;
	int penalties = 0;
	GroupType group;
	int points = 0; // Used in group matches
	void read(const rapidjson::Value& v);
	bool operator > (const Team& a) const {
		return this->points > a.points;
	}
};

class Teams {
public:
	typedef string CodeString;
	Hash<CodeString, Team> teams;
	std::map<CountyType, string> team_code_country_map;
	std::map<CodeString, CountyType> team_code_code_map;
	std::map<CountyType, GroupType> team_group_map;

	Teams() {
		build_team_static_map();
		build_team_hash();
	}

	Team& find(string team_code);
	void build_team_hash();
	void build_team_static_map();
	void update();
	GroupType get_group(CountyType c);
	GroupType get_group(CodeString c);
	vector<Team> get_vector();
	CountyType get_team_code(string code);
};

class TeamEvent {
public:
	int id;
	string type; // Should replace use enum
	string player;
	int time;
	void read(const rapidjson::Value& v);
	int parse_time(string s);
	~TeamEvent() {id = -2;}
	bool operator == (const TeamEvent& a) const {
		return this->id == a.id;
	}
};

class Match {
public:
	Team home_team;
	Team away_team;
	vector<TeamEvent> home_events;
	vector<TeamEvent> away_events;
	string winner; // 'True' means winner is home team
	MyTime time;
	bool valid; // Mark whether the object is valid.
	void read(const std::string& json);
	void read(const rapidjson::Value& d);
	void read_events(vector<TeamEvent>& events, const rapidjson::Value& v);
	void clean_events(vector<TeamEvent>& events);
	Match() {
		valid = false;
	}
};

class Matches {
public:
	vector<Match> v;
	void read(const string& json);
	void read(FILE* fp);
	int get_match_index_till(Timeline timeline);
	int get_current_match_info(Timeline timeline);
	size_t size();
	Match& operator [] (int i);
};

class Players {
public:
	Hash<string, Player> players;

	Matches* matches_ptr;

	void clear();
	void update(Timeline timeline);
	void set_matches(Matches* m);
	void build_player_hash(Timeline timeline);
	void count_goal(int i, vector<TeamEvent> tv, Team team);
	Hash<string, Player>& hash_raw();
};

class Group {
public:
	GroupType group_num; // Group A to H
	Rank<Team> member; // Each group has 4 members

	Group() = default;
};

class Groups {
public:
	vector<Rank<Team> > groups = vector<Rank<Team> >(8);
	Teams* teams;

	//Groups() {
	//	make_group();
	//};

	Groups(Teams* t) {
		set_team(t);
		make_group();
	}
	void set_team(Teams* t) {teams = t;};
	void make_group() {
		groups.clear();
		groups.resize(8);
		auto v = teams->get_vector();
		for (auto& i : v) {
			groups[i.group].add(i);
		}
	}
	void update() {
		make_group();
		for (auto& i : groups) {
			i.update();
		}
	}
	Rank<Team>& get_group(GroupType group_num) {return groups[(int)group_num];};
	Rank<Team>& get_group(int group_num) {return groups[group_num];};
	Rank<Team>& get_group(string group_str) {
		assert(group_str.length() == 1);
		return groups[group_str[0] - 'A'];
	};



};

#endif //WORLD_CUP_QUERYING_STRUCTURES_H
