/*
 * @Author: LetMeFly
 * @Date: 2024-02-16 10:42:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-16 10:45:09
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool ifReverse = false;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (q.size()) {
            ans.push_back({});
            for (int _ = q.size(); _ > 0; _--) {
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
            if (ifReverse) {
                reverse(ans.back().begin(), ans.back().end());
            }
            ifReverse = !ifReverse;
        }
        return ans;
    }
};