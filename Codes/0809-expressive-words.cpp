/*
 * @Author: LetMeFly
 * @Date: 2022-11-25 10:52:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-25 12:19:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<char, int> pii;
class Solution {
private:
    void string2vectorPair(string& s, vector<pii>& p) {
        char lastChar = s[0];
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] != lastChar) {
                p.push_back({lastChar, cnt});
                if (i != n)
                    lastChar = s[i];
                cnt = 0;
            }
            cnt++;
        }
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pii> origin;
        string2vectorPair(s, origin);
        int ans = 0;
        for (string& s : words) {
            vector<pii> thisWord;
            string2vectorPair(s, thisWord);
            if (origin.size() != thisWord.size())
                continue;
            bool can = true;
            for (int i = 0; i < origin.size(); i++) {
                if (origin[i] == thisWord[i] || (origin[i].first == thisWord[i].first && origin[i].second > thisWord[i].second && origin[i].second >= 3))
                    continue;
                can = false;
                break;
            }
            ans += can;
        }
        return ans;
    }
};

/*
heeellooo
["hello","hi","helo"]

*/

#ifdef _WIN32
int main() {
    string s, words;
    while (cin >> s >> words) {
        vector<string> w = stringToVectorString(words);
        for (string& s : w) {
            s = s.substr(1, s.size() - 2);
        }
        Solution sol;
        cout << sol.expressiveWords(s, w) << endl;
    }
    return 0;
}
#endif