/*
 * @Author: LetMeFly
 * @Date: 2026-02-15 15:24:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-15 16:08:41
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    int same1(string& s) {
        int ans = 0;
        int cnt = 0;
        int last = '0';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != last) {
                ans = max(ans, cnt);
                cnt = 1;
                last = s[i];
            } else {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }

    int same2(string& s) {
        return max(same2(s, 'a', 'b'), max(same2(s, 'b', 'c'), same2(s, 'a', 'c')));
    }

    int same2(string& s, char a, char b) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<int, int> ma;
            ma[0] = i - 1;
            int cnt = 0;
            for (; s[i] == a || s[i] == b; i++) {
                cnt += s[i] == a ? 1 : -1;
                if (ma.count(cnt)) {
                    ans = max(ans, i - ma[cnt]);
                } else {
                    ma[cnt] = i;
                }
                // printf("same2(\"%s\", '%c', '%c'): i = %d, cnt = %d, ma[%d] = %d, ans = %d\n", s.c_str(), a, b, i, cnt, cnt, ma[cnt], ans);
            }
        }
        return ans;
    }

    int same3(string& s) {
        // 假设s[i]到s[j]的abc出现次数相同，则有：
        //     1. cnt_a[j] - cnt_a[i] = cnt_b[j] - cnt_b[i]
        //     2. cnt_a[j] - cnt_a[i] = cnt_c[j] - cnt_c[i]
        // 则有：
        //     1. cnt_a[j] - cnt_b[j] = cnt_a[i] - cnt_b[i]
        //     2. cnt_a[j] - cnt_c[j] = cnt_a[i] - cnt_c[i]
        // 于是可记录(cnt_a-cnt_b, cnt_a-cnt_c)两个值
        unordered_map<ll, int> ma;
        ma[same3_pair2ll(0, 0)] = -1;
        int cnt[3] = {0, 0, 0};
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            int diff1 = cnt[0] - cnt[1];
            int diff2 = cnt[0] - cnt[2];
            ll key = same3_pair2ll(diff1, diff2);
            if (ma.count(key)) {
                ans = max(ans, i - ma[key]);
            } else {
                ma[key] = i;
            }
        }
        return ans;
    }

    inline ll same3_pair2ll(int diff1, int diff2) {
        return (diff1 + 100000) * 200000LL + diff2;
    }
public:
    int longestBalanced(string& s) {
        return max(same1(s), max(same2(s), same3(s)));
    }
};