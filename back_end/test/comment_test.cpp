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
    ASSERT_EQ(c.v[0].comment_raw, "test_comment");
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

TEST(comment_test, add_test) {
    Comments c;
    string file_path = "../../data/test_comments.json";
    c.load_comments_from_file(file_path);
    CommentType ct;
    ct.id = 3001;
    ct.name = "3name";
    ct.time = "2018-11-30";
    ct.comment_raw = "test3";
    ct.index = 3;
    c.add_comment(ct);

    ASSERT_EQ(c.v.size(), 3);
    ASSERT_EQ(c.v[2].id, 3001);

    ASSERT_EQ(c.d.GetArray().Size(), 3);
}