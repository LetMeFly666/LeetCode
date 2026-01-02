/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 13:29:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 14:46:26
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline static mt19937 gen = mt19937(random_device{}());
    inline static uniform_int_distribution<> dis;
public:
    int repeatedNTimes(vector<int>& nums) {
        dis.param(uniform_int_distribution<>::param_type(0, nums.size() - 1));
        int loc1, loc2;
        do {
            loc1 = dis(gen);
            loc2 = dis(gen);
        } while (loc1 == loc2 || nums[loc1] != nums[loc2]);
        return nums[loc1];
    }
};