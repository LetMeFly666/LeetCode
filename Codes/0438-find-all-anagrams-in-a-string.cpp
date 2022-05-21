/*
 * @Author: LetMeFly
 * @Date: 2021-11-28 11:20:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-28 11:31:24
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length()) 
            return ans;
        int diff[26] = {0}; // p - s
        for (char &c : p) {
            diff[c - 'a']++;
        }
        int allDiff = p.length();
        for (int i = 0; i < p.length(); i++) {
            if (diff[s[i] - 'a'] > 0) { // diff变小了
                allDiff--;
            }
            else { // diff变大了
                allDiff++;
            }
            diff[s[i] - 'a']--;
        }
        if (!allDiff) ans.push_back(0);
        for (int i = p.length(); i < s.length(); i++) {
            if (diff[s[i] - 'a'] > 0) allDiff--;
            else allDiff++;
            diff[s[i] - 'a']--;
            if (diff[s[i - p.length()] - 'a'] < 0) allDiff--;
            else allDiff++;
            diff[s[i - p.length()] - 'a']++;
            if (!allDiff) ans.push_back(i - p.length() + 1);
        }
        
        return ans;
    }
};