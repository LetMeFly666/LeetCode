/*
 * @Author: LetMeFly
 * @Date: 2026-01-06 10:19:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-06 10:22:09
 */
#if defined(_WIN32) || defined(__APPLE__)
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
    int maxLevelSum(TreeNode* root) {
        int ans = 1, maximum = -1000000000;
        int nowLayer = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            nowLayer++;
            int layerSum = 0;
            for (int i = q.size(); i > 0; i--) {
                TreeNode* thisNode = q.front();
                q.pop();
                layerSum += thisNode->val;
                if (thisNode->left) {
                    q.push(thisNode->left);
                }
                if (thisNode->right) {
                    q.push(thisNode->right);
                }
            }
            if (layerSum > maximum) {
                maximum = layerSum;
                ans = nowLayer;
            }
        }
        return ans;
    }
};