/*
 * @Author: LetMeFly
 * @Date: 2024-05-10 16:00:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-10 16:00:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for (int t : batteryPercentages) {
            if (t - ans > 0) {
                ans++;
            }
        }
        return ans;
    }
};