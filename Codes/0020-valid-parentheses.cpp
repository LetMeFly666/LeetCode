/*
 * @Author: LetMeFly
 * @Date: 2022-04-19 10:44:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-19 10:46:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (st.empty())
                    return false;
                if (st.top() == '(' && c == ')' || st.top() == '[' && c == ']' || st.top() == '{' && c == '}' )
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};