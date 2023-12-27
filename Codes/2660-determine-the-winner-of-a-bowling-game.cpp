/*
 * @Author: LetMeFly
 * @Date: 2023-12-27 15:08:39
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-27 15:12:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int getScore(vector<int>& v) {  // v: 1~1000
        if (v.size() == 1) {
            return v[0];
        }
        int ans = v[0] + (v[0] == 10 ? 2 : 1) * v[1];
        for (int i = 2; i < v.size(); i++) {
            ans += (v[i - 1] == 10 || v[i - 2] == 10 ? 2 : 1) * v[i];
        }
        return ans;
    }
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int v1 = getScore(player1), v2 = getScore(player2);
        return v1 == v2 ? 0 : v1 < v2 ? 2 : 1;
    }
};