// /*
//  * @Author: LetMeFly
//  * @Date: 2021-08-29 13:58:45
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-08-29 14:10:58
//  */
// #include <bits/stdc++.h>
// using namespace std;
// #define mem(a) memset(a, 0, sizeof(a))
// #define dbg(x) cout << #x << " = " << x << endl
// #define fi(i, l, r) for (int i = l; i < r; i++)
// #define cd(a) scanf("%d", &a)
// typedef long long ll;
// void debug(vector<int>v)
// {
//     for(int i=0;i<v.size();i++)
//     {
//         cout<<v[i]<<' ';
//     }
//     puts("");
// }

// vector<string> split(string toSplit, char c)  // 将字符串以字符c为间隔分开
// {
//     vector<string> ans;
//     toSplit+=c;
//     int left=0;
//     for(int right=0;right<toSplit.size();right++)
//     {
//         if(toSplit[right]==c)  //left->right-1
//         {
//             ans.push_back(toSplit.substr(left,right-left));
//             left=right+1;
//         }
//     }
//     return ans;
// }

// vector<int> stringToVector(string s)
// {
//     vector<int>v;
//     s=s.substr(1, s.size()).substr(0, s.size()-1);
//     vector<string>vs=split(s, ',');
//     for(int i=0;i<vs.size();i++)
//     {
//         string temp=vs[i];
//         int t;
//         sscanf(temp.c_str(), "%d", &t);
//         v.push_back(t);
//     }
//     return v;
// }

// class Solution {
// public:
//     int sumOddLengthSubarrays(vector<int>& arr) {
//         int n=arr.size();
//         arr.insert(arr.begin(),0);
//         for(int i=1;i<=n;i++){
//             arr[i]+=arr[i-1];
//         }
//         debug(arr); //*******
//         int ans=0;
//         for(int len=1;len<=n;len+=2){
//             for(int begin=1;begin+len-1<=n;begin++){
//                 printf("begin=%d, end=%d\n", begin, begin+len-1); // *****
//                 ans+=arr[begin+len-1]-arr[begin-1];
//             }
//         }
//         return ans;
//     }
// };

// int main()
// {
//     string s;
//     while(cin>>s)
//     {
//         vector<int>v=stringToVector(s);
//         Solution sol;
//         cout<<sol.sumOddLengthSubarrays(v)<<endl;
//     }
//     return 0;
// }

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        arr.insert(arr.begin(),0);
        for(int i=1;i<=n;i++){
            arr[i]+=arr[i-1];
        }
        int ans=0;
        for(int len=1;len<=n;len+=2){
            for(int begin=1;begin+len-1<=n;begin++){
                ans+=arr[begin+len-1]-arr[begin-1];
            }
        }
        return ans;
    }
};