// /*
//  * @Author: LetMeFly
//  * @Date: 2021-07-29 10:20:30
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-07-29 10:38:08
//  */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;

// int pow2[21]={1};
// void init()
// {
//     for(int i=1;i<=20;i++)
//         pow2[i]=pow2[i-1]*2;
// }

// int findLine(int n)
// {
//     for(int i=0;i<=20;i++)
//         if(pow2[i]>n)
//             return i;
//     return -1; // LeetCode int 函数必须显式返回值
// }

// int opposite(int n)
// {
//     int lineNum=findLine(n);
//     int lineMax=pow2[lineNum]-1;
//     int lineMin=pow2[lineNum-1];
//     return lineMin+lineMax-n;
// }

// class Solution
// {
// public:
//     vector<int> pathInZigZagTree(int label)
//     {
//         init();
//         vector<int>ans;
//         while (label)
//         {
//             ans.insert(ans.begin(), label);
//             label = opposite(label)/2;
//         }
//         return ans;
//     }
// };

// void debug(vector<int>v)
// {
//     for(int i=0;i<v.size();i++)
//     {
//         cout<<v[i]<<' ';
//     }
//     puts("");
// }

// int main()
// {
//     int a;
//     cin>>a;
//     Solution sol;
//     debug(sol.pathInZigZagTree(a));
//     system("pause");
//     return 0;
// }

// 优化空间
class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> ans;
        while (label)
        {
            ans.insert(ans.begin(), label);
            int k = 1, lineNum;
            for (int i = 0; i <= 20; i++)
            {
                if (k > label)
                {
                    lineNum = i;
                    break;
                }
                k *= 2;
            }
            k=1;
            for(int i=1;i<lineNum;i++)
                k*=2;
            // label = k+k*2-1-label;
            label = (k*3-1-label)/2;
        }
        return ans;
    }
};