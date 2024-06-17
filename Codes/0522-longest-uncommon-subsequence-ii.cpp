/*
 * @Author: LetMeFly
 * @Date: 2024-06-17 22:33:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-17 22:54:31
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isSub(string& a, string& b) {
        for (int ia = 0, ib = 0; ia < a.size(); ia++, ib++) {
            while (ib < b.size() && b[ib] != a[ia]) {
                ib++;
            }
            if (ib == b.size()) {
                return false;
            }
        }
        return true;
    }

    bool ok(vector<string>& strs, int index) {
        for (int i = 0; i < strs.size(); i++) {
            if (i != index && isSub(strs[index], strs[i])) {
                return false;
            }
        }
        return true;
    }
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });
        for (int i = 0; i < strs.size(); i++) {
            if (ok(strs, i)) {
                return strs[i].size();
            }
        }
        return -1;
    }
};

#ifdef _WIN32
int main() {
    // string a = "aabbcc", b =  "aabbcd";
    // dbg((a.find(b) != string::npos));

    // vector<string> v = {"aabbcc", "aabbcc", "c", "e", "aabbcd"};
    vector<string> v = {"aba", "cdc", "eae"};
    Solution sol;
    cout << sol.findLUSlength(v) << endl;
    return 0;
}
#endif