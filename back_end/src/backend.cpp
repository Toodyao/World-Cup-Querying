#include "backend.h"
#include <iostream>

using std::cout;
using std::endl;

void BackEnd::init() {
	// Get data ready
	FILE* fp = fopen("../../data/output.json", "r");
	assert(fp);
	matches.read(fp);

	// Default timeline
	timeline.set_curr("2018-06-14T15:00:00Z");

	players.set_matches(&matches);

	teams.set_timeline(&timeline);
	teams.set_match(&matches);

	groups.set_team(&teams);
	groups.make_group();

	knockout.set_matches(&matches);
	knockout.set_timeline(&timeline);
	knockout.set_groups(&groups);

	has_match_bool = false;

	comments.load_comments_from_file("../../data/comments.json");
}

void BackEnd::init(string data_path) {
	// Get data ready
	FILE* fp = fopen(data_path.c_str(), "r");
	matches.read(fp);

	// Default timeline
	timeline.set_curr("2018-06-14T15:00:00Z");

	players.set_matches(&matches);

	teams.set_timeline(&timeline);
	teams.set_match(&matches);

	groups.set_team(&teams);
	groups.make_group();

	knockout.set_matches(&matches);
	knockout.set_timeline(&timeline);
	knockout.set_groups(&groups);

	has_match_bool = false;

    comments.load_comments_from_file("../back_end/data/comments.json");
}

void BackEnd::update() {
	players.update(timeline);
	update_goal_rank();

	teams.update();
	groups.update();

	has_match_bool = (matches.get_current_match_index(timeline) != -1);
	curr_match = matches.get_current_match_info(timeline);


	knockout.update();
}

void BackEnd::update_goal_rank() {
	int index = matches.get_match_index_till(timeline);
	goal_rank.clear();
	auto& hash_table = players.hash_raw().v;
	for (size_t i = 0; i < hash_table.size(); i++) {
		auto& list = hash_table[i];
		for (size_t j = 0; j < list.size(); j++) {
			goal_rank.add(list[j].value);
		}
	}
	goal_rank.update();
}

void BackEnd::set_time(const string& s) {
	timeline.set_curr(s);
}

int BackEnd::get_curr_match_index(Timeline timeline) {
	return matches.get_match_index_till(timeline);
}

string BackEnd::get_time_string() {
	return timeline.get_time_string();
}

bool BackEnd::has_match() {
	return has_match_bool;
}

string BackEnd::get_home_name() {
	return curr_match.home_team.country;
}

string BackEnd::get_away_name() {
	return curr_match.away_team.country;
}

int BackEnd::get_home_goal() {
	auto temp = curr_match.home_team;
	return temp.goals + temp.goal_penalties + temp.goal_opposite;
}

int BackEnd::get_away_goal() {
	auto temp = curr_match.away_team;
	return temp.goals + temp.goal_penalties + temp.goal_opposite;
}

vector<string> BackEnd::get_goal_rank_player_name() {
	vector<string> ret;
	for (auto& i : goal_rank.v) {
		ret.push_back(i.name);
	}
	return ret;
}

vector<Player> BackEnd::get_goal_rank() {
	return goal_rank.v;
}

vector<Match> BackEnd::get_knockout() {
	return knockout.tree;
}

std::pair<int, int> BackEnd::count_goal(Match match, Timeline timeline) {
	int h = 0, a = 0;

	vector<TeamEvent> home, away;
	if (timeline.curr() - match.time.seconds() <= 130*60) {
		home = match.get_curr_event(0, timeline);
		away = match.get_curr_event(1, timeline);
	} else {
		home = match.home_events;
		away = match.away_events;
	}

	for (auto& i : home) {
		if (i.type == "goal" || i.type == "goal-penalty")
			h++;
		else if (i.type == "goal-own")
			a++;
	}

	for (auto& i : away) {
		if (i.type == "goal" || i.type == "goal-penalty")
			a++;
		else if (i.type == "goal-own")
			h++;
	}

	return std::make_pair(h, a);
}

Match BackEnd::get_match(const int index) {
    return matches[index];
}

vector<CommentType> BackEnd::get_comment_list(int index) {
    return comments.get_comment_list(index);
}
