/*
 * @Author: LetMeFly
 * @Date: 2022-09-27 08:51:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-27 09:19:21
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
// class Solution {
// public:
//     int rob(TreeNode* root) {
//         unordered_map<TreeNode*, int> node2num;
//         int cntNum = 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         while (q.size()) {
//             TreeNode* thisNode = q.front();
//             q.pop();
//             node2num[thisNode] = cntNum++;
//             if (thisNode->left)
//                 q.push(thisNode->left);
//             if (thisNode->right)
//                 q.push(thisNode->right);
//         }
//         vector<int> rob(cntNum, 0);
//         vector<int> notRob(cntNum, 0);

//     }
// };

class Solution {
private:
    pair<int, int> chooseOrNot(TreeNode* root) {  // <选择，不选>节点root的情况下的最大打劫值
        if (!root)
            return {0, 0};
        pair<int, int> left = chooseOrNot(root->left);
        pair<int, int> right = chooseOrNot(root->right);
        return {left.second + right.second + root->val, max(left.first, left.second) + max(right.first, right.second)};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> state = chooseOrNot(root);
        return max(state.first, state.second);
    }
};