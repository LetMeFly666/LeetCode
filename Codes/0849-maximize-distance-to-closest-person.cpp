/*
 * @Author: LetMeFly
 * @Date: 2023-08-22 08:57:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-22 09:02:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=1;
        int lastSeat = -1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i]) {
                if (lastSeat == -1) {  // 首次
                    ans = max(ans, i);
                }
                else {
                    ans = max(ans, (i - lastSeat) / 2);
                }
                lastSeat = i;
            }
        }
        ans = max(ans, (int)seats.size() - lastSeat - 1);
        return ans;
    }
};