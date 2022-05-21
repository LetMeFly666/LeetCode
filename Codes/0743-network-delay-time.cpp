// /*
//  * @Author: LetMeFly
//  * @Date: 2021-08-02 10:05:23
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-08-02 10:57:02
//  */
// // /*
// //  * @Author: LetMeFly
// //  * @Date: 2021-08-02 10:05:23
// //  * @LastEditors: LetMeFly
// //  * @LastEditTime: 2021-08-02 10:43:42
// //  */
// // #include <bits/stdc++.h>
// // using namespace std;
// // #define mem(a) memset(a, 0, sizeof(a))
// // #define dbg(x) cout << #x << " = " << x << endl
// // #define fi(i, l, r) for (int i = l; i < r; i++)
// // #define cd(a) scanf("%d", &a)
// // typedef long long ll;
// // typedef pair<int,int>pii;
// // bool visited[110];
// // struct cmp
// // {
// //     bool operator()(const pair<int,int>a, const pair<int,int>b)
// //     {
// //         return a.second>b.second;
// //     }
// // };
// // class Solution
// // {
// // public:
// //     int networkDelayTime(vector<vector<int>> &times, int n, int k)
// //     {
// //         mem(visited);
// //         int ans=0;
// //         vector<pair<int,int> >v[n+1];
// //         for(vector<vector<int>>::iterator it=times.begin();it!=times.end();it++)
// //         {
// //             v[(*it)[0]].push_back(pair<int,int>((*it)[1],(*it)[2]));
// //         }
// //         priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;

// //         while(q.size())
// //         {
// //             pii thisPiar=q.top();
// //             q.pop();
// //             int to=thisPiar.first;
// //         }
// //     }
// // };

// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// typedef pair<int,int>pii;
// struct hh
// {
//     int to,distance,fromTime;
// };
// struct cmp
// {
//     bool operator()(const hh a,const hh b)
//     {
//         return a.distance>b.distance;
//     }
// };
// bool visited[111];
// void push(priority_queue<hh,vector<hh>,cmp>&q, vector<pii>v[], int thisNode, int thisTime)
// {
//     for(int i=0;i<v[thisNode].size();i++)
//     {
//         if(!visited[i])
//         {
//             hh h;
//             h.distance=v[thisNode][i].second;
//             h.to=v[thisNode][i].first;
//             h.fromTime=thisTime;
//         }
//     }
// }
// class Solution
// {
// public:
//     int networkDelayTime(vector<vector<int>> &times, int n, int k)
//     {
//         mem(visited);
//         vector<pii>v[111];
//         for(int i=0;i<times.size();i++)
//         {
//             v[times[i][0]].push_back(pii(times[i][1],times[i][2]));
//         }
//         priority_queue<hh,vector<hh>,cmp>q;
//         for(int i=0;i<v[n].size();i++)
//         {
//             hh h;
//             h.fromTime=0;
//             h.to=v[n][i].first;
//             h.distance=v[n][i].second;
//             q.push(h);
//         }
//     }
// };

// From Web 突然不会了，很懵现在

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
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        const int inf = INT_MAX / 2;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (auto &t : times)
        {
            int x = t[0] - 1, y = t[1] - 1;
            g[x][y] = t[2];
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        vector<int> used(n);
        for (int i = 0; i < n; ++i)
        {
            int x = -1;
            for (int y = 0; y < n; ++y)
            {
                if (!used[y] && (x == -1 || dist[y] < dist[x]))
                {
                    x = y;
                }
            }
            used[x] = true;
            for (int y = 0; y < n; ++y)
            {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};