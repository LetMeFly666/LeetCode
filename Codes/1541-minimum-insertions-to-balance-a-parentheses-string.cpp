/*
 * @Author: LetMeFly
 * @Date: 2026-10-09 08:25:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-09 09:51:51
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

/*
本解法当前思路

记录未匹配的左括号和右括号数量。
如果遇到左括号，left++，补全未配对的右括号：
    1. 若右括号为奇数个，先补上一个
    2. 抵消掉能抵消的括号
    3. 如果右括号还有剩余，则补上对应数量一半的左括号
如果遇到右括号，right++：
    1. 如果左括号已经不够抵消右括号，则补上所需左括号
    2. 抵消掉能抵消的括号
相当于遇到右括号就看有无左括号，有就存一个或者直接抵消掉，没有就补上左括号；遇到左括号就清算右括号

嗯，反正是屎山代码一坨。
*/
