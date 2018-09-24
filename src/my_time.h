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
	MyTime(std::string& t);

	void set_time(std::string t);

	std::string get_string();
	int seconds();
};

#endif //WORLD_CUP_QUERYING_MY_TIME_H
