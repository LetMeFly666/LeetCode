/*
 * @Author: LetMeFly
 * @Date: 2021-08-06 14:40:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-06 14:57:03
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
const int N=12,M=1<<12;
bool visited[N][M]={0};
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n=graph.size();
        queue<tuple<int,int,int>>q;
        // bool visited[n][1<<n]={0};
        fi(i,0,n)
            fi(j,0,1<<n)
                visited[i][j]=false;
        fi(i,0,n)
        {
            q.emplace(i,1<<i,0);
            visited[i][1<<i]=true;
        }
        while(q.size())
        {
            auto [u,mask,dist]=q.front();
            q.pop();
            if(mask==(1<<n)-1)
                return dist;
            for(int v:graph[u])
            {
                int newMask=mask|(1<<v);
                if(!visited[v][newMask])
                {
                    visited[v][newMask]=true;
                    q.emplace(v,newMask,dist+1);
                }
            }
        }
        return -1; // 应该是到不了这里吧
    }
};