/*
 * @Author: LetMeFly
 * @Date: 2023-09-14 09:59:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-14 10:07:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<int> se;
        for (auto& q : queens) {
            se.insert(q[0] * 100 + q[1]);
        }

        vector<vector<int>> ans;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (!dx && !dy) {
                    continue;
                }
                int nowX = king[0], nowY = king[1];
                while (nowX + dx >= 0 && nowX + dx < 8 && nowY + dy >= 0 && nowY + dy < 8) {
                    nowX += dx, nowY += dy;
                    if (se.count(nowX * 100 + nowY)) {
                        ans.push_back({nowX, nowY});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};