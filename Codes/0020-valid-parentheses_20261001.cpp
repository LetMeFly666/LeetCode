/*
 * @Author: LetMeFly
 * @Date: 2026-10-01 09:18:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-01 09:22:00
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (st.empty()) {
                return false;
            } else {
                char a = st.top();
                st.pop();
                if (!(a == '(' && c == ')' || a == '[' && c == ']' || a == '{' && c == '}')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
