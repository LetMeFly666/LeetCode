/*
 * @Author: LetMeFly
 * @Date: 2022-06-04 10:00:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-04 10:14:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int th = 0;
        while (th < intervals.size() && intervals[th][1] < newInterval[0]) {
            ans.push_back(intervals[th]);
            th++;
        }
        if (th == intervals.size()) {
            ans.push_back(newInterval);
        }
        else {
            int l = intervals[th][0];
            while (th < intervals.size() && intervals[th][0] <= newInterval[1]) {
                th++;
            }
            
        }

        return ans;
    }
};
#else  // FirstTry
// Copy From LeetCode
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
#endif  // FirstTry