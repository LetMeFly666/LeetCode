/*
 * @Author: LetMeFly
 * @Date: 2022-09-22 08:23:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-22 08:27:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int nowTh = -1, nowThTh;
        for (int& t : arr) {
            if (nowTh == -1) {
                for (int i = 0; i < pieces.size(); i++) {
                    if (pieces[i][0] == t) {
                        nowTh = i;
                        nowThTh = 0;
                    }
                }
                if (nowTh == -1) {
                    return false;
                }
            }
            if (t != pieces[nowTh][nowThTh]) {
                return false;
            }
            nowThTh++;
            if (nowThTh == pieces[nowTh].size()) {
                nowTh = -1;
            }
        }
        return true;
    }
};