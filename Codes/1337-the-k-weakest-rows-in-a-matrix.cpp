/*
 * @Author: LetMeFly
 * @Date: 2021-08-01 10:32:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-01 10:39:05
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int n=mat.size(),m=mat[0].size();
        vector<int>ans;
        int s=0;
        bool already[100]={0};
        for(int i=0;i<n;i++)
            mat[i].push_back(0);
        m++;
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(mat[i][j]==0&&!already[i])
                {
                    already[i]=true;
                    ans.push_back(i);
                    s++;
                    if(s>=k)
                        return ans;
                }
            }
        }
        return ans; // leetcode必须返回一个，虽然没有必要
    }
};