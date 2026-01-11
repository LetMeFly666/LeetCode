/*
 * @Author: LetMeFly
 * @Date: 2026-01-11 22:23:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-11 22:44:08
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> idx;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (idx.size() && heights[i] < heights[idx.top()]) {
                int lastIdx = idx.top();
                idx.pop();
                ans = max(ans, heights[lastIdx] * (i - idx.top() - 1));
            }
            idx.push(i);
        }
        return ans;
    }
};