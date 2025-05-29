/*
 * @Author: LetMeFly
 * @Date: 2025-05-29 22:14:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-29 22:50:54
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<vector<int>> buildTree(vector<vector<int>>& edges) {
        vector<vector<int>> ans(edges.size() + 1);
        for (vector<int>& edge : edges) {
            ans[edge[0]].push_back(edge[1]);
            ans[edge[1]].push_back(edge[0]);
        }
        return ans;
    }

    vector<bool> tree2color(vector<vector<int>>& tree) {
        vector<bool> ans(tree.size());
        queue<array<int, 3>> q;  // [<lastNode, thisNode, color>, <...>, ...
        q.push({-1, 0, 0});
        while (q.size()) {
            auto [lastNode, thisNode, color] = q.front();
            q.pop();
            ans[thisNode] = color;
            for (int nextNode : tree[thisNode]) {
                if (nextNode != lastNode) {
                    q.push({thisNode, nextNode, color ? 0 : 1});
                }
            }
        }
        return ans;
    }

    pair<int, int> count01(vector<bool>& color) {
        pair<int, int> ans;
        for (bool b : color) {
            if (b) {
                ans.second++;
            } else {
                ans.first++;
            }
        }
        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> graph1 = move(buildTree(edges1)), graph2 = move(buildTree(edges2));
        vector<bool> color1 = tree2color(graph1), color2 = tree2color(graph2);
        auto [black1, white1] = count01(color1);
        auto [black2, white2] = count01(color2);
        int toAdd = max(black2, white2);
        black1 += toAdd, white1 += toAdd;
        vector<int> ans(color1.size());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = color1[i] ? white1 : black1;
        }
        return ans;
    }
};