/*
 * @Author: LetMeFly
 * @Date: 2026-09-27 08:22:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-27 09:12:03
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string reverseParentheses(const string& s) {
        int n = s.size();
        vector<int> mate(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int girlfriend = st.top();
                st.pop();
                mate[girlfriend] = i;
                mate[i] = girlfriend;
            }
        }

        string ans;
        ans.reserve(n);
        for (int i = 0, direction = 1; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = mate[i];
                direction = -direction;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
