/*
 * @Author: LetMeFly
 * @Date: 2021-08-05 10:45:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-05 11:12:58
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
// bool visited[1010];
// class Solution
// {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>> &graph)
//     {
//         int n=graph.size();
//         fi(i,0,n)visited[i]=0;
//         queue<int>q;
//         vector<int>ans;
//         fi(i,0,n)
//         {
//             if(graph[i].empty())
//             {
//                 visited[i]=true;
//                 q.push(i);
//             }
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n=graph.size();
        // fi(i,0,n)visited[i]=false;
        vector<vector<int>>v(n);
        // int du[n]={0};
        vector<int>du(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                v[graph[i][j]].push_back(i);
            }
            du[i]=graph[i].size();
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(!du[i])
            {
                q.push(i);
            }
        }
        // vector<int>ans;
        while(q.size())
        {
            int thisNum=q.front();
            q.pop();
            for(int i=0;i<v[thisNum].size();i++)
            {
                du[v[thisNum][i]]--;
                if(du[v[thisNum][i]]==0)
                {
                    q.push(v[thisNum][i]);
                    // ans.push_back(thisNum);
                }
            }
        }
        // sort(ans.begin(),ans.end());
        vector<int>ans;
        fi(i,0,n)if(!du[i])ans.push_back(i);
        return ans;
    }
};