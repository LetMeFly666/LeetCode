/*
 * @Author: LetMeFly
 * @Date: 2024-01-05 18:18:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-05 18:21:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        heights.back() = 1e7;
        vector<int> ans(heights.size());
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (st.size() && heights[st.top()] < heights[i]) {
                int thisGuy = st.top();
                st.pop();
                ans[thisGuy] = i - thisGuy;
            }
            st.push(i);
        }
        return ans;
    }
};