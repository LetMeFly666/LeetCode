/*
 * @Author: LetMeFly
 * @Date: 2022-04-11 10:12:33
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-11 10:15:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        if (v[0][0] == v[1][0]) {
            for (int i = 2; i < v.size(); i++) {
                if (v[i][0] != v[0][0])
                    return false;
            }
            return true;
        }
        double k = 1. * (v[1][1] - v[0][1]) / (v[1][0] - v[0][0]);
        for (int i = 2; i < v.size(); i++) {
            if (1. * (v[i][1] - v[0][1]) / (v[i][0] - v[0][0]) != k)
                return false;
        }
        return true;
    }
};