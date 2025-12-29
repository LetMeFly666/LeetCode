/*
 * @Author: LetMeFly
 * @Date: 2025-12-29 18:40:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-29 22:37:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:

    vector<char> mappings[36];
    vector<vector<char>> pyramid;

    inline int bottom2int(char a, char b) {
        return (a - 'A') * 6 + b - 'A';
    }

    bool dfs(int i, int j) {
        if (i < 0) {
            return true;
        }
        if (j > i) {
            return dfs(i - 1, 0);
        }

        for (char c : mappings[bottom2int(pyramid[i + 1][j], pyramid[i + 1][j + 1])]) {
            pyramid[i][j] = c;
            if (dfs(i, j + 1)) {
                return true;
            }
        }
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string& s : allowed) {
            mappings[bottom2int(s[0], s[1])].push_back(s[2]);
        }
        int n = bottom.size();
        pyramid.resize(n);
        for (int i = 0; i < n; i++) {
            pyramid[i].resize(i + 1);
        }
        for (int i = 0; i < n; i++) {
            pyramid[n - 1][i] = bottom[i];
        }
        return dfs(n - 2, 0);
    }
};