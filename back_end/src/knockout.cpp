#include "knockout.h"

void Knockout::build_tree() {
	tree.clear();
	tree.resize(16);

	if (timeline->curr() < group_end_time.seconds()) {
		return;
	}

	Groups g = *groups;
	add(7,  make_match(g[A][0], g[B][1]));
	add(8,  make_match(g[C][0], g[D][1]));
	add(9,  make_match(g[E][0], g[F][1]));
	add(10, make_match(g[G][0], g[H][1]));

	add(11, make_match(g[B][0], g[A][1]));
	add(12, make_match(g[D][0], g[C][1]));
	add(13, make_match(g[F][0], g[E][1]));
	add(14, make_match(g[H][0], g[G][1]));
}

Match Knockout::make_match(Team home_team, Team away_team) {
	Match m;
	m.home_team = home_team;
	m.away_team = away_team;
	//m.valid = true;
	return m;
}

void Knockout::add(int i, Match m) {
	tree[i] = m;
}

void Knockout::update() {
	build_tree();
	int begin_index = 48; // Knockout match starts at index 48.
	int end_index = matches->get_match_index_till(*timeline);
	for (int level = 0; level < 4; level++) {
		for (int i = begin_index; i <= end_index; i++) {
			pass_match((*matches)[i]);
		}
		go_up();
	}
	recount_goal(*timeline);
}

void Knockout::pass_match(Match m) {
	for (auto& i : tree) {
		// Find proper tree node
		if ((i.home_team.code_str == m.home_team.code_str && i.away_team.code_str == m.away_team.code_str)
			|| (i.home_team.code_str == m.away_team.code_str && i.away_team.code_str == m.home_team.code_str)) {
			i = m;
			i.valid = true;
		}
	}
}

int Knockout::go_up() {
	// 1/16
	for (int i = 7; i <= 14; i += 2) {
		if (tree[i].valid && tree[i+1].valid && !tree[i/2].valid) {
			// If this match finished, then winner go up.
			Team win_team_a = get_win_team(i);
			Team win_team_b = get_win_team(i+1);
			add(i/2, make_match(win_team_a, win_team_b));
		}
	}
	// 1/8
	for (int i = 3; i <= 6; i++) {
		if (tree[i].valid && tree[i+1].valid && !tree[i/2].valid) {
			// If this match finished, then let winner go up.
			Team win_team_a = get_win_team(i);
			Team win_team_b = get_win_team(i+1);
			add(i/2, make_match(win_team_a, win_team_b));
		}
	}
	// 1/4
	for (int i = 1; i <= 2; i++) {
		if (tree[i].valid && tree[i+1].valid && !tree[i/2].valid) {
			// If this match finished, then let winner go up.
			Team win_team_a = get_win_team(i);
			Team win_team_b = get_win_team(i+1);
			add(i/2, make_match(win_team_a, win_team_b));
		}
	}
	if (tree[1].valid && tree[2].valid && !tree[15].valid) {
		// 3rd and 4th place
		Team lose_team_a = get_lose_team(1);
		Team lose_team_b = get_lose_team(2);
		add(15, make_match(lose_team_a, lose_team_b));
	}
	if (tree[1].valid && tree[2].valid && !tree[0].valid) {
		// 1st and 2nd place
		Team win_team_a = get_win_team(1);
		Team win_team_b = get_win_team(2);
		add(0, make_match(win_team_a, win_team_b));
	}
}

void Knockout::set_matches(Matches* m) {
	matches = m;
}

void Knockout::set_timeline(Timeline* t) {
	timeline = t;
}

void Knockout::set_groups(Groups* g) {
	groups = g;
}

Team Knockout::get_win_team(int i) {
	string winner = tree[i].winner;
	if (winner == tree[i].home_team.country)
		return tree[i].home_team;
	else
		return tree[i].away_team;
}

Team Knockout::get_lose_team(int i) {
	string winner = tree[i].winner;
	if (winner == tree[i].home_team.country)
		return tree[i].away_team;
	else
		return tree[i].home_team;
}

void Knockout::recount_goal(Timeline timeline) {
	// Re-count goal for on going match.
	for (auto& i : tree) {
		if (timeline.curr() - i.time.seconds() >= 130) {
			auto temp = count_goal(i);
			i.home_team.goals = temp.first;
			i.away_team.goals = temp.second;
		}
	}
}

std::pair<int, int> Knockout::count_goal(Match match) {
	int h = 0, a = 0;
	for (auto& i : match.home_events) {
		if (i.type == "goal" || i.type == "goal-penalty")
			h++;
		else if (i.type == "goal-own")
			a++;
	}

	for (auto& i : match.away_events) {
		if (i.type == "goal" || i.type == "goal-penalty")
			a++;
		else if (i.type == "goal-own")
			h++;
	}

	return std::make_pair(h, a);
}
