/*
 * @Author: LetMeFly
 * @Date: 2022-09-10 11:00:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-10 11:12:29
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
#ifdef FirstTry  // Half
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* fakeRoot = new TreeNode(0, root, nullptr);
        queue<TreeNode*> q;
        q.push(fakeRoot);
        while (q.size()) {
            TreeNode* thisNode = q.front();
            q.pop();
            if (thisNode->left && thisNode->left->val < low) {  // 左子小于low

            }
        }
        return fakeRoot->left;
    }
};
#else  // FirstTry
// SecondTry  // 官解
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val < low) {
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            return trimBST(root->left, low, high);
        } else {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
    }
};
#endif  // FirstTry