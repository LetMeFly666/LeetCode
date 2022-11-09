/*
 * @Author: LetMeFly
 * @Date: 2022-10-02 08:15:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-02 09:02:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error  // 应该是：XL->LX, RX->XR
class Solution {
public:
    bool canTransform(string& start, string& end) {
        if (start.size() != end.size())
            return false;
        for (int i = start.size(); i >= 0; i--) {
            if (start[i] == end[i])
                continue;
            if (end[i] == 'X' && i > 0 && start[i - 1] == 'X' && start[i] == end[i - 1] && start[i] != 'X') {
                i--;
            }
            else {
                printf("i = %d, start[%d] = %c, end[%d] = %c\n", i, i, start[i], i, end[i]);
                return false;
            }
        }
        return true;
    }
};
#else  // FirstTry
#ifdef SecondTry  // 不能只考虑相邻两个字符
class Solution {
public:
    bool canTransform(string& start, string& end) {
        if (start.size() != end.size())
            return false;
        for (int i = start.size(); i >= 0; i--) {
            if (start[i] != end[i]) {
                if (i > 0 && ((start[i] == 'X' && start[i - 1] == 'R' && end[i] == 'R' && end[i - 1] == 'X') || (start[i] == 'L' && start[i - 1] == 'X' && end[i] == 'X' && end[i - 1] == 'L'))) {
                    i--;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
#else  // SecondTry
// ThirdTry  // Copy
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') {
                i++;
            }
            while (j < n && end[j] == 'X') {
                j++;
            }
            if (i < n && j < n) {
                if (start[i] != end[j]) {
                    return false;
                }
                char c = start[i];
                if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
        }
        while (i < n) {
            if (start[i] != 'X') {
                return false;
            }
            i++;
        }
        while (j < n) {
            if (end[j] != 'X') {
                return false;
            }
            j++;
        }
        return true;
    }
};
#endif  // SecondTry
#endif  // FirstTry