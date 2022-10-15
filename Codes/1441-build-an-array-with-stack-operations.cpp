/*
 * @Author: LetMeFly
 * @Date: 2022-10-15 09:57:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-15 09:59:38
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int now = 1;
        for (int& t : target) {
            while (t != now) {
                ans.push_back("Push");
                ans.push_back("Pop");
                now++;
            }
            ans.push_back("Push");
            now++;
        }
        return ans;
    }
};