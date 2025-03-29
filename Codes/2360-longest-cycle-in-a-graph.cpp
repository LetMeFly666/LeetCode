/*
 * @Author: LetMeFly
 * @Date: 2025-03-29 10:47:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 11:16:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
[3,3,4,2,3]
 0 1 2 3 4

        1
        ↓
0-----> 3 <----- 4 
        |        ↑
        ↓        |
        2 -------+
*/
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int cnt = 1;
        vector<int> visited(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            // int begin = cnt;
            while (edges[i] != -1 && !visited[i]) {
                visited[i] = cnt++;
                printf("visited[%d] = %d, next: %d\n", i, visited[i], edges[i]);  // ************
                i = edges[i];
            }
            if (edges[i] != -1) {
                // printf("cnt - begin = %d - %d = %d\n", cnt, begin, cnt - begin);  // *******
                ans = max(ans, cnt - edges[i]);
            }
        }
        return ans;
    }
};