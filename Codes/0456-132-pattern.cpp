/*
 * @Author: LetMeFly
 * @Date: 2022-10-22 12:55:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-22 13:01:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int k = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < k)
                return true;
            while (st.size() && nums[i] > st.top()) {
                k = max(k, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};