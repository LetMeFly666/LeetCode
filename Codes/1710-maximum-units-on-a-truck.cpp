/*
 * @Author: LetMeFly
 * @Date: 2022-11-15 08:52:10
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-15 09:05:20
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        int ans = 0;
        for (auto&& box : boxTypes) {
            int thisNumOfBox = min(box[0], truckSize);
            ans += thisNumOfBox * box[1];
            truckSize -= thisNumOfBox;
        }
        return ans;
    }
};