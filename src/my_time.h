#ifndef WORLD_CUP_QUERYING_MY_TIME_H
#define WORLD_CUP_QUERYING_MY_TIME_H

#include <time.h>
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
	MyTime(std::string& t);

	std::string get_string();
	int seconds();
};

#endif //WORLD_CUP_QUERYING_MY_TIME_H
