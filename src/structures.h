// This file stores necessary structures used in this World Cup Querying System

#ifndef WORLD_CUP_QUERYING_STRUCTURES_H
#define WORLD_CUP_QUERYING_STRUCTURES_H

#include <string>
#include <vector>
#include <rapidjson/document.h>
using std::string;
using std::vector;

class Match;

class Matches {
public:
	vector<Match> v;
	void read(const string& json);
	size_t size();
	Match& operator [] (int i);
};

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
};

class TeamEvent {
public:
	int id;
	string type; // Should replace use enum
	string player;
	string time; // Should use time library // Rewrite use int
	void read(const rapidjson::Value& v);
};

class Team {
public:
	int id; // Don't know what is it
	string country;
	string code;
	int goals;
	int penalties;
	void read(const rapidjson::Value& v);
};

class Match {
public:
	Team home_team;
	Team away_team;
	vector<TeamEvent> home_events;
	vector<TeamEvent> away_events;
	string winner; // 'True' means winner is home team
	string time; // Should replace use time library
	void read(const std::string& json);
	void read(const rapidjson::Value& d);
	void read_events(vector<TeamEvent>& events, const rapidjson::Value& v);
};


#endif //WORLD_CUP_QUERYING_STRUCTURES_H
