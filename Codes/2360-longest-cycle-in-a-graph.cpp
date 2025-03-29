/*
 * @Author: LetMeFly
 * @Date: 2025-03-29 10:47:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 11:08:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int cnt = 1;
        vector<int> visited(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            int begin = cnt;
            while (edges[i] != -1 && !visited[i]) {
                visited[i] = cnt++;
                i = edges[i];
            }
            if (edges[i] != -1) {
                ans = max(ans, cnt - begin);
            }
        }
        return ans;
    }
};