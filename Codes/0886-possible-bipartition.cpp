/*
 * @Author: LetMeFly
 * @Date: 2022-10-16 09:59:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-16 10:09:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto& v : dislikes) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n + 1, false);
        vector<int> node(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                node[i] = 1;
                unordered_set<int> appeared;
                appeared.insert(i);
                queue<int> q;
                q.push(i);
                while (q.size()) {
                    int thisNode = q.front();
                    q.pop();
                    for (int toNode : graph[thisNode]) {
                        if (!visited[toNode]) {  // 第一次遍历到
                            visited[toNode] = true;
                            node[toNode] = node[thisNode] == 1 ? 0 : 1;
                            appeared.insert(toNode);
                            q.push(toNode);
                        }
                        else {
                            if (appeared.count(toNode)) {  // 这俩点相连
                                if (node[thisNode] == node[toNode])
                                    return false;  // !!!!!!!!
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};