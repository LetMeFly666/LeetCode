/*
 * @Author: LetMeFly
 * @Date: 2024-01-10 19:14:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-10 19:15:37
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == 'B' && st.size() && st.top() == 'A') {
                st.pop();
            }
            else if (c == 'D' && st.size() && st.top() == 'C') {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.size();
    }
};