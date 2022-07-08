/*
 * @Author: LetMeFly
 * @Date: 2022-07-04 23:31:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-04 23:33:15
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
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l >= r)
            return nullptr;

        int mid = (l + r) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid);
        root->right = build(nums, mid + 1, r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};