#include <gtest/gtest.h>
#include <iostream>
#include "comments.h"

using std::cout;
using std::endl;

TEST(comment_test, read_test) {
    Comments c;
    string file_path = "../../data/test_comments.json";
    c.load_comments_from_file(file_path);
    ASSERT_EQ(c.v[0].id, 1001);
    ASSERT_EQ(c.v[0].time, "2018-11-30");
    ASSERT_EQ(c.v[0].name, "test_name");
    ASSERT_EQ(c.v[0].comment_raw, "fuck");
    ASSERT_EQ(c.v[0].index, 1);

    ASSERT_EQ(c.v[1].id, 2002);
}

TEST(comment_test, del_test) {
    Comments c;
    string file_path = "../../data/test_comments.json";
    c.load_comments_from_file(file_path);
    c.del_comment(1001);
    ASSERT_EQ(c.v.size(), 1);
    ASSERT_EQ(c.d.GetArray().Size(), 1);
}

