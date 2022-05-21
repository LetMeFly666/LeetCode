/*
 * @Author: LetMeFly
 * @Date: 2021-08-03 09:09:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-08-03 09:52:47
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

void debug(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    puts("");
}

vector<string> split(string toSplit, char c) // 将字符串以字符c为间隔分开
{
    vector<string> ans;
    toSplit += c;
    int left = 0;
    for (int right = 0; right < toSplit.size(); right++)
    {
        if (toSplit[right] == c) //left->right-1
        {
            ans.push_back(toSplit.substr(left, right - left));
            left = right + 1;
        }
    }
    return ans;
}

vector<int> stringToVector(string s)
{
    vector<int> v;
    s = s.substr(1, s.size()).substr(0, s.size() - 1);
    vector<string> vs = split(s, ',');
    for (int i = 0; i < vs.size(); i++)
    {
        string temp = vs[i];
        int t;
        sscanf(temp.c_str(), "%d", &t);
        v.push_back(t);
    }
    return v;
}

void testForStringToVector()
{
    string s;
    while (cin >> s)
    {
        debug(stringToVector(s));
    }
    exit(0);
}

// class Solution
// {
// public:
//     int findUnsortedSubarray(vector<int> &nums)
//     {
//         vector<int>a(nums);
//         sort(a.begin(),a.end());
//         int l=a.size();
//         int locQian=0,locHou=l-1;
//         while(locQian<l&&a[locQian]==nums[locQian])locQian++;
//         while(locHou>=0&&a[locHou]==nums[locHou])locHou--;
//         // if(locQian<locHou)return locHou-locQian-1;
//         // else return 0;
//         return max(locHou-locQian+1, 0);
//     }
// };

// method 2
bool already(vector<int>&nums)
{
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]<nums[i-1])
            return false;
    }
    return true;
}
// class Solution2
// {
// public:
//     int findUnsortedSubarray(vector<int> &nums)
//     {
//         if(already(nums))return 0;
//         int locQian=1,locHou=nums.size()-2;
//         while(locQian<nums.size()&&nums[locQian]>=nums[locQian-1])locQian++;
//         while(locHou>=0&&nums[locHou]<nums[locHou+1])locHou--;
//         return locHou-locQian+3;
//     }
// };

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        if(already(nums))return 0;
        int m=INT_MAX,M=INT_MIN;
        int locQian=nums.size()-1;
        int locHou=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[n-1-i]<=m)m=nums[n-1-i];
            else locQian=n-1-i;
            if(nums[i]>=M)M=nums[i];
            else locHou=i;
        }
        return locHou-locQian+1;
    }
};

// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int n = nums.size();
//         int maxn = INT_MIN, right = -1;
//         int minn = INT_MAX, left = -1;
//         for (int i = 0; i < n; i++) {
//             if (maxn > nums[i]) {
//                 right = i;
//             } else {
//                 maxn = nums[i];
//             }
//             if (minn < nums[n - i - 1]) {
//                 left = n - i - 1;
//             } else {
//                 minn = nums[n - i - 1];
//             }
//         }
//         return right == -1 ? 0 : right - left + 1;
//     }
// };

int main()
{
    string s;
    cin >> s;
    vector<int> nums = stringToVector(s);
    Solution sol;
    cout << sol.findUnsortedSubarray(nums) << endl;
    system("pause");
    return 0;
}