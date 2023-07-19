/*
 * @Author: LetMeFly
 * @Date: 2023-07-19 08:46:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-19 08:54:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // ↑→↓←

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> se;
        for (auto& obstacle : obstacles) {
            se.insert(obstacle[0] * 60001 + obstacle[1]);  // 30001不可，会无法通过最后一组数据，因为存在负数
        }

        int nowDirection = 0, x = 0, y = 0;
        int ans = 0;
        for (int t : commands) {
            if (t == -2) {
                nowDirection = (nowDirection + 3) % 4;
            }
            else if (t == -1) {
                nowDirection = (nowDirection + 1) % 4;
            }
            else {
                for (int i = 0; i < t; i++) {
                    int tx = x + directions[nowDirection][0], ty = y + directions[nowDirection][1];
                    if (se.count(tx * 60001 + ty)) {
                        break;
                    }
                    x = tx, y = ty;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};