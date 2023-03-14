/*
 * @Author: LetMeFly
 * @Date: 2023-03-14 13:26:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-14 13:30:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = wall.size();
        unordered_map<int, int> ma;
        for (vector<int>& line : wall) {
            int cntWidth = 0;
            for (int i = 0; i + 1 < line.size(); i++) {
                cntWidth += line[i];
                ma[cntWidth]++;
            }
        }
        for (auto& [loc, times] : ma) {
            ans = min(ans, (int)wall.size() - times);
        }
        return ans;
    }
};