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