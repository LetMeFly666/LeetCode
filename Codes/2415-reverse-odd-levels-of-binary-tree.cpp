/*
 * @Author: LetMeFly
 * @Date: 2023-12-15 09:32:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-15 09:38:21
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
        stack<pair<TreeNode*, bool>> parent;
        int layer = 0;
        q.push(root);
        while (q.size()) {
            int size = q.size();
            if (layer % 2) {

            }
            else {
                for (int i = 0; i < size; i++) {
                    TreeNode* thisNode = q.front();
                    q.pop();
                    if (thisNode->left) {
                        q.push(thisNode->left);
                        parent.push({thisNode, true});
                    }
                    if (thisNode->right) {
                        q.push(thisNode->right);
                        
                    }
                }
            }
        }
    }
};