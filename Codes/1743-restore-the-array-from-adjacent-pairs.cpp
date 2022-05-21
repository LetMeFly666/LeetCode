/*
 * @Author: LetMeFly
 * @Date: 2021-07-25 18:53:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-07-25 19:41:23
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

int times[200010];
int who[200010][2];
class Solution
{
private:
    int getFirst()
    {
        for(int i=0;i<=200000;i++)
        {
            if(times[i]==1)
            {
                return i-100000;
            }
        }
        return 0; //int函数循环中返回不行
    }
    int getNext(int a)
    {
        a+=100000;
        int first=who[a][0];
        int second = who[a][1];
        if(times[first+100000]==2)return first;
        else if(times[second+100000]==2)return second;
        else if(times[first+100000]==1)return first;
        else return second;
        return 0; //int函数循环中返回不行
    }
    void init()
    {
        for(int i=0;i<=200000;i++)
        {
            times[i]=0;
        }
    }
    
public:
    vector<int> restoreArray(vector<vector<int> > &adjacentPairs)
    {
        init();
        int l=adjacentPairs.size();
        for(int i=0;i<l;i++)
        {
            who[adjacentPairs[i][0]+100000][times[adjacentPairs[i][0]+100000]]=adjacentPairs[i][1];
            who[adjacentPairs[i][1]+100000][times[adjacentPairs[i][1]+100000]]=adjacentPairs[i][0];
            times[adjacentPairs[i][0]+100000]++;
            times[adjacentPairs[i][1]+100000]++;
        }
        vector<int>ans;
        int which=getFirst();
        ans.push_back(which);
        times[which+100000]--;
        // while(1)
        // {
        //     int temp=who[which+100000][0];
        //     if(times[temp+100000]==2)
        //     {
        //         ans.push_back(temp);
        //         which=temp;
        //         times[temp+100000]=0;
        //     }
        //     else if(times[temp+100000]==0)
        //     {
        //         temp=who[which+100000][1];
        //         ans.push_back(temp);
        //         if(times[temp+100000]==1)
        //         {
        //             break;
        //         }
        //         times[temp+100000]=0;
        //     }
        //     else if(times[temp+100000]==1)
        //     {
        //         ans.push_back(temp);
        //         break;
        //     }
        //     else
        //     {
        //         printf("999999");
        //         break;
        //     }
        // }
        while(times[(which=getNext(which))+100000]==2)
        {
            ans.push_back(which);
            times[which+100000]=0;
        }
        ans.push_back(which);
        return ans;
    }
};

int main()
{
    vector<vector<int> >input;
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        vector<int>v;
        cin>>a>>b;
        v.push_back(a);
        v.push_back(b);
        input.push_back(v);
    }
    Solution sol;
    vector<int>ans=sol.restoreArray(input);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<' ';
    }
    puts("");
    system("pause");
    return 0;
}

/*
3
2 1
3 4
3 2

*/

/*
3
4 -2
1 4
-3 1

*/