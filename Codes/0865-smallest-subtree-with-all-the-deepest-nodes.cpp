/*
 * @Author: LetMeFly
 * @Date: 2026-01-09 13:11:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-09 13:19:41
 */
#if defined(_WIN32) || defined(__APPLE__)
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
typedef pair<TreeNode*, int> result;
class Solution {
private:
    result dfs(TreeNode* root) {
        result left = root->left ? dfs(root->left) : result{nullptr, 0};
        result right = root->right ? dfs(root->right) : result{nullptr, 0};
        TreeNode* node = left.second == right.second ? root : (left.second > right.second ? left.first : right.first);
        return {node, max(left.second, right.second) + 1};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};