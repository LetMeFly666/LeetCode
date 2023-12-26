/*
 * @Author: LetMeFly
 * @Date: 2023-12-26 09:12:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-26 10:04:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int m, n;
    vector<vector<char>> seats;
    unordered_map<int, int> visited;

    bool isOkState(int row, int status) {
        // return true;
        for (int j = 0; j < n; j++) {
            if (!(status & (1 << j))) {
                continue;
            }
            // 二进制状态下这一位为1
            if (seats[row][j] == '#') {
                return false;
            }
            if (j > 0 && (status & (1 << (j - 1)))) {  // 相邻两个1
                return false;
            }
        }
        return true;
    }

    int RealDFS(int row, int status) {
        if (visited.count((row << n) + status)) {
            return visited[(row << n) + status];
        }
        if (!isOkState(row, status)) {
            return -1000;
        }
        int cnt1 = __builtin_popcount(status);
        if (!row) {
            return cnt1;
        }
        int ans = 0;
        for (int lastStatus = 0; lastStatus < (1 << n); lastStatus++) {
            ans = max(ans, dfs(row - 1, lastStatus));
        }
        ans += cnt1;
        return visited[(row << n) + status] = ans;
    }

    int dfs(int row, int status) {
        int ans = RealDFS(row, status);
        char bin[33];
        itoa(status, bin, 2);
        if (row == 2) {
            printf("row = %d, status = %d = %s, ans = %d\n", row, status, bin, ans);
        }
        return ans;
    }
public:
    int maxStudents(vector<vector<char>>& seats) {
        this->seats = move(seats);
        m = this->seats.size(), n = this->seats[0].size();
        int ans = 0;
        for (int j = 0; j < (1 << n); j++) {
            ans = max(ans, dfs(m - 1, j));
        }
        return ans;
    }
};

#ifdef _WIN32
/*
[["#",".","#","#",".","#"],[".","#","#","#","#","."],["#",".","#","#",".","#"]]

#.##.#
.####.
#.##.#
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<vector<char>> v = stringToVectorVectorC(s);
        cout << sol.maxStudents(v) << endl;
    }
    return 0;
}
#endif