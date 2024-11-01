/*
 * @Author: LetMeFly
 * @Date: 2024-11-01 12:23:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-11-01 12:30:53
 * @Description: 时空复杂度超越百分比：AC,100.00%,94.62%
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        ll day0a = 0, day0b = 0, day1a = energyDrinkA[0], day1b = energyDrinkB[0];
        for (int i = 1; i < energyDrinkA.size(); i++) {
            ll day2a = max(day1a, day0b) + energyDrinkA[i];
            ll day2b = max(day0a, day1b) + energyDrinkB[i];
            day0a = day1a, day0b = day1b, day1a = day2a, day1b = day2b;
        }
        return max(day1a, day1b);
    }
};