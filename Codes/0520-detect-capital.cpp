/*
 * @Author: LetMeFly
 * @Date: 2021-11-13 11:08:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-11-13 11:14:33
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
    bool allSamll(string &words) {
        for (char &c : words) {
            if (c >= 'A' && c <= 'Z')  
                return false;
        }
        return true;
    }

    bool allBig(string &words) {
        for (char &c : words) {
            if (c >= 'a' && c <= 'z')  
                return false;
        }
        return true;
    }

    bool firstBig(string &words) {
        if (words[0] >= 'a' && words[0] <= 'z')
            return false;
        for (int i = 1; i < words.size(); i++) {
            if (words[i] >= 'A' && words[i] <= 'Z')  
                return false;
        }
        return true;
    }
public:
    bool detectCapitalUse(string &words) {
        if (allSamll(words)) return true;
        if (allBig(words)) return true;
        if (firstBig(words)) return true;
        return false;
    }
};