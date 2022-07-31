/*
 * @Author: LetMeFly
 * @Date: 2022-07-31 10:16:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-31 10:20:18
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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = -1;
        
        int nowLayer = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int thisLayerNum = q.size();  // 这一层有几个元素
            int thisSum = 0;
            for (int i = 0; i < thisLayerNum; i++) {
                TreeNode* thisNode = q.front();
                q.pop();
                thisSum += thisNode->val;
                if (thisNode->left)
                    q.push(thisNode->left);
                if (thisNode->right)
                    q.push(thisNode->right);
            }
            if (thisSum > maxSum) {
                maxSum = thisSum;
                ans = nowLayer;
            }
            nowLayer++;
        }

        return ans;
    }
};