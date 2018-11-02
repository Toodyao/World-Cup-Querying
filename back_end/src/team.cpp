#include "structures.h"
using std::make_pair;

void Team::read(const rapidjson::Value& v) {
	country   = v["country"].GetString();
	code_str  = v["code"].GetString();
	goals     = v["goals"].GetInt();
	goal_penalties = v["penalties"].GetInt();

#ifdef DEBUG_READ_DATA_OUTPUT
	//	cout << "{" << endl;
	cout << country << endl;
	cout << code_str << endl;
	cout << goals << endl;
	cout << goal_penalties << endl;
//	cout << "}" << endl;
#endif
}

void Teams::build_team_hash() {
	teams.clear();
	for (auto& i : team_code_code_map) {
		Team temp;
		temp.goals = 0;
		temp.goal_penalties = 0;
		temp.points = 0;
		temp.code_str = i.first;
		temp.code = team_code_code_map[temp.code_str];
		temp.country = team_code_country_map[i.second];
		temp.group = get_group(temp.code);
		teams.insert(temp.code_str, temp);
	}
}

void Teams::build_team_static_map() {

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

	team_group_map.clear();

	team_group_map.insert(make_pair(RUS,  A));
	team_group_map.insert(make_pair(KSA,  A));
	team_group_map.insert(make_pair(URU,  A));
	team_group_map.insert(make_pair(EGY,  A));

	team_group_map.insert(make_pair(MAR,  B));
	team_group_map.insert(make_pair(IRN,  B));
	team_group_map.insert(make_pair(POR,  B));
	team_group_map.insert(make_pair(ESP,  B));

	team_group_map.insert(make_pair(FRA,  C));
	team_group_map.insert(make_pair(AUS,  C));
	team_group_map.insert(make_pair(PER,  C));
	team_group_map.insert(make_pair(DEN,  C));

	team_group_map.insert(make_pair(ARG,  D));
	team_group_map.insert(make_pair(ISL,  D));
	team_group_map.insert(make_pair(NGA,  D));
	team_group_map.insert(make_pair(CRO,  D));

	team_group_map.insert(make_pair(BRA,  E));
	team_group_map.insert(make_pair(SRB,  E));
	team_group_map.insert(make_pair(CRC,  E));
	team_group_map.insert(make_pair(SUI,  E));

	team_group_map.insert(make_pair(SWE,  F));
	team_group_map.insert(make_pair(MEX,  F));
	team_group_map.insert(make_pair(KOR,  F));
	team_group_map.insert(make_pair(GER,  F));

	team_group_map.insert(make_pair(BEL,  G));
	team_group_map.insert(make_pair(ENG,  G));
	team_group_map.insert(make_pair(PAN,  G));
	team_group_map.insert(make_pair(TUN,  G));

	team_group_map.insert(make_pair(COL,  H));
	team_group_map.insert(make_pair(JPN,  H));
	team_group_map.insert(make_pair(POL,  H));
	team_group_map.insert(make_pair(SEN,  H));
}

CountyType Teams::get_team_code(string code) {
	return team_code_code_map[code];
}

void Teams::update() {
	teams.clear();
	build_team_hash();

	int index = matches->get_match_index_till(*timeline);
	Matches m = *matches;

	for (int i = 0; i < index; i++) {
		string home_team_code = m[i].home_team.code_str;
		string away_team_code = m[i].away_team.code_str;
		Team& home_team = teams.find(home_team_code);
		Team& away_team = teams.find(away_team_code);
		count_goal(m[i].home_events, i, home_team, away_team);
		count_goal(m[i].away_events, i, away_team, home_team);

		count_points(m[i].winner, home_team, away_team);
	}

	// Match is not finished, count partial.
	string home_team_code = m[index].home_team.code_str;
	string away_team_code = m[index].away_team.code_str;
	Team& home_team = teams.find(home_team_code);
	Team& away_team = teams.find(away_team_code);
	auto home_event_partial = m[index].get_curr_event(0, *timeline);
	auto away_event_partial = m[index].get_curr_event(1, *timeline);
	count_goal(home_event_partial, index, home_team, away_team);
	count_goal(away_event_partial, index, away_team, home_team);

	if (timeline->curr() > m[index].time.seconds()) { // If match is finished.
		count_points(m[index].winner, home_team, away_team);
	}
}

void Teams::count_points(const string& winner, Team& home_team, Team& away_team) {
	if (winner == home_team.country)
			home_team.points += 3;
	else if (winner == away_team.country)
			away_team.points += 3;
	else { // Draw
			home_team.points += 1;
			away_team.points += 1;
	}
}

void Teams::count_goal(vector<TeamEvent>& event, int i, Team& home_team, Team& away_team) {
	for (auto& e : event) {
		if(e.type == "goal") {
			home_team.goals += 1;
			home_team.goal_diff += 1;
			away_team.goal_diff -= 1;
		}
		if (e.type == "goal-penalty") {
			home_team.goal_penalties += 1;
			home_team.goal_diff += 1;
			away_team.goal_diff -= 1;
		}
		if (e.type == "goal-own") {
			home_team.goal_own += 1;
			away_team.goal_opposite += 1;
		}
	}
}

vector<Team> Teams::get_vector() {
	vector<Team> v;
	for (auto& list : teams.v) {
		for (auto& item : list) {
			v.push_back(item.value);
		}
	}
	return v;
}

Team& Teams::find(string team_code) {
	return teams.find(team_code);
}

GroupType Teams::get_group(CountyType c) {
	return team_group_map[c];
}

GroupType Teams::get_group(Teams::CodeString c) {
	return team_group_map[team_code_code_map[c]];
}

void Teams::set_player(Players* p) {
	players = p;
}

void Teams::set_match(Matches* m) {
	matches = m;
}

void Teams::set_timeline(Timeline* t) {
	timeline = t;
}
