/*
 * @Author: LetMeFly
 * @Date: 2024-11-12 18:08:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-12 18:25:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt[2] = {0};
        int ans = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt[s[r] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {  // 啊这，De了半天原来是“任一”
                cnt[s[l++] - '0']--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};

#ifdef _WIN32
int main() {
    string s = "10101";
    int k = 1;
    Solution sol;
    cout << sol.countKConstraintSubstrings(s, k) << endl;
    return 0;
}
#endif