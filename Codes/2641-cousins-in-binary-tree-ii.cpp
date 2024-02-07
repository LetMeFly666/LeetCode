/*
 * @Author: LetMeFly
 * @Date: 2024-02-07 10:02:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-07 10:16:39
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<pair<TreeNode*, TreeNode*>> v = {{root, nullptr}, };  // [<thisNode, broNode>, ...]
        while (v.size()) {
            int valSum = 0;
            vector<pair<TreeNode*, TreeNode*>> nextV;
            unordered_map<TreeNode*, int> originalVal;
            for (auto&& [thisNode, broNode] : v) {
                originalVal[thisNode] = thisNode->val;
                valSum += thisNode->val;
                if (thisNode->left) {
                    nextV.push_back({thisNode->left, thisNode->right});
                }
                if (thisNode->right) {
                    nextV.push_back({thisNode->right, thisNode->left});
                }
            }
            for (auto&& [thisNode, broNode] : v) {
                thisNode->val = valSum - thisNode->val - originalVal[broNode];
            }
            swap(v, nextV);  // 这里不可：memmove(&v, &nextV, nextV.size());
        }
        return root;
    }
};