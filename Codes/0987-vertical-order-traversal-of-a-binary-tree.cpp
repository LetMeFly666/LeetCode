/*
 * @Author: LetMeFly
 * @Date: 2021-07-31 09:29:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-31 09:55:04
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//------------begin---------------

typedef pair<int,int> pii;
typedef vector<pii>vii;
vii v[2010];
int l,r;

void dfs(TreeNode *root, int x, int y)
{
    if(!root) return;
    l=min(l,y),r=max(r,y);
    v[y].push_back(pii(x,root->val));
    dfs(root->left, x+1, y-1);
    dfs(root->right, x+1, y+1);
}

vector<vector<int> >ans;

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        for(int i=0;i<2010;i++)v[i].clear();
        ans.clear();
        if(!root)return ans;
        l=2000,r=0;
        dfs(root,0,1000);
        for(int i=l;i<=r;i++)
        {
            sort(v[i].begin(),v[i].end());
            vector<int>thisVector;
            for(int j=0;j<v[i].size();j++)
                thisVector.push_back(v[i][j].second);
            ans.push_back(thisVector);
        }
        return ans;
    }
};