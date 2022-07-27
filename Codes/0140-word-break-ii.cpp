/*
 * @Author: LetMeFly
 * @Date: 2022-07-27 11:42:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-27 11:56:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " : " << x << endl
#endif

#define judge(thisWord) \
    \
    if (!st.count(thisWord))\
        goto loop;\
    thisBreak.push_back(thisWord);

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> st;
        for (string& s : wordDict) {
            st.insert(s);
        }
        int n = s.size() - 1;
        for (int i = 0; i < (1 << n); i++) {
            vector<string> thisBreak;
            string toInsert;
            string thisWord;

            int last = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    thisWord = s.substr(last, j - last + 1);
                    judge(thisWord);
                    last = j + 1;
                }
            }
            thisWord = s.substr(last, s.size() - last);
            judge(thisWord);

            for (int i = 0; i < thisBreak.size(); i++) {
                if (i)
                    toInsert += ' ';
                toInsert += thisBreak[i];
            }
            ans.push_back(toInsert);
            loop:;
        }
        return ans;
    }
};

/*
"catsanddog"
["cat","cats","and","sand","dog"]

*/
#ifdef _WIN32
int main() {
    string s, t;
    while (cin >> s >> t) {
        if (s[0] == '"') s = s.substr(1, s.size() - 1);
        if (s.back() == '"') s = s.substr(0, s.size() - 1);
        vector<string> v = stringToVectorString(t);
        Solution sol;
        debug(sol.wordBreak(s, v));
    }
    return 0;
}
#endif