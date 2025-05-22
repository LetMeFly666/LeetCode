/*
 * @Author: LetMeFly
 * @Date: 2025-05-22 13:41:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-22 18:33:52
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool ok(vector<int>& nums, vector<vector<int>>& queries, int t) {
        vector<int> diff(nums.size() + 1);
        for (int i = 0; i < t; i++) {
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += diff[i];
            if (nums[i] > cnt) {
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = -1;
        int l = 0, r = queries.size() - 1;  // [l, r]
        while (l <= r) {
            int m = (l + r) >> 1;
            if (ok(nums, queries, m)) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};