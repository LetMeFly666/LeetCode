/*
 * @Author: LetMeFly
 * @Date: 2023-11-27 18:30:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-27 18:36:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(-1);
        stack<int> st;
        st.push(-1);
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (st.size() > 1 && arr[i] < arr[st.top()]) {
                int last = st.top();
                st.pop();
                ans = (ans + (long long)arr[last] * (last - st.top()) * (i - last)) % MOD;
            }
            st.push(i);
        }
        return ans;
    }
};