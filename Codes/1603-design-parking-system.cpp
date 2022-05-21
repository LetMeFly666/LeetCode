/*
 * @Author: LetMeFly
 * @Date: 2022-04-23 10:53:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-23 10:57:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class ParkingSystem {
private:
    int cnt[3];
public:
    ParkingSystem(int big, int medium, int small) {
        cnt[0] = big;
        cnt[1] = medium;
        cnt[2] = small;
    }
    
    bool addCar(int carType) {
        if (cnt[carType - 1]) {
            cnt[carType - 1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */