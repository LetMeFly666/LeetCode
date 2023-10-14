/*
 * @Author: LetMeFly
 * @Date: 2023-10-14 11:10:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-14 11:11:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int t : nums) {
            ans ^= t;
        }
        return ans;
    }
};