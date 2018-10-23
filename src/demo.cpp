#include "demo.h"
#include "structures.h"
#include "rank.hpp"
#include <iostream>
#include <set>

using namespace std;

void demo::init() {
	// Get data ready
	FILE* fp = fopen("../../data/output.json", "r");
	//FILE* fp = fopen("../../data/test_data_group.json", "r");
	matches.read(fp);

	// Default timeline
	timeline.set_curr("2018-06-14T15:00:00Z");

	// Team hash table init
	build_team_hash();

	// Team code convert map
	build_team_code_map();

	// Group init
	for (int i = 0; i < 8; i++) {
		groups[i].group_num = (GroupType)i;
	}
}

void demo::update() {
	update_player();
	update_goal_rank();

	update_team();
}

void demo::update_goal_rank() {
	int index = matches.get_match_index_till(timeline);
	goal_rank.clear();
	auto& hash_table = players.v;
	for (int i = 0; i < hash_table.size(); i++) {
		auto& list = hash_table[i];
		for (int j = 0; j < list.size(); j++) {
			goal_rank.add(list[j].value);
		}
	}
//	for (auto it = players.begin(); it != players.end(); ++it) {
//		goal_rank.add(it->second);
//	}
	goal_rank.update();
}

void demo::update_player() {
	players.clear();
	int index = matches.get_match_index_till(timeline);
	for (int i = 0; i < index; i++) {
		count_goal(i, matches[i].home_events, matches[i].home_team); // Home team goal till timeline.
		count_goal(i, matches[i].away_events, matches[i].away_team); // Away team goal till timeline.
	}

	int end_time_point = timeline.curr() - matches[index].time.seconds();
	assert(end_time_point > 0);

	count_goal(index, matches[index].home_events, matches[index].home_team); // Home team goal (on-going).
	count_goal(index, matches[index].away_events, matches[index].away_team); // Away team goal (on-going).
}

void demo::set_time(const string& s) {
	timeline.set_curr(s);
}

void demo::print_player() {
//	for (Hash::iterator it = players.begin(); it != players.end(); ++it) {
//		std::cout << it->first;
//		std::cout << ": ";
//		std::cout << it->second.goal << std::endl;
//	}
}

void demo::print_goal_rank() {
	for (int i = 0; i < goal_rank.size(); i++) {
		std::cout << goal_rank[i].name;
		std::cout << ": ";
		std::cout << goal_rank[i].goal << std::endl;
	}
}

void demo::count_goal(int i, vector<TeamEvent> tv, Team team) {
	for (int j = 0; j < tv.size(); j++) {
		if (tv[j].type == "goal" || tv[j].type == "goal-penalty") {
			if (players.find_ptr(tv[j].player) == nullptr) { // If not exits, add new.
				Player tmp;
				tmp.country = team.country;
				tmp.name = tv[j].player;
				tmp.goal = 1;
				//std::pair<string, Player> p(tv[j].player, tmp);
				players.insert(tv[j].player, tmp);
			} else {
				auto& it = players.find(tv[j].player);
				it.goal++;
			}
		}
	}
}

void demo::goal_rank_test() {
	int goal_count[7] = {0};
	for (int i = 0; i < goal_rank.size(); i++) {
		goal_count[goal_rank[i].goal]++;
	}

	assert(goal_count[2] == 13);
	assert(goal_count[3] == 7);
	assert(goal_count[4] == 5);
	assert(goal_count[5] == 0);
	assert(goal_count[6] == 1);

	cout << "goal rank correct" << endl;
}

void demo::build_team_hash() {
	int team_num = 64;
	std::set<string> s;
	int set_size = 0;
	for (int i = 0; i < team_num; i++) {
		string team_code = matches[i].home_team.code;
		s.insert(team_code);
		if (s.size() == set_size) {
			continue; // If team duplicated
		} else {
			Team team_temp = matches[i].home_team;
			team_temp.goals = 0;
			team_temp.penalties = 0;
			team_temp.points = 0;
			team_temp.group = get_team_group(team_temp.code);
			teams.insert(team_code, team_temp);
		}
	}
}

vector<Team> demo::get_all_team_vector() {
	vector<Team> v;
	for (auto& list : teams.v) {
		for (auto& item : list) {
			v.push_back(item.value);
		}
	}
	return v;
}

void demo::update_team() {
	teams.clear();
	build_team_hash();

}

GroupType demo::get_team_group(string code) {

}

