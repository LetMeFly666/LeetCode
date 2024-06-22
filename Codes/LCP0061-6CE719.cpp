/*
 * @Author: LetMeFly
 * @Date: 2024-06-21 20:29:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-21 20:32:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool same(int a, int b, int x, int y) {
        return (a > b && x > y) || (a == b && x == y) || (a < b && x < y);
    }
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int ans = 0;
        for (int thisCnt = 0, i = 1; i <= temperatureA.size(); i++) {
            if (i == temperatureA.size() || !same(temperatureA[i - 1], temperatureA[i], temperatureB[i - 1], temperatureB[i])) {
                ans = max(ans, thisCnt);
                thisCnt = 0;
            }
            else {
                thisCnt++;
            }
        }
        return ans;
    }
};