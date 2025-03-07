/*
 * @Author: LetMeFly
 * @Date: 2025-03-07 23:32:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-07 23:49:07
 * @Description: AC,6771ms击败5.56%,567.46MB击败5.56%
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isok(vector<int>& v, int k) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (abs(v[i] - v[j]) == k) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size(), end = 1 << n;
        for (int i = 1; i < end; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    v.push_back(nums[j]);
                }
            }
            ans += isok(v, k);
        }
        return ans;
    }
};