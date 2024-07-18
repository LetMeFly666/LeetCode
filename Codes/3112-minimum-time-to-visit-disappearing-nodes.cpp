/*
 * @Author: LetMeFly
 * @Date: 2024-07-18 09:35:18
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-18 10:39:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // TLE
class Solution {  // BFS，肯定会超时
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> ans(n, -1);
        queue<int> q;
        q.push(0);
        ans[0] = 0;
        while (q.size()) {
            for (int i = q.size(); i > 0; i--) {
                int thisNode = q.front();
                q.pop();
                int thisTime = ans[thisNode];
                for (auto[nextNode, length] : graph[thisNode]) {
                    int nextTime = thisTime + length;
                    if (nextTime >= disappear[nextNode]) {
                        continue;
                    }
                    if (ans[nextNode] == -1 || ans[nextNode] > nextTime) {
                        ans[nextNode] = nextTime;
                        // printf("%d's nextTime = %d\n", nextNode, nextTime);  //************ */
                        q.push(nextNode);
                    }
                }
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // Dijkstra
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> ans(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // [<time, toNode>, ...
        pq.push({0, 0});
        while (pq.size()) {
            auto [thisTime, thisNode] = pq.top();
            pq.pop();
            if (ans[thisNode] != -1) {
                continue;
            }
            ans[thisNode] = thisTime;
            for (auto [nextNode, length] : graph[thisNode]) {
                if (ans[nextNode] != -1 || thisTime + length >= disappear[nextNode]) {
                    continue;
                }
                pq.push({thisTime + length, nextNode});
            }
        }
        return ans;
    }
};
#endif  // FirstTry


#ifdef _WIN32
int main() {
    int n = 3;
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}};
    vector<int> disappear = {1, 1, 5};
    Solution sol;
    debug(sol.minimumTime(n, edges, disappear));
    return 0;
}
#endif