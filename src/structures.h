// This file stores necessary structures used in this World Cup Querying System

#ifndef WORLD_CUP_QUERYING_STRUCTURES_H
#define WORLD_CUP_QUERYING_STRUCTURES_H

#include <string>
#include <vector>
#include <rapidjson/document.h>
#include "my_time.h"
#include "timeline.h"

using std::string;
using std::vector;

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
//	int id; // Don't know what is it
	string country;
	string code;
	int goals;
	int penalties;
	void read(const rapidjson::Value& v);
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

#endif //WORLD_CUP_QUERYING_STRUCTURES_H
