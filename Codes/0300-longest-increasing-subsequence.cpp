#ifdef FirstTry  // 一年半前的代码：
/*
 * @Author: LetMeFly
 * @Date: 2021-07-26 09:27:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-10 11:43:33
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

#define length 2500
int d[length+5];

void debug(int *it, int *begin, int *end, int toFind)
{
    for(int *pi=begin;pi<end;pi++)
    {
        cout << *pi << ' ';
    }
    cout << "[finding " << toFind << "]: " << it-begin << endl;
}

void debug(vector<int>&v)
{
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << ' ';
    }
    puts("");
}

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // debug(nums); //**************
        int len=0;
        d[len]=nums[0];
        len=1;
        int l=nums.size();
        for(int i=1;i<l;i++)
        {
            if(nums[i]>d[len-1])
            {
                d[len]=nums[i];
                len++;
            }
            else
            {
                int *it=lower_bound(d, d+len, nums[i]);
                // debug(it, d, d+len, nums[i]); //**************
                *it=nums[i];
            }            
        }
        return len;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    while(n--)
    {
        int t;
        cd(t);
        v.push_back(t);
    }
    // string input;
    // cin>>input;
    // input=input.substr(1, input.size()-1).substr(0, input.size()-1)+',';
    // int t;
    // while(~sscanf(input.c_str(), "%d,", t))
    // {
    //     v.push_back(t);
    // }
    // debug(v);//**********
    Solution sol;
    cout<<sol.lengthOfLIS(v)<<endl;
    system("pause");
}

/*
6
0 1 0 3 2 3

*/
#else  // FirstTry
// SecondTry  // 2022-12-10
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
#endif  // FirstTry