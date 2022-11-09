/*
 * @Author: LetMeFly
 * @Date: 2022-07-12 10:51:30
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-12 11:18:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
template<class Type>
void debug(vector<Type>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    puts("");
}
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
typedef tuple<TreeNode*, vector<int>, int> pii;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        queue<pii> q;
        if (root)
            q.push({root, {root->val}, root->val});
        while (q.size()) {
            TreeNode* root;
            vector<int> path;
            int sum;
            tie (root, path, sum) = q.front();
            dbg(root->val);
            debug(path);
            dbg(sum);
            q.pop();
            if (!root->left && !root->right) {
                if (sum == targetSum) {
                    ans.push_back(path);
                }
            }
            if (root->left) {
                path.push_back(root->left->val);
                sum += root->left->val;
                q.push({root->left, path, sum});
                path.erase(--path.end());
                sum -= root->left->val;
            }
            if (root->right) {
                path.push_back(root->right->val);
                sum += root->right->val;
                q.push({root->right, path, sum});
            }
        }
        return ans;
    }
};
#else  // FirstTry
typedef pair<TreeNode*, int> pii;
class Solution {
private:
    vector<vector<int>> ans;
    unordered_map<TreeNode*, TreeNode*> parent;

    void insertNewPath(TreeNode* leaf) {
        vector<int> path;
        while (true) {
            path.push_back(leaf->val);
            TreeNode* thisParent = parent[leaf];
            if (thisParent == leaf)
                break;
            leaf = thisParent;
        }        
        reverse(path.begin(), path.end());
        ans.push_back(path);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return {};
        parent[root] = root;
        queue<pii> q;
        q.push({root, root->val});
        while (q.size()) {
            auto[root, sum] = q.front();
            q.pop();
            if (!root->left && !root->right) {
                if (sum == targetSum)
                    insertNewPath(root);
            }
            if (root->left) {
                q.push({root->left, sum + root->left->val});
                parent[root->left] = root;
            }
            if (root->right) {
                q.push({root->right, sum + root->right->val});
                parent[root->right] = root;
            }
        }
        return ans;
    }
};
#endif  // FirstTry