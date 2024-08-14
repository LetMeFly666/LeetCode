/*
 * @Author: LetMeFly
 * @Date: 2024-08-14 23:26:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-14 23:33:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            bool same = nums[i] % 2 == nums[i + 1] % 2;
            nums[i] = cnt;
            cnt += same;
        }
        nums.back() = cnt;
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = nums[queries[i][1]] == nums[queries[i][0]];
        }
        return ans;
    }
};