#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include "structures.h"
#include "heap.hpp"
using namespace std;

TEST(tool_test, heap_test) {
	srand(0);
	Heap<Player> h(new MyGreater<Player>);
	int n = 100;
	for (int i = 0; i < n; i++) {
		Player a;
		a.goal = i;
		a.name = to_string(i);
		h.push(a);
	}
	n = h.size();
	for (int i = n - 1; i >= 0; i--) {
		Player tmp = h.top();
		EXPECT_EQ(i, tmp.goal);
		h.pop();
	}
}