/*
 * @Author: LetMeFly
 * @Date: 2022-04-16 16:28:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-16 16:33:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef pair<TreeNode*, int> pii;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<pii> q;
        q.push({root, 0});
        while (q.size()) {
            auto [node, thisLayer] = q.front();
            q.pop();
            if (!node)
                continue;
            if (thisLayer >= ans.size())
                ans.push_back(node->val);
            else
                ans[thisLayer] = node->val;
            q.push({node->left, thisLayer + 1});
            q.push({node->right, thisLayer + 1});
        }
        return ans;
    }
};