#include "timeline.h"
#include "my_time.h"

Timeline::Timeline() {
	curr_time = 0;
	prev_time = 0;
}

bool Timeline::changed() {
	return curr_time != prev_time;
}

void Timeline::set_curr(std::string s) {
	prev_time = curr_time;
	MyTime t(s);
	curr_time = t.seconds();
}

int Timeline::get_curr() {
	return curr_time;
}

int Timeline::get_prev() {
	return prev_time;
}




