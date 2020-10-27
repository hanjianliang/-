#include <iostream>
#include <string.h>
#include <random>

#include "lottery.h"


int main(int argc, char* argv[])
{
    while(1)
    {
        std::cout << std::endl << std::endl;
        std::cout << "====================菜单=====================" << std::endl;
        std::cout << "== 1.双色球" << std::endl;
        std::cout << "== 0.退出" << std::endl;
        std::cout << "=============================================" << std::endl;

        int32_t iswitch = -1;
        std::cout << "输入选项：" << std::endl;
        std::cin >> iswitch;

        if (iswitch < 0 || iswitch > 2)
        {
            std::cout << "输入错误！" << std::endl;
        }

        switch(iswitch)
        {
            case 0:
            {
                std::cout << "" << std::endl;
                exit(1);
            }
            case 1:
            {
                DuotoneBallLottery myDuotoneBallLottery;
                myDuotoneBallLottery.GenDuotoneBall();
                break;
            }
            case 2:
            {
                break;
            }
            default:
                break;
        }

        std::cout << std::endl << std::endl;
    }

    return 0;
}