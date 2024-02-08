/*
 * @Author: LetMeFly
 * @Date: 2024-02-08 12:02:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-08 12:07:35
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
class Solution {
private:
    int x, y;
    TreeNode* x_father, *y_father;
    int x_depth, y_depth;

    void dfs(TreeNode* root, int depth, TreeNode* father) {
        if (!root) {
            return ;
        }
        if (root->val == x) {
            x_father = father;
            x_depth = depth;
        }
        if (root->val == y) {
            y_father = father;
            y_depth = depth;
        }
        dfs(root->left, depth + 1, root);
        dfs(root->right, depth + 1, root);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x, this->y = y;
        dfs(root, 0, nullptr);
        return x_father != y_father && x_depth == y_depth;
    }
};