void demo::build_team_code_map() {

	team_code_country_map.clear();

	team_code_country_map.insert(make_pair(RUS, "Russia"));
	team_code_country_map.insert(make_pair(KSA, "Saudi Arabia"));
	team_code_country_map.insert(make_pair(URU, "Uruguay"));
	team_code_country_map.insert(make_pair(EGY, "Egypt"));
	team_code_country_map.insert(make_pair(MAR, "Morocco"));
	team_code_country_map.insert(make_pair(IRN, "Iran"));
	team_code_country_map.insert(make_pair(POR, "Portugal"));
	team_code_country_map.insert(make_pair(ESP, "Spain"));
	team_code_country_map.insert(make_pair(FRA, "France"));
	team_code_country_map.insert(make_pair(AUS, "Australia"));
	team_code_country_map.insert(make_pair(ARG, "Argentina"));
	team_code_country_map.insert(make_pair(ISL, "Iceland"));
	team_code_country_map.insert(make_pair(PER, "Peru"));
	team_code_country_map.insert(make_pair(DEN, "Denmark"));
	team_code_country_map.insert(make_pair(NGA, "Nigeria"));
	team_code_country_map.insert(make_pair(CRO, "Croatia"));
	team_code_country_map.insert(make_pair(CRC, "Costa Rica"));
	team_code_country_map.insert(make_pair(SRB, "Serbia"));
	team_code_country_map.insert(make_pair(GER, "Germany"));
	team_code_country_map.insert(make_pair(MEX, "Mexico"));
	team_code_country_map.insert(make_pair(BRA, "Brazil"));
	team_code_country_map.insert(make_pair(SUI, "Switzerland"));
	team_code_country_map.insert(make_pair(SWE, "Sweden"));
	team_code_country_map.insert(make_pair(KOR, "Korea Republic"));
	team_code_country_map.insert(make_pair(BEL, "Belgium"));
	team_code_country_map.insert(make_pair(PAN, "Panama"));
	team_code_country_map.insert(make_pair(TUN, "Tunisia"));
	team_code_country_map.insert(make_pair(ENG, "England"));
	team_code_country_map.insert(make_pair(COL, "Colombia"));
	team_code_country_map.insert(make_pair(JPN, "Japan"));
	team_code_country_map.insert(make_pair(POL, "Poland"));
	team_code_country_map.insert(make_pair(SEN, "Senegal"));

	team_code_code_map.clear();

	team_code_code_map.insert(make_pair("RUS",  RUS));
	team_code_code_map.insert(make_pair("KSA",  KSA));
	team_code_code_map.insert(make_pair("URU",  URU));
	team_code_code_map.insert(make_pair("EGY",  EGY));
	team_code_code_map.insert(make_pair("MAR",  MAR));
	team_code_code_map.insert(make_pair("IRN",  IRN));
	team_code_code_map.insert(make_pair("POR",  POR));
	team_code_code_map.insert(make_pair("ESP",  ESP));
	team_code_code_map.insert(make_pair("FRA",  FRA));
	team_code_code_map.insert(make_pair("AUS",  AUS));
	team_code_code_map.insert(make_pair("ARG",  ARG));
	team_code_code_map.insert(make_pair("ISL",  ISL));
	team_code_code_map.insert(make_pair("PER",  PER));
	team_code_code_map.insert(make_pair("DEN",  DEN));
	team_code_code_map.insert(make_pair("NGA",  NGA));
	team_code_code_map.insert(make_pair("CRO",  CRO));
	team_code_code_map.insert(make_pair("CRC",  CRC));
	team_code_code_map.insert(make_pair("SRB",  SRB));
	team_code_code_map.insert(make_pair("GER",  GER));
	team_code_code_map.insert(make_pair("MEX",  MEX));
	team_code_code_map.insert(make_pair("BRA",  BRA));
	team_code_code_map.insert(make_pair("SUI",  SUI));
	team_code_code_map.insert(make_pair("SWE",  SWE));
	team_code_code_map.insert(make_pair("KOR",  KOR));
	team_code_code_map.insert(make_pair("BEL",  BEL));
	team_code_code_map.insert(make_pair("PAN",  PAN));
	team_code_code_map.insert(make_pair("TUN",  TUN));
	team_code_code_map.insert(make_pair("ENG",  ENG));
	team_code_code_map.insert(make_pair("COL",  COL));
	team_code_code_map.insert(make_pair("JPN",  JPN));
	team_code_code_map.insert(make_pair("POL",  POL));
	team_code_code_map.insert(make_pair("SEN",  SEN));
}

CountyType demo::get_team_code(string code) {
	//return team_code_code_map.find(code)->second;
	return team_code_code_map[code];
}
