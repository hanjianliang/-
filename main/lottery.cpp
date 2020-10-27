#include <iostream>
#include <random>

#include "lottery.h"


DuotoneBallLottery::DuotoneBallLottery()
{
    for (int i = 1; i <= 33; ++i)
    {
        this->redBalls.push_back(i);
    }

    for (int i = 1; i <= 16; ++i)
    {
        this->blueBall.push_back(i);
    }
}

int DuotoneBallLottery::GenDuotoneBall()
{
    if (this->redBalls.size() != 33)
    {
        return -1;
    }

    // 红色球
    while(this->redBalls.size() > 6)
    {
        std::random_device rd;
        std::default_random_engine rng {rd()};
        std::uniform_int_distribution<int> dist {0, (int)this->redBalls.size() - 1};
        int randNum = dist(rng);

        auto iter = this->redBalls.begin() + randNum;
        this->redBalls.erase(iter);
    }

    std::cout << std::endl << "---------------------------------------------" << std::endl;
    std::cout << "红球：";
    for (auto redBallNum : this->redBalls)
    {
        std::cout << "   " << redBallNum;
    }
    std::cout << std::endl;

    // 蓝色球
    {
        std::random_device rd;
        std::default_random_engine rng {rd()};
        std::uniform_int_distribution<int> dist {0, (int)this->blueBall.size() - 1};
        int randNum = dist(rng);

        std::cout << "蓝球：   " << blueBall[randNum] << std::endl;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::endl;
    return 0;
}