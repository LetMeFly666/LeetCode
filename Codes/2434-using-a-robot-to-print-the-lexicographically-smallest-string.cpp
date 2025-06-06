/*
 * @Author: LetMeFly
 * @Date: 2025-06-06 21:49:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-06 22:19:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string robotWithString(string s) {
        vector<char> mini(s.size() + 1, 'z');
        for (int i = s.size() - 1; i >= 0; i--) {
            mini[i] = min(mini[i + 1], s[i]);
        }
        stack<char> st;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
            while (st.size() && st.top() <= mini[i + 1]) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};