/*
 * @Author: LetMeFly
 * @Date: 2022-11-22 14:36:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-22 14:39:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> ma;
        int cnt = 0;
        ma[0] = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                cnt++;
            else
                cnt--;
            if (ma.count(cnt)) {
                ans = max(ans, i - ma[cnt]);
            }
            else {
                ma[cnt] = i;
            }
        }
        return ans;
    }
};