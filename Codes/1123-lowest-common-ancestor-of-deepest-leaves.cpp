/*
 * @Author: LetMeFly
 * @Date: 2023-09-06 22:43:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-06 22:49:44
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
typedef pair<TreeNode*, int> pti;
class Solution {
private:
    pti dfs(TreeNode* root) {
        if (!root) {
            return {nullptr, 0};
        }
        pti left = dfs(root->left);
        pti right = dfs(root->right);
        if (left.second == right.second) {
            return {root, left.second + 1};
        }
        else if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        else {
            return {left.first, left.second + 1};
        }
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};