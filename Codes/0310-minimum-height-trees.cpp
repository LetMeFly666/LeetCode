/*
 * @Author: LetMeFly
 * @Date: 2024-03-17 18:53:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-17 20:54:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error 这样多个点必剩两个
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degrees(n);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                degrees[i] = 0;
                q.push(i);
            }
        }
        while (q.size() > 2) {
            int thisNode = q.front();
            q.pop();
            for (int nextNode : graph[thisNode]) {
                if (!degrees[nextNode]) {
                    continue;
                }
                degrees[nextNode]--;
                if (degrees[nextNode] == 1) {
                    q.push(nextNode);
                    degrees[nextNode] = 0;
                }
            }
        }
        vector<int> ans = {q.front()};
        q.pop();
        if (q.size()) {
            ans.push_back(q.front());
        }
        return ans;
    }
};
#else  // FirstTry
#ifdef SecondTry  // Error! 1. n=1时需特判，因此时无度为1的节点 2. 不能只判断队列中元素是否不多于2，因为可能有节点还未被遍历到
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        vector<vector<int>> graph(n);
        for (vector<int>& v : edges) {
            degree[v[0]]++;
            degree[v[1]]++;
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (q.size() > 2) {
            for (int _ = q.size(); _ > 0; _--) {
                int thisNode = q.front();
                q.pop();
                for (int nextNode : graph[thisNode]) {
                    degree[nextNode]--;
                    if (degree[nextNode] == 1) {
                        q.push(nextNode);
                    }
                }
            }
        }
        vector<int> ans = {q.front()};
        q.pop();
        if (q.size()) {
            ans.push_back(q.front());
        }
        return ans;
    }
};
#else  // SecondTry
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {  // 这里不要忘了！要不然degree不为1
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> graph(n);
        for (vector<int>& v : edges) {
            degree[v[0]]++;
            degree[v[1]]++;
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        int remainNode = n;
        while (remainNode > 2) {
            for (int _ = q.size(); _ > 0; _--) {
                remainNode--;
                int thisNode = q.front();
                q.pop();
                for (int nextNode : graph[thisNode]) {
                    degree[nextNode]--;
                    if (degree[nextNode] == 1) {
                        q.push(nextNode);
                    }
                }
            }
        }
        vector<int> ans = {q.front()};
        q.pop();
        if (q.size()) {
            ans.push_back(q.front());
        }
        return ans;
    }
};
#endif  // SecondTry
#endif  // FirstTry

#ifdef _WIN32
/*
4
[[1,0],[1,2],[1,3]]

*/
/*
1
[]

*/
int main() {
    Solution sol;
    int n;
    string s;
    while (cin >> n >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        debug(sol.findMinHeightTrees(n, v));
    }
    return 0;
}
#endif