/*
 * @Author: LetMeFly
 * @Date: 2022-05-29 10:13:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-29 11:00:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    TreeNode* reverse(TreeNode* X, TreeNode* Y, TreeNode* Z) {
        if (!Y)
            return X;
        TreeNode* ans = reverse(Y, Y->left, Y->right);
        Y->left = Z;
        Y->right = X;
        X->left = X->right = nullptr;
        if (Z) {
            Z->left = Z->right = nullptr;
        }
        return ans;
    }
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root)
            return root;
        return reverse(root, root->left, root->right);
    }
};