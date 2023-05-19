/*
 * @Author: LetMeFly
 * @Date: 2023-05-19 19:35:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-19 19:51:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_map<char, int> ma;
    
    int dfs() {
        int ans = 0;
        for (auto&& [c, times] : ma) {
            if (times > 0) {
                ans++;
                times--;
                // printf("times = %d, ma[%c] = %d\n", times, c, ma[c]);  //********
                ans += dfs();
                times++;
            }
        }
        return ans;
    }
public:
    int numTilePossibilities(string tiles) {
        for (char c : tiles) {
            ma[c]++;
        }
        return dfs();
    }
};