/*
 * @Author: LetMeFly
 * @Date: 2022-10-09 09:23:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-09 09:35:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


struct SpecialChar {  // 左括号 / 数值
    bool isLeft;  // 左括号？
    int val;  // 若不是左括号，则此val有效

    SpecialChar(bool isLeft, int val = 0): isLeft(isLeft), val(val) {};
};

class Solution {
public:
    int scoreOfParentheses(string& s) {
        stack<SpecialChar> st;
        for (char& c : s) {
            if (c == '(') {
                st.push(SpecialChar(true));
            }
            else {  // 必有左括号
                int s = 0;
                while (!st.top().isLeft) {
                    s += st.top().val;
                    st.pop();
                }
                st.pop();  // 对应左括号出栈
                st.push(SpecialChar(false, s ? s * 2 : 1));
            }
        }
        int ans = 0;
        while (st.size()) {
            ans += st.top().val;
            st.pop();
        }
        return ans;
    }
};