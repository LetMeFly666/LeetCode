/*
 * @Author: LetMeFly
 * @Date: 2022-07-23 10:15:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-23 10:26:10
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<vector<int>> from(n + 1);
        vector<int> inDegree(n + 1, 0);
        for (vector<int>& v : sequences) {
            for (int i = 1; i < v.size(); i++) {  // v[i - 1] → v[i]
                from[v[i - 1]].push_back(v[i]);
                inDegree[v[i]]++;
            }
        }
        queue<int> zero;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                zero.push(i);
            }
        }
        while (zero.size()) {
            if (zero.size() != 1)
                return false;
            int thisFrom = zero.front();
            zero.pop();
            for (int& thisTo : from[thisFrom]) {
                inDegree[thisTo]--;
                if (!inDegree[thisTo]) {
                    zero.push(thisTo);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (inDegree[i])
                return false;
        }
        return true;
    }
};