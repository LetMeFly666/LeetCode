/*
 * @Author: LetMeFly
 * @Date: 2022-08-14 10:04:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-14 10:19:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // O(n), O(n)
class Solution {
public:
    int maxScore(string& s) {
        int n = s.size();
        vector<int> frontZero(n);
        vector<int> backOne(n);
        frontZero[0] = s[0] == '0';
        for (int i = 1; i < n; i++) {
            frontZero[i] = frontZero[i - 1] + (s[i] == '0');
        }
        backOne[n - 1] = s[n - 1] == '1';
        for (int i = n - 2; i >= 0; i--) {
            backOne[i] = backOne[i + 1] + (s[i] == '1');
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, frontZero[i - 1] + backOne[i]);
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry  // O(n), O(1)
class Solution {
public:
    int maxScore(string s) {
        int score = s[0] == '0';
        int n = s.size();
        for (int i = 1; i < n; i++) {
            score += s[i] == '1';
        }
        int ans = score;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '0')
                score++;
            else
                score--;
            ans = max(ans, score);
        }
        return ans;
    }
};
#endif  // FirstTry