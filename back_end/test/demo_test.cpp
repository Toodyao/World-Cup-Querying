#include <gtest/gtest.h>
#include <demo.h>

TEST(demo_test, knockout_test) {
	demo d;
	d.set_time("2018-08-07T15:00:00Z");
	d.update();
	ASSERT_EQ(d.knockout.tree[0].valid, true);
	ASSERT_EQ(d.knockout.tree[0].winner, "France");
}

TEST(demo_test, goal_rank_test) {
	demo d;
	d.set_time("2018-08-07T15:00:00Z");
	d.update();
	int goal_count[7] = {0};
	for (int i = 0; i < d.goal_rank.size(); i++) {
		goal_count[d.goal_rank[i].goal]++;
	}

	ASSERT_EQ(goal_count[2], 13);
	ASSERT_EQ(goal_count[3], 7);
	ASSERT_EQ(goal_count[4], 5);
	ASSERT_EQ(goal_count[5], 0);
	ASSERT_EQ(goal_count[6], 1);
}