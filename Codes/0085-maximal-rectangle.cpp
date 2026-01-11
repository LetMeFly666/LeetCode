/*
 * @Author: LetMeFly
 * @Date: 2026-01-11 22:47:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-11 23:13:41
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int> heights(matrix[0].size() + 2);
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i].insert(matrix[i].begin(), '0');
            matrix[i].push_back('0');
            stack<int> st;
            for (int j = 0; j < matrix[i].size(); j++) {
                heights[j] = heights[j] && matrix[i][j] == '1' ? heights[j] + 1 : matrix[i][j] == '1';
                while (st.size() && heights[j] < heights[st.top()]) {  // 记得st.size()也要判断，否则哨兵0会驱逐哨兵0
                    int idx = st.top();
                    st.pop();
                    ans = max(ans, heights[idx] * (j - st.top() - 1));
                }
                st.push(j);
            }
        }
        return ans;
    }
};