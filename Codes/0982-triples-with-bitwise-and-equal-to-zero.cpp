/*
 * @Author: LetMeFly
 * @Date: 2023-03-04 14:19:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-04 14:21:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> two(1 << 16);
        for (int& a : nums) {
            for (int& b : nums) {
                two[a & b]++;
            }
        }
        int ans = 0;
        for (int& one : nums) {
            for (int mask = 0; mask < (1 << 16); mask++) {
                if ((one & mask) == 0) {
                    ans += two[mask];
                }
            }
        }
        return ans;
    }
};