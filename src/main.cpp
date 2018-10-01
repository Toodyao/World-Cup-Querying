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

	demo d;
	d.init();
	d.set_time("2018-06-16T00:22:00Z");
	d.update_player();
	d.update_goal_rank();
	d.print_goal_rank();
	cout << "-----------" << endl;
	d.set_time("2018-07-16T00:22:00Z");
	d.update_player();
	d.update_goal_rank();
	d.print_goal_rank();
	cout << d.players.hash_conflict() << endl;
	d.goal_rank_test();
//	d.print_player();
//	show_goal_rank(m);
	return 0;
}

void show_goal_rank(const Matches& m) {
	Heap<Player> goal_rank;
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
