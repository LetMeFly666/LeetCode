/*
 * @Author: LetMeFly
 * @Date: 2023-10-29 07:10:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-29 07:13:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (i + 1 > citations[i]) {
                return i;
            }
        }
        return citations.size();
    }
};