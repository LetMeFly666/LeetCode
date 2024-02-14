/*
 * @Author: LetMeFly
 * @Date: 2024-02-14 10:06:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-14 10:09:52
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (q.size()) {
            ans.push_back({});
            for (int i = q.size(); i > 0; i--) {
                TreeNode* thisNode = q.front();
                q.pop();
                ans.back().push_back(thisNode->val);
                if (thisNode->left) {
                    q.push(thisNode->left);
                }
                if (thisNode->right) {
                    q.push(thisNode->right);
                }
            }
        }
        return ans;
    }
};