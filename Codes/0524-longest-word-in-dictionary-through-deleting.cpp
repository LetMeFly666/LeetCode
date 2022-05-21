/*
 * @Author: LetMeFly
 * @Date: 2021-09-14 09:50:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-09-14 10:06:07
 */
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
class Solution {
private:
    bool sub(string &s, string &a)
    {
        int locA=0;
        for (int locS=0; locS<s.size()&&locA<a.size();locS++)
        {
            if(s[locS]==a[locA])
                locA++;
        }
        return locA==a.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        string ans;
        for(string &thisS:dictionary)
        {
            // dbg(thisS); //******
            // dbg(thisS.size()); //*****
            // dbg(s.size()); //****
            // dbg(ans.size()); //*****
            if(thisS.size()>s.size()||thisS.size()<=ans.size())continue;
            // puts("000001"); //*********
            if (sub(s,thisS))ans = thisS;
        }
        return ans;
    }
};
/*
thisS = ale
thisS.size() = 3
s.size() = 8
ans.size() = 0
thisS = apple
thisS.size() = 5
s.size() = 8
ans.size() = 0
thisS = monkey
thisS.size() = 6
s.size() = 8
ans.size() = 0
thisS = plea
thisS.size() = 4
s.size() = 8
ans.size() = 0


*/