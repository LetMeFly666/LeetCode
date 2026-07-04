#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (vector<int>& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        
        int ans = 100000;
        vector<bool> visited(n + 1);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while (q.size()) {
            int a = q.front();
            q.pop();
            for (auto [b, d] : graph[a]) {
                if (!visited[b]) {
                    visited[b] = true;
                    q.push(b);
                    ans = min(ans, d);
                }
            }
        }
        return ans;
    }
};
