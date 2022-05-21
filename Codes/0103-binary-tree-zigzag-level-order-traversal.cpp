/*
 * @Author: LetMeFly
 * @Date: 2022-04-19 10:48:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-19 10:54:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<TreeNode*, int> pii;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<pii> q;
        q.push({root, 0});
        vector<int> thisV;
        int lastLayer = 0;
        while (q.size()) {
            auto [node, layer] = q.front();
            q.pop();
            if (!node)
                continue;
            if (layer != lastLayer) {
                ans.push_back(thisV);
                thisV.clear();
                lastLayer = layer;
            }
            thisV.push_back(node->val);
            q.push({node->left, layer + 1});
            q.push({node->right, layer + 1});
        }
        ans.push_back(thisV);
        for (int i = 0; i < ans.size(); i++) {
            if (i % 2) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};