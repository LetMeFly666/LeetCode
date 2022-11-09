/*
 * @Author: LetMeFly
 * @Date: 2022-08-31 08:51:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-31 08:55:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int locPushed = 0, locPopped = 0;
        while (locPopped < popped.size()) {
            while (st.empty() || st.top() != popped[locPopped]) {
                if (locPushed == pushed.size())
                    return false;
                st.push(pushed[locPushed++]);
            }
            st.pop();
            locPopped++;
        }
        return true;
    }
};