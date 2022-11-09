/*
 * @Author: LetMeFly
 * @Date: 2022-11-05 09:28:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-05 09:37:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool parseBoolExpr(string& expression) {
        stack<char> st;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            if (expression[i] == '!' || expression[i] == '&' || expression[i] == '|' || expression[i] == 't' || expression[i] == 'f') {
                st.push(expression[i]);
            }
            else if (expression[i] == ')') {
                int cntT = 0, cntF = 0;
                while (st.top() == 't' || st.top() == 'f') {
                    if (st.top() == 't')
                        cntT++;
                    else
                        cntF++;
                    st.pop();
                }
                char op = st.top();
                st.pop();
                if (op == '&') {
                    st.push(cntF ? 'f' : 't');
                }
                else if (op == '|') {
                    st.push(cntT ? 't' : 'f');
                }
                else {
                    st.push(cntT ? 'f' : 't');
                }
            }
            // else will be “(”、“,”
        }
        return st.top() == 't';
    }
};