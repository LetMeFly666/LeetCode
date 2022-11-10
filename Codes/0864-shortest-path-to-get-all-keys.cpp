/*
 * @Author: LetMeFly
 * @Date: 2022-11-10 08:19:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-10 10:08:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry  // Error
struct Node {
    int x, y;
    bool keys[26];
    int cntKey;
    int step;

    Node(int x, int y) {
        this->x = x, this->y = y;
        this->cntKey = 0;
        this->step = 0;
    }
};

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int startX, startY;
        int cntKey = 0, cntUnlocked = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (islower(grid[i][j])) {
                    cntKey++;
                }
                else if (grid[i][j] == '@') {
                    startX = i, startY = j;
                }
            }
        }
        queue<Node> q;
        q.push(Node(startX, startY));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[startX][startY] = true;
        while (q.size()) {
            Node thisNode = q.front();
            q.pop();
            int thisX = thisNode.x, thisY = thisNode.y;
            for (int d = 0; d < 4; d++) {
                int tx = thisX + directions[d][0], ty = thisY + directions[d][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if (!visited[tx][ty] && grid[tx][ty] != '#') {
                        if (grid[tx][ty] == '.') {
                            Node newNode = thisNode;
                            newNode.x = tx, newNode.y = ty;
                            newNode.step++;
                            visited[tx][ty] = true;
                        }
                        else if (islower(grid[tx][ty])) {
                            Node newNode = thisNode;
                            newNode.x = tx, newNode.y = ty;
                            newNode.step++;
                            newNode.keys[grid[tx][ty] - 'a'] = true;
                            newNode.cntKey++;
                            visited[tx][ty] = true;
                        }
                        else if (isupper(grid[tx][ty])) {
                            if (thisNode.keys[tolower(grid[tx][ty]) - 'a']) {
                                Node newNode = thisNode;
                                newNode.x = tx, newNode.y = ty;
                                newNode.step++;
                                visited[tx][ty] = true;
                                cntUnlocked++;
                                if (cntUnlocked == cntKey) {
                                    return newNode.step;
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};
#else  // FirstTry
// SecondTry  // 目标是获得所有钥匙，而不是打开所有锁。
struct MyNode {
    int x, y;
    int mask;
    int step;

    MyNode(int x, int y) : x(x), y(y), mask(0), step(0) {}
};

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int startX, startY;
        int cntLock = 0;
        int n = grid.size(), m = grid[0].size();
        int key2th[26];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (islower(grid[i][j])) {
                    key2th[grid[i][j] - 'a'] = cntLock++;
                }
                else if (grid[i][j] == '@') {
                    startX = i, startY = j;
                }
            }
        }
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(1 << cntLock, false)));
        queue<MyNode> q;
        q.push(MyNode(startX, startY));
        visited[startX][startY][0] = true;
        while (q.size()) {
            MyNode thisNode = q.front();
            q.pop();
            int thisX = thisNode.x, thisY = thisNode.y, thisMask = thisNode.mask;
            // if (thisX == 1 && thisY == 4) {
            //     puts("Debug begin");  //********
            // }
            for (int d = 0; d < 4; d++) {
                int tx = thisX + directions[d][0], ty = thisY + directions[d][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] != '#') {
                    if (grid[tx][ty] == '.' || grid[tx][ty] == '@') {  // @也是空地！！！
                        if (!visited[tx][ty][thisMask]) {
                            visited[tx][ty][thisMask] = true;
                            MyNode newNode = thisNode;
                            newNode.x = tx, newNode.y = ty;
                            // printf("(%d, %d) -> (%d, %d), fromNode.mask = %d, toNode.mask = %d\n", thisX, thisY, tx, ty, thisNode.mask, newNode.mask);  //*******
                            newNode.step++;
                            q.push(newNode);
                        }
                    }
                    else if (islower(grid[tx][ty])) {
                        int toMask = thisMask | (1 << key2th[grid[tx][ty] - 'a']);
                        if (!visited[tx][ty][toMask]) {
                            visited[tx][ty][toMask] = true;
                            MyNode newNode = thisNode;
                            newNode.x = tx, newNode.y = ty;
                            newNode.step++;
                            newNode.mask = toMask;
                            // printf("(%d, %d) -> (%d, %d), fromNode.mask = %d, toNode.mask = %d\n", thisX, thisY, tx, ty, thisNode.mask, newNode.mask);  //*******
                            q.push(newNode);
                            if (toMask == (1 << cntLock) - 1) {
                                return newNode.step; 
                            }
                        }
                    }
                    else if (isupper(grid[tx][ty])) {
                        if (thisMask & (1 << key2th[grid[tx][ty] - 'A'])) {
                            if (!visited[tx][ty][thisMask]) {
                                visited[tx][ty][thisMask] = true;
                                MyNode newNode = thisNode;
                                newNode.x = tx, newNode.y = ty;
                                // printf("(%d, %d) -> (%d, %d), fromNode.mask = %d, toNode.mask = %d\n", thisX, thisY, tx, ty, thisNode.mask, newNode.mask);  //*******
                                newNode.step++;
                                q.push(newNode);
                            }
                        }
                    }
                    // printf("tx = %d, ty = %d, thisNode = {(%d, %d), %d, %d}\n", tx, ty, thisNode.x, thisNode.y, thisNode.mask, thisNode.step);  //********
                }
            }
        }
        return -1;
    }
};
#endif  // FirstTry

#ifdef _WIN32
/*
["@.a.#","###.#","b.A.B"]

*/
/*
["@...a",".###A","b.BCc"]

@...a
.###A
b.BCc

*/
int main() {
    string s;
    while (cin >> s) {
        vector<string> v = stringToVectorString(s);
        for (string& s : v) {
            s = s.substr(1, s.size() - 2);
        }
        debug(v);
        Solution sol;
        cout << sol.shortestPathAllKeys(v) << endl;
    }
    return 0;
}
#endif