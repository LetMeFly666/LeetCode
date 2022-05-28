/*
 * @Author: LetMeFly
 * @Date: 2022-05-28 10:31:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-28 10:36:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// 原语（primitive）
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int left = 0;  // 当前有几个未配对的左括号
        for (char& c : s) {
            if (c == '(') {
                if (left) {
                    ans += '(';
                }
                left++;
            }
            else {
                left--;
                if (left) {
                    ans += ')';
                }
            }
        }
        return ans;
    }
};