/*
 * @Author: LetMeFly
 * @Date: 2024-07-22 22:25:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-22 23:51:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

# ifdef FirstTry  // Error: 例如7和2可以互相炸，dfs(2) = 2，此时dfs(7)时会直接加上cache[2]的2，相当于7算了两次
typedef long long ll;
class Solution {
private:
    vector<int> cache;
    vector<bool> visited;
    vector<vector<int>> graph;

    int dfs(int x) {
        if (cache[x]) {
            return cache[x];
        }
        if (x == 7) {
            printf("x = 7\n");  //******************
        }
        cache[x] = 1;
        visited[x] = true;
        for (int nextNode : graph[x]) {
            if (!visited[nextNode]) {
                cache[x] += dfs(nextNode);
            }
        }
        return cache[x];
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        graph = vector<vector<int>>(n);
        for (int i = 0; i < bombs.size(); i++) {
            for (int j = i + 1; j < bombs.size(); j++) {
                ll d2 = (ll)(bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + (ll)(bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
                if (d2 <= (ll)bombs[i][2] * bombs[i][2]) {  // i能引爆j
                    graph[i].push_back(j);
                }
                if (d2 <= (ll)bombs[j][2] * bombs[j][2]) {
                    graph[j].push_back(i);
                }
            }
        }
        debug(graph);  //*****

        int ans = 1;
        cache = vector<int>(n);
        for (int i = 0; i < n; i++) {
            // visited.resize(n, false);  // 不可
            visited = vector<bool>(n);
            ans = max(ans, dfs(i));
            if (dfs(i) == 4) {    //****
                printf("dfs(%d) = %d\n", i, 4);  //****
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 每次清空cache TODO: if can 拓扑排序
typedef long long ll;
class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> graph;

    int dfs(int x) {
        visited[x] = true;
        int ans = 1;
        for (int nextNode : graph[x]) {
            if (!visited[nextNode]) {
                ans += dfs(nextNode);
            }
        }
        return ans;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        graph = vector<vector<int>>(n);
        for (int i = 0; i < bombs.size(); i++) {
            for (int j = i + 1; j < bombs.size(); j++) {
                ll d2 = (ll)(bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + (ll)(bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
                if (d2 <= (ll)bombs[i][2] * bombs[i][2]) {  // i能引爆j
                    graph[i].push_back(j);
                }
                if (d2 <= (ll)bombs[j][2] * bombs[j][2]) {
                    graph[j].push_back(i);
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            visited = vector<bool>(n);
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
int main() {
    vector<pair<string, int>> tests = {
        {"[[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]", 5},
        {"[[2,1,3],[6,1,4]]", 2},
        {"[[868,658,84],[82,386,48],[464,157,11],[422,654,85],[864,418,84],[366,314,72],[955,270,60],[460,98,60],[824,147,38],[580,660,27],[423,102,73],[317,471,74]]", 3}
    };
    // string s = "[[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]";  // 5
    // string s = "[[2,1,3],[6,1,4]]";  // 2
    // string s = "[[868,658,84],[82,386,48],[464,157,11],[422,654,85],[864,418,84],[366,314,72],[955,270,60],[460,98,60],[824,147,38],[580,660,27],[423,102,73],[317,471,74]]";  // 3
    for (auto [s, ans] : tests) {
        vector<vector<int>> bombs= stringToVectorVector(s);
        Solution sol;
        assert(sol.maximumDetonation(bombs) == ans);
    }
    return 0;
}
#endif