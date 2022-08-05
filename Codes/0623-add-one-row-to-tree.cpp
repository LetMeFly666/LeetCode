/*
 * @Author: LetMeFly
 * @Date: 2022-08-05 15:33:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-05 15:53:50
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
#ifdef FirstAndSecondTry  // BFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        int nowLayer = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int thisLayerNodesNum = q.size();
            nowLayer++;
            for (int i = 0; i < thisLayerNodesNum; i++) {
                TreeNode* thisNode = q.front();
                q.pop();
                if (nowLayer == depth) {
                    TreeNode* leftNewNode = new TreeNode(val, thisNode->left, nullptr);
                    TreeNode* rightNewNode = new TreeNode(val, nullptr, thisNode->right);
                    thisNode->left = leftNewNode, thisNode->right = rightNewNode;

                    #ifdef FirstTry

                    if (leftNewNode->left) {
                        q.push(leftNewNode->left);
                    }
                    if (rightNewNode->right) {
                        q.push(rightNewNode->right);
                    }

                    #endif  // FirstTry
                }
                else {
                    if (thisNode->left) {
                        q.push(thisNode->left);
                    }
                    if (thisNode->right) {
                        q.push(thisNode->right);
                    }
                }
            }
            
            #ifdef FirstTry
            #else  // FirstTry
            // SecondTry
            if (nowLayer == depth) {
                break;  // 直接break掉即可
            }
            #endif  // FirstTry
        }
        return root;
    }
};
#else  // FirstAndSecondTry
// ThirdTry  // DFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) {
            return nullptr;
        }
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        if (depth == 2) {  // 不必再继续递归
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
        }
        else {
            addOneRow(root->left, val, depth - 1);
            addOneRow(root->right, val, depth - 1);
        }
        return root;
    }
};
#endif  // FirstAndSecondTry