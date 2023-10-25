/*
 * @Author: LetMeFly
 * @Date: 2023-10-25 20:05:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-25 20:23:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int check(int n) {
        string to = to_string(n * n);
        int l = to.size();
        for (int mask = 0; mask < (1 << l); mask++) {
            int cnt = 0;
            int nowNum = 0;
            for (int i = 0; i < l; i++) {
                nowNum = nowNum * 10 + (to[i] - '0');
                if ((mask >> i) & 1) {  // 这一位后面隔开
                    cnt += nowNum;
                    nowNum = 0;
                }
            }
            if (cnt + nowNum == n) {  // 想着“会有结尾的i是不行的”
                return n * n;
            }
        }
        return 0;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += check(i);
        }
        return ans;
    }
};

#ifdef _WIN32
int main() {
    int n;
    while (cin >> n) {
        Solution sol;
        cout << sol.punishmentNumber(n) << endl;
    }
    return 0;
}
#endif