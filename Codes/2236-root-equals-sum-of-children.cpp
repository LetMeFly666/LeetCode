/*
 * @Author: LetMeFly
 * @Date: 2023-08-20 09:07:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-20 09:08:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};