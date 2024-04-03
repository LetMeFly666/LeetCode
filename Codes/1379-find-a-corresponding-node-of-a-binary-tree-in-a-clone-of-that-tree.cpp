/*
 * @Author: LetMeFly
 * @Date: 2024-04-03 12:57:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-03 13:01:32
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

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(cloned);
        while (true) {  // 一定会找到
            TreeNode* thisNode = q.front();
            q.pop();
            if (thisNode->val == target->val) {
                return thisNode;
            }
            if (thisNode->left) {
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                q.push(thisNode->right);
            }
        }
    }
};