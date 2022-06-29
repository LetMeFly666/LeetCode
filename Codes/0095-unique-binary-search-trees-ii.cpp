/*
 * @Author: LetMeFly
 * @Date: 2022-06-29 11:31:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-29 14:45:19
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

#ifdef FirstTry  // 写了一半
class Solution {
private:
    vector<TreeNode*> ans;

    void goon(TreeNode* root, vector<TreeNode*> nodes, vector<int> remainNum) {
        if (remainNum)
    }
public:
    vector<TreeNode*> generateTrees(int n) {

        return ans;
    }
};
#else  // FirstTry
// Second Try
class Solution {
private:
    vector<TreeNode*> generateTrees(int l, int r) {
        if (l > r)
            return {nullptr};
        vector<TreeNode*> roots;
        for (int rootNum = l; rootNum <= r; rootNum++) {
            vector<TreeNode*> leftTree = generateTrees(l, rootNum - 1);
            vector<TreeNode*> rightTree = generateTrees(rootNum + 1, r);
            for (TreeNode* thisLeft : leftTree) {
                for (TreeNode* thisRight : rightTree) {
                    TreeNode* thisRoot = new TreeNode(rootNum);
                    thisRoot->left = thisLeft;
                    thisRoot->right = thisRight;
                    roots.push_back(thisRoot);
                }
            }
        }
        return roots;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};
#endif  // FirstTry