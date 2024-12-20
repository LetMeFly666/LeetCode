/*
 * @Author: LetMeFly
 * @Date: 2024-12-20 09:04:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-20 20:52:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // WA - sizeof(ans)只会为指针的大小
class Solution {
private:
    void count(int* ans, string& s, int l, int r) {
        memset(ans, 0, sizeof(ans));
        for (int i = l; i < r; i++) {
            ans[s[i] - 'a']++;
        }
    }

    bool same26(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int minAnagramLength(string& s) {
        int should[26], now[26];
        for (int ans = 1; ans < s.size(); ans++) {
            if (s.size() % ans) {
                continue;
            }
            count(should, s, 0, ans);
            // printf("ans = %d, should[] = {%d, %d, ...}, now[] = {%d, %d, ...}\n", ans, should[0], should[1], now[0], now[1]);  //*********
            for (int i = ans; i < s.size(); i += ans) {
                count(now, s, i, i + ans);
                if (!same26(should, now)) {
                    goto loop;
                }
            }
            return ans;
            loop:;
        }
        return s.size();
    }
};
#else  // FirstTry
// SecondTry - 这次要用C++的vector了，数组版本见C版本
class Solution {
private:
    vector<int> count(string& s, int l, int r) {
        vector<int> ans(26);
        for (int i = l; i < r; i++) {
            ans[s[i] - 'a']++;
        }
        return ans;
    }

    bool same(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int minAnagramLength(string& s) {
        for (int ans = 1; ans < s.size(); ans++) {
            if (s.size() % ans) {
                continue;
            }
            vector<int> should = count(s, 0, ans);
            for (int i = ans; i < s.size(); i += ans) {
                vector<int> now = count(s, i, i + ans);
                if (!same(should, now)) {
                    goto loop;
                }
            }
            return ans;
            loop:;
        }
        return s.size();
    }
};
#endif  // FirstTry

#ifdef _WIN32
/*
jjj 1

abba 2

cdef 4
*/
int main() {
    Solution sol;
    string s;
    while (cin >> s) {
        cout << sol.minAnagramLength(s) << endl;
    }
    return 0;
}
#endif