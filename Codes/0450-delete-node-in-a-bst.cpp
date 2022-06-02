/*
 * @Author: LetMeFly
 * @Date: 2022-06-02 09:21:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-02 09:40:58
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
#ifdef FirstTry  // RE
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)  // 节点为空
            return root;
        if (key > root->val)  { // 要搜索节点在右子树
            root->right = deleteNode(root->right, key);
            return root;
        }
        else if (key < root->val)  { // 要搜索节点在左子树
            root->left = deleteNode(root->left, key);
            return root;
        }
        else {  // 找到了要搜索的节点
            if (!root->left && !root->right) {  // 要删节点是叶节点
                delete root;
                return nullptr;
            }
            else if (!root->left) {  // 要删节点没有左节点
                TreeNode* ans = root->right;
                delete root;
                return ans;
            }
            else if (!root->right) {  // 要删节点没有右节点
                TreeNode* ans = root->left;
                delete root;
                return ans;
            }
            else {  // 要删节点有左右子节点
                TreeNode* p = root->right;
                while (p->left)  // 寻找右子树的最左节点
                    p = p->left;
                root->right = deleteNode(root->right, p->val);
                p->left = root->left;
                p->right = root->right;
                delete root;
                return p;
            }
        }
    }
};
#else  // FirstTry
// Copy From LeetCode
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val == key) {
            if (!root->left && !root->right) {
                return nullptr;
            }
            if (!root->right) {
                return root->left;
            }
            if (!root->left) {
                return root->right;
            }
            TreeNode *successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            root->right = deleteNode(root->right, successor->val);
            successor->right = root->right;
            successor->left = root->left;
            return successor;
        }
        return root;
    }
};
#endif  // FirstTry