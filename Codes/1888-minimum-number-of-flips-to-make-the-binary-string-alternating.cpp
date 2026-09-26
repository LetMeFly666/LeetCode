/*
 * @Author: LetMeFly
 * @Date: 2026-03-07 17:46:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-08 11:41:56
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif


/*
01001001101
   3次右移
01001101010
   ||
01010101010

相当于
01001001101
      ||
01001010101
  --
01010101010
_         _
*/
class Solution {
public:
    int minFlips(const string& s) {
        int total = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            total += s[i] % 2 == i % 2;
        }
        int ans = min(total, n - total);
        if (n % 2 == 0) {
            return ans;
        }
        for (int i = 0, now = 0; i < n; i++) {
            now += s[i] % 2 == i % 2;
            int original_front = now;
            int original_back = total - original_front;
            int changed_front = i + 1 - original_front;
            int changed_back = n - i - 1 - original_back;
            ans = min(ans, min(original_front + changed_back, changed_front + original_back));
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
001000000010
|   | | |
101010101010

001000000010
    | | |
001010101010
-  右移一位
010101010100
   3次不可

4
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.minFlips(s) << endl;
    }
    return 0;
}
#endif