/*
 * @Author: LetMeFly
 * @Date: 2022-05-18 16:16:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-18 18:46:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef First_Half
// 写了一半发现不太行，吃个饭回来不想写了。
class Grid {
public:
    int x, y;
    set<int> can;  // 可以填入的数字
    Grid() {}
    Grid(int x, int y): x(x), y(y) {}
    Grid(int x, int y, const set<int>& can): x(x), y(y), can(can) {}
    bool operator < (const Grid& second) const {
        return can.size() > second.can.size();
    }
};

const static set<int> _1to9 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

set<int> operator & (const set<int>& a, const set<int>& b) {
    set<int> ans;
    for (auto t : a) {
        if (b.count(t)) {
            ans.insert(t);
        }
    }
    return ans;
}

class Solution {
private:
    priority_queue<Grid> pq;
    set<int> rowCan[9];
    set<int> colCan[9];
    set<int> gridCan[3][3];
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            rowCan[9] = _1to9;
            for (int j = 0; j < 9; j++) {
                if (board[row][j] != '.') {
                    rowCan[j].erase(board[row][j] - '0');
                }
            }
        }
        for (int col = 0; col < 9; col++) {
            colCan[9] = _1to9;
            for (int i = 0; i < 9; i++) {
                if (board[i][col] != '.') {
                    colCan[i].erase(board[i][col] - '0');
                }
            }
        }
        for (int gridThX = 0; gridThX < 3; gridThX++) {
            for (int gridThY = 0; gridThY < 3; gridThY++) {
                gridCan[gridThX][gridThY] = _1to9;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[gridThX * 3 + i][gridThY * 3 + j] != '.') {
                            gridCan[gridThX][gridThY].erase(board[gridThX * 3 + i][gridThY * 3 + j] - '0');
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    pq.emplace(i, j, rowCan[i] & colCan[j] & gridCan[i][j]);
                    // pq.push({i, j, rowCan[i] & colCan[j] & gridCan[i][j]});  // 一样的效果
                }
            }
        }

        while (pq.size()) {
            Grid grid = pq.top();
            pq.pop();
            assert(grid.can.size() == 1);
            
            int x = grid.x, y = grid.y;
            int val = *grid.can.begin();
            board[x][y] = val + '0';
            rowCan[x].erase(val);
            colCan[y].erase(val);
            gridCan[x / 3][y / 3].erase(val);
        }

    }
};

#ifdef _WIN32
int main() {
    // 测试是否真的为小的优先
    priority_queue<Grid> pq;
    set<int> se = {1, 2, 5};
    Grid g(5, 5, se);
    pq.push(g);
    se = {1, 2, 5, 6};
    Grid g2(5, 5, se);
    pq.push(g2);
    se = {1, 2, 5};
    Grid g3(5, 5, se);
    pq.push(g3);
    cout << pq.top().can.size() << endl;
    system("pause");
    return 0;
}
#endif


#else  // First_Half

#ifdef _WIN32
#else
template<class Type>
void debug(vector<Type>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    puts("");
}

template<class Type>
void debug(vector<vector<Type>> v) {
    if (v.empty()) {
        puts("++\n++\n");
    }
    stringstream ss;
    for (auto t : v[0]) {
        ss << t << ' ';
    }
    string s;
    getline(ss, s);
    int l = s.size();

    function<void(int)> printOneline = [](int l) {
        putchar('+');
        for (int i = 0; i < l; i++) {
            putchar('-');
        }
        puts("+");
    };

    printOneline(l);
    for (auto tv : v) {
        putchar('|');
        for (auto t : tv) {
            cout << t << ' ';
        }
        puts("|");
    }
    printOneline(l);
}
#endif

#ifdef SecondTry
// Error：可能不能一次确定任意一个位置的值，因此需要搜索
const static set<int> _1to9 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

set<int> operator & (const set<int>& a, const set<int>& b) {
    set<int> ans;
    for (auto t : a) {
        if (b.count(t)) {
            ans.insert(t);
        }
    }
    return ans;
}

void debug(set<int> grid[9][9]) {
    puts("--------------------------");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << "[" << i << ", " << j << "]:";
            for (int t : grid[i][j]) {
                cout << " " << t;
            }
            puts("");
        }
    }
    puts("--------------------------");
}

class Solution {
private:
    set<int> rowCan[9];
    set<int> colCan[9];
    set<int> gridCan[3][3];
    set<int> grid[9][9];
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            rowCan[row] = _1to9;
            for (int j = 0; j < 9; j++) {
                if (board[row][j] != '.') {
                    rowCan[j].erase(board[row][j] - '0');
                }
            }
        }
        for (int col = 0; col < 9; col++) {
            colCan[col] = _1to9;
            for (int i = 0; i < 9; i++) {
                if (board[i][col] != '.') {
                    colCan[i].erase(board[i][col] - '0');
                }
            }
        }
        for (int gridThX = 0; gridThX < 3; gridThX++) {
            for (int gridThY = 0; gridThY < 3; gridThY++) {
                gridCan[gridThX][gridThY] = _1to9;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[gridThX * 3 + i][gridThY * 3 + j] != '.') {
                            gridCan[gridThX][gridThY].erase(board[gridThX * 3 + i][gridThY * 3 + j] - '0');
                        }
                    }
                }
            }
        }

        int remainNum = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    grid[i][j] = rowCan[i] & colCan[j] & gridCan[i / 3][j / 3];
                    remainNum++;
                }
            }
        }

        debug(grid);
        while (remainNum) {
            bool found = false;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (grid[i][j].size() == 1) {
                        remainNum--;
                        found = true;
                        int val = *grid[i][j].begin();
                        board[i][j] = val + '0';
                        for (int i2 = 0; i2 < 9; i2++) {
                            grid[i2][j].erase(val);
                        }
                        for (int j2 = 0; j2 < 9; j2++) {
                            grid[i][j2].erase(val);
                        }
                        int girdNumX = i / 3, gridNumY = j / 3;
                        for (int i2 = 0; i2 < 3; i2++) {
                            for (int j2 = 0; j2 < 3; j2++) {
                                grid[girdNumX + i2][gridNumY + j2].erase(val);
                            }
                        }
                        goto loop;
                    }
                }
            }
            debug(grid);
            // assert(found);
            if (!found) {
                debug(board);
                break;
            }
            loop:;
        }
    }
};

#ifdef _WIN32
int main() {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution sol;
    sol.solveSudoku(board);

    debug(board);
    system("pause");
    return 0;
}
#endif

#else
// Copy From LeetCode https://leetcode.cn/problems/sudoku-solver/solution/jie-shu-du-by-leetcode-solution/
class Solution {
private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int, int>> spaces;

public:
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        auto [i, j] = spaces[pos];
        for (int digit = 0; digit < 9 && !valid; ++digit) {
            if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;
                dfs(board, pos + 1);
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                }
                else {
                    int digit = board[i][j] - '0' - 1;
                    line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                }
            }
        }

        dfs(board, 0);
    }
};

#endif  // Second_Try
#endif  // First_Half