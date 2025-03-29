/*
 * @Author: LetMeFly
 * @Date: 2025-03-29 10:47:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 11:33:25
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
/*
 0  1 2 3
[2,-1,3,1]

0-->2-->3-->1

*/
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
                printf("visited[%d] = %d, next: %d\n", i, visited[i], edges[i]);  // ************
                i = edges[i];
            }
            if (edges[i] != -1 && visited[i] >= begin) {
                printf("i = %d, edges[%d] = %d\n", i, i, edges[i]);  // ****
                // printf("cnt - begin = %d - %d = %d\n", cnt, begin, cnt - begin);  // *******
                printf("cnt - edges[i] = %d - %d = %d\n", cnt, edges[i], cnt - edges[i]);  // *******
                ans = max(ans, cnt - edges[i]);
            }
        }
        return ans;
    }
};


#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.longestCycle(v) << endl;
    }
    return 0;
}
#endif