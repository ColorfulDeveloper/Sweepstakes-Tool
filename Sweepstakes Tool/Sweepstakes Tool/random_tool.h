#pragma once

#include <random>

class RandomTool
{
public:
    int randint(int start, int end)
    {
        // 创建随机数引擎
        std::random_device rd;
        std::mt19937 gen(rd());

        // 生成随机整数
        std::uniform_int_distribution<> dist_int(start, end);
        return dist_int(gen);
    }
};