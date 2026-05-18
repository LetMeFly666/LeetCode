/*
 * @Author: LetMeFly
 * @Date: 2026-05-18 21:34:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-18 21:43:19
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> visited(n);
        unordered_map<int, vector<int>> same;
        for (int i = 0; i < n; i++) {
            same[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int ans = 0;
        while (true) {
            int n = q.size();
            while (n--) {
                int now = q.front();
                q.pop();
                if (now == n - 1) {
                    return ans;
                }
                if (now - 1 >= 0 && !visited[now - 1]) {
                    q.push(now - 1);
                    visited[now - 1] = true;
                }
                if (now + 1 < n && !visited[now + 1]) {
                    q.push(now + 1);
                    visited[now + 1] = true;
                }
                if (same.count(arr[now])) {
                    for (int next : same[arr[now]]) {
                        if (!visited[next]) {
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                    same.erase(arr[now]);
                }
            }
            ans++;
        }
    }
};
