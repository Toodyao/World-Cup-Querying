// This file stores necessary structures used in this World Cup Querying System

#ifndef WORLD_CUP_QUERYING_STRUCTURES_H
#define WORLD_CUP_QUERYING_STRUCTURES_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class TeamEvents {
public:
	int id;
	string type; // Should replace use enum
	string player;
	string time; // Should use time library
};

class Team {
public:
	int id; // Don't know what is it
	string country;
	string code;
	int goals;
	int penalties;
	vector<TeamEvents> events;
};

class Match {
public:
	Team home_team;
	Team away_team;
	bool winner; // 'True' means winner is home team
	string time; // Should replace use time library
};

#endif //WORLD_CUP_QUERYING_STRUCTURES_H
