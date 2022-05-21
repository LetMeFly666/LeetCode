// /*
//  * @Author: LetMeFly
//  * @Date: 2021-08-26 10:21:19
//  * @LastEditors: LetMeFly
//  * @LastEditTime: 2021-08-26 10:51:11
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

// class Solution
// {
// public:
//     int numRescueBoats(vector<int> &people, int limit)
//     {
//         sort(people.begin(),people.end());
//         int ans=0;
//         for(int i=people.size()-1;i>=0;i--)
//         {
//             ans++;
//             if(i==0)continue;
//             vector<int>::iterator it=lower_bound(people.begin(),people.begin()+i,limit-people[i]);
//             // printf("i=%d, people.size()=%d, it-begin=%d\n",i, people.size(),it-people.begin()); //********
//             if(it==people.begin()+i)
//             {
//                 if(people.size()>1)
//                     it--;
//             }
//             if(it<people.begin()+i&&*it<=limit-people[i])
//             {
//                 people.erase(it);
//                 i--;
//             }
//             else
//             {
//                 it--;
//                 if(it>=people.begin()&&*it<=limit-people[i])
//                 {
//                     people.erase(it);
//                     i--;
//                 }
//             }
//             // debug(people); //*********
//         }
//         return ans;
//     }
// };

// int main()
// {
//     string s;
//     int limits;
//     while(cin>>s>>limits)
//     {
//         vector<int>v=stringToVector(s);
//         Solution sol;
//         cout<<sol.numRescueBoats(v,limits)<<endl;
//     }
//     return 0;
// }

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int light = 0, heavy = people.size() - 1;
        while (light <= heavy) {
            if (people[light] + people[heavy] > limit) {
                --heavy;
            } else {
                ++light;
                --heavy;
            }
            ++ans;
        }
        return ans;
    }
};