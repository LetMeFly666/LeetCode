/*
 * @Author: LetMeFly
 * @Date: 2026-09-04 18:29:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-04 18:32:35
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int getM(vector<int>& nums, int i) {
        int ans = nums[0];
        for (int j = 0; j <= i; j++) {
            ans = max(ans, nums[j]);
        }
        return ans;
    }

    int getm(vector<int>& nums, int i) {
        int ans = nums[i];
        for (; i < nums.size(); i++) {
            ans = min(ans, nums[i]);
        }
        return ans;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = 1000000001;
        for (int i = 0, n = nums.size(); i < n; i++) {
            ans = min(ans, getM(nums, i) - getm(nums, i));
        }
        return ans > k ? -1 : ans;
    }
};
