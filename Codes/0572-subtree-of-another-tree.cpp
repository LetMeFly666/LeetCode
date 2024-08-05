/*
 * @Author: LetMeFly
 * @Date: 2024-08-04 10:18:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-04 10:25:11
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
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a || !b) {
            return a == b;
        }
        return a->val == b->val && isSame(a->left, b->left) && isSame(a->right, b->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* thisNode = q.front();
            q.pop();
            if (isSame(thisNode, subRoot)) {
                return true;
            }
            if (thisNode->left) {
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                q.push(thisNode->right);
            }
        }
        return false;
    }
};