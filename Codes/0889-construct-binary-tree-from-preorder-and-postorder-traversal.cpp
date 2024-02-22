/*
 * @Author: LetMeFly
 * @Date: 2024-02-22 10:05:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-02-22 10:21:12
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
private:
    unordered_map<int, vector<int>::iterator> ma;
    
    TreeNode* dfs(vector<int>::iterator preLeft, vector<int>::iterator preRight, vector<int>::iterator postLeft, vector<int>::iterator postRight) {
        if (preLeft >= preRight) {
            return nullptr;
        }
        if (preLeft + 1 == preRight) {  // 只有一个节点
            return new TreeNode(*preLeft);
        }
        int leftLength = leftLength = ma[*(preLeft + 1)] - postLeft + 1;  // 注意是*(preLeft + 1)
        return new TreeNode(
            *preLeft,
            dfs(preLeft + 1, preLeft + 1 + leftLength, postLeft, postLeft + leftLength),
            dfs(preLeft + 1 + leftLength, preRight, postLeft + leftLength, postRight - 1)
        );
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preOrder, vector<int>& postOrder) {
        for (vector<int>::iterator it = postOrder.begin(); it != postOrder.end(); it++) {
            ma[*it] = it;
        }
        return dfs(preOrder.begin(), preOrder.end(), postOrder.begin(), postOrder.end());
    }
};