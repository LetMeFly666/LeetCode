/*
 * @Author: LetMeFly
 * @Date: 2023-02-24 21:46:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-02-24 21:55:04
 */
//无向图 迪杰斯特拉模板 朴素版
#include <bits/stdc++.h>
using namespace std;

int t;
int g[110][110];
int dis[110];
int n, m, s;
bool f[110];

void dijksta()
{
    memset(f, 0, sizeof(f));
    memset(dis, 0x3f, sizeof(dis));

    dis[s] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!f[j] && (t == -1 || dis[j] < dis[t]))
                t = j; //寻找还未确定最短路的点中路径最短的点
        }

        // if (f[t])continue;   //如果某个点已经被确定就直接跳过  //*********
        f[t] = 1;
        printf("t = %d\n", t);

        for (int j = 1; j <= n; j++)
        {
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        }
    }
}

void hp()
{

    cin >> n >> m;

    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        g[a][b] = min(g[a][b], x);
    }
    cin >> s;
    dijksta();
    for (int i = 1; i <= n; i++)
        if (dis[i] != 0x3f3f3f3f)
            cout << dis[i] << " ";
        else
            cout << "impossible"
                 << " ";
    puts("");
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> t;

    while (t--)
        hp();

    return 0;
}
/**************************************************************
    Problem: 5807
    User: hpsleep [NTU20软工hp最后一舞]
    Language: C++
    Result: 正确
    Time:2 ms
    Memory:1436 kb
****************************************************************/