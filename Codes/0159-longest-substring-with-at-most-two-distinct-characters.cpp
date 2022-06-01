/*
 * @Author: LetMeFly
 * @Date: 2022-06-01 16:05:53
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-01 16:45:44
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 是最多两种字符，不是每种字符只能出现1次
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
            return 0;
        int ans = 1, left = 0;
        vector<int> dp(26, 0);
        dp[s[0] - 'a'] = true;
        for (int i = 1; i < s.size(); i++) {
            while (dp[s[i] - 'a'] > 1) {
                dp[s[left++] - 'a']--;
            }
            dp[s[i] - 'a']++;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string& s) {
        char appendChar[2];
        int cnt[2] = {0, 0};
        int type = 0;
        int ans = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            bool appended = false;
            for (int i = 0; i < type; i++) {
                if (s[right] == appendChar[i]) {
                    appended = true;
                    cnt[i]++;
                    break;
                }
            }
            if (!appended) {
                if (type == 2) {
                    while (cnt[0] && cnt[1]) {  // 可能会第二种char先归零
                        for (int i = 0; i < type; i++) {
                            if (s[left] == appendChar[i]) {
                                cnt[i]--;
                                left++;
                                break;  // 这里必须退出循环，否则下一个可能正好等于cnt[1]
                            }
                        }
                    }
                    if (!cnt[0]) {
                        cnt[0] = cnt[1];
                        appendChar[0] = appendChar[1];
                    }
                    type--;
                }
                appendChar[type] = s[right];
                cnt[type++] = 1;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
#endif  // FirstTry

/*
"eceba"
"ccaabbb"
"abaccc"

*/

#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        if (s[0] == '"')
            s = s.substr(1, s.size() - 1);
        if (*prev(s.end()) == '"') 
            s = s.substr(0, s.size() - 1);
        cout << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;
    }
    return 0;
}
#endif