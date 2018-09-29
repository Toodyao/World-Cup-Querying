#include <iostream>
#include <rapidjson/filereadstream.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <set>
#include <unordered_map>
#include "structures.h"
#include "my_time.h"
#include "heap.hpp"
#include "timeline.h"
#include "demo.h"
#include "hash.hpp"

using namespace std;
using namespace rapidjson;

#define DEBUG_READ_DATA_OUTPUT

void show_goal_rank(const Matches& m);


int main() {
//	FILE* fp = fopen("../../data/output.json", "r");
//	Matches m;
//	m.read(fp);
//
//	Timeline timeline;
//	timeline.set_curr("2018-06-14T15:00:00Z");
//	m.get_match_info(timeline);
//
//	typedef std::unordered_map<string, Player> Hash;
//	Hash players;
//	Player p;
//	players.insert(make_pair("1", p));
	demo d;
	d.init();
	d.set_time("2018-07-16T00:22:00Z");
	d.update_player();
	d.update_goal_rank();
	d.print_goal_rank();
//	d.print_player();
//	show_goal_rank(m);

	std::hash<std::string> h;
	h("test");

	return 0;
}

void show_goal_rank(const Matches& m) {
	Heap<Player> goal_rank(new MyGreater<Player>);
	for (auto& match : m.v) {
		for (auto& event : match.home_events) {
			if (event.type == "goal" || event.type == "goal-penalty") {
				Player tmp;
				tmp.name = event.player;
//				s.insert(event.player);
				int player_index = 0;
				if ((player_index = goal_rank.find(tmp)) != -1) {
					// If player exists in the goal_rank
					goal_rank.v[player_index].goal++;
					goal_rank.update_node(player_index);
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
//				s.insert(event.player);
				int player_index = 0;
				if ((player_index = goal_rank.find(tmp)) != -1) {
					// If player exists in the goal_rank
					goal_rank.v[player_index].goal++;
					goal_rank.update_node(player_index);
				} else {
					tmp.country = match.away_team.country;
					tmp.goal++;
					goal_rank.push(tmp);
				}
			}
		}
	}
	int rank_size = goal_rank.size();
	vector<Player> v;
	int goal_count[7] = {0};
	for (int i = 0; i < rank_size; i++) {
		goal_count[goal_rank.top().goal]++;
		v.push_back(goal_rank.top());
		goal_rank.pop();
	}

	assert(goal_count[2] == 13);
	assert(goal_count[3] == 7);
	assert(goal_count[4] == 5);
	assert(goal_count[5] == 0);
	assert(goal_count[6] == 1);

	for (auto& i : v) {
		cout << i.name;
		cout << ": ";
		cout << i.goal << endl;
	}

}
