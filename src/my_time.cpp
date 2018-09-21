#include "my_time.h"

MyTime::MyTime(std::string& t) {
	// String format example: 2018-06-14T15:00:00Z

	zero_time.tm_year = 2018 - 1900;
	zero_time.tm_mon  = 06   - 1;
	zero_time.tm_mday = 14;
	zero_time.tm_hour = 15;
	zero_time.tm_min  = 00;
	zero_time.tm_sec  = 00;

	time_zone_diff = 8;

	time_raw.tm_year = stoi(t.substr(0, 4)) - 1900;
	time_raw.tm_mon  = stoi(t.substr(5, 2)) - 1;
	time_raw.tm_mday = stoi(t.substr(8, 2));
	time_raw.tm_hour = stoi(t.substr(11, 2));
	time_raw.tm_min  = stoi(t.substr(14, 2));
	time_raw.tm_sec  = stoi(t.substr(17, 2));
	time_value = mktime(&time_raw);
	zero_value = mktime(&zero_time);
	seconds_total = difftime(time_value, zero_value);
}

std::string MyTime::get_string() {
	std::string ret(asctime(&time_raw));
	return ret;
}

int MyTime::seconds() {
	return (int)seconds_total;
}
