/*
 * @Author: LetMeFly
 * @Date: 2024-05-24 21:15:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-24 21:25:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (st.size() && st.top() > nums[i] && (st.size() - 1) + (nums.size() - i) >= k) {
                st.pop();
            }
            if (st.size() < k) {
                st.push(nums[i]);
            }
        }
        // stack -> vector
        vector<int> ans;
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};