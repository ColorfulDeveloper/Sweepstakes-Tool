#pragma once

#include <vector>
#include <string>
#include <sstream>

#include "file_tool.h"
#include "random_tool.h"

class MemberList
{
public:
    // 初始化列表
    void init()
    {
        std::string file_str;
        this->file_tool.read("save.txt", file_str);
        std::stringstream ss(file_str);
        std::string str;
        while (std::getline(ss, str, ';'))
        {
            this->list.push_back(str);
        }
    }

    // 抽奖
    std::string randget()
    {
        int id = this->random_tool.randint(0, (list.size() - 1));
        return this->list[id];
    }

    std::vector<std::string> list;
private:
    RandomTool random_tool;
    FileTool file_tool;
};