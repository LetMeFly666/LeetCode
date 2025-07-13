/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 16:44:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 16:57:27
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
拿当前min教练匹配剩下最min学员
*/
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0;
        for (int t = 0, p = 0; t < trainers.size() && p < players.size(); t++) {
            if (trainers[t] >= players[p]) {
                ans++, p++;
            }
        }
        return ans;
    }
};