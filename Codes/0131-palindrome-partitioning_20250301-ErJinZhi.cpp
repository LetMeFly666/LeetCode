/*
 * @Author: LetMeFly
 * @Date: 2025-03-01 15:34:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-01 16:01:13
 * @Description: 头脑不清醒这题写了半小时好难受
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
s = aba
n = 3
status = 4(共4种状态)
*/

class Solution {
private:
    int n;
    string s;

    bool isok(int l, int r) {  // [l, r)
        for (r--; l < r; l++, r--) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }

    bool isOk_all(int code) {
        int l = 0;
        for (int r = 0; r < n - 1; r++) {
            if (code >> r & 1) {
                if (!isok(l, r + 1)) {
                    return false;
                }
                l = r + 1;
            }
        }
        return isok(l, n);
    }

    void store(vector<vector<string>>& ans, int code) {
        ans.push_back({});
        int l = 0;
        for (int r = 0; r < n - 1; r++) {
            if (code >> r & 1) {
                ans.back().push_back(s.substr(l, r - l + 1));
                l = r + 1;
            }
        }
        ans.back().push_back(s.substr(l, n - l + 1));
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        this->s = move(s);
        int status = 1 << (n - 1);
        vector<vector<string>> ans;
        for (int c = 0; c < status; c++) {
            if (isOk_all(c)) {
                store(ans, c);
            }
        }
        return ans;
    }
};

#ifdef _WIN32
/*
aab

[["a","a","b"],["aa","b"]]
*/
/*
efe

[["e","f","e"],["efe"]]
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        debug(sol.partition(s));
    }
    return 0;
}
#endif