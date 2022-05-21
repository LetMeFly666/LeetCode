/*
 * @Author: LetMeFly
 * @Date: 2022-05-19 08:54:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-19 09:14:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (st.size() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                int width = i - left - 1;
                int newHeight = min(height[i], height[left]) - height[top];
                ans += width * newHeight;
            }
            st.push(i);
        }
        return ans;
    }
};