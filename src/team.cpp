#include "structures.h"
using std::make_pair;

void Team::read(const rapidjson::Value& v) {
	country   = v["country"].GetString();
	code      = v["code"].GetString();
	goals     = v["goals"].GetInt();
	penalties = v["penalties"].GetInt();

#ifdef DEBUG_READ_DATA_OUTPUT
	//	cout << "{" << endl;
	cout << country << endl;
	cout << code << endl;
	cout << goals << endl;
	cout << penalties << endl;
//	cout << "}" << endl;
#endif
}

void Teams::build_team_hash() {
	teams.clear();
	for (auto& i : team_code_code_map) {
		Team temp;
		temp.goals = 0;
		temp.penalties = 0;
		temp.points = 0;
		temp.code = i.first;
		temp.country = team_code_country_map[i.second];
		//temp.group
		teams.insert(temp.code, temp);
	}
}

void Teams::build_team_code_map() {

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

CountyType Teams::get_team_code(string code) {
	return team_code_code_map[code];
}

void Teams::update() {
	teams.clear();
	build_team_hash();
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
