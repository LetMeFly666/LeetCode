/*
 * @Author: LetMeFly
 * @Date: 2026-09-24 07:59:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-24 08:01:23
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int cnt(int t) {
        int ans = 0;
        while (t) {
            ans += t % 10;
            t /= 10;
        }
        return ans;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (cnt(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};
