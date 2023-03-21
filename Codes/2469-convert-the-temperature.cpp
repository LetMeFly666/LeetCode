/*
 * @Author: LetMeFly
 * @Date: 2023-03-21 12:23:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-21 12:24:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};