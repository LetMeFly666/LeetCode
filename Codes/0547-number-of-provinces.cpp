/*
 * @Author: LetMeFly
 * @Date: 2022-12-13 16:46:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-13 16:54:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                queue<int> q;
                q.push(i);
                ans++;
                while (q.size()) {
                    int thisNode = q.front();
                    q.pop();
                    for (int to = 0; to < n; to++) {
                        if (isConnected[thisNode][to] && !visited[to]) {
                            visited[to] = true;
                            q.push(to);
                        }
                    }
                }
            }
        }
        return ans;
    }
};