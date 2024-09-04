/*
 * @Author: LetMeFly
 * @Date: 2024-09-01 14:55:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-09-01 14:57:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for (int i = startTime.size() - 1; i >= 0; i--) {
            ans += startTime[i] <= queryTime && endTime[i] >= queryTime;
        }
        return ans;
    }
};