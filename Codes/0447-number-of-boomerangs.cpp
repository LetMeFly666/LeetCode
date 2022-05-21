/*
 * @Author: LetMeFly
 * @Date: 2021-09-13 22:28:21
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-13 22:32:31
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            map<int,int>ma;
            for(int j=0;j<n;j++)
            {
                int d=(points[j][0]-points[i][0])*(points[j][0]-points[i][0])+(points[j][1]-points[i][1])*(points[j][1]-points[i][1]);
                ma[d]++;
            }
            for(map<int,int>::iterator it=ma.begin();it!=ma.end();it++)
            {
                int thisNum=it->second;
                ans+=thisNum*(thisNum-1);
            }
        }
        return ans;
    }
};