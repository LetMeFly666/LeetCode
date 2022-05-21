/*
 * @Author: LetMeFly
 * @Date: 2022-05-16 09:40:43
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-16 09:59:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " : " << x << endl
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool found;
    bool nextIsAnswer;
    TreeNode* toFind;
    TreeNode* answerNode;
    void middle(TreeNode* root) {
        // static int times = 0;
        // dbg(++times);
        if (found)
            return;
        if (!root)
            return;
        middle(root->left);
        if (found)  // 这个必须加上，否则middle(root->left)后可能found就变成true了
            return;
        if (nextIsAnswer) {
            dbg(root->val);
            answerNode = root;
            found = true;
        }
        if (root == toFind) {
            nextIsAnswer = true;
        }
        middle(root->right);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        found = false;
        nextIsAnswer = false;
        toFind = p;
        answerNode = nullptr;
        middle(root);
        return answerNode;
    }
};