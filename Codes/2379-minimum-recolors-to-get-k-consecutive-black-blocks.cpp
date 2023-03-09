/*
 * @Author: LetMeFly
 * @Date: 2023-03-09 09:04:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-09 09:06:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumRecolors(string& blocks, int k) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += blocks[i] == 'W';
        }
        int ans = cnt;
        for (int i = k; i < blocks.size(); i++) {
            cnt += blocks[i] == 'W';
            cnt -= blocks[i - k] == 'W';
            ans = min(ans, cnt);
        }
        return ans;
    }
};