/*
 * @Author: LetMeFly
 * @Date: 2022-11-23 09:29:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-23 09:32:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> ma;
        for (int i = lowLimit; i <= highLimit; i++) {
            int n = i;
            int cnt = 0;
            while (n) {
                cnt += n % 10;
                n /= 10;
            }
            ma[cnt]++;
        }
        // int ans, M = -1;
        // for (auto&& [box, times] : ma) {
        //     if (times > M) {
        //         M = times;
        //         ans = box;
        //     }
        // }
        // return ans;
        int ans = 0;
        for (auto&& [box, times] : ma) {
            ans = max(ans, times);
        }
        return ans;
    }
};