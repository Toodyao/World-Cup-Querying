#ifndef WORLD_CUP_QUERYING_MY_TIME_H
#define WORLD_CUP_QUERYING_MY_TIME_H

#include <ctime>
#include <string>

class MyTime {
private:
	typedef struct tm tm;
	tm time_raw = {0};
	time_t time_value;
	tm zero_time = {0}; // Time of the first match
	time_t zero_value;
	double seconds_total;
	int time_zone_diff;
public:
	MyTime();
	explicit MyTime(std::string& t);
	explicit MyTime(const char* t);

	void set_time(std::string t);

	std::string get_string();
	int seconds();
	int year();
	int mon();
	int day();
	int hour();
	int min();
	int sec();
};

#endif //WORLD_CUP_QUERYING_MY_TIME_H
