/*
 * @Author: LetMeFly
 * @Date: 2025-05-26 10:24:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-26 23:26:40
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> out(colors.size());
        vector<int> indegree(colors.size());
        for (vector<int>& edge: edges) {
            out[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < colors.size(); i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        vector<array<int, 26>> dp(colors.size());
        int ans = 0;
        while (q.size()) {
            int thisNode = q.front();
            q.pop();
            ans = max(ans, ++dp[thisNode][colors[thisNode] - 'a']);
            for (int nextNode : out[thisNode]) {
                indegree[nextNode]--;
                if (!indegree[nextNode]) {
                    q.push(nextNode);
                }
                for (int i = 0; i < 26; i++) {
                    dp[nextNode][i] = max(dp[nextNode][i], dp[thisNode][i]);
                }
            }
        }
        return q.size() ? -1 : ans;
    }
};