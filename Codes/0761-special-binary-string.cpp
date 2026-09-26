/*
 * @Author: LetMeFly
 * @Date: 2026-02-20 11:00:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-20 11:12:06
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
11011000
(()(()))
(  ()   (())    )
*/
class Solution {
private:
    vector<pair<int, int>> split(string& s) {
        vector<pair<int, int>> ans;
        int diff = 0, from = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                diff++;
            } else {
                diff--;
            }
            if (!diff) {
                ans.push_back({from, i});
                from = i + 1;
            }
        }
        return ans;
    }
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) {
            return s;
        }
        vector<pair<int, int>> pairs = split(s);
        if (pairs.size() == 1) {
            return '1' + makeLargestSpecial(s.substr(1, s.size() - 2)) + '0';
        }
        vector<string> parts;
        parts.reserve(pairs.size());
        for (auto [l, r] : pairs) {
            parts.push_back(makeLargestSpecial(s.substr(l, r - l + 1)));
        }
        sort(parts.begin(), parts.end(), greater<>());
        string ans;
        for (string& part : parts) {
            ans += part;
        }
        return ans;
    }
};