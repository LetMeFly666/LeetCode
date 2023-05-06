/*
 * @Author: LetMeFly
 * @Date: 2023-05-06 09:42:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-06 09:46:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> ma = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        int cnt[5] = {0};
        int nowFrog = 0;
        int ans = 0;
        for (char c : croakOfFrogs) {
            int th = ma[c];
            if (th == 0) {  // 新青蛙
                nowFrog++;
                ans = max(ans, nowFrog);
                cnt[0]++;
            }
            else {  // 老青蛙
                if (!cnt[th - 1]) {
                    return -1;
                }
                cnt[th - 1]--;
                if (th == 4) {  // 这个青蛙叫完了
                    nowFrog--;
                }
                else {
                    cnt[th]++;
                }
            }
        }
        return nowFrog ? -1 : ans;
    }
};