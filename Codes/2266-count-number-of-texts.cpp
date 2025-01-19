/*
 * @Author: LetMeFly
 * @Date: 2025-01-19 12:53:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-19 15:09:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
/*
3:
1->1
2->2(11|2)
3->4(12|111|21|3=1+2+1)
4->4+2x2+4
*/
/*
7和9是4个
*/
typedef long long ll;

class Solution {
private:
    const static int mod = 1e9 + 7;
public:
    int countTexts(string pressedKeys) {
        // init
        int max3 = 0, max4 = 0;
        int nowCnt = 0;
        for (int i = 0; i < pressedKeys.size(); i++) {
            nowCnt++;
            if (i == pressedKeys.size() - 1 || pressedKeys[i] != pressedKeys[i + 1]) {
                if (pressedKeys[i] == '7' || pressedKeys[i] == '9') {
                    max4 = max(max4, nowCnt);
                } else {
                    max3 = max(max3, nowCnt);
                }
                nowCnt = 0;
            }
        }
        vector<int> dp3(max3 + 1);
        dp3[0] = 1;
        for (int i = 1; i <= max3; i++) {
            for (int j = 1; j < 4; j++) {
                if (i - j < 0) {
                    continue;
                }
                dp3[i] = (dp3[i] + ((ll)dp3[i - j] * (ll)dp3[j] % mod)) % mod;  // dp[i] += dp[i - j] * dp[j]
            }
        }
        vector<int> dp4(max4 + 1);
        dp4[0] = 1;
        for (int i = 1; i <= max4; i++) {
            for (int j = 1; j < 5; j++) {
                if (i - j < 0) {
                    continue;
                }
                dp4[j] = ((dp4[j] + dp4[i - j]) % mod + dp4[j]) % mod;  // to change
            }
        }
        // statistic
        int ans = 0;
        for (int i = 0; i < pressedKeys.size(); i++) {
            nowCnt++;
            if (i == pressedKeys.size() - 1 || pressedKeys[i] != pressedKeys[i + 1]) {
                if (pressedKeys[i] == '7' || pressedKeys[i] == '9') {
                    ans = (ans + dp4[nowCnt]) % mod;
                } else {
                    ans = (ans + dp3[nowCnt]) % mod;
                }
                nowCnt = 0;
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry

#endif  // FirstTry
const int mod = 1e9 + 7;
int dp3[100001], dp4[100001];
int init = []() {
    dp3[0] = dp4[0] = 1;
    dp3[1] = dp4[1] = 1;
    dp3[2] = dp4[2] = 2;
    dp3[3] = dp4[3] = 4;
    for (int i = 4; i <= 100000; i++) {
        dp3[i] = ((dp3[i- 1] + dp3[i - 2]) % mod + dp3[i - 3]) % mod;
        dp4[i] = (((dp4[i - 1] + dp4[i - 2]) % mod + dp4[i - 3]) % mod + dp4[i - 4]) % mod;
    }
    return 0;
}();

class Solution {
public:
    int countTexts(string& pressedKeys) {
        long long ans = 1;
        int cnt = 0;
        for (int i = 0; i < pressedKeys.size(); i++) {
            cnt++;
            if (i == pressedKeys.size() - 1 || pressedKeys[i] != pressedKeys[i + 1]) {
                ans = ans * (pressedKeys[i] == '7' || pressedKeys[i] == '9' ? dp4[cnt] : dp3[cnt]) % mod;
                cnt = 0;
            }
        }
        return ans;
    }
};
#ifdef _WIN32
/*
22233

8
*/
/*
444479999555588866

3136
*/
int main() {
    string s;
    Solution sol;
    while (cin >> s) {
        cout << sol.countTexts(s) << endl;
    }
    return 0;
}
#endif