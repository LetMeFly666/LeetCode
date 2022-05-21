/*
 * @Author: LetMeFly
 * @Date: 2021-10-17 00:07:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-17 00:09:59
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void bianLi(TreeNode* root, vector<int>&a) {
    if (!root) return;
    a.push_back(root -> val);
    bianLi(root -> left, a);
    bianLi(root -> right, a);
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>a;
        bianLi(root, a);
        sort(a.begin(), a.end());
        return a[k - 1];
    }
};