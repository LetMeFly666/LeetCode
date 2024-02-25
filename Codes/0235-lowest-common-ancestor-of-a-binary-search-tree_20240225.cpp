/*
 * @Author: LetMeFly
 * @Date: 2024-02-25 10:48:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-25 10:50:29
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

class Solution {  // AC,83.74%,90.18%
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else {
                return root;
            }
        }
    }
};