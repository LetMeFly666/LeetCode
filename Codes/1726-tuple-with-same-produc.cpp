/*
 * @Author: LetMeFly
 * @Date: 2023-10-19 10:14:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-19 10:15:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> ma;
        for (int i =  0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ma[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto&& [k, v] : ma) {
            ans += v * (v - 1) * 4;
        }
        return ans;
    }
};