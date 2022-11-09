/*
 * @Author: LetMeFly
 * @Date: 2022-09-09 13:38:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-09 13:48:16
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// typedef pair<bool, vector<TreeNode*>> pbv;
class Solution {
private:
    /*
        如果找到finding，就返回当前到finding的路径
        否则就返回空数组
    */
    vector<TreeNode*> dfs(TreeNode* root, TreeNode* finding) {
        if (!root)
            return {};
        if (root == finding)
            return {finding};
        vector<TreeNode*> left = dfs(root->left, finding);
        if (left.size()) {
            left.push_back(root);
            return left;
        }
        vector<TreeNode*> right = dfs(root->right, finding);
        if (right.size()) {
            right.push_back(root);
            return right;
        }
        return {};
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP = dfs(root, p);
        vector<TreeNode*> pathQ = dfs(root, q);
        unordered_set<TreeNode*> se;
        for (auto& thisNode : pathP) {
            se.insert(thisNode);
        }
        for (auto& thisNode : pathQ) {
            if (se.count(thisNode)) {
                return thisNode;
            }
        }
        return nullptr;  // FakeReturn
    }
};