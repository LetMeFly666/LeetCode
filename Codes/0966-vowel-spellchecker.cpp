/*
 * @Author: LetMeFly
 * @Date: 2025-09-14 15:21:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-14 15:33:04
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    string toLower(string s) {
        for (char& c : s) {
            if ('A' <= c && c <= 'Z') {
                c = tolower(c);
            }
        }
        return s;
    }

    string toAeiou(string s) {
        for (char& c : s) {
            if (c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = 'a';
            }
        }
        return s;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> original;
        unordered_map<string, string> lowers, aeious;  // 其实改为<string, int>只存下标也行
        for (string& s : wordlist) {
            original.insert(s);
            string lower = toLower(s);
            if (!lowers.count(lower)) {
                lowers[lower] = s;
            }
            string aeiou = toAeiou(lower);
            if (!aeious.count(aeiou)) {
                aeious[aeiou] = s;
            }
        }
        for (string& q : queries) {
            if (original.count(q)) {
                continue;
            }
            string lower = toLower(q);
            if (lowers.count(lower)) {
                q = lowers[lower];
                continue;
            }
            string aeiou = toAeiou(lower);
            if (aeious.count(aeiou)) {
                q = aeious[aeiou];
                continue;
            }
            q = "";  // 这个别忘了
        }
        return queries;
    }
};