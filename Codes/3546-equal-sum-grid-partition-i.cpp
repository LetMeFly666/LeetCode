/*
 * @Author: LetMeFly
 * @Date: 2026-03-25 21:42:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-25 22:05:04
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

#define CHECK_AND_BREAK(now, sum) \
    if ((now) == (sum)) {         \
        return true;              \
    }                             \
    if ((now) > (sum)) {          \
        break;                    \
    }
typedef long long ll;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll sum = 0;
        for (vector<int>& row : grid) {
            for (int& v : row) {
                sum += v;
            }
        }
        if (sum % 2) {
            return false;
        }
        sum /= 2;

        ll now = 0;
        for (vector<int>& row : grid) {
            for (int& v : row) {
                now += v;
            }
            CHECK_AND_BREAK(now, sum)
        }

        now = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 0; i < grid.size(); i++) {
                now += grid[i][j];
            }
            CHECK_AND_BREAK(now, sum)
        }

        return false;
    }
};
