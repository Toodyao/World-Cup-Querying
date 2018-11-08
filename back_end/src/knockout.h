#ifndef WORLD_CUP_QUERYING_KNOCKOUT_H
#define WORLD_CUP_QUERYING_KNOCKOUT_H

#include "structures.h"

class Knockout {
public:
	vector<Match> tree = vector<Match> (16);

	Matches* matches;
	Timeline* timeline;
	Groups* groups;

	void set_matches(Matches* m);
	void set_timeline(Timeline* t);
	void set_groups(Groups* g);

	void build_tree();
	Match make_match(Team home_team, Team away_team);
	void add(int i, Match m);
	void update();
	void pass_match(Match m);
	int go_up();
	Team get_win_team(int i);
	Team get_lose_team(int i);
	void recount_goal(Timeline timeline);
	std::pair<int, int> count_goal(Match match);
};


#endif //WORLD_CUP_QUERYING_KNOCKOUT_H
