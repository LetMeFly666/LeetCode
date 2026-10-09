/*
 * @Author: LetMeFly
 * @Date: 2026-10-09 08:25:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-09 08:55:07
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int meetLeft(int& left, int& right) {
        int ans = 0;
        if (right % 2) {
            right++;
            ans++;
        }
        int loss = min(left, right / 2);
        left -= loss;
        right -= loss * 2;
        ans += right / 2;
        right = 0;
        return ans;
    }

    int meetRight(int& left, int& right) {
        int ans = 0;
        if ((right + 1) / 2 > left) {
            ans += (right + 1) / 2;
            left = (right + 1) / 2;
        }
        int loss = min(left, right / 2);
        left -= loss;
        right -= loss * 2;
        return ans;
    }
public:
    int minInsertions(const string& s) {
        int ans = 0;
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') {
                ans += meetLeft(++left, right);
            } else {
                ans += meetRight(left, ++right);
            }
        }
        ans += meetLeft(left, right);
        ans += left * 2;
        return ans;
    }
};

/*
v1错误原因：

(()))(()))()())))
 ---  ---   ---
()()()))
    ---
()())
  ---
()
())

不可。

左括号后面必须紧跟两个**连续的**右括号
*/
