#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include <rank.hpp>
#include <hash.hpp>
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

TEST(tool_test, rank_test) {
	Rank<int> r;
	int n = 10;
	for (int i = 0 ; i < n; i++) {
		r.add(i);
	}
	r.update();
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(r[i], 9-i);
	}
}

TEST(tool_test, hash_test) {
	Hash<int, string> h;
	h.insert(123, "123");
	h.insert(567, "Mike");
	h.insert(12312313, "long");
	string s;

	EXPECT_EQ(h.find(123), "123");
	EXPECT_EQ(h.find(567), "Mike");
	EXPECT_EQ(h.find(12312313), "long");



	Player p;
	p.name = "Mike";
	p.goal = 0;
	p.country = "US";
	Hash<string, Player> hh;
	hh.insert(p.name, p);
	Player* tmp = hh.find_ptr(p.name);
	EXPECT_EQ(tmp->name, "Mike");
	tmp = hh.find_ptr("not exists");
	EXPECT_EQ(tmp, nullptr);
}

TEST(tool_test, my_vector_test) {
	MyVector<int> v;
	int n = 10;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}
	EXPECT_EQ(v.size(), 10);
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(v[i], i);
	}

	for (int i = 0; i < n; i+=2) {
		v.erase(i);
	}
	EXPECT_EQ(v.size(), 5);
	EXPECT_EQ(v[0], 1);
	EXPECT_EQ(v[1], 3);
	EXPECT_EQ(v[2], 5);
	EXPECT_EQ(v[3], 7);
	EXPECT_EQ(v[4], 9);

}