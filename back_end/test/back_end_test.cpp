#include <gtest/gtest.h>
#include <iostream>
#include "backend.h"

using std::cout;
using std::endl;

TEST(back_end_test, get_time_test) {
	BackEnd be;
	be.init();
	ASSERT_EQ(be.get_time_string(), "2018-06-14T15:00:00Z");
	be.set_time("2018-06-14T14:00:00Z");
}

TEST(back_end_test, match_get_partial_test) {
	BackEnd be;
	be.init();
	be.set_time("2018-06-14T16:04:00Z");
	be.update();
	auto v = be.curr_match.get_curr_event(0, be.timeline);
	ASSERT_EQ(v.size(), 6);

	be.set_time("2018-06-14T16:03:30Z");
	be.update();
	v = be.curr_match.get_curr_event(0, be.timeline);
	ASSERT_EQ(v.size(), 4);

	be.set_time("2018-07-14T15:12:00Z");
	be.update();
	v = be.curr_match.get_curr_event(0, be.timeline);
	ASSERT_EQ(v.size(), 5);
}

TEST(back_end_test, home_and_away_goal_test) {
	BackEnd be;
	be.init();
	be.set_time("2018-06-14T15:12:00Z");
	be.update();
	ASSERT_EQ(be.get_home_goal(), 1);
	ASSERT_EQ(be.get_away_goal(), 0);

	be.set_time("2018-07-14T15:12:00Z");
	be.update();
	ASSERT_EQ(be.get_home_goal(), 1);
	ASSERT_EQ(be.get_away_goal(), 0);

}