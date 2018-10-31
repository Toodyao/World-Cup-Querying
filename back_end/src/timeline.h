#ifndef WORLD_CUP_QUERYING_TIMELINE_H
#define WORLD_CUP_QUERYING_TIMELINE_H

#include <string>

class Timeline {
private:
	int curr_time;
	int prev_time;
public:
	Timeline();
	bool changed();
	void set_curr(std::string s);
	int curr();
	int prev();
};

#endif //WORLD_CUP_QUERYING_TIMELINE_H
