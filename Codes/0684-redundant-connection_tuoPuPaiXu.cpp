/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 21:33:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 21:44:51
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<int> fa;

    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void union_(int x, int y) {
        fa[find(x)] = find(y);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        fa.resize(edges.size() + 1);
        for (int i = 1; i <= edges.size(); i++) {
            fa[i] = i;
        }
        // for (vector<int>& edge : edges) {
        //     union_(edge[0], edge[1]);
        // }
        // for (int i = edges.size() - 1; i > 0; i--) {
        //     if (find(edges[i][0]) == find(edges[i][1])) {
        //         return edges[i];
        //     }
        // }
        for (vector<int>& edge : edges) {
            if (find(edge[0]) == find(edge[1])) {
                return edge;
            } else {
                union_(edge[0], edge[1]);
            }
        }
        return {};  // FAKE RETURN
    }
};