#pragma once

#include <string>
#include <iostream>

#include "member_list.h"

class App
{
public:
    // 初始化
    void init()
    {
        this->member_list.init();
        this->isRunning = true;
    }

    // 程序循环
    void run()
    {
        while (this->isRunning)
        {
            system("cls");
            std::cout << "#欢迎使用抽奖工具" << std::endl;
            std::cout << "======================" << std::endl;
            std::cout << "1 --> 开始抽奖" << std::endl;
            std::cout << "2 --> 查看抽奖列表" << std::endl;
            std::cout << "======================" << std::endl;
            std::cout << "请输入:";
            std::string input;
            getline(std::cin, input);
            if (input == "1")
            {
                this->randget();
            }
            else if (input == "2")
            {
                this->check_list();
            }
            else
            {
                std::cout << "输入异常" << std::endl;
                system("pause");
            }
        }
    }

    // 退出
    void quit()
    {
        exit(0);
    }
private:
    // 抽奖
    void randget()
    {
        std::string name = this->member_list.randget();
        std::cout << name << " 中奖了!" << std::endl;
        system("pause");
    }

    // 查看成员列表
    void check_list()
    {
        for (int id = 0; id < this->member_list.list.size(); id++)
        {
            std::cout << this->member_list.list[id] << std::endl;
        }
        std::cout << "#共有" << this->member_list.list.size() << "个成员#" << std::endl;
        system("pause");
    }

    bool isRunning;
    MemberList member_list;
};