/*
 * @Author: LetMeFly
 * @Date: 2022-12-02 13:05:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-02 13:35:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#define FristTry

#ifdef FristTry  // AC,100%,99.26%
class Solution {
public:
    vector<int> minOperations(string& boxes) {
        int right1 = 0, left1 = 0, cnt = 0;
        int n = boxes.size();
        for (int i = 1; i < n; i++) {
            if (boxes[i] == '1') {
                right1++, cnt += i;
            }
        }
        vector<int> ans(n);
        ans[0] = cnt;
        for (int i = 1; i < n; i++) {
            if (boxes[i - 1] == '1')
                left1++;
            cnt -= right1;
            cnt += left1;
            ans[i] = cnt;
            if (boxes[i] == '1')
                right1--;
        }
        return ans;
    }
};
#else  // FristTry
// SecondTry  // Error
class Solution {
public:
    vector<int> minOperations(string& boxes) {
        int right1 = 0, left1 = 0, cnt = 0;
        int n = boxes.size();
        for (int i = 1; i < n; i++) {
            if (boxes[i] == '1') {
                right1++, cnt += i;
            }
        }
        vector<int> ans(n);
        ans[0] = cnt;
        for (int i = 1; i < n; i++) {
            if (boxes[i - 1] == '1')
                left1++;
            if (boxes[i - 1] == '1')
                right1--;
            cnt -= right1;
            cnt += left1;
            ans[i] = cnt;
        }
        return ans;
    }
};
#endif  // FristTry