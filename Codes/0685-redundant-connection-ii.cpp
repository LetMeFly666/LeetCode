/*
 * @Author: LetMeFly
 * @Date: 2024-11-03 16:09:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-03 16:52:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA
/*
[[4,2],[1,5],[5,2],[5,3],[2,4]]

+---+
↓   ↑
4-->2
    ↑
1-->5-->3


算法会返回[5,2]，其实答案是[4,2]

因此不能依据“去掉一条边”后是否有“孤立点”来判断去掉这条边是否可行
*/
class Solution {
private:
    vector<int> fa;

    bool couldRemoveThisEdge(vector<vector<int>>& edges, int index) {
        vector<bool> hasEdge(edges.size() + 1);
        for (int i = 0; i < edges.size(); i++) {
            if (i == index) {
                continue;
            }
            hasEdge[edges[i][0]] = hasEdge[edges[i][1]] = true;            
        }
        for (int i = 1; i <= edges.size(); i++) {
            if (!hasEdge[i]) {
                return false;
            }
        }
        return true;
    }

    vector<int> solution_indegree(vector<vector<int>>& edges, int node) {
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (edges[i][1] == node && couldRemoveThisEdge(edges, i)) {
                return edges[i];
            }
        }
        return {};  // FAKE RETURN
    }

    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void union_(int x, int y) {
        fa[find(x)] = find(y);
    }

    vector<int> solution_unionFind(vector<vector<int>>& edges) {
        fa.resize(edges.size() + 1);
        for (int i = 1; i <= edges.size(); i++) {
            fa[i] = i;
        }
        for (vector<int>& edge : edges) {
            if (find(edge[0]) == find(edge[1])) {
                return edge;
            } else {
                union_(edge[0], edge[1]);
            }
        }
        return {};  // FAKE RETURN
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<bool> inDegree(edges.size() + 1);
        for (vector<int>& edge : edges) {
            if (inDegree[edge[1]]) {  // 找到了入度为2的点
                return solution_indegree(edges, edge[1]);
            } else {
                inDegree[edge[1]] = true;
            }
        }
        return solution_unionFind(edges);
    }
};
#else  // FirstTry
// SecondTry  // 依据去掉一条边后是否有环判断去掉这条边是否可行
class Solution {
private:
    vector<int> fa;

    bool couldRemoveThisEdge(vector<vector<int>>& edges, int index) {
        initFa(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            if (i == index) {
                continue;
            }
            if (find(edges[i][0]) == find(edges[i][1])) {
                return false;
            }
            union_(edges[i][0], edges[i][1]);
        }
        return true;
    }

    vector<int> solution_indegree(vector<vector<int>>& edges, int node) {
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (edges[i][1] == node && couldRemoveThisEdge(edges, i)) {
                return edges[i];
            }
        }
        return {};  // FAKE RETURN
    }

    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void union_(int x, int y) {
        fa[find(x)] = find(y);
    }

    void initFa(int n) {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }

    vector<int> solution_unionFind(vector<vector<int>>& edges) {
        initFa(edges.size());
        for (vector<int>& edge : edges) {
            if (find(edge[0]) == find(edge[1])) {
                return edge;
            } else {
                union_(edge[0], edge[1]);
            }
        }
        return {};  // FAKE RETURN
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<bool> inDegree(edges.size() + 1);
        for (vector<int>& edge : edges) {
            if (inDegree[edge[1]]) {  // 找到了入度为2的点
                return solution_indegree(edges, edge[1]);
            } else {
                inDegree[edge[1]] = true;
            }
        }
        return solution_unionFind(edges);
    }
};
#endif  // FirstTry