/*
 * @Author: LetMeFly
 * @Date: 2022-08-03 16:21:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-03 16:32:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/* 
    请参考https://leetcode.cn/problems/orderly-queue/solution/by-huang-bin-bin-7-26r5/
    思路真不错
*/

class Solution {
public:
    string orderlyQueue(string& s, int k) {
        if (k != 1) {
            sort(s.begin(), s.end());
            return s;
        }
        vector<string> v;
        for (int i = 0; i < s.size(); i++) {
            v.push_back(s.substr(i, s.size() - i) + s.substr(0, i));
        }
        sort(v.begin(), v.end());
        return v[0];
    }
};