/*
 * @Author: LetMeFly
 * @Date: 2023-08-25 11:05:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-25 11:08:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int goodNodes(TreeNode* root, int parentMax=-100000) {
        if (!root) {
            return 0;
        }
        int nowMax = max(parentMax, root->val);
        return (root->val >= parentMax) + goodNodes(root->left, nowMax) + goodNodes(root->right, nowMax);
    }
};