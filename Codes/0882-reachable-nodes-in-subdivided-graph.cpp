/*
 * @Author: LetMeFly
 * @Date: 2022-11-26 21:36:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-26 23:01:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error

#define two2one(a, b) (a * 10000 + b)
#define pair2int(a) two2one(a[0], a[1])
typedef pair<int, int> pii;
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, int> visited;  // <node, maxVisited>
        unordered_map<int, int> myEdges;  // <node, chainLength>
        unordered_set<int> visitedNode;
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            myEdges[pair2int(edge)] = edge[2];
            myEdges[two2one(edge[1], edge[0])] = edge[2];
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ans = 1;
        visitedNode.insert(0);
        queue<pii> q;  // <fromNode, remainStep>
        q.push({0, maxMoves});
        while (q.size()) {
            pii thisNode = q.front();
            q.pop();
            int from = thisNode.first;
            int remainStep = thisNode.second;
            for (int to : graph[from]) {
                int alreadyStep = visited[two2one(from, to)];
                int maxStep = myEdges[two2one(from, to)];
                int anotherSideAlready = visited[two2one(to, from)];
                if (remainStep > alreadyStep && alreadyStep + anotherSideAlready < maxStep) {
                    int thisGoOnEdge = min(remainStep, maxStep);
                    ans += thisGoOnEdge - alreadyStep;  // TODO: 减去另一边。没有减去另一边走过的，为什么结果还是比答案小
                    visited[two2one(from, to)] = thisGoOnEdge;
                    if (remainStep > maxStep) {  // can to another side
                        if (!visitedNode.count(to)) {
                            ans++;
                            thisGoOnEdge++;
                            visitedNode.insert(to);
                        }
                        if (remainStep > thisGoOnEdge) {
                            q.push({to, remainStep - thisGoOnEdge});
                        }
                    }
                }
            }
        }
        return ans;
    }
};

#else  // FirstTry
// SecondTry  // Copy From https://leetcode.cn/problems/reachable-nodes-in-subdivided-graph/solutions/1990614/xi-fen-tu-zhong-de-ke-dao-da-jie-dian-by-u8m1/
class Solution {
public:
    int encode(int u, int v, int n) {
        return u * n + v;
    }

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adList(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], nodes = edge[2];
            adList[u].emplace_back(v, nodes);
            adList[v].emplace_back(u, nodes);
        }

        unordered_map<int, int> used;
        unordered_set<int> visited;
        int reachableNodes = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        while (!pq.empty() && pq.top().first <= maxMoves) {
            auto [step, u] = pq.top();
            pq.pop();
            if (visited.count(u)) {
                continue;
            }
            visited.emplace(u);
            reachableNodes++;
            for (auto [v, nodes] : adList[u]) {
                if (nodes + step + 1 <= maxMoves && !visited.count(v)) {
                    pq.emplace(nodes + step + 1, v);
                }
                used[encode(u, v, n)] = min(nodes, maxMoves - step);
            }
        }

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], nodes = edge[2];
            reachableNodes += min(nodes, used[encode(u, v, n)] + used[encode(v, u, n)]);
        }
        return reachableNodes;
    }
};
#endif  // FirstTry

/*
[[0,1,10],[0,2,1],[1,2,2]]
6
3

*/

/*
[[3,4,8],[0,1,3],[1,4,0],[1,2,3],[0,3,2],[0,4,10],[1,3,3],[2,4,3],[2,3,3],[0,2,10]]
7
5

*/

#ifdef _WIN32
int main() {
    string s;
    int a, b;
    while (cin >> s >> a >> b) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.reachableNodes(v, a, b) << endl;
    }
    return 0;
}
#endif