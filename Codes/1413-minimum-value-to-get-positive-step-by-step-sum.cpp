/*
 * @Author: LetMeFly
 * @Date: 2022-08-09 09:42:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-09 09:42:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1;
        int cnt = 0;
        for (int& t : nums) {
            cnt += t;
            ans = max(ans, -cnt + 1);
        }
        return ans;
    }
};