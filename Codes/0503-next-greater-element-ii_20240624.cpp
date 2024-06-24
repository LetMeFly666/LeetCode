/*
 * @Author: LetMeFly
 * @Date: 2024-06-24 12:36:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-24 12:47:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n * 2; i++) {
            int th = i % n;
            while (st.size() && nums[st.top()] < nums[th]) {
                // printf("st.top() = %d, nums[%d] = %d, th = %d, nums[%d] = %d\n", st.top(), st.top(), nums[st.top()], th, th, nums[th]);  //*********
                ans[st.top()] = nums[th];
                st.pop();
            }
            st.push(th);
        }
        return ans;
    }
};

#ifdef _WIN32
int main() {
    vector<int> nums = {1, 2, 1};
    Solution sol;
    debug(sol.nextGreaterElements(nums));
    return 0;
}
#endif

// 这几天缺乏睡眠了属于是