#include "structures.h"

void Matches::read(const string& json) {
	rapidjson::Document d;
	d.Parse(json.c_str());
//	cout << d.GetType() << endl;
	assert(d.IsArray());
	int debug_count = 0;
	for (auto& i : d.GetArray()) {
		Match temp;
		temp.read(i);
		v.push_back(temp);
		debug_count++;
	}
}

void Matches::read(FILE* fp) {
	char readBuffer[65536];
	rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	rapidjson::Document d;
	d.ParseStream(is);
	fclose(fp);

	assert(d.IsArray());
	int debug_count = 0;
	for (auto& i : d.GetArray()) {
		Match temp;
		temp.read(i);
		v.push_back(temp);
		debug_count++;
	}
}

size_t Matches::size() {
	return v.size();
}

Match& Matches::operator[](int i) {
	return v[i];
}

int Matches::get_match_index_till(Timeline timeline) {
	// Find match index according to the timeline.
	int ret = -1;
	for (int i = 0; i < v.size(); i++) {
		if (timeline.curr() >= v[i].time.seconds())
//				&& timeline.curr() - v[i].time.seconds() < 130*60)
			ret = i;
	}
	return ret;
}

int Matches::get_current_match_info(Timeline timeline) {
	// If no match at that timeline, return -1.
	int ret = -1;
	for (int i = 0; i < v.size(); i++) {
		if (timeline.curr() >= v[i].time.seconds()
				&& timeline.curr() - v[i].time.seconds() < 130*60)
			ret = i;
	}
	return ret;
}