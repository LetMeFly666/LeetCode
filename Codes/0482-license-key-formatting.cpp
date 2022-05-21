/*
 * @Author: LetMeFly
 * @Date: 2021-10-04 13:31:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-10-04 13:40:02
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
    char newChar(char &c) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        return c;
    }
public:
    string licenseKeyFormatting(string s, int k) {
        string temp;
        for (char &c:s)
            if (c != '-')
                temp += newChar(c);
        int l = temp.size();
        int num = l / k;
        int first = (l - 1) % k + 1;
        dbg(temp);
        dbg(first);
        string ans;
        int to=0;
        for(;to<first;to++) {
            ans+=temp[to];
        }
        ans+='-';
        int thisNum = 0;
        while(to<l) {
            ans += temp[to++];
            thisNum++;
            if (thisNum == k) {
                thisNum = 0;
                ans += '-';
            }
        }
        ans.erase(--ans.end());
        return ans;
    }
};