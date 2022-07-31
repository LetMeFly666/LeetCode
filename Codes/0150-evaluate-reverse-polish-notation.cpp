/*
 * @Author: LetMeFly
 * @Date: 2022-07-31 12:22:19
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-31 12:25:03
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                if (s == "+")
                    st.push(first + second);
                else if (s == "-")
                    st.push(first - second);
                else if (s == "*")
                    st.push(first * second);
                else if (s == "/")
                    st.push(first / second);
            }
            else {
                st.push(atoi(s.c_str()));
            }
        }
        return st.top();
    }
};