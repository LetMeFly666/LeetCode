/*
 * @Author: LetMeFly
 * @Date: 2024-03-16 09:14:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-16 09:44:39
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // TLE(maybe)：没有记录哪些位置被访问过，因此同一位置可能会被加入多次
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        queue<int> can;  // 能到达的所有行
        for (int i = 0; i < grid.size(); i++) {
            can.push(i);
        }
        int ans = 0;  // ans即为列
        while (can.size()) {
            ans++;
            if (ans == grid[0].size()) {
                break;
            }
            for (int i = can.size(); i > 0; i--) {
                int row = can.front();
                can.pop();
                for (int j = -1; j <= 1; j++) {
                    if (row + j >= 0 && row + j < grid.size() && grid[row + j][ans] > grid[row][ans - 1]) {
                        can.push(row + j);
                    }
                }
            }
        }
        return --ans;
    }
};
#else  // FirstTry
// SecondTry
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        unordered_set<int> can;
        for (int i = 0; i < grid.size(); i++) {
            can.insert(i);
        }
        int ans = 0;
        while (can.size()) {
            ans++;
            if (ans == grid[0].size()) {
                break;
            }
            unordered_set<int> nextCan;
            for (int row : can) {
                for (int j = -1; j <= 1; j++) {
                    if (row + j >= 0 && row + j < grid.size() && grid[row + j][ans] > grid[row][ans - 1]) {
                        nextCan.insert(row + j);
                    }
                }
            }
            swap(can, nextCan);
        }
        return --ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
/*
[[3,2,4],[2,1,9],[1,1,7]]

0
*/
/*
[[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]

3
*/
int main() {
    Solution sol;
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.maxMoves(v) << endl;
    }
    return 0;
}
#endif