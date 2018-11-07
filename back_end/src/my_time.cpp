#include "my_time.h"

MyTime::MyTime() {
	// String format example: 2018-06-14T15:00:00Z
	zero_time.tm_year = 2018 - 1900;
	zero_time.tm_mon  = 06   - 1;
	zero_time.tm_mday = 14;
	zero_time.tm_hour = 15;
	zero_time.tm_min  = 00;
	zero_time.tm_sec  = 00;

	time_zone_diff = 8;
}

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

MyTime::MyTime(const char* t) {
	zero_time.tm_year = 2018 - 1900;
	zero_time.tm_mon  = 06   - 1;
	zero_time.tm_mday = 14;
	zero_time.tm_hour = 15;
	zero_time.tm_min  = 00;
	zero_time.tm_sec  = 00;

	time_zone_diff = 8;
	set_time(t);
}

std::string MyTime::get_string() {
	char buf[30];
	sprintf(buf, "%d-%02d-%02dT%02d:%02d:%02dZ",
			year(),
			mon(),
			day(),
			hour(),
			min(),
			sec()
	);
	std::string ret(buf);
	return ret;
}

int MyTime::seconds() {
	return (int)seconds_total;
}

void MyTime::set_time(std::string t) {
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

int MyTime::year() {
	return time_raw.tm_year + 1900;
}

int MyTime::mon() {
	return time_raw.tm_mon + 1;
}

int MyTime::day() {
	return time_raw.tm_mday;
}

int MyTime::hour() {
	return time_raw.tm_hour;
}

int MyTime::min() {
	return time_raw.tm_min;
}

int MyTime::sec() {
	return time_raw.tm_sec;
}
