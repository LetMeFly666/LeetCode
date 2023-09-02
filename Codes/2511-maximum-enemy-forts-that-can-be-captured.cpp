/*
 * @Author: LetMeFly
 * @Date: 2023-09-02 09:34:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-02 09:40:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int captureForts(vector<int>& forts) {  // 1和-1之间最多连续0的个数
        int ans = 0;
        int last = 2, cnt = 0;
        for (int i = 0; i < forts.size(); i++) {
            if (forts[i]) {
                if ( last != forts[i] && last != 2) {
                    ans = max(ans, cnt);
                }
                last = forts[i];
                cnt = 0;
            }
            else {  // 0
                cnt++;
            }
        }
        return ans;
    }
};