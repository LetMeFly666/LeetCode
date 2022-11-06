/*
 * @Author: LetMeFly
 * @Date: 2022-11-06 08:34:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-06 08:40:40
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        int n = nums.size(), to = 2 * nums.size();
        for (int i = 0; i < to; i++) {
            int loc = i % n;
            while (!st.empty() && nums[st.top()] < nums[loc]) {
                ans[st.top()] = nums[loc];
                st.pop();
            }
            st.push(loc);
        }
        return ans;
    }
};