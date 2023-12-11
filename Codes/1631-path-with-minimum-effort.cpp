/*
 * @Author: LetMeFly
 * @Date: 2023-12-11 09:21:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-11 17:32:12
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

const int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<pair<int, int>>> graph(n * m);  // graph[i]: [[j, 5], [k, 3]]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int d = 0; d < 4; d++) {
                    int ti = i + directions[d][0], tj = j + directions[d][1];
                    if (ti < 0 || ti >= n || tj < 0 || tj >= m) {
                        continue;
                    }
                    int diff = abs(heights[i][j] - heights[ti][tj]);
                    int x = i * m + j, y = ti * m + tj;
                    graph[x].push_back({y, diff});
                }
            }
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({0, 0});
        vector<int> ans(n * m, 1e9);  // 从0到i的最大绝对值之差
        ans[0] = 0;
        while (pq.size()) {
            auto [index, diff] = pq.top();
            pq.pop();
            // printf("index = %d\n", index);  //******************
            for (auto [toIndex, toDiff] : graph[index]) {
                int nextDiff = max(diff, toDiff);
                if (ans[toIndex] > nextDiff) {
                    ans[toIndex] = nextDiff;
                    pq.push({toIndex, nextDiff});
                    // printf("toIndex = %d\n", toIndex);  //******************
                }
            }
        }
        // for (int i = 0; i < n * m; i++) {  //*********************
        //     printf("ans[%d] = %d\n", i, ans[i]);
        // }
        return ans.back();
    }
};

#ifdef _WIN32
/*
[[1,10,6,7,9,10,4,9]]
*/

/*
[[4,3,4,10,5,5,9,2],[10,8,2,10,9,7,5,6],[5,8,10,10,10,7,4,2],[5,1,3,1,1,3,1,9],[6,4,10,6,10,9,4,6]]

4  3 4  10 5  5 9 2
10 8 2  10 9  7 5 6
5  8 10 10 10 7 4 2
5  1 3  1  1  3 1 9
6  4 10 6  10 9 4 6
*/

int main() {
    string s;
    Solution sol;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.minimumEffortPath(v) << endl;
    }
    return 0;
}
#endif