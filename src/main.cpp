#include <iostream>
#include <rapidjson/filereadstream.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <set>
#include "structures.h"
#include "my_time.h"
#include "heap.hpp"
using namespace std;
using namespace rapidjson;

void test(string s) {
	cout << s << endl;
}

#define DEBUG_READ_DATA_OUTPUT

int main() {
	string json_path = "../../data/output-line.json";
//	string json_path = "../../data/test_data_group";
	ifstream json_file(json_path);

	string json;
	getline(json_file, json);

	Matches m;
	m.read(json);


	// TODO: Heap problem, cannot auto sort
	// TODO: Data problem, Harry KANE's goal count wrong
	Heap<Player> goal_rank(new MyGreater<Player>);
	for (auto& match : m.v) {
		for (auto& event : match.home_events) {
			if (event.type == "goal" || event.type == "goal-penalty") {
				Player tmp;
				tmp.name = event.player;
				int player_index = 0;
				if ((player_index = goal_rank.find(tmp)) != -1) {
					// If player exists in the goal_rank
					goal_rank.v[player_index].goal++;
					goal_rank.swap_up(player_index);
				} else {
					tmp.country = match.home_team.country;
					tmp.goal++;
					goal_rank.push(tmp);
				}
			}
		}
		for (auto& event : match.away_events) {
			if (event.type == "goal" || event.type == "goal-penalty") {
				Player tmp;
				tmp.name = event.player;
				int player_index = 0;
				if ((player_index = goal_rank.find(tmp)) != -1) {
					// If player exists in the goal_rank
					goal_rank.v[player_index].goal++;
					goal_rank.swap_up(player_index);
				} else {
					tmp.country = match.away_team.country;
					tmp.goal++;
					goal_rank.push(tmp);
				}
			}
		}
	}
	int rank_size = goal_rank.size();
	for (int i = 0; i < rank_size; i++) {
		cout << goal_rank.top().name;
		cout << ": ";
		cout << goal_rank.top().goal << endl;
		goal_rank.pop();
	}


	return 0;
}