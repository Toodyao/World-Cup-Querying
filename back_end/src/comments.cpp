#include "comments.h"

void Comments::load_comments_from_file(const string& file_path) {
    this->file_path = file_path;
    FILE* fp = fopen(file_path.c_str(), "r");
    assert(fp);
    char readBuffer[65535];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    d.ParseStream(is);
    fclose(fp);

    assert(d.IsArray());
    for (auto& i : d.GetArray()) {
        CommentType temp;
        temp.id = i["id"].GetInt();
        temp.time = i["time"].GetString();
        temp.name = i["name"].GetString();
        temp.comment_raw = i["comment"].GetString();
        temp.index = i["index"].GetInt();
        v.push_back(temp);
    }
}

void Comments::add_comment(CommentType t) {
    v.push_back(t);
}

void Comments::del_comment(int id) {
    // id is unique

    // Delete local vector
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->id == id) {
            v.erase(it);
            break;
        }
    }

    // Delete DOM tree
    for (auto it = d.GetArray().begin(); it != d.GetArray().end(); ++it) {
        if ((*it)["id"] == id) {
            d.Erase(it);
            break;
        }
    }

    write_back();
}

void Comments::refresh() {
    v.clear();
}

vector<CommentType> Comments::get_comment_list(int index) {
    vector<CommentType> ret;
    for (auto& i : v)
        if (i.index == index)
            ret.push_back(i);

    return ret;
}

void Comments::write_back() {
    FILE* fp = fopen(file_path.c_str(), "wb");
    assert(fp);
    char writeBuffer[65535];
    rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
    Writer<FileWriteStream> writer(os);
    d.Accept(writer);
    fclose(fp);
}
