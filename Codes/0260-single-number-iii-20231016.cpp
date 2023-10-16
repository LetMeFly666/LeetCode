/*
 * @Author: LetMeFly
 * @Date: 2023-10-16 22:38:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-16 22:46:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int temp = 0;
        for (int t : nums) {
            temp ^= t;
        }
        int mask = temp & (-temp);
        vector<int> ans(2);
        for (int t : nums) {
            ans[(t & mask) != 0] ^= t;
        }
        return ans;
    }
};