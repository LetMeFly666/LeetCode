/*
 * @Author: LetMeFly
 * @Date: 2023-08-27 09:02:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-27 09:06:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),  intervals.end());
        intervals.push_back({100000, 100000});  // 哨兵思想
        vector<vector<int>> ans;
        int from = intervals[0][0], to = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= to) {
                to = max(to, intervals[i][1]);
            }
            else {
                ans.push_back({from, to});
                from = intervals[i][0], to = intervals[i][1];
            }
        }
        return ans;
    }
};