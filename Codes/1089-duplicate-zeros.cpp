/*
 * @Author: LetMeFly
 * @Date: 2022-06-17 09:21:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-17 09:24:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// 方法一：额外空间记录，先过了再说
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans(arr.size());
        int loc = 0;
        for (int& t : arr) {
            if (t) {
                ans[loc++] = t;
                if (loc == arr.size())
                    break;
            }
            else {
                ans[loc++] = 0;
                if (loc == arr.size())
                    break;
                ans[loc++] = 0;
                if (loc == arr.size())
                    break;
            }
        }
        arr = ans;
    }
};