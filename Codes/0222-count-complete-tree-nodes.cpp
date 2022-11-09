/*
 * @Author: LetMeFly
 * @Date: 2022-09-04 15:18:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-04 15:21:10
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
// FirstTry  // 广搜
class Solution {
public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (q.size()) {
            TreeNode* thisNode = q.front();
            q.pop();
            ans++;

            if (thisNode->left)
                q.push(thisNode->left);
            if (thisNode->right)
                q.push(thisNode->right);
        }
        return ans;
    }
};
// // 方法二：二分，CopyFrom官方题解
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if (root == nullptr) {
//             return 0;
//         }
//         int level = 0;
//         TreeNode* node = root;
//         while (node->left != nullptr) {
//             level++;
//             node = node->left;
//         }
//         int low = 1 << level, high = (1 << (level + 1)) - 1;
//         while (low < high) {
//             int mid = (high - low + 1) / 2 + low;
//             if (exists(root, level, mid)) {
//                 low = mid;
//             } else {
//                 high = mid - 1;
//             }
//         }
//         return low;
//     }

//     bool exists(TreeNode* root, int level, int k) {
//         int bits = 1 << (level - 1);
//         TreeNode* node = root;
//         while (node != nullptr && bits > 0) {
//             if (!(bits & k)) {
//                 node = node->left;
//             } else {
//                 node = node->right;
//             }
//             bits >>= 1;
//         }
//         return node != nullptr;
//     }
// };