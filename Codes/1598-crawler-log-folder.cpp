/*
 * @Author: LetMeFly
 * @Date: 2022-09-09 13:23:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-09 13:25:14
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int nowDepth = 0;
        for (string& thisLog : logs) {
            if (thisLog == "../") {
                nowDepth = max(nowDepth - 1, 0);
            }
            else if (thisLog == "./") {
                continue;
            }
            else {
                nowDepth++;
            }
        }
        return nowDepth;
    }
};