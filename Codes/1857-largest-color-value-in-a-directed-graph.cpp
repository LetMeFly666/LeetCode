/*
 * @Author: LetMeFly
 * @Date: 2025-05-26 10:24:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-26 10:30:56
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> inNodes(edges.size() + 1);
        vector<int> out(edges.size() + 1);
        for (vector<int>& edge : edges) {
            inNodes[edge[1]].push_back(edge[0]);
            out[edge[1]]++;
        }
        vector<array<int, 26>> dp(edges.size() + 1);
        queue<int> q;
        for (int i = 0; i <= edges.size(); i++) {
            if (!out[i]) {
                q.push(i);
            }
        }
        while (q.size()) {
            int thisNode = q.front();
            dp[thisNode][colors[thisNode] - 'a']++;
            q.pop();
            for (int inNode : inNodes[thisNode]) {
                out[inNode]--;
                if (!out[inNode]) {
                    q.push(inNode);
                }
                for (int i = 0; i < 26; i++) {
                    dp[inNode][i] += dp[thisNode][i];
                }
            }
        }
        if (q.size()) {
            return -1;
        }
        int ans = 0;
        for (array<int, 26>& a : dp) {
            for (int t : a) {
                ans = max(ans, t);
            }
        }
        return ans;
    }
};