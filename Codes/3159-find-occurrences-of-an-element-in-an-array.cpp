/*
 * @Author: LetMeFly
 * @Date: 2024-12-27 12:13:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-27 12:14:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> locs;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                locs.push_back(i);
            }
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = queries[i] > locs.size() ? -1 : locs[queries[i] - 1];
        }
        return ans;
    }
};