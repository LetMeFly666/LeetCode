/*
 * @Author: LetMeFly
 * @Date: 2024-07-17 12:33:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-17 13:01:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<bool> remain;
    vector<vector<int>> graph, distances;

    // 计算remain状态下任意被保留的两点之间的最短距离 并将结果保存在distances中
    void floyd() {
        for (int k = 0; k < remain.size(); k++) {
            if (!remain[k]) {
                continue;
            }
            for (int i = 0; i < remain.size(); i++) {
                if (!remain[i]) {
                    continue;
                }
                for (int j = 0; j < remain.size(); j++) {
                    if (!remain[j]) {
                        continue;
                    }
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        graph = vector<vector<int>>(n, vector<int>(n, 100001));
        remain.resize(n);
        for (vector<int>& road : roads) {
            graph[road[1]][road[0]] = graph[road[0]][road[1]] = min(graph[road[0]][road[1]], road[2]);
        }
        int ans = 0;
        for (int state = 0; state < (1 << n); state++) {
            for (int i = 0; i < n; i++) {
                remain[i] = state & (1 << i);
            }
            distances = graph;
            floyd();
            for (int i = 0; i < n; i++) {
                if (!remain[i]) {
                    continue;
                }
                for (int j = i + 1; j < n; j++) {
                    if (!remain[j]) {
                        continue;
                    }
                    if (distances[i][j] > maxDistance) {
                        goto loop;
                    }
                }
            }
            ans++;
            loop:;
        }
        return ans;
    }
};

#ifdef _WIN32
int main() {
    vector<vector<int>> roads = {{0, 1, 2}, {1, 2, 10}, {0, 2, 10}};
    Solution sol;
    cout << sol.numberOfSets(3, 5, roads) << endl;
    return 0;
}
#endif