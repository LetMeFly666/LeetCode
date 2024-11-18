/*
 * @Author: LetMeFly
 * @Date: 2024-11-18 21:03:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-18 21:08:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size()));
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int cnt = 0, s = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int nx = i + x, ny = j + y;
                        if (0 <= nx && nx < img.size() && 0 <= ny && ny < img[0].size()) {
                            s += img[nx][ny];
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