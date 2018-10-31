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
	prev_time = curr_time; // Consider high frequency use situation, need refactor.
	t.set_time(s);
	curr_time = t.seconds();
}

int Timeline::curr() {
	return curr_time;
}

int Timeline::prev() {
	return prev_time;
}

std::string Timeline::get_time_string() {
	return t.get_string();
}

Timeline::Timeline(std::string& s) {
	set_curr(s);
}




