/*
 * @Author: LetMeFly
 * @Date: 2022-03-19 15:14:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-19 15:22:37
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
public:
    string tree2str(TreeNode* root) {
        string ans = to_string(root->val);
        if (root->left) {
            ans += "(";
            ans += tree2str(root->left);
            ans += ")";
        }
        else if (root->right) {
            ans += "()";
        }
        if (root->right) {
            ans += "(" + tree2str(root->right) + ")";
        }
        return ans;
    }
};