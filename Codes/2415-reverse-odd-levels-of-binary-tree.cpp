/*
 * @Author: LetMeFly
 * @Date: 2023-12-15 09:32:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-15 15:50:29
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            queue<TreeNode*> p = q;  // parent
            stack<TreeNode*> c;  // child
            if (!q.front()->left) {
                break;
            }
            while (n--) {
                TreeNode* thisNode = q.front();
                q.pop();
                c.push(thisNode->left);
                c.push(thisNode->right);
                q.push(thisNode->left);
                q.push(thisNode->left);
            }
            while (p.size()) {
                TreeNode* thisNode = p.front();
                p.pop();
                TreeNode* c1 = c.top();
                c.pop();
                TreeNode* c2 = c.top();
                c.pop();
                thisNode->left = c1;
                thisNode->right = c2;
            }
        }
        return root;
    }
};