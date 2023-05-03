/*
 * @Author: LetMeFly
 * @Date: 2023-05-03 09:37:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-03 09:43:53
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isValid(string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == 'a') {
                st.push('a');
            }
            else if (c == 'b') {
                if (st.empty() || st.top() != 'a') {
                    return false;
                }
                else {
                    st.pop();
                    st.push('b');
                }
            }
            else {
                if (st.empty() || st.top() != 'b') {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};