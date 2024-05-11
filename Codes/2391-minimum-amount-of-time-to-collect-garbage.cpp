/*
 * @Author: LetMeFly
 * @Date: 2024-05-11 09:31:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-11 09:44:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {  // MPG
        int ans = 0;
        int last[3] = {0};
        char collect[3] = {'M', 'P', 'G'};
        for (int i = 0; i < garbage.size(); i++) {
            ans += garbage[i].size();
            for (char c : garbage[i]) {
                for (int j = 0; j < 3; j++) {
                    if (c == collect[j]) {
                        last[j] = i;
                    }
                }
            }
        }
        // printf("ans = %d\nlast: [%d, %d, %d]\n", ans, last[0], last[1], last[2]);  //**************
        for (int i = 0; i < travel.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (last[j] >= i + 1) {
                    ans += travel[i];
                    // printf("last[%d] = %d, i + 1 = %d, ans = %d\n", j, last[j], i + 1, ans);  //*************
                }
            }
        }
        return ans;
    }
};