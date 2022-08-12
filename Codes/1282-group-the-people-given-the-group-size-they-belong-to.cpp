/*
 * @Author: LetMeFly
 * @Date: 2022-08-12 09:44:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-12 09:47:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();
        vector<vector<int>> v(n + 1);
        for (int i = 0; i < n; i++) {
            int thisGroupSize = groupSizes[i];
            v[thisGroupSize].push_back(i);
            if (v[thisGroupSize].size() == thisGroupSize) {
                ans.push_back(v[thisGroupSize]);
                v[thisGroupSize].clear();
            }
        }
        return ans;
    }
};