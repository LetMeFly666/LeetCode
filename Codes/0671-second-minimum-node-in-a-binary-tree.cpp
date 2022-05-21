/*
 * @Author: LetMeFly
 * @Date: 2021-07-27 09:15:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-27 09:23:00
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

int val[30];
int len;
class Solution
{
private:
    int getVal(TreeNode* thisNode)
    {
        if(thisNode->left)
        {
            return val[len++]=min(getVal(thisNode->left), getVal(thisNode->right));
        }
        else
        {
            return val[len++]=thisNode->val;
        }        
    }
public:
    int findSecondMinimumValue(TreeNode *root)
    {
        len=0;
        getVal(root);
        sort(val, val+len);
        int m=val[0];
        for(int i=1;i<len;i++)
        {
            if(val[i]>m)
            {
                return val[i];
            }
        }
        return -1;
    }
};