/*
 * @Author: LetMeFly
 * @Date: 2026-07-29 12:05:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-29 17:54:26
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
private:
    ll k;

    /*
        计算C_a^b
        C_6^2 = 6*5/(1*2)
    */
    ll C(ll a, ll b) {
        b = min(b, a - b);
        ll ans = 1;
        for (ll numerator = a, denominator = 1; denominator <= b; numerator--, denominator++) {
            ans = ans * numerator / denominator;
            if (ans >= k) {
                return k;
            }
        }
        return ans;
    }

    // all: C_len^a * C_{len-a}^b * ...
    ll methods(int cnt[], int len) {
        ll all = 1;
        for (int i = 0; i < 26; i++) {
            all *= C(len, cnt[i]);
            len -= cnt[i];
            if (all >= k) {
                return k;
            }
        }
        return all;
    }
public:
    string smallestPalindrome(string s, int k) {
        this->k = k;
        int cnt[26] = {0};
        int len = s.size() / 2;
        for (int i = 0; i < len; i++) {
            cnt[s[i] - 'a']++;
        }
        
        if (methods(cnt, len) < k) {
            return "";
        }

        string front(len, '0');
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 26; j++) {
                if (!cnt[j]) {
                    continue;
                }
                front[i] = 'a' + j;
                cnt[j]--;
                ll fill_this = methods(cnt, len - i - 1);
                if (fill_this >= this->k) {
                    break;
                }
                this->k -= fill_this;
                cnt[j]++;
            }
        }

        string ans = front;
        if (s.size() % 2) {
            ans += s[len];
        }
        ranges::reverse(front);
        ans += front;
        return ans;
    }
};
