/*
 * @Author: LetMeFly
 * @Date: 2022-07-25 16:41:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-25 16:41:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& t : nums) {
            ans ^= t;
        }
        return ans;
    }
};