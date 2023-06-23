/*
 * @Author: LetMeFly
 * @Date: 2023-06-23 07:41:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-23 07:42:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int value(string& s) {
        int ans = 0;
        for (char c : s) {
            if (c < '0' || c > '9') {
                return s.size();
            }
            ans = ans * 10 + c - '0';
        }
        return ans;
    }
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (string& s : strs) {
            ans = max(ans, value(s));
        }
        return ans;
    }
};