/*
 * @Author: LetMeFly
 * @Date: 2023-05-22 09:32:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-22 09:44:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, long long limit) {
        limit -= root->val;
        if (!root->left && !root->right) {  // 叶节点
            if (limit <= 0) {
                return root;
            }
            else {
                // delete root;
                return nullptr;
            }
        }
        TreeNode* left = root->left ? sufficientSubset(root->left, limit) : nullptr;
        TreeNode* right = root->right ? sufficientSubset(root->right, limit) : nullptr;
        if (!left && !right) {
            // delete root;
            return nullptr;
        }
        else {
            root->left = left;
            root->right = right;
            return root;
        }
    }
};