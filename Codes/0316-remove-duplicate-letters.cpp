/*
 * @Author: LetMeFly
 * @Date: 2022-09-23 14:57:40
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-23 15:03:02
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string removeDuplicateLetters(string& s) {
        // 预处理，统计每个字符出现了多少次
        int remain[26] = {0};
        for (char& c : s) {
            remain[c - 'a']++;
        }
        // 单调栈开始
        stack<char> st;
        bool isInStack[26] = {false};
        for (char& c : s) {
            remain[c - 'a']--;
            if (isInStack[c - 'a'])
                continue;
            while (st.size() && st.top() > c && remain[st.top() - 'a']) {
                isInStack[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            isInStack[c - 'a'] = true;
        }
        string ans;
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};