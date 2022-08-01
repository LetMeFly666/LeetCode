/*
 * @Author: LetMeFly
 * @Date: 2022-08-01 08:28:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-01 08:35:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ')
                st.push(s[i]);
            if (s[i] == ' ' || !i) {
                if (st.size()) {
                    if (ans.size())
                        ans += ' ';
                    while (st.size()) {
                        ans += st.top();
                        st.pop();
                    }
                }
            }
        }
        return ans;
    }
};