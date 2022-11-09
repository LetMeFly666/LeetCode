/*
 * @Author: LetMeFly
 * @Date: 2022-08-17 08:32:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-17 08:33:22
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
    int deepestLeavesSum(TreeNode* root) {  // root not null
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            ans = 0;
            for (int i = q.size(); i > 0; i--) {
                TreeNode* thisNode = q.front();
                q.pop();
                ans += thisNode->val;
                if (thisNode->left)
                    q.push(thisNode->left);
                if (thisNode->right)
                    q.push(thisNode->right);
            }
        }
        return ans;
    }
};