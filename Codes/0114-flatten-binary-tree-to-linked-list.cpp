/*
 * @Author: LetMeFly
 * @Date: 2022-07-12 13:12:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-12 13:36:31
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
#ifdef FirstTry
class Solution {
private:
    TreeNode* head;
    TreeNode* p;

    void addVal(int n) {
        p->right = new TreeNode(n);
        p = p->right;
    }

    void dfs(TreeNode* root) {
        if (!root)
            return;
        addVal(root->val);
        dfs(root->left);
        dfs(root->right);
    }
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        head = new TreeNode;
        p = head;
        dfs(root);
        *root = *(head->right);
    }
};
#else  // FirstTry
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* left4mostright = root->left;
                while (left4mostright->right)
                    left4mostright = left4mostright->right;
                left4mostright->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
#endif  // FirstTry