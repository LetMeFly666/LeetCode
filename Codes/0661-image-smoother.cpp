/*
 * @Author: LetMeFly
 * @Date: 2022-03-24 08:31:59
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-03-24 08:39:13
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef First_Try
// 以为去掉了四周
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size() - 2, vector<int>(img[0].size() - 2));
        for (int i = 1; i + 1 < img.size(); i++) {
            for (int j = 1; j + 1 < img[0].size(); j++) {
                int s = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        s += img[i + x][j + y];
                    }
                }
                ans[i - 1][j - 1] = s / 9;
            }
        }
        return ans;
    }
};
#else
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size()));
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int s = 0, cnt = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x + i >= 0 && x + i < img.size() && y + j >= 0 && y + j < img[0].size()) {
                            s += img[i + x][j + y];
                            cnt++;
                        }
                    }
                }
                ans[i][j] = s / cnt;
            }
        }
        return ans;
    }
};
#endif