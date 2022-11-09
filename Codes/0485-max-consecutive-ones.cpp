/*
 * @Author: LetMeFly
 * @Date: 2022-11-01 21:31:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-01 21:33:18
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        bool lastIs1 = false;
        int nowCnt = 0;
        for(int i : nums) {
            if (i) {
                lastIs1 = true;
                nowCnt++;
            }
            else {
                if (lastIs1) {
                    lastIs1 = false;
                    ans = max(ans, nowCnt);
                    nowCnt = 0;
                }
            }
        }
        ans = max(ans, nowCnt);
        return ans;
    }
};