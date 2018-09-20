// This file stores necessary structures used in this World Cup Querying System

#ifndef WORLD_CUP_QUERYING_STRUCTURES_H
#define WORLD_CUP_QUERYING_STRUCTURES_H

#include <string>
#include <vector>
#include <rapidjson/document.h>
using std::string;
using std::vector;

class TeamEvents {
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
	vector<TeamEvents> home_events;
	vector<TeamEvents> away_events;
	string winner; // 'True' means winner is home team
	string time; // Should replace use time library
	void read(const std::string& json);
	void read_events(vector<TeamEvents> events, rapidjson::Value& v);
};


#endif //WORLD_CUP_QUERYING_STRUCTURES_H
