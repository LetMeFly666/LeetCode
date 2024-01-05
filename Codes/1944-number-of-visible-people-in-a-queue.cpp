/*
 * @Author: LetMeFly
 * @Date: 2024-01-05 18:18:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-05 19:00:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans(heights.size());
        stack<int> st;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (st.size() && heights[st.top()] < heights[i]) {
                st.pop();
                ans[i]++;
            }
            if (st.size()) {
                ans[i]++;
            }
            st.push(i);
        }
        return ans;
    }
};