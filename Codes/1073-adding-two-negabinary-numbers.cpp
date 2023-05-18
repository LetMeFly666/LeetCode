/*
 * @Author: LetMeFly
 * @Date: 2023-05-18 09:36:35
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-05-18 09:46:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        for (int i = arr1.size() - 1, j = arr2.size() - 1, c = 0; i >= 0 || j >= 0 || c; i--, j--) {
            int a = i >= 0 ? arr1[i] : 0;
            int b = j >= 0 ? arr2[j] : 0;
            int x = a + b + c;
            if (x >= 2) {
                x -= 2;
                c = -1;
            }
            else if (x == -1) {
                x = 1;
                c = 1;
            }
            else {
                c = 0;
            }
            ans.push_back(x);
        }
        while (ans.size() > 1 && !ans.back()) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};