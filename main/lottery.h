#include <iostream>

class DuotoneBallLottery
{
public:
    DuotoneBallLottery();
    ~DuotoneBallLottery() = default;

    int GenDuotoneBall();

private:
    std::vector<int> redBalls;
    std::vector<int> blueBall;
};