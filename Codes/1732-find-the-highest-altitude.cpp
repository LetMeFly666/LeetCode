/*
 * @Author: LetMeFly
 * @Date: 2022-11-19 08:30:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-19 08:30:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int now = 0;
        for (int& t : gain) {
            now += t;
            ans = max(ans, now);
        }
        return ans;
    }
};