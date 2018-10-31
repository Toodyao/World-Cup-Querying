#ifndef WORLD_CUP_QUERYING_TIMELINE_H
#define WORLD_CUP_QUERYING_TIMELINE_H

#include <string>
#include "my_time.h"

class Timeline {
private:
	int curr_time;
	int prev_time;
	MyTime t;
public:
	Timeline();
	Timeline(std::string& s);
	bool changed();
	void set_curr(std::string s);
	int curr();
	int prev();
	std::string get_time_string();
};

#endif //WORLD_CUP_QUERYING_TIMELINE_H
