/*
 * @Author: LetMeFly
 * @Date: 2022-07-03 14:24:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-03 14:51:58
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
typedef pair<TreeNode*, int> pii;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<pii> q;
        int lastLayer = 0;
        q.push({root, 0});
        vector<vector<int>> ans;
        vector<int> thisAns;
        while (q.size()) {
            auto[p, thisLayer] = q.front();
            q.pop();
            if (!p)
                continue;
            if (thisLayer != lastLayer) {
                lastLayer = thisLayer;
                ans.push_back(thisAns);
                thisAns.clear();
            }
            thisAns.push_back(p->val);
            q.push({p->left, thisLayer + 1});
            q.push({p->right, thisLayer + 1});
        }
        ans.push_back(thisAns);
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // 针对C++的空间优化
typedef pair<TreeNode*, int> pii;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        int lastLayer = 0;
        queue<pii> q;
        q.push({root, 0});
        vector<vector<int>> ans;
        ans.push_back({});
        while (q.size()) {
            auto[p, thisLayer] = q.front();
            q.pop();
            if (!p)
                continue;
            if (thisLayer != lastLayer) {
                lastLayer = thisLayer;
                ans.push_back({});  // 这里不需要clear()了
            }
            ans[thisLayer].push_back(p->val);
            q.push({p->left, thisLayer + 1});
            q.push({p->right, thisLayer + 1});
        }
        // 这里也不需要push最后一层了
        return ans;
    }
};
#endif  // FirstTry