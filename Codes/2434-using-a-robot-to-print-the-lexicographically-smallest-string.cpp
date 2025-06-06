/*
 * @Author: LetMeFly
 * @Date: 2025-06-06 21:49:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-06 22:08:25
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string robotWithString(string s) {
        string ans;
        stack<char> st;
        for (char c : s) {
            while (st.size() && c < st.top()) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};