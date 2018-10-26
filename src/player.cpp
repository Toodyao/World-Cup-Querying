#include "structures.h"

Player::Player() {
	name = "";
	country = "";
	goal = 0;
	substitution_in = 0;
	substitution_out = 0;
	yellow_card = 0;
	red_card = 0;
	goal_penalty = 0;
	goal_own = 0;
}

void Players::update(Timeline timeline) {
	build_player_hash(timeline);
}

void Players::build_player_hash(Timeline timeline) {
	players.clear();
	auto& matches = *matches_ptr;
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

void Players::count_goal(int i, vector<TeamEvent> tv, Team team) {
	// TODO: bug, not precise, i not use
	for (int j = 0; j < tv.size(); j++) {
		if (tv[j].type == "goal" || tv[j].type == "goal-penalty") {
			if (players.find_ptr(tv[j].player) == nullptr) { // If not exits, add new.
				Player tmp;
				tmp.country = team.country;
				tmp.country_code = team.code_str;
				tmp.name = tv[j].player;
				tmp.goal = 1;
				//std::pair<string, Player> p(tv[j].player, tmp);
				players.insert(tv[j].player, tmp);
			} else {
				auto& it = players.find(tv[j].player);
				it.goal++;
			}
		}
		if (tv[j].type == "goal_own") {

		}
	}
}

void Players::clear() {
	players.clear();
}

Hash<string, Player>& Players::hash_raw() {
	return players;
}

void Players::set_matches(Matches* m) {
	matches_ptr = m;
}

vector<Player> Players::get_vector() {
	vector<Player> v;
	for (auto& list : players.v) {
		for (auto& item : list) {
			v.push_back(item.value);
		}
	}
	return v;
}

vector<Rank<Team>> Groups::get_vector() {
	return groups;
}
