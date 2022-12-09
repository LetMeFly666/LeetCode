/*
 * @Author: LetMeFly
 * @Date: 2022-12-09 09:43:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-09 09:50:29
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // 方法一：二进制枚举
/*
```python
for i in range(15):
    print(3 ** i, end=", ")
```
*/

// const int three[15] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969};
class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> three(1, 1);
        while (three.back() < n) {
            three.push_back(three.back() * 3);
        }
        int num = three.size(), to = 1 << num;
        for (int state = 0; state < to; state++) {
            int s = 0;
            for (int j = 0; j < num; j++) {
                if (state & (1 << j)) {
                    s += three[j];
                }
            }
            if (s == n)
                return true;
        }
        return false;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2)
                return false;
            n /= 3;
        }
        return true;
    }
};
#endif  // FirstTry