/*
 * @Author: LetMeFly
 * @Date: 2022-08-19 08:27:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-19 08:29:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for (int i = startTime.size() - 1; i >= 0; i--) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ans++;
        }
        return ans;
    }
};