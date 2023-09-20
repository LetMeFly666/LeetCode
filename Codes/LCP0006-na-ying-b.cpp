/*
 * @Author: LetMeFly
 * @Date: 2023-09-20 10:41:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-20 10:41:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans = 0;
        for (int t : coins) {
            ans += (t + 1)/ 2;
        }
        return ans;
    }
};