/*
 * @Author: LetMeFly
 * @Date: 2022-07-03 15:37:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-03 15:54:21
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
typedef vector<int>::iterator it;
class Solution {
private:
    unordered_map<int, it> ma;
    it houBegin, houEnd;

    TreeNode* buildTree(it zhongBegin, it zhongEnd) {
        if (zhongBegin >= zhongEnd)
            return nullptr;
        TreeNode* root = new TreeNode(*--houEnd);
        it place = ma[*houEnd];
        root->right = buildTree(place + 1, zhongEnd);
        root->left = buildTree(zhongBegin, place);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (it i = inorder.begin(); i != inorder.end(); i++) {
            ma[*i] = i;
        }
        houBegin = postorder.begin(), houEnd = postorder.end();
        return buildTree(inorder.begin(), inorder.end());
    }
};