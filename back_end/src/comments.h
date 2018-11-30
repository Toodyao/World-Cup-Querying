#ifndef WORLD_CUP_QUERYING_COMMENTS_H
#define WORLD_CUP_QUERYING_COMMENTS_H

#include <vector>
#include <string>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/writer.h>

using std::string;
using std::vector;
using namespace rapidjson;

typedef struct CommentValue {
    int id; // Format: index*1000+number
    string time;
    string comment_raw;
    string name;
    int index; // Belongs to which match
} CommentType;

class Comments {
public:
    vector<CommentType> v;
    string file_path;
    rapidjson::Document d;
    Comments() {};
    void load_comments_from_file(const string& file_path);
    void add_comment(CommentType t);
    void del_comment(int id);
    void refresh();
    void write_back();
    vector<CommentType> get_comment_list(int index);

};


#endif //WORLD_CUP_QUERYING_COMMENTS_H
