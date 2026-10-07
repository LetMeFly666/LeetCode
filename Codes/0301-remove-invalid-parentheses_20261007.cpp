/*
 * @Author: LetMeFly
 * @Date: 2026-10-07 11:25:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-07 11:47:10
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    vector<int> idxs;  // 括号位置
    int mini_remove;

    void getInfo(const string& s) {
        int left = 0;
        mini_remove = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                idxs.push_back(i);
                left++;
            } else if (s[i] == ')') {
                idxs.push_back(i);
                if (left) {
                    left--;
                } else {
                    mini_remove++;
                }
            }
        }
        mini_remove += left;
    }

    string genS(const string& s, int mask) {
        string this_s;
        this_s.reserve(s.size() - mini_remove);
        vector<int> deleted;
        deleted.reserve(idxs.size());
        for (int i = 0; i < idxs.size(); i++) {
            if (mask >> i & 1) {
                deleted.push_back(idxs[i]);
            }
        }
        for (int is = 0, ic = 0; is < s.size(); is++) {
            if (ic < deleted.size() && is == deleted[ic]) {
                ic++;
            } else {
                this_s.push_back(s[is]);
            }
        }
        return this_s;
    }

    bool ok(const string& s) {
        int left = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                if (left) {
                    left--;
                } else {
                    return false;
                }
            }
        }
        return !left;
    }
public:
    vector<string> removeInvalidParentheses(const string& s) {
        unordered_set<string> se;
        getInfo(s);
        int parentheses = idxs.size();
        
        for (int i = 0, to = 1 << parentheses; i < to; i++) {
            if (__builtin_popcount(i) != mini_remove) {
                continue;
            }
            string this_s = genS(s, i);
            if (ok(this_s)) {
                se.insert(this_s);
            }
        }
        return vector<string>(se.begin(), se.end());
    }
};
